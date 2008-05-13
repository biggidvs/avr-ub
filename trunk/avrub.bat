@rem auto create by AVRUBD at 2008-4-14 обнГ 04:03:17
avr-gcc.exe  -mmcu=atmega169 -Wall -gdwarf-2  -Os -fsigned-char -MD -MP  -c  bootldr.c
avr-gcc.exe -mmcu=atmega169  -Wl,-section-start=.text=0x3800 bootldr.o     -o Bootldr.elf
avr-objcopy -O ihex -R .eeprom  Bootldr.elf Bootldr.hex
@pause
