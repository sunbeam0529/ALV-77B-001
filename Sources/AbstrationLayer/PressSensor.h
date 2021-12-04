#ifndef __PRESSSENSOR_H__
#define __PRESSSENSOR_H__

#include "Cpu.h"
uint16_t GetPressValue(uint8_t dev);
void PressSensorInit(void);
void WriteReg(uint8_t dev,uint8_t reg,uint8_t data);
uint8_t ReadReg(uint8_t dev,uint8_t reg);
uint8_t GetPressPreload(uint8_t dev);
uint16_t GetPressRawdata(uint8_t dev);
int16_t GetPressBaseline(uint8_t dev);

#endif
