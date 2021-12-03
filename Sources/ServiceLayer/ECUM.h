#ifndef __ECUM_H__
#define __ECUM_H__

void TimeBaseCount(void);
uint16_t GetTimeCounter(void);
extern volatile uint8_t TimeBase1msFlag;
extern volatile uint8_t TimeBase5msFlag;
extern volatile uint8_t TimeBase10msFlag;
extern volatile uint8_t TimeBase20msFlag;
extern volatile uint8_t TimeBase50msFlag;
extern volatile uint8_t TimeBase100msFlag;
extern volatile uint8_t TimeBase1000msFlag;



#endif
