#include "TJA1128Drv.h"
#include "PinDef.h"

//local function
static void WWD_write1bit(uint8_t bits);

void LIN_PORT_Init(void)
{
    //PIN Tx & rx set as LPUART mode
    PINS_DRV_SetMuxModeSel(DEF_IO_SPI_SDI_PORT_NAME,DEF_IO_SPI_SDI_PIN,PORT_MUX_ALT2);
    PINS_DRV_SetMuxModeSel(DEF_IO_SPI_SDO_PORT_NAME,DEF_IO_SPI_SDO_PIN,PORT_MUX_ALT2);

}

void SDI_write1bit(uint8_t bits)
{
	if(bits == 0)
	{
        PINS_DRV_ClearPins(DEF_IO_SPI_SDI_PORT,1<<DEF_IO_SPI_SDI_PIN);
	}
	else
	{
		PINS_DRV_SetPins(DEF_IO_SPI_SDI_PORT,1<<DEF_IO_SPI_SDI_PIN);
	}
}

void SCK_write1bit(uint8_t bits)
{
	if(bits == 0)
	{
		PINS_DRV_ClearPins(DEF_IO_SPI_SCK_PORT,1<<DEF_IO_SPI_SCK_PIN);
	}
	else
	{
		PINS_DRV_SetPins(DEF_IO_SPI_SCK_PORT,1<<DEF_IO_SPI_SCK_PIN);
	}
}

void SCSN_write1bit(uint8_t bits)
{
	if(bits == 0)
	{
		PINS_DRV_ClearPins(DEF_IO_SPI_SCSN_PORT,1<<DEF_IO_SPI_SCSN_PIN);
	}
	else
	{
		PINS_DRV_SetPins(DEF_IO_SPI_SCSN_PORT,1<<DEF_IO_SPI_SCSN_PIN);
	}
}

void WWD_write1bit(uint8_t bits)
{
	if(bits == 0)
	{
		PINS_DRV_ClearPins(DEF_IO_SBC_WWD_PORT,1<<DEF_IO_SBC_WWD_PIN);
	}
	else
	{
		PINS_DRV_SetPins(DEF_IO_SBC_WWD_PORT,1<<DEF_IO_SBC_WWD_PIN);
	}
}


uint8_t SDO_read1bit(void)
{
    uint8_t retVal;
    retVal = PINS_DRV_ReadPins(DEF_IO_SPI_SDO_PORT);
    if((1<<DEF_IO_SPI_SDO_PIN) & retVal)
    {
        //true
        return 1;
    }
    else
    {
        //false
        return 0;
    }

}



void SPI_GPIO_Init(void)
{
    //PIN SDI,SDO,SCK,SCSN set as GPIO mode
    PINS_DRV_SetMuxModeSel(DEF_IO_SPI_SCK_PORT_NAME,DEF_IO_SPI_SCK_PIN,PORT_MUX_AS_GPIO);
    PINS_DRV_SetMuxModeSel(DEF_IO_SPI_SDI_PORT_NAME,DEF_IO_SPI_SDI_PIN,PORT_MUX_AS_GPIO);
    PINS_DRV_SetMuxModeSel(DEF_IO_SPI_SCSN_PORT_NAME,DEF_IO_SPI_SCSN_PIN,PORT_MUX_AS_GPIO);
    PINS_DRV_SetMuxModeSel(DEF_IO_SPI_SDO_PORT_NAME,DEF_IO_SPI_SDO_PIN,PORT_MUX_AS_GPIO);

    //set pins direction
    PINS_DRV_SetPinDirection(DEF_IO_SPI_SCK_PORT,DEF_IO_SPI_SCK_PIN,GPIO_OUTPUT_DIRECTION);
    PINS_DRV_SetPinDirection(DEF_IO_SPI_SDI_PORT,DEF_IO_SPI_SDI_PIN,GPIO_OUTPUT_DIRECTION);
    PINS_DRV_SetPinDirection(DEF_IO_SPI_SCSN_PORT,DEF_IO_SPI_SCSN_PIN,GPIO_OUTPUT_DIRECTION);
    PINS_DRV_SetPinDirection(DEF_IO_SPI_SDO_PORT,DEF_IO_SPI_SDO_PIN,GPIO_INPUT_DIRECTION);

    //SDI
	// PTC7 GPIO pin
	PORTC->PCR[7] = PORT_PCR_MUX(1);
	// Turn OFF
	PTC->PCOR = 1 << 7;
	// PTC7 configured as output
	PTC->PDDR |= 1 << 7;
}

void SPI_Delay(uint32_t time)//about 0.25uS
{
	volatile uint8_t delay_cycle;
	while(time--);
	{
		delay_cycle = 20;
		while(delay_cycle--);
	}
}

uint8_t SPI_ReadByte(uint8_t addr)
{
	uint8_t buf=0;
	SCSN_write1bit(0);
	addr <<= 1;
	addr |= 0x01;// read only
	for(uint8_t i=0;i<8;i++)
	{
		SCK_write1bit(1);
		SDI_write1bit(addr & (0x80>>i));
		SPI_Delay(100);
		SCK_write1bit(0);
		SPI_Delay(100);
	}
	for(uint8_t i=0;i<8;i++)
	{
		SCK_write1bit(1);
		SPI_Delay(100);
		buf <<= 1;
		buf |= SDO_read1bit();
		SCK_write1bit(0);
		SPI_Delay(100);
	}

	SCSN_write1bit(1);

	return buf;
}

uint8_t SPI_WriteByte(uint8_t addr,uint8_t data)
{
	uint8_t buf=0;
	SCSN_write1bit(0);
	addr <<= 1;
	addr |= 0x00;// read & write
	for(uint8_t i=0;i<8;i++)
	{
		SCK_write1bit(1);
		SDI_write1bit(addr & (0x80>>i));
		SPI_Delay(100);
		SCK_write1bit(0);
		SPI_Delay(100);
	}
	for(uint8_t i=0;i<8;i++)
	{
		SCK_write1bit(1);
		SDI_write1bit(data & (0x80>>i));
		SPI_Delay(100);
		buf <<= 1;
		buf |= SDO_read1bit();
		SCK_write1bit(0);
		SPI_Delay(100);
	}

	SCSN_write1bit(1);

	return buf;
}













