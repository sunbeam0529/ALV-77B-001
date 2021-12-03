#ifndef __PRESSSENSOR_H__
#define __PRESSSENSOR_H__

#include "Cpu.h"
uint16_t GetPressValue(void);
void PressSensorInit(void);
void WriteReg(uint8_t reg,uint8_t data);
uint8_t ReadReg(uint8_t reg);
uint8_t GetPressPreload(void);
uint16_t GetPressRawdata(void);
int16_t GetPressBaseline(void);

#endif
