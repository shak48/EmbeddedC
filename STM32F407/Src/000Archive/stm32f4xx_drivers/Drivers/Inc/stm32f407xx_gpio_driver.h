/*
 * stm32f407xx_gpio_driver.h
 *
 *  Created on: Dec 19, 2021
 *      Author: shak48
 */


#ifndef INC_STM32F407XX_GPIO_DRIVER_H_
#define INC_STM32F407XX_GPIO_DRIVER_H_

#include "stm32f407xx.h"


typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOptType;
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;

/*Handle structure fir GPIO pin*/
typedef struct
{
	GPIO_RegDef_t *pGPIOx;
	GPIO_PinConfig_t GPIO_PinConfig;
}GPIO_Handle_t;



//GPIO pin no

#define GPOIO_PIN_NO_0 		0
#define GPOIO_PIN_NO_1		1
#define GPOIO_PIN_NO_2		2
#define GPOIO_PIN_NO_3		3
#define GPOIO_PIN_NO_4		4
#define GPOIO_PIN_NO_5		5
#define GPOIO_PIN_NO_6		6
#define GPOIO_PIN_NO_7		7
#define GPOIO_PIN_NO_8		8
#define GPOIO_PIN_NO_9		9
#define GPOIO_PIN_NO_10		10
#define GPOIO_PIN_NO_11		11
#define GPOIO_PIN_NO_12		12
#define GPOIO_PIN_NO_13		13
#define GPOIO_PIN_NO_14		14
#define GPOIO_PIN_NO_15		15



//GPIO modes
#define GPIO_MODE_IN 		0
#define GPIO_MODE_OUT 		1
#define GPIO_MODE_ALTFN		2
#define GPIO_MODE_ANALOG	3
#define GPIO_MODE_IT_FT		4
#define GPIO_MODE_IT_RT		5
#define GPIO_MODE_IT_RFT	6


//gpio OUTPUT TUYPE

//GPIO modes
#define GPIO_OP_MODE_PP 	0
#define GPIO_OP_MODE_OD 	1

//gpio OUTPUT Tspeed

#define GPIO_SPEED_LOW 		0
#define GPIO_SPEED_MEDIUM 	1
#define GPIO_SPEED_FAST		2
#define GPIO_SPEED_HIGH		3

// GGPIO push pull down config macros

#define GPIO_SPEED_LOW 		0
#define GPIO_SPEED_MEDIUM 	1
#define GPIO_SPEED_FAST		2
#define GPIO_SPEED_HIGH		3


//GPIO pull spush comfig

#define GPIO_NO_PUPD 		0
#define GPIO_PIN_PU			1
#define GPIO_PIN_PD			2

// API prototypes

void GPIO_PCLK_Control(GPIO_RegDef_t *pGPIOx, uint8_t);


void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

uint8_t 	GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t 	GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);

void 		GPIO_IRQInterruptConfig(uint8_t, uint8_t);
void 		GPIO_IRQPriorityConfig(uint8_t , uint16_t);
void 		GPIO_IRQHandling(uint8_t );


void GPIO_WriteOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t , uint8_t);
void GPIO_WriteOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t );

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t);

#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */

/*Configuration structure for GPIO pin*/

