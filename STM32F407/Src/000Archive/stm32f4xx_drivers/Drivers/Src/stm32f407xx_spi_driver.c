/*
 * stm32f407xx_spi_driver.c
 *
 *  Created on: Dec 18, 2021
 *      Author: shak48
 */

#include "stm32f407xx_i2c_driver.h"


// init deinit
void SPI_PCLK_Control(SPI_RegDef_t *pSPIx, uint8_t En_Or_Di)
{
	if(En_Or_Di == ENABLE)
	{
		if(pSPIx	==	SPI1)
		{
			SPI1_PCLK_EN();
		}
		else if(pSPIx	==	SPI2)
		{
			SPI2_PCLK_EN();
		}
		else if(pSPIx	==	SPI3)
		{
			SPI3_PCLK_EN();
		}
		else if(pSPIx	==	SPI4)
		{
			SPI4_PCLK_EN();
		}
		else if(pSPIx	==	SPI5)
		{
			SPI5_PCLK_EN();
		}
		else if(pSPIx	==	SPI6)
		{
			SPI6_PCLK_EN();
		}
	}
	if(En_Or_Di == DISABLE)
	{
		if(pSPIx	==	SPI1)
		{
			SPI1_PCLK_DI();
		}
		else if(pSPIx	==	SPI2)
		{
			SPI2_PCLK_DI();
		}
		else if(pSPIx	==	SPI3)
		{
			SPI3_PCLK_DI();
		}
		else if(pSPIx	==	SPI4)
		{
			SPI4_PCLK_DI();
		}
		else if(pSPIx	==	SPI5)
		{
			SPI5_PCLK_DI();
		}
		else if(pSPIx	==	SPI6)
		{
			SPI6_PCLK_DI();
		}
	}
}
void SPI_Init(SPI_Handle_t *pSPIHandle)
{
	SPI_PCLK_Control(pSPIHandle->pSPIx, ENABLE);
	uint32_t temp =0;
	//device mode
	temp |= pSPIHandle->SPI_Config.SPI_DviceMode << SPI_CR1_MSTR;
	//bus config
	if(pSPIHandle->SPI_Config.SPI_BusConfig == SPI_BUS_CONFIG_FD)
	{
		temp &= ~(1<<SPI_CR1_BIDIMODE);
	}
	else if(pSPIHandle->SPI_Config.SPI_BusConfig == SPI_BUS_CONFIG_HD)
	{
		temp |= (1<<SPI_CR1_BIDIMODE);
	}
	else if(pSPIHandle->SPI_Config.SPI_BusConfig == SPI_BUS_CONFIG_SIPLEX_RX_ONLY)
	{
		temp &= (1<<SPI_CR1_BIDIMODE);
		temp &= ~(1<<SPI_CR1_BIDIOE);
	}
	else if(pSPIHandle->SPI_Config.SPI_BusConfig == SPI_BUS_CONFIG_SIPLEX_TX_ONLY)
	{
		temp &= (~1<<SPI_CR1_BIDIMODE);
		temp &= (1<<SPI_CR1_BIDIOE);
	}

	temp |= pSPIHandle->SPI_Config.SPI_SclkSpeed <<SPI_CR1_BR;

	temp |= pSPIHandle->SPI_Config.SPI_DFF <<SPI_CR1_DFF;

	temp |= pSPIHandle->SPI_Config.SPI_CPOL <<SPI_CR1_CPOL;

	temp |= pSPIHandle->SPI_Config.SPI_CPHA <<SPI_CR1_CPHA;

	temp |= pSPIHandle->SPI_Config.SPI_SSM <<SPI_CR1_SSM;


	pSPIHandle->pSPIx->CR1 |= temp;



}
void 		SPI_DeInit(SPI_RegDef_t *pSPIx);


uint8_t  SPI_GetFlagStatus(SPI_RegDef_t *pSPIx, uint32_t flagName)
{
	if(pSPIx->SR & flagName)
	{
		return FLAG_SET;
	}

	return FLAG_RESET;
}


//data RX TX

//this is blocking blocking// polling
void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len)
{
//	uint8_t *pRxBuffer;
	while(Len >0)
	{
		while(SPI_GetFlagStatus(pSPIx, SPI_TXE_FLAG) == FLAG_RESET);

		if((pSPIx->CR1 & (1<<SPI_CR1_DFF)))
		{
			pSPIx->DR = *((uint16_t*)(pTxBuffer));
			Len--;
			Len--;
			(uint16_t*)pTxBuffer++;
		}else
		{
			pSPIx->DR = *pTxBuffer;

		///Dummy code
			//*pRxBuffer = SPI2->DR;
			printf("%d \n",(uint8_t)SPI1->DR);
	///Dummycode above
			Len--;
			pTxBuffer++;
		}
	}
}


//data RX TX

//this is blocking blocking// polling
void SPI_ReceiveData(SPI_RegDef_t *pSPIx,uint8_t *pRxBuffer, uint32_t Len)
{
	while(Len >0)
	{
		while(SPI_GetFlagStatus(pSPIx, SPI_RXE_FLAG) == FLAG_SET);

		if((pSPIx->CR1 & (1<<SPI_CR1_DFF)))
		{
			*((uint16_t*)(pRxBuffer)) = pSPIx->DR;
			Len--;
			Len--;
			(uint16_t*)pRxBuffer++;
		}else
		{
			*pRxBuffer=pSPIx->DR;
			Len--;
			pRxBuffer++;
		}
	}
}

//this is blocking blocking// polling
uint8_t SPI_SendDataIT(SPI_Handle_t *pSPIHandle, uint8_t *pTxBuffer, uint32_t Len)
{
	uint8_t state = pSPIHandle->TxState;

	if(state != SPI_BUSY_IN_TX)
	{
		//Save Tx States
		pSPIHandle->pTxBuffer = pTxBuffer;
		pSPIHandle->TxLen = Len;
		pSPIHandle->TxState = SPI_BUSY_IN_TX;

	//Set interrupt control bit
		pSPIHandle->pSPIx->CR2 |= (1<<SPI_CR2_TXEIE);
	}

	return state;
}


//data RX TX

//this is blocking blocking// polling
uint8_t SPI_ReceiveDataIT(SPI_Handle_t *pSPIHandle,uint8_t *pRxBuffer, uint32_t Len)
{
	uint8_t state = pSPIHandle->RxState;

	if(state != SPI_BUSY_IN_RX)
	{
		//Save Tx States
		pSPIHandle->pRxBuffer = pRxBuffer;
		pSPIHandle->RxLen = Len;
		pSPIHandle->RxState = SPI_BUSY_IN_RX;

	//Set interrupt control bit
		pSPIHandle->pSPIx->CR2 |= (1<<SPI_CR2_RXEIE);
	}

	return state;
}

void SPI_Peri_Control(SPI_RegDef_t *pSPIx, uint8_t En_Or_Di)
{
	if(En_Or_Di == ENABLE)
	{
		pSPIx->CR1 |= (1 << SPI_CR1_SPE);
	}else
	{
		pSPIx->CR1 &= ~(1 << SPI_CR1_SPE);
	}
}

void SPI_SSI_Control(SPI_RegDef_t *pSPIx, uint8_t En_Or_Di)
{
	if(En_Or_Di == ENABLE)
	{
		pSPIx->CR1 |= (1 << SPI_CR1_SSI);
	}else
	{
		pSPIx->CR1 &= ~(1 << SPI_CR1_SSI);
	}
}

void SPI_SSOE_Control(SPI_RegDef_t *pSPIx, uint8_t En_Or_Di)
{
	if(En_Or_Di == ENABLE)
	{
		pSPIx->CR2 |= (1 << SPI_CR2_SSOE);
	}else
	{
		pSPIx->CR2 &= ~(1 << SPI_CR2_SSOE);
	}
}




//IRQ config

void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t En_Or_Di)
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
void 		SPI_IRQPriorityConfig(uint8_t IRQNumber, uint16_t IRQPriority);
void 		SPI_IRQHandling(SPI_Handle_t *pSPIHandle)
{
	//check for TXE
	uint8_t temp1;
	uint8_t temp2;

	//check for TXE flag

	temp1 = pSPIHandle->pSPIx->SR & (1<<SPI_SR_TXE);
	temp2 = pSPIHandle->pSPIx->CR2 & (1<<SPI_CR2_TXEIE);
	if(temp1 && temp2)
	{
		spi_txne_interrupt_handle(pSPIHandle);

	}

	//check for RXNE
	temp1 = pSPIHandle->pSPIx->SR & (1<<SPI_SR_RXNE);
	temp2 = pSPIHandle->pSPIx->CR2 & (1<<SPI_CR2_RXEIE);
	if(temp1 && temp2)
	{
		spi_rxne_interrupt_handle(pSPIHandle);
	}

	//check for OVR
	temp1 = pSPIHandle->pSPIx->SR & (1<<SPI_SR_OVR);
	temp2 = pSPIHandle->pSPIx->CR2 & (1<<SPI_CR2_ERRIE);
	if(temp1 && temp2)
	{
		spi_ovr_interrupt_handle(pSPIHandle);

	}
}

static void spi_txne_interrupt_handle(SPI_Handle_t *pSPIHandle)
{
		while(pSPIHandle->TxLen >0)
		{
			while(SPI_GetFlagStatus(pSPIHandle->pSPIx, SPI_TXE_FLAG) == FLAG_RESET);

			if((pSPIHandle->pSPIx->CR1 & (1<<SPI_CR1_DFF)))
			{
				pSPIHandle->pSPIx->DR = *((uint16_t*)(pSPIHandle->pTxBuffer));
				pSPIHandle->TxLen--;
				pSPIHandle->TxLen--;
				(uint16_t*)pSPIHandle->pTxBuffer++;
			}else
			{
				pSPIHandle->pSPIx->DR = *pSPIHandle->pTxBuffer;
				pSPIHandle->TxLen--;
				pSPIHandle->pTxBuffer++;
			}
		}
		//clear tx interrupt
		if(!pSPIHandle->TxLen)
		{
			SPI_CloseTransmission(pSPIHandle);
		}
}
static void spi_rxne_interrupt_handle(SPI_Handle_t *pSPIHandle)
{
	while(pSPIHandle->RxLen >0)
	{
		while(SPI_GetFlagStatus(pSPIHandle->pSPIx, SPI_RXE_FLAG) == FLAG_SET);

		if((pSPIHandle->pSPIx->CR1 & (1<<SPI_CR1_DFF)))
		{
			pSPIHandle->pSPIx->DR = *((uint16_t*)(pSPIHandle->pRxBuffer));
			pSPIHandle->RxLen--;
			pSPIHandle->RxLen--;
			(uint16_t*)pSPIHandle->pRxBuffer++;
		}else
		{
			pSPIHandle->pSPIx->DR = *pSPIHandle->pRxBuffer;
			pSPIHandle->RxLen--;
			pSPIHandle->pRxBuffer++;
		}
	}
	//clear tx interrupt
	if(!pSPIHandle->RxLen)
	{
		SPI_CloseReception(pSPIHandle);
	}
}
static void spi_ovr_interrupt_handle(SPI_Handle_t *pSPIHandle)
{
	uint8_t temp;
	if(pSPIHandle->TxState != SPI_BUSY_IN_TX)
	{
		temp = pSPIHandle->pSPIx->DR;
		temp = pSPIHandle->pSPIx->SR;

	}
	(void)temp;
}


void SPI_ClearOVRFlag(SPI_RegDef_t *pSPIx)
{
	uint8_t temp;
	temp = pSPIx->DR;
	temp = pSPIx->SR;
	(void)temp;

}
void SPI_CloseTransmission(SPI_Handle_t *pSPIHandle)
{
	pSPIHandle->pSPIx->CR2 &= ~(1<<SPI_CR2_TXEIE);
	pSPIHandle->pTxBuffer = NULL;
	pSPIHandle->TxLen = 0;
	pSPIHandle->TxState = SPI_READY;
	SPI_Application_Event_CallBack(pSPIHandle,SPI_EVENT_TX_CMPLT);
}
void SPI_CloseReception(SPI_Handle_t *pSPIHandle)
{
	pSPIHandle->pSPIx->CR2 &= ~(1<<SPI_CR2_RXEIE);
	pSPIHandle->pRxBuffer = NULL;
	pSPIHandle->RxLen = 0;
	pSPIHandle->RxState = SPI_READY;
	SPI_Application_Event_CallBack(pSPIHandle,SPI_EVENT_RX_CMPLT);
}


__attribute__((weak)) void SPI_Application_Event_CallBack(SPI_Handle_t *SPIHandle, uint8_t Event)
{

}

