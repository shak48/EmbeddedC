#include <stdint.h>
#include <string.h>

#include "stm32f407xx_gpio_driver.h"
#include "stm32f407xx_spi_driver.h"



#define HIGH 1
#define LOW 1
#define BUTTON_PRESSED LOW

int main(void){

	GPIO_Handle_t GpioLedGreen, GpioBtn;
	memset(&GpioLedGreen,0,sizeof(GpioLedGreen));
	memset(&GpioBtn,0,sizeof(GpioBtn));

	GpioBtn.pGPIOx = GPIOA;
	GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPOIO_PIN_NO_0;
	GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
	GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PD;

	GpioLedGreen.pGPIOx = GPIOD;
	GpioLedGreen.GPIO_PinConfig.GPIO_PinNumber = GPOIO_PIN_NO_12;
	GpioLedGreen.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLedGreen.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GpioLedGreen.GPIO_PinConfig.GPIO_PinOptType = GPIO_OP_MODE_PP;
	GpioLedGreen.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;


	GPIO_PCLK_Control(GPIOA, ENABLE);
	GPIO_PCLK_Control(GPIOD, ENABLE);
	GPIO_Init(&GpioBtn);
	GPIO_Init(&GpioLedGreen);

//IRQ enable
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI0, NVIC_IRQ_PRIO15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI0, ENABLE);

	for(;;);
}

void EXTI0_IRQHandler(void)
{
	for(uint32_t i=0;i<=900000;i++){;}
	GPIO_IRQHandling(GPOIO_PIN_NO_0);
	GPIO_ToggleOutputPin(GPIOD, GPOIO_PIN_NO_12);
}


