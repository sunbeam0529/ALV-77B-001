#ifndef __PINDEF_H__
#define __PINDEF_H__

//PRESS SENSOR PART    
#define DEF_IO_I2C_SCL_PORT         PTB
#define DEF_IO_I2C_SCL_PIN          5
#define DEF_IO_I2C_SDA_PORT         PTE
#define DEF_IO_I2C_SDA_PIN          8

//SBC PART
#define DEF_IO_SPI_SCK_PORT         PTD
#define DEF_IO_SPI_SCK_PORT_NAME    PORTD
#define DEF_IO_SPI_SCK_PIN          1

#define DEF_IO_SPI_SDI_PORT         PTC
#define DEF_IO_SPI_SDI_PORT_NAME    PORTC
#define DEF_IO_SPI_SDI_PIN          7

#define DEF_IO_SPI_SCSN_PORT        PTA
#define DEF_IO_SPI_SCSN_PORT_NAME   PORTA
#define DEF_IO_SPI_SCSN_PIN         10

#define DEF_IO_SPI_SDO_PORT         PTC
#define DEF_IO_SPI_SDO_PORT_NAME    PORTC
#define DEF_IO_SPI_SDO_PIN          6

#define DEF_IO_SBC_WWD_PORT         PTA
#define DEF_IO_SBC_WWD_PORT_NAME    PORTA
#define DEF_IO_SBC_WWD_PIN          11


#endif
