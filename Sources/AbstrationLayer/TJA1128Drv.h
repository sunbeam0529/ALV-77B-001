#ifndef __TJA1128DRV_H__
#define __TJA1128DRV_H__

#include "Cpu.h"

//globe function
void SDI_write1bit(uint8_t bits);
void SCK_write1bit(uint8_t bits);
void SCSN_write1bit(uint8_t bits);
uint8_t SDO_read1bit(void);

uint8_t SPI_ReadByte(uint8_t addr);
void SPI_Delay(uint32_t time);
void SPI_GPIO_Init(void);
uint8_t SPI_WriteByte(uint8_t addr,uint8_t data);

void LIN_PORT_Init(void);
void SBC_Init(void);



#endif /* __TJA1128DRV_H__ */
