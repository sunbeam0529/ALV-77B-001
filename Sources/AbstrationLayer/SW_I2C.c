/*
 * SW_I2C.c
 *
 *  Created on: 2021Äê12ÔÂ4ÈÕ
 *      Author: dm01
 */

#include "SW_I2C.h"

#define I2C_SDA_OUTPUT_DIR PINS_DRV_SetPinDirection(DEF_IO_I2C_SDA_PORT,DEF_IO_I2C_SDA_PIN,GPIO_OUTPUT_DIRECTION)
#define I2C_SDA_INPUT_DIR  PINS_DRV_SetPinDirection(DEF_IO_I2C_SDA_PORT,DEF_IO_I2C_SDA_PIN,GPIO_INPUT_DIRECTION)
#define I2C_SDA_SET PINS_DRV_WritePin(DEF_IO_I2C_SDA_PORT,DEF_IO_I2C_SDA_PIN,1)
#define I2C_SCL_SET PINS_DRV_WritePin(DEF_IO_I2C_SCL_PORT,DEF_IO_I2C_SCL_PIN,1)
#define I2C_SDA_CLR PINS_DRV_WritePin(DEF_IO_I2C_SDA_PORT,DEF_IO_I2C_SDA_PIN,0)
#define I2C_SCL_CLR PINS_DRV_WritePin(DEF_IO_I2C_SCL_PORT,DEF_IO_I2C_SCL_PIN,0)
#define I2C_PIN_SDA (PINS_DRV_ReadPins(DEF_IO_I2C_SDA_PORT) & 1<<DEF_IO_I2C_SDA_PIN)

static i2c_delay(uint32_t cnt)
{
	//cnt <<= 4;
    while (cnt--)
    {
        NOP();
    }
    
}

static void i2c_start(void)
{
    I2C_SDA_OUTPUT_DIR;
    I2C_SDA_SET;
    i2c_delay(5);
    I2C_SCL_SET;
    i2c_delay(5);
    I2C_SDA_CLR;
    i2c_delay(5);
    I2C_SCL_CLR;
    i2c_delay(5);
}

static void i2c_stop(bool sendStop)
{
    if (sendStop == false)
    {
        return;
    }
    
    I2C_SDA_OUTPUT_DIR;
    I2C_SCL_CLR;
    i2c_delay(5);
    I2C_SDA_CLR;
    i2c_delay(5);
    I2C_SCL_SET;
    i2c_delay(5);
    I2C_SDA_SET;
    i2c_delay(5);
}

static uint8_t i2c_wait_ack(bool sendStop)
{
    I2C_SDA_SET;
    I2C_SDA_INPUT_DIR;
    i2c_delay(5);
    I2C_SCL_SET;
    i2c_delay(5);
    if(I2C_PIN_SDA)
    {
        i2c_stop(sendStop);
        return 0;
    }
    I2C_SCL_CLR;
    return 1; 
}

static void i2c_send_ack(void)
{
    I2C_SDA_OUTPUT_DIR;
    I2C_SDA_CLR;
    i2c_delay(5);
    I2C_SCL_SET;
    i2c_delay(5);
    I2C_SCL_CLR;    
}

static void i2c_send_noack(void)
{
    I2C_SDA_OUTPUT_DIR;
    I2C_SDA_SET;
    i2c_delay(5);
    I2C_SCL_SET;
    i2c_delay(5);
    I2C_SCL_CLR;    
}

static void i2c_send_data(uint8_t data)
{
    uint8_t i = 8;
    
    I2C_SDA_OUTPUT_DIR;
    I2C_SCL_CLR;
    i2c_delay(10);
    while(i--)
    {
        
        if(data & 0x80)
        {
            I2C_SDA_SET;
        }         
        else
        {
            I2C_SDA_CLR;
        }
        
        i2c_delay(5);
        data <<= 1;
        I2C_SCL_SET;
        i2c_delay(5);
        I2C_SCL_CLR;
        i2c_delay(5);
    }    
}

static uint8_t i2c_receive_data(void)
{
    uint8_t i = 8;
    uint8_t data = 0;
    
    I2C_SDA_SET;
    I2C_SDA_INPUT_DIR;
    while(i--)
    {
        data <<= 1;
        I2C_SCL_CLR;
        i2c_delay(5);
        I2C_SCL_SET;
        i2c_delay(5);
        if(I2C_PIN_SDA) 
            data |= 0x01;
    }
    I2C_SCL_CLR;
    
    return(data);    
}

uint8_t SWI2C_SendDataBlocking(uint8_t addr, const uint8_t * txBuff,uint32_t txSize, bool sendStop)
{
    addr <<= 1;
    i2c_start();
    i2c_send_data(addr);
    if(i2c_wait_ack(sendStop) == 0)
    {
        i2c_stop(sendStop);
        return 0;
    }
    for (uint8_t i = 0; i < txSize; i++)
    {
        i2c_send_data(txBuff[i]);
        if(i2c_wait_ack(sendStop) == 0)
        {
            i2c_stop(sendStop);
            return 0;
        }
    }

    i2c_stop(sendStop);

    return 1;
    
}

uint8_t SWI2C_ReceiveDataBlocking(uint8_t addr, uint8_t * rxBuff,uint32_t rxSize, bool sendStop)
{
    addr <<= 1;
    addr |= 0x01;

    i2c_start();
    i2c_send_data(addr);
    if(i2c_wait_ack(sendStop) == 0)
    {
        i2c_stop(sendStop);
        return 0;
    }
    for(uint8_t i = 0; i < rxSize; i++)
    {
        rxBuff[i] = i2c_receive_data();
        if(i < (rxSize - 1))
            i2c_send_ack();
    }
    i2c_send_noack();
    i2c_stop(sendStop);
    
    return 1;    
}








