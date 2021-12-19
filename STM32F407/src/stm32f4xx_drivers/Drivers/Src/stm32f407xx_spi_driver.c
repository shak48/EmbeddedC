/*
 * stm32f407xx_spi_driver.c
 *
 *  Created on: Dec 18, 2021
 *      Author: shak48
 */

#include "stm32f407xx_spi_driver.h"


// init deinit
void SPI_PCLK_Control(SPI_RegDef_t *pSPIx, uint8_t En_Or_Di)
{
	if(En_Or_Di == ENABLE)
	{
		if(pSPIx	==	SPI1)
		{
			SPI1_PCLK_EN();
		}
		else if(pSPIx	==	SPI2)
		{
			SPI2_PCLK_EN();
		}
		else if(pSPIx	==	SPI3)
		{
			SPI3_PCLK_EN();
		}
		else if(pSPIx	==	SPI4)
		{
			SPI4_PCLK_EN();
		}
		else if(pSPIx	==	SPI5)
		{
			SPI5_PCLK_EN();
		}
		else if(pSPIx	==	SPI6)
		{
			SPI6_PCLK_EN();
		}
	}
	if(En_Or_Di == DISABLE)
	{
		if(pSPIx	==	SPI1)
		{
			SPI1_PCLK_DI();
		}
		else if(pSPIx	==	SPI2)
		{
			SPI2_PCLK_DI();
		}
		else if(pSPIx	==	SPI3)
		{
			SPI3_PCLK_DI();
		}
		else if(pSPIx	==	SPI4)
		{
			SPI4_PCLK_DI();
		}
		else if(pSPIx	==	SPI5)
		{
			SPI5_PCLK_DI();
		}
		else if(pSPIx	==	SPI6)
		{
			SPI6_PCLK_DI();
		}
	}
}
void SPI_Init(SPI_Handle_t *pSPIHandle)
{
	uint32_t temp =0;
	//device mode
	temp |= pSPIHandle->SPI_Config.SPI_DviceMode << SPI_CR1_MSTR;
	//bus config
	if(pSPIHandle->SPI_Config.SPI_BusConfig == SPI_BUS_CONFIG_FD)
	{
		temp &= ~(1<<15);
	}else if(pSPIHandle->SPI_Config.SPI_BusConfig == SPI_BUS_CONFIG_HD)
	{
		temp |= (1<<15);
	}else if(pSPIHandle->SPI_Config.SPI_BusConfig == SPI_BUS_CONFIG_SIPLEX_RX_ONLY)
	{
		temp &= ~(1<<15);
		temp |= (1<<10);
	}

	temp |= pSPIHandle->SPI_Config.SPI_SclkSpeed <<3;

	temp |= pSPIHandle->SPI_Config.SPI_DFF <<SPI_CR1_DFF;

	temp |= pSPIHandle->SPI_Config.SPI_CPOL <<SPI_CR1_CPOL;

	temp |= pSPIHandle->SPI_Config.SPI_CPHA <<SPI_CR1_CPHA;

	pSPIHandle->pSPIx->CR1 |= temp;



}
void 		SPI_DeInit(SPI_RegDef_t *pSPIx);


//data RX TX

void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len)
{

}



void SPI_ReceiveData(SPI_RegDef_t *pSPIx,uint8_t *pRxBuffer, uint32_t Len);

//IRQ config

void 		SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t En_Or_Di);
void 		SPI_IRQPriorityConfig(uint8_t IRQNumber, uint16_t IRQPriority);
void 		SPI_IRQHandling(SPI_Handle_t *pSPIHandle);
