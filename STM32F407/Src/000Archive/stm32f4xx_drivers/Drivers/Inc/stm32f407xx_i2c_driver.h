/*
 * stm32f407xx_spi_driver.h
 *
 *  Created on: Dec 19, 2021
 *      Author: shak48
 */


#ifndef INC_STM32F407XX_I2C_DRIVER_H_
#define INC_STM32F407XX_I2C_DRIVER_H_

#include "stm32f407xx.h"


typedef struct
{
	uint32_t 	I2C_SCLSpeed;
	uint8_t 	I2C_DeviceAddress;
	uint8_t 	I2C_AckControl;
	uint8_t 	I2C_FMDutyCycle;
}I2C_Config_t;

typedef struct
{
	I2C_RegDef_t 	*pI2Cx;
	I2C_Config_t 	I2C_Config;
	//uint8_t			*pTxBuffer;
	//uint8_t			*pRxBuffer;
	//uint32_t		TxLen;
	//uint32_t		RxLen;
	//uint32_t		TxState;
	//uint32_t		RxState;
}I2C_Handle_t;


#define I2C_SCL_SPEED_SM 100000U
#define I2C_SCL_SPEED_FM 400000U


#define I2C_ACK_ENABLE 		1
#define I2C_ACK_DISABLE		0


#define I2C_FM_DUTY_2 		0
#define I2C_FM_DUTY_16_9	1

//bit pos definituon for spi cr1

#define I2C_CR1_PE			0
#define I2C_CR1_SMBUS		1
#define I2C_CR1_SMBTYPE		3
#define I2C_CR1_ENARP		4
#define I2C_CR1_ENPEC		5
#define I2C_CR1_ENGC		6
#define I2C_CR1_NOSTRETCH	7
#define I2C_CR1_START		8
#define I2C_CR1_STOP		9
#define I2C_CR1_ACK			10
#define I2C_CR1_POS			11
#define I2C_CR1_PEC			12
#define I2C_CR1_ALERT		13
#define I2C_CR1_SWRST		15


//bit definition mcro for cr2

#define I2C_CR2_FREQ[5]		0
#define I2C_CR2_ITERREN		8
#define I2C_CR2_ITEVTEN		9
#define I2C_CR2_ITBUFEN		10
#define I2C_CR2_LAST		12


//spi sr
#define I2C_SR1_SB			0
#define I2C_SR1_ADDR		1
#define I2C_SR1_BTF			2
#define I2C_SR1_ADD10		3
#define I2C_SR1_STOPF		4
#define I2C_SR1_RXNE		6
#define I2C_SR1_TXNE		7
#define I2C_SR1_BERR		8
#define I2C_SR1_ARLO		9
#define I2C_SR1_AF			10
#define I2C_SR1_OVR			11
#define I2C_SR1_PECERR		12
#define I2C_SR1_TIMEOUT		13
#define I2C_SR1_SMBALERT	14


#define I2C_SR2_MSL			0
#define I2C_SR2_BUSY		1
#define I2C_SR2_TRA			2
#define I2C_SR2_GENCALL		4
#define I2C_SR2_SMBDEFAULT	5
#define I2C_SR2_SMBHOST		6
#define I2C_SR2_DUALF		7
#define I2C_SR2_PEC			8
#define I2C_SR2_ARLO		9
#define I2C_SR2_AF			10
#define I2C_SR2_OVR			11
#define I2C_SR2_PECERR		12
#define I2C_SR2_TIMEOUT		13
#define I2C_SR2_SMBALERT	14


#define I2C_RXE_FLAG		(1 << I2C_SR_RXNE)
#define I2C_TXE_FLAG		(1 << I2C_SR_TXE)
#define I2C_CHSIDE_FLAG		(1 << I2C_SR_CHSIDE)
#define I2C_UDR_FLAG		(1 << I2C_SR_UDR)
#define I2C_CRCERR_FLAG		(1 << I2C_SR_CRCERR)
#define I2C_MODEF_FLAG		(1 << I2C_SR_MODEF)
#define I2C_OVR_FLAG		(1 << I2C_SR_OVR)
#define I2C_BSY_FLAG		(1 << I2C_SR_BSY)
#define I2C_FRE_FLAG		(1 << I2C_SR_FRE)


//I2C States

#define I2C_READY			0
#define I2C_BUSY_IN_RX		1
#define I2C_BUSY_IN_TX		2

//posible spi events

#define I2C_EVENT_TX_CMPLT	1
#define I2C_EVENT_RX_CMPLT	2
#define I2C_EVENT_OVR_ERR	3
#define I2C_EVENT_CRC_ERR	4

// API prototypes



// init deinit
void 		I2C_PCLK_Control(I2C_RegDef_t *pI2Cx, uint8_t En_Or_Di);
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

void I2C_Application_Event_CallBack(I2C_Handle_t *SPIHandle, uint8_t Event);




#endif /* INC_STM32F407XX_SPI_DRIVER_H_ */
