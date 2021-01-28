/*  
    Spray0 
    Copyright © 2021 Spray0,All Rights Reserved.
    <javen.chan@outlook.com>
    2021-1 Ver1.0 Changzhou.China
*/

#include <stdio.h>
#include "./PCA9536/PCA9536.h"

#define I2C_INTERFACE_ADDR 1
int PCA9536;
int main(int argc, char *argv[])
{
    printf("PCA9536 Demo Spray0 2021-1\r\n");
    PCA9536 = PCA9536_Initialize(I2C_INTERFACE_ADDR);
    if(PCA9536>0)printf("Initialize PCA9536 OK @/dev/i2c-%d\r\n",I2C_INTERFACE_ADDR);
    else {
        printf("Initialize PCA9536 ... error\r\n");
        return -1;
    }
    if(argc == 2){
        unsigned char color=atoi(argv[1]);
        printf("Input argv:%d\r\n",color);
        if(color<8){
            // Set OutputPort register
            PCA9536_WRITE_REG(PCA9536,REG_OutputPort,0xF8+color);
        }
    }
    
    printf("Read all regs...\r\n");
    uint8_t buf;
    PCA9536_READ_REG(PCA9536,REG_InputPort,&buf);
    printf("ReadREG>[%d]REG_InputPort         : 0x%x\r\n",REG_InputPort,buf);
    PCA9536_READ_REG(PCA9536,REG_OutputPort,&buf);
    printf("ReadREG>[%d]REG_OutputPort        : 0x%x\r\n",REG_OutputPort,buf);
    PCA9536_READ_REG(PCA9536,REG_PolarityInversion,&buf);
    printf("ReadREG>[%d]REG_PolarityInversion : 0x%x\r\n",REG_PolarityInversion,buf);
    PCA9536_READ_REG(PCA9536,REG_Configuration,&buf);
    printf("ReadREG>[%d]REG_Configuration     : 0x%x\r\n",REG_Configuration,buf);

    close(PCA9536);
    printf("Done.\r\n");

    return 0;
}