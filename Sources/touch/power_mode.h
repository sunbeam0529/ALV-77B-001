/****************************************************************************//*!
*
* @file     power_mode.h
*
* @version  1.0.0.0
*
* @date     September-2017
*
* @brief    Power modes for S32K144
*
*******************************************************************************/
#ifndef __POWER_MODE_H
#define __POWER_MODE_H

/*******************************************************************************
* Defines
*******************************************************************************/
#define RUN  1
#define STOP 2
#define VLPR 4
#define VLPW 8
#define VLPS 16
#define HSRUN 128

/*******************************************************************************
* Define run mode clock source
*******************************************************************************/
#define RUN_PLL  10
#define RUN_FIRC 11

#ifdef CLOCKMODE_FIRC_48MHZ
#define CLOCKMODE RUN_FIRC
#endif

#ifdef CLOCKMODE_PLL_80MHZ
#define CLOCKMODE RUN_PLL
#endif

/*******************************************************************************
* Function prototypes
******************************************************************************/
void Run_to_VLPS(void);
void Run_to_VLPR(void);
void VLPR_to_VLPS(void);


#endif /* __POWER_MODE_H */
