/*
 * stm32f407xx_spi_driver.h
 *
 *  Created on: Dec 19, 2021
 *      Author: shak48
 */

#include <stm32f407xx.h>

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


//bit pos definituon for spi cr1

#define SPI_CR1_CPHA		0
#define SPI_CR1_CPOL		1
#define SPI_CR1_MSTR		2
#define SPI_CR1_BR			3
#define SPI_CR1_SPE			6
#define SPI_CR1_LSB			7
#define SPI_CR1_SSI			8
#define SPI_CR1_SSM			9
#define SPI_CR1_RXONLY		10
#define SPI_CR1_DFF			11
#define SPI_CR1_CRCNEXT		12
#define SPI_CR1_CRCEN		13
#define SPI_CR1_BIDIOE		14
#define SPI_CR1_BIDIMODE	15


//bit definition mcro for cr2

#define SPI_CR2_RXMAEN		0
#define SPI_CR2_TXMAEN		1
#define SPI_CR2_SSOE		2
#define SPI_CR2_FRF			4
#define SPI_CR2_ERRIE		5
#define SPI_CR2_RXEIE		6
#define SPI_CR2_TXEIE		7

//spi sr
#define SPI_SR_RXNE			0
#define SPI_SR_TXE			1
#define SPI_SR_CHSIDE		2
#define SPI_SR_UDR			3
#define SPI_SR_CRCERR		4
#define SPI_SR_MODEF		5
#define SPI_SR_OVR			6
#define SPI_SR_BSY			7
#define SPI_SR_FRE			8


#define SPI_RXE_FLAG		(1 << SPI_SR_RXNE)
#define SPI_TXE_FLAG		(1 << SPI_SR_TXE)
#define SPI_CHSIDE_FLAG		(1 << SPI_SR_CHSIDE)
#define SPI_UDR_FLAG		(1 << SPI_SR_UDR)
#define SPI_CRCERR_FLAG		(1 << SPI_SR_CRCERR)
#define SPI_MODEF_FLAG		(1 << SPI_SR_MODEF)
#define SPI_OVR_FLAG		(1 << SPI_SR_OVR)
#define SPI_BSY_FLAG		(1 << SPI_SR_BSY)
#define SPI_FRE_FLAG		(1 << SPI_SR_FRE)


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


//other perri control

void SPI_Peri_Control(SPI_RegDef_t *pSPIx, uint8_t En_Or_Di);

void SPI_SSM_Control(SPI_RegDef_t *pSPIx, uint8_t En_Or_Di);


#endif /* INC_STM32F407XX_SPI_DRIVER_H_ */
