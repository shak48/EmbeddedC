#include <stdint.h>
#include "stm32f407xx.h"
#include "stm32f407xx_gpio_driver.h"


#define BUTTON_PRESSED 1
void delay(uint32_t);

void delay(uint32_t cycles)
{
	for(uint32_t i =0; i<cycles; i++);
}
int main(void){

	GPIO_Handle_t GpioLedGreen,GpioLedRed, GpioBtn;

	GpioBtn.pGPIOx = GPIOA;
	GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPOIO_PIN_NO_0;
	GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GpioLedGreen.pGPIOx = GPIOD;
	GpioLedGreen.GPIO_PinConfig.GPIO_PinNumber = GPOIO_PIN_NO_12;
	GpioLedGreen.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLedGreen.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GpioLedGreen.GPIO_PinConfig.GPIO_PinOptType = GPIO_OP_MODE_PP;
	GpioLedGreen.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GpioLedRed.pGPIOx = GPIOD;
	GpioLedRed.GPIO_PinConfig.GPIO_PinNumber = GPOIO_PIN_NO_13;
	GpioLedRed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLedRed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GpioLedRed.GPIO_PinConfig.GPIO_PinOptType = GPIO_OP_MODE_PP;
	GpioLedRed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PCLK_Control(GPIOA, ENABLE);
	GPIO_PCLK_Control(GPIOD, ENABLE);
	GPIO_Init(&GpioBtn);
	GPIO_Init(&GpioLedGreen);
	GPIO_Init(&GpioLedRed);


while(1){
	if(GPIO_ReadFromInputPin(GPIOA, GPOIO_PIN_NO_0) == BUTTON_PRESSED){
		delay(10000);
		GPIO_ToggleOutputPin(GPIOD, GPOIO_PIN_NO_12);
		GPIO_ToggleOutputPin(GPIOD, GPOIO_PIN_NO_13);
	}

}
	return 0;
}

//git fetch
