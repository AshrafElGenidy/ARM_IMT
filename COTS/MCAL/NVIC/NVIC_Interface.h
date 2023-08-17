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
	WWDG,
	EXTI16,
	EXTI21,
	EXTI22,
	FLASH,
	RCC,
	EXTI0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	DMA1_0,
	DMA1_1,
	DMA1_2,
	DMA1_3,
	DMA1_4,
	DMA1_5,
	DMA1_6,
	ADC,
	EXTI9_5,
	TMI1_BRK_TMR9,
	TMI1_UP,TIM10,
	TMI1_TRG_COM_TIM11,
	TIM1_CC,
	TIM2,
	TIM3,
	TIM4,
	I2C1_EV,
	I2C_ER,
	I2C2_EV,
	I2C2_ER,
	SPI1,
	SPI2,
	USART1,
	USART2,
	EXTI17_RTC_ALARM,
	EXTI18_OTG_FS_WKUP,
	DMA1_7,
	SDIO,
	TIM5,
	SPI3,
	DMA2_0,
	DMA2_1,
	DMA2_2,
	DMA2_3,
	DMA2_4,
	OTG_FS,
	DMA2_5,
	DMA2_6,
	DMA2_7,
	USART6,
	I2C3_EV,
	I2C3_ER,
	FPU,
	SPI4
}PER_t;

void NVIC_esInit();
void NVIC_vdEnablePerInt(PER_t copy_enPerID);
void NVIC_vdDisablePerInt(PER_t copy_enPerID);
void NVIC_vdSetPendingFlag(PER_t copy_enPerID);
void NVIC_vdClearPendingFlag(PER_t copy_enPerID);
ErrorStatus NVIC_esSetPerPriority(PER_t copy_enPerID, u8 copy_u8Group, u8 copy_u8SubGroup);


#endif  /*NVIC_INTERFACE_H_*/