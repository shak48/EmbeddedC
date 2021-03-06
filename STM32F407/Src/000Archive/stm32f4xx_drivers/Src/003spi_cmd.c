#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "stm32f407xx_gpio_driver.h"
#include "stm32f407xx_spi_driver.h"

extern void initialise_monitor_handles(void);

void SPI1_GPIOInit(void)
{
	GPIO_Handle_t SPIPins;

	SPIPins.pGPIOx = GPIOA;
	SPIPins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	SPIPins.GPIO_PinConfig.GPIO_PinAltFunMode= 5;
	SPIPins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	SPIPins.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	//NSS
	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPOIO_PIN_NO_4;
	GPIO_Init(&SPIPins);
	//SCLK
	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPOIO_PIN_NO_5;
	GPIO_Init(&SPIPins);
	//MISO
	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPOIO_PIN_NO_6;
	GPIO_Init(&SPIPins);
	//MOSI
	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPOIO_PIN_NO_7;
	GPIO_Init(&SPIPins);


}

void SPI1_Inits(void)
{
	SPI_Handle_t SPI2Handle;
	SPI2Handle.pSPIx = SPI1;
	SPI2Handle.SPI_Config.SPI_BusConfig = SPI_BUS_CONFIG_FD;
	SPI2Handle.SPI_Config.SPI_DviceMode = SPI_DEVICE_MODE_MASTER;
	SPI2Handle.SPI_Config.SPI_SclkSpeed = SPI_SCLK_SPEED_DIV8;
	SPI2Handle.SPI_Config.SPI_DFF = SPI_DFF_8BITS;
	SPI2Handle.SPI_Config.SPI_CPHA = SPI_CPOL_LOW;
	SPI2Handle.SPI_Config.SPI_CPOL= SPI_CPOL_LOW;
	SPI2Handle.SPI_Config.SPI_SSM = SPI_SSM_DI;

	SPI_Init(&SPI2Handle);
}




//PC2 SPI2 MISO
//PBC3 SPI2 MOSI
//PB13 SPI2 SCLK
//PB12 SPI2 NSS
//ALT FUNC MODE :5




void SPI2_GPIOInit(void)
{
	GPIO_Handle_t SPIPins;

	SPIPins.pGPIOx = GPIOB;
	SPIPins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	SPIPins.GPIO_PinConfig.GPIO_PinAltFunMode= 5;
	SPIPins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	SPIPins.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	//SCLK
	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPOIO_PIN_NO_13;
	GPIO_Init(&SPIPins);
	//NSS
	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPOIO_PIN_NO_12;
	GPIO_Init(&SPIPins);


	//From port C

	SPIPins.pGPIOx = GPIOC;

	//MISO
	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPOIO_PIN_NO_2;
	GPIO_Init(&SPIPins);
	//MOSI
	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPOIO_PIN_NO_3;
	GPIO_Init(&SPIPins);


}

void SPI2_Inits(void)
{
	SPI_Handle_t SPI2Handle;
	SPI2Handle.pSPIx = SPI2;
	SPI2Handle.SPI_Config.SPI_BusConfig = SPI_BUS_CONFIG_FD;
	SPI2Handle.SPI_Config.SPI_DviceMode = SPI_DEVICE_MODE_SLAVE;
	SPI2Handle.SPI_Config.SPI_SclkSpeed = SPI_SCLK_SPEED_DIV8;
	SPI2Handle.SPI_Config.SPI_DFF = SPI_DFF_8BITS;
	SPI2Handle.SPI_Config.SPI_CPHA = SPI_CPOL_LOW;
	SPI2Handle.SPI_Config.SPI_CPOL= SPI_CPOL_LOW;
	SPI2Handle.SPI_Config.SPI_SSM = SPI_SSM_DI;
//	SPI2Handle.SPI_Config.

	SPI_Init(&SPI2Handle);
}




int main(void){
	initialise_monitor_handles();	//Using same chip as Master and Slave. SPI1->PortA is Master and SPI2->PortB+C are

	char usrData[]= "Sending Data over SPI1.";
	printf("Demo test\n");

	SPI1_GPIOInit();

	SPI1_Inits();

	SPI2_GPIOInit();

	SPI2_Inits();

	//SPI_SSI_Control(SPI1, ENABLE);
	//SPI_SSI_Control(SPI2, ENABLE);

	SPI_SSOE_Control(SPI1, ENABLE);

	SPI_Peri_Control(SPI1, ENABLE);
	SPI_Peri_Control(SPI2, ENABLE);



	SPI_SendData(SPI1, (uint8_t*)usrData, strlen(usrData));

	while(SPI_GetFlagStatus(SPI1, SPI_SR_BSY));
	SPI_Peri_Control(SPI1, DISABLE);


	while(1)
	{
		printf("Demo test");
	}

}

