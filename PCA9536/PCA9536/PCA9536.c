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

#include "PCA9536.h"

int PCA9536_READ_REG(int fp, enum PCA9536D_REG_ADDR addr,unsigned char *data){
    int rtn;
    rtn = write(fp, &addr, 1);
     if ( rtn != 1 ) {
        printf("ERROR sending command %d :- %s\n",rtn, strerror (errno));
        return -1;
    } 
    rtn = read(fp, data, 1);
    if ( rtn < 1) {
        printf("ERROR reading data %d :- %s\n",rtn, strerror (errno));
      return -1;
    }
     return 1;
}

int PCA9536_WRITE_REG(int fp, enum PCA9536D_REG_ADDR addr,unsigned char data){
    int rtn;
    unsigned char send[2]={addr,data};
    rtn = write(fp, send, 2);
    if ( rtn != 2 ) {
        printf("ERROR sending command %d :- %s\n",rtn, strerror (errno));
        return -1;
    } 
    return 1;
}

int PCA9536_Initialize(unsigned char I2C_Interface){
    char filename[20];
    int fp;
  
    snprintf(filename, 19, "/dev/i2c-%d", I2C_Interface);
    fp = open(filename, O_RDWR);
    if (fp < 0) {
        return fp;
    }

    if (ioctl(fp, I2C_SLAVE, DEFAULT_ADDR) < 0) {
        close(fp);
        return -1;
    }

    /*user code*/

    // Set PIN0,1,2 as output
    if(PCA9536_WRITE_REG(fp,REG_Configuration,0xF8)<0)return -1;
    // Set OutputPort register  PIN0,1,2=L
    if(PCA9536_WRITE_REG(fp,REG_OutputPort,0xF8)<0)return -1;

    /*user code end*/

    return fp;
}
