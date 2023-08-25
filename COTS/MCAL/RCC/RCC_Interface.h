/************************************************************************/
/* SWC			: RCC Driver											*/
/* Author		: Ashraf Ehab											*/
/* Version		: V1.0													*/
/* Date			: 24 Aug 2023											*/
/* Description	: SWC for Reset and Control Clock						*/
/************************************************************************/
#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MACROS.h"

/*Peripheral IDs*/
typedef enum
{
	USBFS,
	DMA1,
	DMA2,
	CRC,
	GPIOA,
	GPIOB,
	GPIOC,
	TIM1,
	TIM2,
	TIM3,
	TIM4,
	TIM5,
	TIM9,
	TIM10,
	TIM11,
	SYSCFG,
	SPI1,
	SPI2,
	SPI3,
	SPI4,
	SDIO,
	ADC1,
	USART1,
	USART2,
	USART6,
	PWR,
	I2C1,
	I2C2,
	I2C3,
	WWDG,
	NOT_A_PERIPHERAL
}PERI_t;

/*__________________________________________________________________________________________________________________________________________*/

/* 
 * Function	: RCC_voidInitSysClk			: Initiates the clock for the micro-controller according to configurations in RCC_Config
 */
void RCC_voidInitSysClk(void);

/* 
 * Function	: RCC_voidEnablePeripheralClk	: Enables the clock for a certain peripheral
 * Input1 	: copy_enPeripheralID			: The ID of that specific peripheral		: PREI_USBFS -> PREI_WWDG
 * Return 	: Error Status of function
 */
ErrorStatus RCC_voidEnablePeripheralClk(PERI_t copy_enPeripheralID);

/* 
 * Function	: RCC_voidDisablePeripheralClk	: Disables the clock for a certain peripheral
 * Input1 	: copy_enPeripheralID			: The ID of that specific peripheral		: PREI_USBFS -> PREI_WWDG
 * Return 	: Error Status of function
 */
ErrorStatus RCC_voidDisablePeripheralClk(PERI_t copy_enPeripheralID);

#endif /*RCC_INTERFACE_H_*/