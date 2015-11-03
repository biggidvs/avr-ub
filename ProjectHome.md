# AVR Universal Bootloader (AVR-UB) #

This project is a general AVR bootloader, for different type of AVR device, all you need to do is modify macro definition, and you do not need to modify the main program. There are many bootloader program on internet, but most of them are only available for special types. When we need to use other types device, we must do a lot of modification. And many of them are only realize the basic functions, and have bugs, hidden problem or may be used inconveniently, so we have developed this program. This project based on ATmega128 bootloader program which developed by Mr ChaoMa, and combined experience in bootloader of PIC18 microcontroller I have wrote before, and used the macro definition skill from AVRUSB, and optimize and test the code time after time, finally get this project.

This AVR universal bootloader can support most types of AVR microcontrollers (Mega series), which have self-programable capability, boot section and UART. If the device have many serial ports, you can use any one of them. This bootloader supports RS232, RS485 and RS422. It can also supports USI, SPI, I2C interface if you made some necessary modify.

This bootloader will occupy less than 1k words flash maximum, and it may occupy less than 300 words minimum. The space occupied by the bootloader is relative with device type, configuration parameters, functions you select, and the optimize grade that the compiler use.

## Main Features ##
  * Support many types of AVR microcontrollers.
  * Support AVR device with multi-uart.
  * Support RS232/RS485/RS422 mode.
  * Support variable communication baudrate and system clock frequcene.
  * Automatically calculate the baudrate error.
  * Write with AVR GCC, 100% C code.
  * High optimized, small code space occupy.
  * Cut out the function conveniently, and can meet different requirements.
  * Support Watchdog.
  * User may use the LED to show the upgrade status.
  * Support hypertrm as download software on PC side.
  * Support FLASH verification.
  * Can define the size of user program section.
  * Linux support
  * and more ...