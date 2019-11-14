#include <LPC23xx.H>
#include "I2C.h"
#include "Delay.h"
#include "Serial.h"
#include "EEPROM.h"
char add1[2]	={0xFF,0x00};
char add2[2]	={0x00,0x00};
int main(void)
{
	FIO4DIR=0xFFFFFFFF;
	FIO4CLR=0xFFFFFFFF;
	InitSerial (0);
	SerialPrint(0,"App Start!\r\n");
	I2cInit();
	while(1)
	{
	WriteEEPROM (0xA0 ,add1,"Developer Rahimi");
		delay_ms(100);
	WriteEEPROM (0xA0 ,add2,"Engineer Rahimi");
	delay_ms(2000);
	
	SerialPrint(0,ReadEEPROM (0xA0,add1 ,16));
		SerialPrint(0,"\r\n");
	delay_ms(1000);
	SerialPrint(0,ReadEEPROM (0xA0,add2 ,15));
	SerialPrint(0,"\r\n");
	

	}
}
