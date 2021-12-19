
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
#define GPIO_MODE_IT_RFT		6


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

//GPIO peripheral clock setup

void GPIO_PCLK_Control(GPIO_RegDef_t *pGPIOx, uint8_t En_Or_Di){

	if(En_Or_Di == ENABLE){
		if(pGPIOx==GPIOA)
		{
			GPIOA_PCLK_EN();
		}else if(pGPIOx==GPIOB)
		{
			GPIOB_PCLK_EN();
		}else if(pGPIOx==GPIOC)
		{
			GPIOC_PCLK_EN();
		}else if(pGPIOx==GPIOD)
		{
			GPIOD_PCLK_EN();
		}else if(pGPIOx==GPIOE)
		{
			GPIOE_PCLK_EN();
		}else if(pGPIOx==GPIOF)
		{
			GPIOF_PCLK_EN();
		}else if(pGPIOx==GPIOG)
		{
			GPIOG_PCLK_EN();
		}else if(pGPIOx==GPIOH)
		{
			GPIOH_PCLK_EN();
		}else if(pGPIOx==GPIOI)
		{
			GPIOI_PCLK_EN();
		}
	}
	else{
		if(pGPIOx==GPIOA)
		{
			GPIOA_PCLK_DI();
		}else if(pGPIOx==GPIOB)
		{
			GPIOB_PCLK_DI();
		}else if(pGPIOx==GPIOC)
		{
			GPIOC_PCLK_DI();
		}else if(pGPIOx==GPIOD)
		{
			GPIOD_PCLK_DI();
		}else if(pGPIOx==GPIOE)
		{
			GPIOE_PCLK_DI();
		}else if(pGPIOx==GPIOF)
		{
			GPIOF_PCLK_DI();
		}else if(pGPIOx==GPIOG)
		{
			GPIOG_PCLK_DI();
		}else if(pGPIOx==GPIOH)
		{
			GPIOH_PCLK_DI();
		}else if(pGPIOx==GPIOI)
		{
			GPIOI_PCLK_DI();
		}
	}
}


//GPOI Init DeInit

void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp=0;
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG){
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER &= ~(0x3 << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER |= temp;
		temp = 0;
	}
	else
	{
		if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_FT)
		{
			EXTI->FTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			EXTI->RTSR &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}
		else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RT)
		{
			EXTI->RTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			EXTI->FTSR &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}
		else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RFT)
		{
			EXTI->FTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			EXTI->RTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}
		EXTI->IMR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		SYSCFG_PCLK_EN();

	}
	temp = 0;
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;

	temp = 0;
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR |= temp;

	temp = 0;
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOptType << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER |= temp;

	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode == GPIO_MODE_ALTFN){
		uint8_t temp1, temp2;
		temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
		temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;
		pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << (4*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4*temp2));
	}



}
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx){
	if(pGPIOx==GPIOA)
	{
		GPIOA_REG_RESET();
	}else if(pGPIOx==GPIOB)
	{
		GPIOB_REG_RESET();
	}else if(pGPIOx==GPIOC)
	{
		GPIOC_REG_RESET();
	}else if(pGPIOx==GPIOD)
	{
		GPIOD_REG_RESET();
	}else if(pGPIOx==GPIOE)
	{
		GPIOE_REG_RESET();
	}else if(pGPIOx==GPIOF)
	{
		GPIOF_REG_RESET();
	}else if(pGPIOx==GPIOG)
	{
		GPIOG_REG_RESET();
	}else if(pGPIOx==GPIOH)
	{
		GPIOH_REG_RESET();
	}else if(pGPIOx==GPIOI)
	{
		GPIOI_REG_RESET();
	}
}

// GPIO read and write
uint8_t 	GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){

	uint8_t value;

	value = (uint8_t) ((pGPIOx->IDR>> PinNumber) & 0x00000001);

	return value;
}
uint16_t 	GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx){

	uint16_t value;

	value = (uint16_t) pGPIOx->IDR;

	return value;
}
void GPIO_WriteOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value){

	if(Value == GPIO_PIN_SET)
	{
		pGPIOx->ODR |= (1 << PinNumber);
	}else
	{
		pGPIOx->ODR &= ~(1 << PinNumber);

	}
}
void GPIO_WriteOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value){

	pGPIOx->ODR |= Value;
}
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{

	pGPIOx->ODR ^= (1 << PinNumber);
}

//GPIO IRQ handling

void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t En_Or_Di)
{
	if(En_Or_Di == ENABLE)
	{
		if(IRQNumber<=31)
		{
			*NVIC_ISER0 |= (1<< IRQNumber);
			*NVIC_ISER0 |= (1<< 0);
		}else if(IRQNumber >31 && IRQNumber <64)
		{
			*NVIC_ISER1 |= (1<< (IRQNumber%32));
		}else if(IRQNumber >=64 && IRQNumber <96)
		{
			*NVIC_ISER2 |= (1<< IRQNumber%64);
		}
	}else
	{
		if(IRQNumber<=31)
		{
			*NVIC_ICER0 |= (1<< IRQNumber);

		}else if(IRQNumber >31 && IRQNumber <64)
		{
			*NVIC_ISER1 |= (1<< (IRQNumber%32));
		}else if(IRQNumber >=64 && IRQNumber <96)
		{
			*NVIC_ISER2 |= (1<< IRQNumber%64);
		}
	}
}

void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority){

	uint8_t iprx = IRQNumber/4;
	uint8_t iprx_section = IRQNumber%4;

	uint8_t shift_amount = (8*iprx_section) + (8- NO_PR_BITS_IMPLEMENTED);

	*(NVIC_PR_BASE_ADDR + (iprx*4)) |= (IRQPriority << shift_amount);
}


void GPIO_IRQHandling(uint8_t PinNumber)
{
	if(EXTI->PR & (1<< PinNumber))
	{
		EXTI->PR |= (1<<PinNumber);
	}
}



#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */

/*Configuration structure for GPIO pin*/

