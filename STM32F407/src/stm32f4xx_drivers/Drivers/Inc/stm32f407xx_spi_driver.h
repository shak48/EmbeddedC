/*
 * stm32f407xx_spi_driver.h
 *
 *  Created on: Dec 19, 2021
 *      Author: shak48
 */

#include "stm32f407xx.h"

#ifndef INC_STM32F407XX_SPI_DRIVER_H_
#define INC_STM32F407XX_SPI_DRIVER_H_

typedef struct
{
	uint8_t SPI_DviceMode;
	uint8_t SPI_BusConfig;
	uint8_t SPI_SclkSpeed;
	uint8_t SPI_DFF;
	uint8_t SPI_CPHA;
	uint8_t SPI_CPOL;
	uint8_t SPI_SSM;
}SPI_Config_t;

typedef struct
{
	SPI_RegDef_t *pSPIx;
	SPI_Config_t SPI_Config;
}SPI_Handle_t;


// API prototypes


// init deinit
void 		SPI_PCLK_Control(SPI_RegDef_t *pSPIx, uint8_t En_Or_Di);
void 		SPI_Init(SPI_Handle_t *pSPIHandle);
void 		SPI_DeInit(SPI_RegDef_t *pSPIx);


//data RX TX

void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len);
void SPI_ReceiveData(SPI_RegDef_t *pSPIx,uint8_t *pRxBuffer, uint32_t Len);

//IRQ config

void 		SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t En_Or_Di);
void 		SPI_IRQPriorityConfig(uint8_t IRQNumber, uint16_t IRQPriority);
void 		SPI_IRQHandling(SPI_Handle_t *pSPIHandle);


#endif /* INC_STM32F407XX_SPI_DRIVER_H_ */
