#include "GPIO.h"
#include <lpc23xx.h>
void INIT_PIN(int Port,int Pin){
	switch(Port){
	  case 0:
	  FIO0DIR |=(1<<Pin);
	  break;
	  case 1:
	  FIO1DIR |=(1<<Pin);
	  break;
	  case 2:
	  FIO2DIR |=(1<<Pin);
	  break;
	  case 3:
	  FIO3DIR |=(1<<Pin);
	  break;
	  case 4:
	  FIO4DIR |=(1<<Pin);
	  break;
	}
}
void SET_PIN(int Port,int Pin){
	switch(Port){
	  case 0:
	  FIO0SET |=(1<<Pin);
	  break;
	  case 1:
	  FIO1SET |=(1<<Pin);
	  break;
	  case 2:
	  FIO2SET |=(1<<Pin);
	  break;
	  case 3:
	  FIO3SET |=(1<<Pin);
	  break;
	  case 4:
	  FIO4SET |=(1<<Pin);
	  break;
	}
}
void CLR_PIN(int Port,int Pin){
	switch(Port){
	  case 0:
	  FIO0CLR |=(1<<Pin);
	  break;
	  case 1:
	  FIO1CLR |=(1<<Pin);
	  break;
	  case 2:
	  FIO2CLR |=(1<<Pin);
	  break;
	  case 3:
	  FIO3CLR |=(1<<Pin);
	  break;
	  case 4:
	  FIO4CLR |=(1<<Pin);
	  break;
	}
}
