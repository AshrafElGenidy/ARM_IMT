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
	c_USBFS,
	c_DMA1,
	c_DMA2,
	c_CRC,
	c_GPIOA,
	c_GPIOB,
	c_GPIOC,
	c_TIM1,
	c_TIM2,
	c_TIM3,
	c_TIM4,
	c_TIM5,
	c_TIM9,
	c_TIM10,
	c_TIM11,
	c_SYSCFG,
	c_SPI1,
	c_SPI2,
	c_SPI3,
	c_SPI4,
	c_SDIO,
	c_ADC1,
	c_USART1,
	c_USART2,
	c_USART6,
	c_PWR,
	c_I2C1,
	c_I2C2,
	c_I2C3,
	c_WWDG,
	NOT_A_PERIPHERAL_CLOCK
}PER_c_t;

/*__________________________________________________________________________________________________________________________________________*/

/* 
 * Function	: RCC_voidInitSysClk			: Initiates the clock for the micro-controller according to configurations in RCC_Config
 */
void RCC_voidInitSysClk(void);

/* 
 * Function	: RCC_voidEnablePeripheralClk	: Enables the clock for a certain peripheral
 * Input1 	: cpy_enPeripheralID			: The ID of that specific peripheral		: PREI_USBFS -> PREI_WWDG
 * Return 	: Error Status of function
 */
ErrorStatus RCC_voidEnablePeripheralClk(PER_c_t cpy_enPeripheralID);

/* 
 * Function	: RCC_voidDisablePeripheralClk	: Disables the clock for a certain peripheral
 * Input1 	: cpy_enPeripheralID			: The ID of that specific peripheral		: PREI_USBFS -> PREI_WWDG
 * Return 	: Error Status of function
 */
ErrorStatus RCC_voidDisablePeripheralClk(PER_c_t cpy_enPeripheralID);

#endif /*RCC_INTERFACE_H_*/