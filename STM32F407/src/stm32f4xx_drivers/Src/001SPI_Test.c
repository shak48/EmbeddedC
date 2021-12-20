#include <stdint.h>
#include <string.h>

#include "stm32f407xx_gpio_driver.h"
#include "stm32f407xx_spi_driver.h"

//PB14 SPI2 MISO
//PB15 SPI2 MOSI
//PB13 SPI2 SCLK
//PB12 SPI2 NSS
//ALT FUNC MODE :5

void SPI2_GPIOInit(void)
{
	GPIO_Handle_t SPIPins;

	SPIPins.pGPIOx = GPIOB;
	SPIPins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	SPIPins.GPIO_PinConfig.GPIO_PinOptType = GPIO_OP_MODE_PP;
	SPIPins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	SPIPins.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	//SCLK
	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPOIO_PIN_NO_13;
	GPIO_Init(&SPIPins);

	//MOSI
	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPOIO_PIN_NO_15;
	GPIO_Init(&SPIPins);
	//MISO
	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPOIO_PIN_NO_14;
	GPIO_Init(&SPIPins);
	//NSS
	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPOIO_PIN_NO_12;
	GPIO_Init(&SPIPins);
}

void SPI2_Inits(void)
{
	SPI_Handle_t SPI2Handle;
	SPI2Handle.pSPIx = SPI2;
	SPI2Handle.SPI_Config.SPI_BusConfig = SPI_BUS_CONFIG_FD;
	SPI2Handle.SPI_Config.SPI_DviceMode = SPI_DEVICE_MODE_MASTER;
	SPI2Handle.SPI_Config.SPI_SclkSpeed = SPI_SCLK_SPEED_DIV2;
	SPI2Handle.SPI_Config.SPI_DFF = SPI_DFF_8BITS;
	SPI2Handle.SPI_Config.SPI_CPHA = SPI_CPOL_LOW;
	SPI2Handle.SPI_Config.SPI_CPOL= SPI_CPOL_LOW;
	SPI2Handle.SPI_Config.SPI_SSM = SPI_SSM_EN;



	SPI_Init(&SPI2Handle);
}


int main(void){
	char usrData[]= "Hellowww World";

	SPI2_GPIOInit();

	SPI_Peri_Control(SPI2, ENABLE);

	SPI_SSM_Control(SPI2, ENABLE);
	SPI2_Inits();

	SPI_SendData(SPI2, (uint8_t*)usrData, strlen(usrData));

	for(;;);
}

