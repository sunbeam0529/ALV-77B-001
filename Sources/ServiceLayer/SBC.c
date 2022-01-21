

#include "SBC.h"
#include "PinDef.h"
#include "TJA1128Drv.h"

static uint8_t SBC_PORT_MODE_test(void);
static void SBC_Config(void);

uint8_t PortMode_data=0,config_this_time=0;

void SBC_Config(void)
{
    uint8_t SPIReadBuf;

	SPIReadBuf = SPI_WriteByte(0x11,0x10);
	SPIReadBuf = SPI_WriteByte(0x30,0xED);
	SPIReadBuf = SPI_WriteByte(0x11,0x10);
	SPIReadBuf = SPI_WriteByte(0x30,0x54);
	//SPIReadBuf = SPI_ReadByte(0x30);
}

void SBC_Init(void)
{
    
    SPI_GPIO_Init();

    if(SBC_PORT_MODE_test() == 0)
    {
        SBC_Config();
        config_this_time = 1;
    }
    LIN_PORT_Init();
    LIN_EN(1);
    LIN_STBN(0);
    PINS_DRV_SetPinIntSel(PORTC, 6UL, PORT_INT_EITHER_EDGE);
    INT_SYS_EnableIRQ(PORT_IRQn);
    l_sys_init();
    l_ifc_init(LI0);
    ld_init(LI0);
}

uint8_t SBC_PORT_MODE_test(void)
{
    int i,data=0,bitbuf;
    //GO TO PORT MODE
    LIN_EN(1);
    LIN_STBN(1);
    //start signal
    SDI_write1bit(1);
    SPI_Delay(600);//about 150uS
    
    if(SDO_read1bit() == 0)
    {
        return 0;//config mode
    }

    //Port Mode
    SDI_write1bit(0);
    SPI_Delay(200);//about 50uS

    for(i=0;i<8;i++)
    {
        SDI_write1bit(!(i%2));
        SPI_Delay(80);//about 20uS
        bitbuf = SDO_read1bit();
        data <<= 1;
        data |= bitbuf&0x01;
        SPI_Delay(80);//about 20uS
    }
    PortMode_data = data;
    SDI_write1bit(1);
    SPI_Delay(200);
    //
    return 1;
}



void LIN_EN(uint8_t en)
{
	SCK_write1bit(en);
}

void LIN_STBN(uint8_t stbn)
{
	SCSN_write1bit(stbn);
}
