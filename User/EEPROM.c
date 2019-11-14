#include <string.h>
#include <stdio.h>
#include "EEPROM.h"
#include "I2C.h"
 int eepindex =0;
void WriteEEPROM (char add_slave ,char *add,char *Data){
	char ee[100];
	 ee[0]=add[0];
	 ee[1]=add[1];
	for(eepindex=0;Data[eepindex]!='\0';eepindex++)
		ee[eepindex+2]=Data[eepindex];
	  eepindex+=2;
  I2cWrite(eepindex,add_slave,ee);

}
char *ReadEEPROM (char add_slave ,char *add,int size){
	I2cWrite(2,0xA0,add);
  	return I2cRead(size,0xA0);
}
