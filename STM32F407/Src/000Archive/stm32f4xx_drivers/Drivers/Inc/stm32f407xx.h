/*
 * stm32f407xx.h
 *
 *  Created on: Dec 19, 2021
 *      Author: shak48
 */




#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include<stdint.h>
#include<stddef.h>
#include<stdio.h>


#define __vo volatile


/*Processor specific NVIX address*/

#define	NVIC_ISER0	((__vo uint32_t*)0xE000E100)
#define	NVIC_ISER1	((__vo uint32_t*)0xE000E104)
#define	NVIC_ISER2	((__vo uint32_t*)0xE000E108)
#define	NVIC_ISER3	((__vo uint32_t*)0xE000E10C)


#define	NVIC_ICER0	((__vo uint32_t*)0XE000E180)
#define	NVIC_ICER1	((__vo uint32_t*)0XE000E184)
#define	NVIC_ICER2	((__vo uint32_t*)0XE000E188)
#define	NVIC_ICER3	((__vo uint32_t*)0XE000E18C)

#define	NVIC_ISPR0	((__vo uint32_t*)0XE000E200)
#define	NVIC_ISPR1	((__vo uint32_t*)0XE000E204)
#define	NVIC_ISPR2	((__vo uint32_t*)0XE000E208)
#define	NVIC_ISPR3	((__vo uint32_t*)0XE000E20C)


#define	NVIC_ICPR0	((__vo uint32_t*)0XE000E280)
#define	NVIC_ICPR1	((__vo uint32_t*)0XE000E284)
#define	NVIC_ICPR2	((__vo uint32_t*)0XE000E288)
#define	NVIC_ICPR3	((__vo uint32_t*)0XE000E28C)

#define	NVIC_IABR0	((__vo uint32_t*)0xE000E300)
#define	NVIC_IABR1	((__vo uint32_t*)0xE000E304)
#define	NVIC_IABR2	((__vo uint32_t*)0xE000E308)
#define	NVIC_IABR3	((__vo uint32_t*)0xE000E30C)


#define	NVIC_PR_BASE_ADDR	((__vo uint32_t*)0xE000E400)

#define NO_PR_BITS_IMPLEMENTED	4

#define IRQ_NO_EXTI0 					6
#define IRQ_NO_EXTI1 					7
#define IRQ_NO_EXTI2 					8
#define IRQ_NO_EXTI3 					9
#define IRQ_NO_EXTI4 					10
#define IRQ_NO_EXTI9_5 					23
#define IRQ_NO_EXTI5_10 				24

#define IRQ_NO_SPI1 					35
#define IRQ_NO_SPI2 					36
#define IRQ_NO_SPI3 					51
#define IRQ_NO_SPI4 					84
#define IRQ_NO_SPI5 					85
#define IRQ_NO_SPI6 					86


#define NVIC_IRQ_PRIO00		0
#define NVIC_IRQ_PRIO15		15

/*
 * Base addr for SRAM and Flash memories
 */

#define FLASH_BASEADDR 	0x08000000U
#define ROM_BASEADDR 	0x1FFF0000U
#define SRAM1_BASEADDR 	0x20000000U //112KB
#define SRAM2_BASEADDR 	0x2001C000U
#define SRAM SRAM1_BASEADDR

/*
 * AHBx APBx Bus Perhipheral base addr
 */

#define PERIPH_BASEADDR 	0x40000000U
#define APB1PERIPH_BASEADDR PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR 0x40010000U
#define AHB1PERIPH_BASEADDR 0x40020000U
#define AHB2PERIPH_BASEADDR 0x50000000U

/*
 *Base addr for Peripherals of AHB1 bus
 */

#define GPIOA_BASEADDR	(AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR	(AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR	(AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR	(AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR	(AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR	(AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR	(AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR	(AHB1PERIPH_BASEADDR + 0x1C00)
#define GPIOI_BASEADDR	(AHB1PERIPH_BASEADDR + 0x2000)

#define RCC_BASEADDR	(AHB1PERIPH_BASEADDR + 0x3800)

#define SYSCFG_BASEADDR	(APB2PERIPH_BASEADDR + 0x3800)

#define EXTI_BASEADDR	(APB2PERIPH_BASEADDR + 0x3C00)

/*
 *Base addr for Peripherals of APB1 bus
 */


#define SPI1_BASEADDR	(APB2PERIPH_BASEADDR + 0x3000)
#define SPI2_BASEADDR	(APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR	(APB1PERIPH_BASEADDR + 0x3C00)
#define SPI4_BASEADDR	(APB2PERIPH_BASEADDR + 0x3400)
#define SPI5_BASEADDR	(APB2PERIPH_BASEADDR + 0x5000)
#define SPI6_BASEADDR	(APB2PERIPH_BASEADDR + 0x5400)




#define I2C1_BASEADDR	(APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR	(APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR	(APB1PERIPH_BASEADDR + 0x5C00)

#define USART2_BASEADDR	(APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR	(APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR	(APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR	(APB1PERIPH_BASEADDR + 0x5000)

/*
 *Base addr for Peripherals of APB2 bus
 */



#define USART1_BASEADDR	(APB2PERIPH_BASEADDR + 0x1000)
#define USART6_BASEADDR	(APB2PERIPH_BASEADDR + 0x1400)









/*************************peripheral register definition structure*****************************************************/

typedef struct
{
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];
}GPIO_RegDef_t;


typedef struct
{
	__vo uint32_t 	CR;
	__vo uint32_t 	PLLCFGR;
	__vo uint32_t 	CFGR;
	__vo uint32_t 	CIR;
	__vo uint32_t 	AHB1RSTR;
	__vo uint32_t 	AHB2RSTR;
	__vo uint32_t 	AHB3RSTR;
	uint32_t		RESERVED0;
	__vo uint32_t 	APB1RSTR;
	__vo uint32_t 	APB2RSTR;
	uint32_t		RESERVED1[2];
	__vo uint32_t 	AHB1ENR;
	__vo uint32_t 	AHB2ENR;
	__vo uint32_t 	AHB3ENR;
	uint32_t		RESERVED2;
	__vo uint32_t 	APB1ENR;
	__vo uint32_t 	APB2ENR;
	uint32_t		RESERVED3[2];
	__vo uint32_t 	AHB1LPENR;
	__vo uint32_t 	AHB2LPENR;
	__vo uint32_t 	AHB3LPENR;
	uint32_t		RESERVED4;
	__vo uint32_t 	APB1LPENR;
	__vo uint32_t 	APB2LPENR;
	uint32_t		RESERVED5[2];
	__vo uint32_t 	BDCR;
	__vo uint32_t 	CSR;
	uint32_t		RESERVED6[2];
	__vo uint32_t 	SSCGR;
	__vo uint32_t 	PLLI2SCFGR;
}RCC_RegDef_t;


/*Exti Peri structure*/

typedef struct
{
	__vo uint32_t IMR;
	__vo uint32_t EMR;
	__vo uint32_t RTSR;
	__vo uint32_t FTSR;
	__vo uint32_t SWIR;
	__vo uint32_t PR;
}EXTI_RegDef_t;


typedef struct
{
	__vo uint32_t MEMRMP;
	__vo uint32_t PMC;
	__vo uint32_t EXTICR[0];
	__vo uint32_t CMPCR;
	//rest doesn't match with datasheet
}SYSCFG_RegDef_t;


typedef struct
{
	__vo uint32_t CR1;
	__vo uint32_t CR2;
	__vo uint32_t SR;
	__vo uint32_t DR;
	__vo uint32_t CRCPR;
	__vo uint32_t RXCRCR;
	__vo uint32_t TXCRCR;
	__vo uint32_t I2SCFGR;
	__vo uint32_t I2SPR;
}SPI_RegDef_t;

typedef struct
{
	__vo uint32_t CR1;
	__vo uint32_t CR2;
	__vo uint32_t OAR1;
	__vo uint32_t OAR2;
	__vo uint32_t DR;
	__vo uint32_t SR1;
	__vo uint32_t SR2;
	__vo uint32_t CCR;
	__vo uint32_t TRISE;
	__vo uint32_t FLTR;
}I2C_RegDef_t;

//SPI Device Mode

#define SPI_DEVICE_MODE_MASTER 1;
#define SPI_DEVICE_MODE_SLAVE 2;

// SPI Bus config

#define SPI_BUS_CONFIG_FD 				1
#define SPI_BUS_CONFIG_HD 				2
#define SPI_BUS_CONFIG_SIPLEX_RX_ONLY 	3
#define SPI_BUS_CONFIG_SIPLEX_TX_ONLY 	4


//SPI Sclk
#define SPI_SCLK_SPEED_DIV2				0
#define SPI_SCLK_SPEED_DIV4				1
#define SPI_SCLK_SPEED_DIV8				2
#define SPI_SCLK_SPEED_DIV16			3
#define SPI_SCLK_SPEED_DIV32			4
#define SPI_SCLK_SPEED_DIV64			5
#define SPI_SCLK_SPEED_DIV128			6
#define SPI_SCLK_SPEED_DIV256			7

//SPI Dff]

#define SPI_DFF_8BITS					0
#define SPI_DFF_16BITS					1


//DPI CPOL

#define SPI_CPOL_HIGH					1
#define SPI_CPOL_LOW					0

//spI SSM

#define SPI_SSM_EN					1
#define SPI_SSM_DI					0


/*
 *perioheral definitions
 */

#define GPIOA 	((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB 	((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC	((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD 	((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE 	((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF 	((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG 	((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH 	((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI 	((GPIO_RegDef_t*)GPIOI_BASEADDR)

#define RCC 	((RCC_RegDef_t*)RCC_BASEADDR)

#define EXTI 	((EXTI_RegDef_t*)(EXTI_BASEADDR))

#define SPI1	((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2	((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3	((SPI_RegDef_t*)SPI3_BASEADDR)
#define SPI4	((SPI_RegDef_t*)SPI4_BASEADDR)
#define SPI5	((SPI_RegDef_t*)SPI5_BASEADDR)
#define SPI6	((SPI_RegDef_t*)SPI6_BASEADDR)



/*
 Clock enable for GPIOx peripherals
 */

#define GPIOA_PCLK_EN() 	RCC->AHB1ENR |= (1<<0)
#define GPIOB_PCLK_EN() 	RCC->AHB1ENR |= (1<<1)
#define GPIOC_PCLK_EN() 	RCC->AHB1ENR |= (1<<2)
#define GPIOD_PCLK_EN() 	RCC->AHB1ENR |= (1<<3)
#define GPIOE_PCLK_EN() 	RCC->AHB1ENR |= (1<<4)
#define GPIOF_PCLK_EN() 	RCC->AHB1ENR |= (1<<5)
#define GPIOG_PCLK_EN() 	RCC->AHB1ENR |= (1<<6)
#define GPIOH_PCLK_EN() 	RCC->AHB1ENR |= (1<<7)
#define GPIOI_PCLK_EN() 	RCC->AHB1ENR |= (1<<8)

/*
 * Clock enable macros for I2Cx peripherals
 */
#define I2C1_PCLK_EN() 		RCC->APB1ENR |= (1<<21)
#define I2C2_PCLK_EN() 		RCC->APB1ENR |= (1<<22)
#define I2C3_PCLK_EN() 		RCC->APB1ENR |= (1<<23)


/*
 *Clock enable macros for SPIx peripherals
 */
#define SPI1_PCLK_EN() 		RCC->APB2ENR |= (1<<12)
#define SPI2_PCLK_EN() 		RCC->APB1ENR |= (1<<14)
#define SPI3_PCLK_EN() 		RCC->APB1ENR |= (1<<15)
#define SPI4_PCLK_EN() 		RCC->APB2ENR |= (1<<13)
#define SPI5_PCLK_EN() 		RCC->APB2ENR |= (1<<20)
#define SPI6_PCLK_EN() 		RCC->APB2ENR |= (1<<21)


/*
 *Clock enable macros for USARTx peripherals
 */
#define USART1_PCLK_EN() 	RCC->APB2ENR |= (1<<4)
#define USART2_PCLK_EN() 	RCC->APB1ENR |= (1<<17)
#define USART3_PCLK_EN() 	RCC->APB1ENR |= (1<<18)
#define UART4_PCLK_EN() 	RCC->APB1ENR |= (1<<19)
#define UART5_PCLK_EN() 	RCC->APB1ENR |= (1<<20)
#define USART6_PCLK_EN() 	RCC->APB2ENR |= (1<<5)		//Check APB1ENR?


/*
 *Clock enable macros for SYSconfig peripherals
 */

#define SYSCFG_PCLK_EN() 	RCC->APB2ENR |= (1<<14)


/*
 Clock disable for GPIOx peripherals
 */


#define GPIOA_PCLK_DI() 	RCC->AHB1ENR &= ~(1<<0)
#define GPIOB_PCLK_DI() 	RCC->AHB1ENR &= ~(1<<1)
#define GPIOC_PCLK_DI() 	RCC->AHB1ENR &= ~(1<<2)
#define GPIOD_PCLK_DI() 	RCC->AHB1ENR &= ~(1<<3)
#define GPIOE_PCLK_DI() 	RCC->AHB1ENR &= ~(1<<4)
#define GPIOF_PCLK_DI() 	RCC->AHB1ENR &= ~(1<<5)
#define GPIOG_PCLK_DI() 	RCC->AHB1ENR &= ~(1<<6)
#define GPIOH_PCLK_DI() 	RCC->AHB1ENR &= ~(1<<7)
#define GPIOI_PCLK_DI() 	RCC->AHB1ENR &= ~(1<<8)


/*
*Clock disable macros for SPIx peripherals
*/
#define SPI1_PCLK_DI() 		RCC->APB2ENR &= ~(1<<12)
#define SPI2_PCLK_DI() 		RCC->APB1ENR &= ~(1<<14)
#define SPI3_PCLK_DI() 		RCC->APB1ENR &= ~(1<<15)
#define SPI4_PCLK_DI() 		RCC->APB2ENR &= ~(1<<13)
#define SPI5_PCLK_DI() 		RCC->APB2ENR &= ~(1<<20)
#define SPI6_PCLK_DI() 		RCC->APB2ENR &= ~(1<<21)

/* Clock disable macros for I2Cx peripherals
*/
#define I2C1_PCLK_DI() 		RCC->APB1ENR &= ~(1<<21)
#define I2C2_PCLK_DI() 		RCC->APB1ENR &= ~(1<<22)
#define I2C3_PCLK_DI() 		RCC->APB1ENR &= ~(1<<23)




/*
*Clock disable macros for USARTx peripherals
*/
#define USART1_PCLK_DI() 	RCC->APB2ENR &= ~(1<<4)
#define USART2_PCLK_DI() 	RCC->APB1ENR &= ~(1<<17)
#define USART3_PCLK_DI() 	RCC->APB1ENR &= ~(1<<18)
#define UART4_PCLK_DI() 	RCC->APB1ENR &= ~(1<<19)
#define UART5_PCLK_DI() 	RCC->APB1ENR &= ~(1<<20)
#define USsART6_PCLK_DI() 	RCC->APB2ENR &= ~(1<<5)		//Check APB1ENR?


//Reset GPIOx peripherals

#define GPIOA_REG_RESET() 	do{RCC->AHB1RSTR |= (1<<0);	RCC->AHB1RSTR &= ~(1<<0);}while(0)
#define GPIOB_REG_RESET() 	do{RCC->AHB1RSTR |= (1<<1);	RCC->AHB1RSTR &= ~(1<<1);}while(0)
#define GPIOC_REG_RESET() 	do{RCC->AHB1RSTR |= (1<<2);	RCC->AHB1RSTR &= ~(1<<2);}while(0)
#define GPIOD_REG_RESET() 	do{RCC->AHB1RSTR |= (1<<3);	RCC->AHB1RSTR &= ~(1<<3);}while(0)
#define GPIOE_REG_RESET() 	do{RCC->AHB1RSTR |= (1<<4);	RCC->AHB1RSTR &= ~(1<<4);}while(0)
#define GPIOF_REG_RESET() 	do{RCC->AHB1RSTR |= (1<<5);	RCC->AHB1RSTR &= ~(1<<5);}while(0)
#define GPIOG_REG_RESET() 	do{RCC->AHB1RSTR |= (1<<6);	RCC->AHB1RSTR &= ~(1<<6);}while(0)
#define GPIOH_REG_RESET() 	do{RCC->AHB1RSTR |= (1<<7);	RCC->AHB1RSTR &= ~(1<<7);}while(0)
#define GPIOI_REG_RESET() 	do{RCC->AHB1RSTR |= (1<<8);	RCC->AHB1RSTR &= ~(1<<8);}while(0)



/*GPIO ADRESS return*/

#define GPIO_ADDR_TO_CODE(x)    (x==GPIOA)    ?    0\
								(x==GPIOB)    ?    1    :\
								(x==GPIOc)    ?    2    :\
								(x==GPIOD)    ?    3    :\
								(x==GPIOE)    ?    4    :\
								(x==GPIOF)    ?    5    :\
								(x==GPIOG)    ?    6    :\
								(x==GPIOH)    ?    7    :\
								(x==GPIOI)    ?    8    :0



/*
*Clock disable macros for SYSconfig peripherals
*/

#define SYSCFG_PCLK_DI() 	RCC->APB2ENR &= ~(1<<14)

#define ENABLE 			1
#define DISABLE 		0

#define SET 			ENABLE
#define RESET			DISABLE

#define GPIO_PIN_SET	SET
#define GPIO_PIN_RESET	RESET

#define FLAG_SET		SET
#define FLAG_RESET		RESET





#include "stm32f407xx_gpio_driver.h"
#include "stm32f407xx_spi_driver.h"
#include "stm32f407xx_i2c_driver.h"


#endif /* INC_STM32F407XX_H_ */
