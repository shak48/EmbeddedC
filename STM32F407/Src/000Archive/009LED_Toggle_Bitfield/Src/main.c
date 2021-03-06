#include <stdint.h>
#include <stdio.h>
#include "main.h"
#include "source.c"



void delay(unsigned long int);
void flash4Leds(unsigned long int);
void ioInitialize(void);

RCC_AHB1ENR_t 	volatile *const pClkCtrlReg 	= (RCC_AHB1ENR_t*)	0x40023830;

GPIOx_MODE_t 	volatile *const pGpioAMode		= (GPIOx_MODE_t*)	0x40020000;
GPIOx_IDR_t		volatile *const pGpioAIdr		= (GPIOx_IDR_t*)	0x40020010;

GPIOx_MODE_t 	volatile *const pGpioDMode		= (GPIOx_MODE_t*)	0x40020C00;
GPIOx_ODR_t		volatile *const pGpioDOdr		= (GPIOx_ODR_t*)	0x40020C14;

uint8_t pinStatus = 0;


int main(void)
{

	ioInitialize();


	while(1){
		if(pinStatus==1){
			flash4Leds(900000);
		}
		if(pinStatus==0){
			flash4Leds(100000);
		}
	pinStatus = (uint8_t)(pGpioAIdr->pin0);
	}
}

void ioInitialize(void){
	pClkCtrlReg->gpioa_en	= 1;
	pClkCtrlReg->gpiod_en	= 1;
	pGpioAMode->pin0		= 0;
	pGpioDMode->pin12		= 1;
	pGpioDMode->pin13		= 1;
	pGpioDMode->pin14		= 1;
	pGpioDMode->pin15		= 1;
}

void delay(unsigned long int number_of_cycles)
{
	for(int i=0;i<=number_of_cycles;i++);
}

void flash4Leds(unsigned long int cycles){
	pGpioDOdr->pin15	= 0;
	pGpioDOdr->pin12	= 1;
	delay(cycles);
	pGpioDOdr->pin12	= 0;
	pGpioDOdr->pin13	= 1;
	delay(cycles);
	pGpioDOdr->pin13	= 0;
	pGpioDOdr->pin14	= 1;
	delay(cycles);
	pGpioDOdr->pin14	= 0;
	pGpioDOdr->pin15	= 1;
	delay(cycles);
}

