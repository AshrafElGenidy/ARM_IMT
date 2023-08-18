/************************************************************************/
/* SWC  	    : NVIC Driver                                           */
/* Author	    : Ashraf Ehab                                           */
/* Version	    : V1.0                                                  */
/* Date 	    : 12 Aug 2023                                           */
/* Description  : SWC for Nested Vectored Interrupt Controller          */
/************************************************************************/
#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MACROS.h"

typedef enum
{
	WWDG = 0,
	EXTI16_PVD,
	EXTI21_TAMP_STAMP,
	EXTI22_RTC_WKUP,
	FLASH,
	RCC,
	EXTI0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	DMA1_Stream0,
	DMA1_Stream1,
	DMA1_Stream2,
	DMA1_Stream3,
	DMA1_Stream4,
	DMA1_Stream5,
	DMA1_Stream6,
	ADC,
	EXTI9_5 = 23,
	TIM1_BRK_TIM9,
	TIM1_UP_TIM10,
	TIM1_TRG_COM_TIM11,
	TIM1_CC,
	TIM2,
	TIM3,
	TIM4,
	I2C1_EV,
	I2C1_ER,
	I2C2_EV,
	I2C2_ER,
	SPI1,
	SPI2,
	USART1,
	USART2,
	EXTI15_10 = 40,
	EXTI17_RTC_Alarm,
	EXTI18_OTG_FS_WKUP,
	DMA1_Stream7 = 47,
	SDIO = 49,
	TIM5,
	SPI3,
	DMA2_Stream0 = 56,
	DMA2_Stream1,
	DMA2_Stream2,
	DMA2_Stream3,
	DMA2_Stream4,
	OTG_FS = 67,
	DMA2_Stream5,
	DMA2_Stream6,
	DMA2_Stream7,
	USART6,
	I2C3_EV,
	I2C3_ER,
	FPU = 81,
	SPI4 = 84,
	NOT_A_PERIPHERAL = 240
}IRQn_t;

void NVIC_vdInit();
ErrorStatus NVIC_esEnablePerInt(IRQn_t copy_enPerID);
ErrorStatus NVIC_esDisablePerInt(IRQn_t copy_enPerID);
ErrorStatus NVIC_esSetPendingFlag(IRQn_t copy_enPerID);
ErrorStatus NVIC_esClearPendingFlag(IRQn_t copy_enPerID);
ErrorStatus NVIC_esSetPerPriority(IRQn_t copy_enPerID, u8 copy_u8Group, u8 copy_u8SubGroup);


#endif  /*NVIC_INTERFACE_H_*/