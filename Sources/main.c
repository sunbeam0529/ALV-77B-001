/* ###################################################################
**     Filename    : main.c
**     Processor   : S32K1xx
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.00
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */




/* Including necessary module. Cpu.h contains other modules needed for compiling.*/
#include "Cpu.h"
#include "printf.h"
#include "ECUM.h"
#include "PressSensor.h"
#include "MCP4716Drv.h"
#include "Touch.h"

volatile int exit_code = 0;
flexio_uart_state_t   uartStateTX;
flexio_device_state_t flexIODeviceState;
/* User includes (#include below this line is not maintained by Processor Expert) */

uint8_t testdata[128]={
    1,2,3,4,5,6,7,8,
    1,2,3,4,5,6,7,8,
    1,2,3,4,5,6,7,8,
    1,2,3,4,5,6,7,8,
    1,2,3,4,5,6,7,8,
    1,2,3,4,5,6,7,8,
    1,2,3,4,5,6,7,8,
    1,2,3,4,5,6,7,8,
    1,2,3,4,5,6,7,8,
    1,2,3,4,5,6,7,8,
    1,2,3,4,5,6,7,8,
    1,2,3,4,5,6,7,8,
    1,2,3,4,5,6,7,8,
    1,2,3,4,5,6,7,8,
    1,2,3,4,5,6,7,8,
    1,2,3,4,5,6,7,8,
};

void _putchar(char character)
{
	uint8_t data=0;

	data = character;

	FLEXIO_UART_DRV_SendDataBlocking(&uartStateTX,&data,1,10);
}

/*! 
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
  /* Write your local variable definition here */
	uint16_t val;
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  #ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                   /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */
    CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT,g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
    CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);

	PINS_DRV_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);

	FLEXIO_DRV_InitDevice(INST_FLEXIO_UART1, &flexIODeviceState);
	FLEXIO_UART_DRV_Init(INST_FLEXIO_UART1, &flexio_uart1_Config0, &uartStateTX);

	//FLEXIO_UART_DRV_SendData(&uartStateTX,testdata,128);
	LPIT_DRV_Init(INST_LPIT1, &lpit1_InitConfig);
	LPIT_DRV_InitChannel(INST_LPIT1, 0, &lpit1_ChnConfig0);
    LPIT_DRV_InitChannel(INST_LPIT1, 1, &lpit1_ChnConfig1);//used for DAC
	LPIT_DRV_StartTimerChannels(INST_LPIT1, (1 << 0));

	PressSensorInit();
    //PINS_DRV_WritePin(PTE,9,1);
	printf("start----------\n");
	WDOG_DRV_Init(INST_WATCHDOG1, &watchdog1_Config0);
    TouchInit();

	for(;;)
	{
		//FLEXIO_UART_DRV_SendDataBlocking(&uartStateTX,testdata,128,1000000);
		//PlaySineWave();
        if(TimeBase1msFlag == 1)
		{
			TimeBase1msFlag = 0;

		}
        if(TimeBase5msFlag == 1)
        {
            TimeBase5msFlag = 0;
            TouchDetect();
            TouchProcess();
            WDOG_DRV_Trigger(INST_WATCHDOG1);
        }
		if(TimeBase100msFlag == 1)
		{
			TimeBase100msFlag = 0;
		}
		if(TimeBase1000msFlag == 1)
		{
			TimeBase1000msFlag = 0;
            //PINS_DRV_TogglePins(PTE,1<<9);
            //StartWave();
			//val = GetPressValue(1);
			//printf("press1=%d\n",val);
            //val = GetPressValue(2);
            //printf("press2=%d\n",val);
            //val = GetPressValue(3);
            //printf("press3=%d\n",val);
			//FLEXIO_UART_DRV_SendDataBlocking(&uartStateTX,testdata,2,1000);
		}
	}

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;) {
    if(exit_code != 0) {
      break;
    }
  }
  return exit_code;
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.1 [05.21]
**     for the NXP S32K series of microcontrollers.
**
** ###################################################################
*/
