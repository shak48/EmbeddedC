

#include <stdint.h>


#define GPIOA 0x40020000U;
#define GPIOD 0x40020C00U;


int main(void)
{
	int32_t *pRCC = (int32_t*)0x40023830, *pGPIOA = (int32_t*) GPIOA;
	//int32_t *pGPIOA_PUPDR = (int32_t*) (GPIOA+0x30);
	*pRCC |= (1<<0);
	*pRCC |= (1<<3);

	*pGPIOA &= ~(3 << 1);

	*(pGPIOA+ 0x0CU) &= ~(3 << 1);
	*(pGPIOA+0x0CU) |= (1 << 1);












	for(;;);
}
