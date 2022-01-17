
#include <stdio.h>


#define RCCADDR 	0x40023830
#define GPIODADDR	0x40020C00
#define GPIOAADDR	0x40020000
#define GPIOOUT		0x40020C14


void delay(unsigned long int);
void flash4Leds(unsigned long int);

void delay(unsigned long int number_of_cycles)
{
	for(int i=0;i<=number_of_cycles;i++);
}

uint32_t volatile 	*const pRCC 		= (uint32_t*)RCCADDR,
					*const pGPIOAMODE 	= (uint32_t*)GPIOAADDR,
					*const pGPIODMODE 	= (uint32_t*)GPIODADDR,
					*const pGPIODOUT 	= (uint32_t*)GPIOOUT;
uint32_t const volatile	*const pGPIOAIDR= (uint32_t*)(0x40020010);

// Driver code to test above function
void flash4Leds(unsigned long int cycles){
	*pGPIODOUT	&= ~(0b0001<<12);
	*pGPIODOUT	|= (0b1000<<12);
	delay(cycles);
	*pGPIODOUT	&= ~(0b1000<<12);
	*pGPIODOUT	|= (0b0100 <<12);
	delay(cycles);
	*pGPIODOUT	&= ~(0b0100<<12);
	*pGPIODOUT	|= (0b0010 <<12);
	delay(cycles);
	*pGPIODOUT	&= ~(0b0010<<12);
	*pGPIODOUT	|= (0b0001 <<12);
	delay(cycles);
}

int main(void)
{
	*pRCC 		|= (0b1001 << 0); //Enable clock GPIOD &A
	*pGPIODMODE	&= ~(0b01010101 << 24);
	*pGPIODMODE	|= (0b01010101 << 24);
	*pGPIOAMODE	&= ~(3 << 0);
	uint8_t pinStat = 0;
    /* Loop forever */
	while(1){
		if(pinStat==1){
			flash4Leds(100000);
		}
		if(pinStat==0){
			flash4Leds(900000);
		}
	pinStat = (uint8_t)(*pGPIOAIDR & 0x1);
	}
}


