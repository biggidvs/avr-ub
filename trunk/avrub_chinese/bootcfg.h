/*

                           e Y8b    Y8b YV4.08P888 88e
                          d8b Y8b    Y8b Y888P 888 888D
                         d888b Y8b    Y8b Y8P  888 88"
                        d8WuHan888b    Y8b Y   888 b,
                       d8888888b Y8b    Y8P    888 88b,
           8888 8888       ,e,                                  888
           8888 888820088e  " Y8b Y888P ,e e, 888,8, dP"Y ,"Y88b888
           8888 8888888 88b888 Y8b Y8P d88 88b888 " C88b "8" 888888
           8888 8888888 888888  Y8b "  888   ,888    Y88D,ee 888888
           'Y88 88P'888 888888   Y8P    "YeeP"888   d,dP "88 888888
   888 88b,                    d8  888                     888
   888 88P' e88 88e  e88 88e  d88  888 e88 88e  ,"Y88b e88 888 ,e e, 888,8,
   888 8K  d888 888bd888 8Shaoziyang88d888 888b"8" 888d888 888d88 88b888 "
   888 88b,Y888 888PY888 888P 888  888Y888 888P,ee 888Y888 888888   ,888
   888 88P' "88 88"  "88 88"  888  888 "88 88" "88 888 "88 888 "YeeP"888


  Project:       AVR ͨ�� BootLoader
  File:          bootcfg.h
                 �û����ò������������ϵͳ��ʵ�������������
  Version:       4.1

  Compiler:      WinAVR 20071221 + AVR Studio 4.14.589

  Author:        Shaoziyang
                 Shaoziyang@gmail.com
                 http://avrubd.googlepages.com
                 http://sourceforge.net/projects/avrub
                 
  Date:          2008.5

  See readme.htm to get more information.

*/

#ifndef _BOOTCFG_H_
#define _BOOTCFG_H_        1

//���崮�ڽ��ջ���������
#define BUFFERSIZE         128

//ϵͳʱ��(Hz)
#ifndef F_CPU
#define F_CPU              8000000UL
#endif

//������
#define BAUDRATE           9600

//Boot����ʼ��ַ: ���ֽڼ���
//�������Ϊ0�򲻶���BootStart�����Խ�Լ�ռ�
#define BootStart          0x1C00 * 2

//���ع����н�������У��
//ChipCheck��BootStart��������ʹ�ã�У�����Ч
#define ChipCheck          1

//Bootloader����ģʽ  0:����  1:��ƽ
#define LEVELMODE          0

#define LEVELPORT          D
#define LEVELPIN           PD7
//������ƽ 1:��  0:��
#define PINLEVEL           0

//�ȴ�����ĳ�ʱʱ�� = TimeOutCnt * timeclk
//��ʱ����
#define TimeOutCnt         20

//ͬ��ʱ����(ms)
#define timeclk            200

//�ȴ��ļ��ĳ�ʱʱ�� = TimeOutCntC * timeclk
//����'C'��������
#define TimeOutCntC        50

//ͬ�����볤��
#define CONNECTCNT         5

//ͬ������
#if (LEVELMODE == 0)
unsigned char ConnectKey[] = {0x41, 0x56, 0x52, 0x55, 0x42};
#endif

//���ں�: 0/1/2..
#define COMPORTNo          0

//���Ź�ʹ��
#define WDG_En             1

//ʹ��RS485ģʽ
#define RS485              0
//RS485/RS422���ƶ˿ں�����
#define RS485PORT          D
#define RS485TXEn          PD5

//ʹ��LEDָʾ״̬
#define LED_En             1
//LED���ƶ˿ں�����
#define LEDPORT            A
#define LEDPORTNo          PA6

//ĳЩ���ͺŵĵ�Ƭ���ڳ�ʼ������Ҫ��ʱ
#define InitDelay          0

//У�鷽��  0:CRC16  1:�ۼӺ�
#define CRCMODE            0

//��ʾģʽ: ��ʾ���ཻ����ʾ��Ϣ�����ÿ��Խ�ʡ�ռ�
#define VERBOSE            1

//��ʾ��Ϣ
#if VERBOSE
#if LEVELMODE
const char msg6[] = "����ģʽ.";
const char msg7[] = "��������.";
#else
//�ȴ�����
const char msg1[] = "�ȴ���������.";
#endif
//��ʱ
const char msg2[] = "��ʱ.";
//�ȴ���������
const char msg3[] = "�ȴ���������.";
//�����ɹ�
const char msg4[] = "�����ɹ�.";
//����ʧ��
const char msg5[] = "����ʧ��.";
#endif

//�������
#define Decrypt            1

//�����㷨
// 0: PC1_128, 128λ PC1 �����㷨
// 1: PC1_256, 256λ PC1 �����㷨

#define Algorithm          0

#if Decrypt

#if (Algorithm == 0)
//���������Կ: 128λ
unsigned char DecryptKey[16] ={
  0x52, 0x65, 0x6D, 0x73,
  0x61, 0x61, 0x6C, 0x70,
  0x73, 0x21, 0x31, 0x32,
  0x33, 0x34, 0x35, 0x36
};
#elif (Algorithm == 1)
//���������Կ: 256λ
unsigned char DecryptKey[32] ={
  0x52, 0x65, 0x6D, 0x73,
  0x61, 0x61, 0x6C, 0x70,
  0x73, 0x21, 0x31, 0x32,
  0x33, 0x34, 0x35, 0x36,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00
};

#endif

#endif

#endif

//End of file: bootcfg.h
