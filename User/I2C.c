#include <LPC23xx.H>
#include "I2C.h"
#include "Serial.h"
 int index=0,I2Counter=2,i=0;
 char r;
 char read[100];
void delay (void)
{
unsigned int i=10;
while(i--);
}
 void I2cInit(void){
	I20SCLL=50;
 	I20SCLH=50;
	//SCS=1;
	
	PCONP   |=  (1 << 7);                              // enable power contol for I2C0
    PINSEL1  |=  0x01400000;
 }
 void I2cWrite(int length,char Add,char Data[100]){
	I20CONCLR=0xFF;
	I20CONSET=0x40;
 	I20CONSET=0x20;
	for(i=0;i<length+2;i++){ 
	switch(I20STAT)
    {
	    case 0x08:
			I20CONCLR = 0x20;
			I20DAT=Add;
			I20CONSET=0x40;
			I20CONCLR=0x08;
			index =0;
			I2Counter=length;
		
	    break;
		case 0x10:
			
		break;
		case 0x18:
			I20DAT = Data[index++];
			I20CONSET=0x40;
			I20CONCLR=0x08;
			I2Counter--;
			
		break;
		case 0x28:
			 if(I2Counter--!=0)
           {
             I20DAT =Data[index++];
			 I20CONSET=0x40;
			I20CONCLR=0x08;
           }
           else
           {
			 i=1000;
       		}
		break;
		default:
			i--;
			//SerialPrint(0,"Error!\r\n");
		break;
	}
	}
	 I20CONSET = 0x10; // Stop condition
	 I20CONSET=0x40;
	I20CONCLR=0x08;
 }

 char *I2cRead(int length,char Add){
	I20CONCLR=0xFF;
	I20CONSET=0x40;
 	I20CONSET=0x20;
	for(i=0;i<100;i++)
	read[i]='\0';
	for(i=0;i<length+2;i++){ 
	switch(I20STAT)
    {
	    case 0x08:
			I20CONCLR = 0x20;
			I20DAT=Add+1 ;
			I20CONSET=0x40;
			I20CONCLR=0x08;
			index =0;
			I2Counter=length;
		
	    break;
		case 0x40:
		I20CONSET=0x04;
      	I20CONCLR=0x08;
		break;
		case 0x50:
			//if(I2Counter!=0){
			I20CONCLR=0x0C;
			I20CONCLR=0x08;
			//read[index]=I20DAT;
			read[index]=I20DAT;
			I20CONSET=0x04;
      		I20CONCLR=0x08;
			index++;
			
			//I2Counter--;
			//}else{
				//I20CONSET = 0x10;
			//}
			// // Stop condition
			//I20DAT = Data[index++];
			//I20CONSET=0x40;
			//I20CONCLR=0x08;
			//I2Counter--;

			
		break;
		default:
			i--;
			//SerialPrint(0,"Error!\r\n");
		break;
	}
 	}
   I20CONSET = 0x10;
   return read;
 }
