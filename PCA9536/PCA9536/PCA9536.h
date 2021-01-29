/*  
    PCA9536D
    NXP
    4-bit I2C-bus and SMBus I/O port
*/
/*  
    Spray0 
    Copyright © 2021 Spray0,All Rights Reserved.
    <javen.chan@outlook.com>
    2021-1 Ver1.0 Changzhou.China
*/

#ifndef PCA9536D_H_
#define PCA9536D_H_

#include <stdint.h>
#include <linux/i2c-dev.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <elf.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define DEFAULT_ADDR          0x41 

enum PCA9536D_REG_ADDR{
    REG_InputPort=0,
    REG_OutputPort,
    REG_PolarityInversion,
    REG_Configuration
};

int PCA9536_WRITE_REG(int fp, enum PCA9536D_REG_ADDR addr,unsigned char data);
int PCA9536_READ_REG(int fp, enum PCA9536D_REG_ADDR addr,unsigned char *data);
int PCA9536_Initialize(unsigned char I2C_Interface);

#endif