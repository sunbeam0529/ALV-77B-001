/*
 * @file     2pad_hw.h
*
* @version  1.0.0.0
*
* @date     January-2019
*
* @brief    Hardware configuration file for 2pad EVB demo
*
 */

#ifndef CFG_2PAD_EVB_2PAD_HW_H_
#define CFG_2PAD_EVB_2PAD_HW_H_

/*******************************************************************************
* Includes
*******************************************************************************/
#include "S32K116.h"
#include "ts_cfg_general.h"

#if (REFERENCE_DESIGN_BOARD == S32K118_2PAD_EVB)
/*******************************************************************************
* Modify: Define number of touch button electrodes
******************************************************************************/
// Number of touch button electrodes from 0 to 2
#define NUMBER_OF_BUTTON_ELECTRODES  8

/*******************************************************************************
* Do not Modify: Enable or disable slider electrodes
******************************************************************************/
// YES or NO  for optional Slider electrodes
#define SLIDER_ENABLE 	NO
/*******************************************************************************
* Do not Modify! Default settings of: number of slider electrodes
* This reference design SW is written for one slider only, consisting of 2 wedge electrodes!
******************************************************************************/
// Slider disabled - zero number of sliders
#define NUMBER_OF_SLIDERS 0
// Slider disabled - zero number of slider electrodes per slider
#define NUMBER_OF_ELECTRODES_PER_SLIDER 0
// Slider disabled - zero number of slider electrodes
#define NUMBER_OF_SLIDER_ELECTRODES  0

/*******************************************************************************
* Do not modify: Wake up (proximity) electrodes
******************************************************************************/
// Define number of wake up electrodes
#define NUMBER_OF_WAKEUP_ELECTRODES   0

/*******************************************************************************
* Do not modify ! Total count of electrodes
******************************************************************************/
#define NUMBER_OF_TOUCH_ELECTRODES   (NUMBER_OF_BUTTON_ELECTRODES + NUMBER_OF_SLIDER_ELECTRODES)
#define NUMBER_OF_ELECTRODES   (NUMBER_OF_BUTTON_ELECTRODES + NUMBER_OF_SLIDER_ELECTRODES + NUMBER_OF_WAKEUP_ELECTRODES)

/*******************************************************************************
* Modify: Guarding option
*  (OFF) no guarding
*  (ON) guarding driven by user configurable pin
******************************************************************************/
#define GUARD OFF

/*******************************************************************************
* BUTTON ELECTRODES PIN CFG
******************************************************************************/
/*******************************************************************************
* Modify: Electrode 0 defines, ON EVB POPULATE:R744, R740
******************************************************************************/
#if (NUMBER_OF_BUTTON_ELECTRODES > 0)
	#define ELEC0
	#define ELEC0_ADC             ADC0      // Modify: ADC module
	#define ELEC0_ADC_CHANNEL     10         // Modify: Cext ADC channel
	#define ELEC0_PORT            PORTC     // Modify: Electrode and Cext PORT
	#define ELEC0_GPIO            PTC       // Modify: Electrode and Cext GPIO
	#define ELEC0_ELEC_GPIO_PIN   3        // Modify: Electrode GPIO pin
	#define ELEC0_CEXT_GPIO_PIN   2		   	// Modify: Cext GPIO pin
	#define ELEC0_PORT_MASK       (1 << ELEC0_ELEC_GPIO_PIN) | (1 << ELEC0_CEXT_GPIO_PIN)
	#define ELEC0_TRGMUX		  30		// Modify: 30 for ADC0, 32 for ADC1
	#define ELEC0_DMAMUX		  42		// Modify: 42 for ADC0, 43 for ADC1
	#define ELEC0_TYPE		  	  BUTTON			// Modify: type of electrode
#endif

/*******************************************************************************
* Modify: Electrode 1 defines, the electrode on EVB does not work,
* need to connect the electrode to elec pins below and  ON EVB POPULATE:R683
******************************************************************************/
#if (NUMBER_OF_BUTTON_ELECTRODES > 1)
	#define ELEC1
	#define ELEC1_ADC             ADC0
	#define ELEC1_ADC_CHANNEL     14
	#define ELEC1_PORT            PORTC
	#define ELEC1_GPIO            PTC
	#define ELEC1_ELEC_GPIO_PIN   1
	#define ELEC1_CEXT_GPIO_PIN   16
	#define ELEC1_PORT_MASK       (1 << ELEC1_ELEC_GPIO_PIN) | (1 << ELEC1_CEXT_GPIO_PIN)
	#define ELEC1_TRGMUX		  30
	#define ELEC1_DMAMUX		  42
	#define ELEC1_TYPE		  	  BUTTON
#endif

#if (NUMBER_OF_BUTTON_ELECTRODES > 2)
	#define ELEC2
	#define ELEC2_ADC             ADC0
	#define ELEC2_ADC_CHANNEL     6
	#define ELEC2_PORT            PORTB
	#define ELEC2_GPIO            PTB
	#define ELEC2_ELEC_GPIO_PIN   3
	#define ELEC2_CEXT_GPIO_PIN   2
	#define ELEC2_PORT_MASK       (1 << ELEC2_ELEC_GPIO_PIN) | (1 << ELEC2_CEXT_GPIO_PIN)
	#define ELEC2_TRGMUX		  30
	#define ELEC2_DMAMUX		  42
	#define ELEC2_TYPE		  	  BUTTON
#endif

#if (NUMBER_OF_BUTTON_ELECTRODES > 3)
	#define ELEC3
	#define ELEC3_ADC             ADC0
	#define ELEC3_ADC_CHANNEL     4
	#define ELEC3_PORT            PORTB
	#define ELEC3_GPIO            PTB
	#define ELEC3_ELEC_GPIO_PIN   1
	#define ELEC3_CEXT_GPIO_PIN   0
	#define ELEC3_PORT_MASK       (1 << ELEC3_ELEC_GPIO_PIN) | (1 << ELEC3_CEXT_GPIO_PIN)
	#define ELEC3_TRGMUX		  30
	#define ELEC3_DMAMUX		  42
	#define ELEC3_TYPE		  	  BUTTON
#endif

#if (NUMBER_OF_BUTTON_ELECTRODES > 4)
	#define ELEC4
	#define ELEC4_ADC             ADC0
	#define ELEC4_ADC_CHANNEL     13
	#define ELEC4_PORT            PORTC
	#define ELEC4_GPIO            PTC
	#define ELEC4_ELEC_GPIO_PIN   9
	#define ELEC4_CEXT_GPIO_PIN   15
	#define ELEC4_PORT_MASK       (1 << ELEC4_ELEC_GPIO_PIN) | (1 << ELEC4_CEXT_GPIO_PIN)
	#define ELEC4_TRGMUX		  30
	#define ELEC4_DMAMUX		  42
	#define ELEC4_TYPE		  	  BUTTON
#endif

#if (NUMBER_OF_BUTTON_ELECTRODES > 5)
	#define ELEC5
	#define ELEC5_ADC             ADC0
	#define ELEC5_ADC_CHANNEL     12
	#define ELEC5_PORT            PORTC
	#define ELEC5_GPIO            PTC
	#define ELEC5_ELEC_GPIO_PIN   8
	#define ELEC5_CEXT_GPIO_PIN   14
	#define ELEC5_PORT_MASK       (1 << ELEC5_ELEC_GPIO_PIN) | (1 << ELEC5_CEXT_GPIO_PIN)
	#define ELEC5_TRGMUX		  30
	#define ELEC5_DMAMUX		  42
	#define ELEC5_TYPE		  	  BUTTON
#endif

#if (NUMBER_OF_BUTTON_ELECTRODES > 6)
	#define ELEC6
	#define ELEC6_ADC             ADC0
	#define ELEC6_ADC_CHANNEL     1
	#define ELEC6_PORT            PORTA
	#define ELEC6_GPIO            PTA
	#define ELEC6_ELEC_GPIO_PIN   13
	#define ELEC6_CEXT_GPIO_PIN   1
	#define ELEC6_PORT_MASK       (1 << ELEC6_ELEC_GPIO_PIN) | (1 << ELEC6_CEXT_GPIO_PIN)
	#define ELEC6_TRGMUX		  30
	#define ELEC6_DMAMUX		  42
	#define ELEC6_TYPE		  	  BUTTON
#endif

#if (NUMBER_OF_BUTTON_ELECTRODES > 7)
	#define ELEC7
	#define ELEC7_ADC             ADC0
	#define ELEC7_ADC_CHANNEL     0
	#define ELEC7_PORT            PORTA
	#define ELEC7_GPIO            PTA
	#define ELEC7_ELEC_GPIO_PIN   12
	#define ELEC7_CEXT_GPIO_PIN   0
	#define ELEC7_PORT_MASK       (1 << ELEC7_ELEC_GPIO_PIN) | (1 << ELEC7_CEXT_GPIO_PIN)
	#define ELEC7_TRGMUX		  30
	#define ELEC7_DMAMUX		  42
	#define ELEC7_TYPE		  	  BUTTON
#endif


/*******************************************************************************
* GUARD ELECTRODE PIN CFG
******************************************************************************/
/*******************************************************************************
* Modify: Guard 0 defines
******************************************************************************/
#if (GUARD)
	#define GUARD_PORT           PORTE     // Modify: Guard PORT
	#define GUARD_GPIO           PTE       // Modify: Guard GPIO
	#define GUARD_GPIO_PIN       4         // Modify: Guard GPIO pin
	#define GUARD_PORT_MASK      (1 << GUARD_GPIO_PIN) // Modify: Guard PORT mask
#endif

#endif

#endif /* CFG_2PAD_EVB_2PAD_HW_H_ */
