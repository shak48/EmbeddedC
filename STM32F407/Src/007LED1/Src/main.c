
#include <stdio.h>


#define RCCADDR 	0x40023830
#define GPIODADDR	0x40020C00
#define GPIOOUT		0x40020C14


void delay(unsigned long int);

void delay(unsigned long int number_of_cycles)
{
	for(int i=0;i<=number_of_cycles;i++);
}

// Driver code to test above function



int main(void)
{
	uint32_t *pRCC = (uint32_t*)RCCADDR, *pGPIODMODE = (uint32_t*)GPIODADDR, *pGPIODOUT = (uint32_t*)GPIOOUT;

	*pRCC 		|= (1 << 3); //Enable clock

	*pGPIODMODE	&= ~(3 << 24); // Clear mode
	*pGPIODMODE	|= (1 << 24); // set mode
	*pGPIODMODE	&= ~(3 << 26); // Clear mode
	*pGPIODMODE	|= (1 << 26); // set mode

	*pGPIODMODE	&= ~(0b01010101 << 24);
	*pGPIODMODE	|= (0b01010101 << 24);


    /* Loop forever */
	for(;;){
		*pGPIODOUT	&= ~(0b1001<<12);
		*pGPIODOUT	|= (0b1100<<12);
		delay(400000);
		*pGPIODOUT	&= ~(0b1100<<12);
	    *pGPIODOUT	|= (0b0110 <<12);
		delay(400000);
		*pGPIODOUT	&= ~(0b0110<<12);
	    *pGPIODOUT	|= (0b0011 <<12);
		delay(400000);
		*pGPIODOUT	&= ~(0b0011<<12);
	    *pGPIODOUT	|= (0b1001 <<12);
		delay(400000);

	}
}
