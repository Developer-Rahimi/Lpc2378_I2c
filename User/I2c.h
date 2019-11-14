#ifndef _I2C_H
#define	_I2C_H
extern void delay (void);
extern void I2cInit(void);
extern void I2cWrite(int length,char Add,char  Data[100]);
extern char *I2cRead(int length,char Add);
#endif
