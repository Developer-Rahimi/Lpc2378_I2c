#ifndef _EEPROM_H
#define	_EEPROM_H
extern  void WriteEEPROM (char add_slave ,char *add,char *Data);
extern char *ReadEEPROM (char add_slave ,char *add,int size);

#endif
