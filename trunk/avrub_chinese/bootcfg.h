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


  Project:       AVR 通用 BootLoader
  File:          bootcfg.h
                 用户配置参数，请根据你系统的实际情况进行设置
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

//定义串口接收缓冲区长度
#define BUFFERSIZE         128

//系统时钟(Hz)
#ifndef F_CPU
#define F_CPU              8000000UL
#endif

//波特率
#define BAUDRATE           9600

//Boot区起始地址: 按字节计算
//如果定义为0或不定义BootStart，可以节约空间
#define BootStart          0x1C00 * 2

//下载过程中进行数据校验
//ChipCheck和BootStart必须联合使用，校验才有效
#define ChipCheck          1

//Bootloader触发模式  0:串口  1:电平
#define LEVELMODE          0

#define LEVELPORT          D
#define LEVELPIN           PD7
//触发电平 1:高  0:低
#define PINLEVEL           0

//等待密码的超时时间 = TimeOutCnt * timeclk
//超时次数
#define TimeOutCnt         20

//同步时间间隔(ms)
#define timeclk            200

//等待文件的超时时间 = TimeOutCntC * timeclk
//发送'C'的最大次数
#define TimeOutCntC        50

//同步密码长度
#define CONNECTCNT         5

//同步密码
#if (LEVELMODE == 0)
unsigned char ConnectKey[] = {0x41, 0x56, 0x52, 0x55, 0x42};
#endif

//串口号: 0/1/2..
#define COMPORTNo          0

//看门狗使能
#define WDG_En             1

//使用RS485模式
#define RS485              0
//RS485/RS422控制端口和引脚
#define RS485PORT          D
#define RS485TXEn          PD5

//使用LED指示状态
#define LED_En             1
//LED控制端口和引脚
#define LEDPORT            A
#define LEDPORTNo          PA6

//某些旧型号的单片机在初始化后需要延时
#define InitDelay          0

//校验方法  0:CRC16  1:累加和
#define CRCMODE            0

//提示模式: 显示更多交互提示信息，不用可以节省空间
#define VERBOSE            1

//提示信息
#if VERBOSE
#if LEVELMODE
const char msg6[] = "升级模式.";
const char msg7[] = "正常启动.";
#else
//等待密码
const char msg1[] = "等待接收密码.";
#endif
//超时
const char msg2[] = "超时.";
//等待接收数据
const char msg3[] = "等待接收数据.";
//升级成功
const char msg4[] = "升级成功.";
//升级失败
const char msg5[] = "升级失败.";
#endif

//允许解密
#define Decrypt            1

//加密算法
// 0: PC1_128, 128位 PC1 加密算法
// 1: PC1_256, 256位 PC1 加密算法

#define Algorithm          0

#if Decrypt

#if (Algorithm == 0)
//定义解密密钥: 128位
unsigned char DecryptKey[16] ={
  0x52, 0x65, 0x6D, 0x73,
  0x61, 0x61, 0x6C, 0x70,
  0x73, 0x21, 0x31, 0x32,
  0x33, 0x34, 0x35, 0x36
};
#elif (Algorithm == 1)
//定义解密密钥: 256位
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
