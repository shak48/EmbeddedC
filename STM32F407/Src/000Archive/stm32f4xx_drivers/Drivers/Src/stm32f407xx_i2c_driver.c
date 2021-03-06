/*
 * stm32f407xx_spi_driver.c
 *
 *  Created on: Dec 18, 2021
 *      Author: shak48
 */

#include "stm32f407xx_i2c_driver.h"



// init deinit
void 	I2C_PCLK_Control(I2C_RegDef_t *pI2Cx, uint8_t En_Or_Di)
{
	if(En_Or_Di == ENABLE)
	{
		if(pI2Cx	==	I2C1)
		{
			I2C1_PCLK_EN();
		}
		else if(pI2Cx	==	I2C2)
		{
			I2C2_PCLK_EN();
		}
		else if(pI2Cx	==	I2C3)
		{
			I2C3_PCLK_EN();
		}
	}
	if(En_Or_Di == DISABLE)
	{
		if(pI2Cx	==	I2C1)
		{
			I2C1_PCLK_DI();
		}
		else if(pI2Cx	==	I2C2)
		{
			I2C2_PCLK_DI();
		}
		else if(pI2Cx	==	I2C3)
		{
			I2C3_PCLK_DI();
		}
}


void 		I2C_Init(I2C_Handle_t *pI2CHandle);
void 		I2C_DeInit(I2C_RegDef_t *pI2Cx);

uint8_t  I2C_GetFlagStatus(I2C_RegDef_t *pI2Cx, uint32_t flagName);

//data RX TX



//IRQ config

void 		I2C_IRQInterruptConfig(uint8_t IRQNumber, uint8_t En_Or_Di);
void 		I2C_IRQPriorityConfig(uint8_t IRQNumber, uint16_t IRQPriority);


//other perri control

void I2C_Peri_Control(I2C_RegDef_t *pI2Cx, uint8_t En_Or_Di);


static void spi_txne_interrupt_handle(I2C_Handle_t *pI2Cx);
static void spi_rxne_interrupt_handle(I2C_Handle_t *pI2Cx);
static void spi_ovr_interrupt_handle(I2C_Handle_t *pI2Cx);

void I2C_ClearOVRFlag(I2C_RegDef_t *pI2Cx);
void I2C_CloseTransmission(I2C_Handle_t *pI2Cx);
void I2C_CloseReception(I2C_Handle_t *pI2Cx);

void I2C_Application_Event_CallBack(I2C_Handle_t *I2CHandle, uint8_t Event);
