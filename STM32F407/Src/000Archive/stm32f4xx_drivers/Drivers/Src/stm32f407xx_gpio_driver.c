
//GPIO peripheral clock setup


#include "stm32f407xx_gpio_driver.h"


void GPIO_PCLK_Control(GPIO_RegDef_t *pGPIOx, uint8_t En_Or_Di)
{
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
	//enable peri clk
	GPIO_PCLK_Control(pGPIOHandle->pGPIOx, ENABLE);
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

	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN){
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

void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint16_t IRQPriority){

	uint8_t iprx = IRQNumber/4;
	uint8_t iprx_section = IRQNumber%4;

	uint8_t shift_amount = (8*iprx_section) + (8- NO_PR_BITS_IMPLEMENTED);

	*(NVIC_PR_BASE_ADDR + iprx) |= (IRQPriority << shift_amount);
}


void GPIO_IRQHandling(uint8_t PinNumber)
{
	if(EXTI->PR & (1<< PinNumber))
	{
		EXTI->PR |= (1<<PinNumber);
	}
}
