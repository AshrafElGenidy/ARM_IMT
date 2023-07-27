/************************************************************************/
/* SWC  	    : RCC Driver                                            */
/* Author	    : Ashraf Ehab                                           */
/* Version	    : V1.0                                                  */
/* Date 	    : 21 Jul 2023                                           */
/* Description  : SWC for Reset and Control Clock                       */
/************************************************************************/
#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#include "../../Lib/STD_TYPES.h"
#include "../../Lib/BIT_MATH.h"
#include "../../Lib/MACROS.h"

/*Peripheral IDs*/
#define PREI_USBFS          (0u)
#define PREI_DMA1           (1u)
#define PREI_DMA2           (2u)
#define PREI_CRC            (3u)
#define PREI_GPIOA          (4u)
#define PREI_GPIOB          (5u)
#define PREI_GPIOC          (6u)
#define PREI_TIM1           (7u)
#define PREI_TIM2           (8u)
#define PREI_TIM3           (9u)
#define PREI_TIM4           (10u)
#define PREI_TIM5           (11u)
#define PREI_TIM9           (12u)
#define PREI_TIM10          (13u)
#define PREI_TIM11          (14u)
#define PREI_SYSCFG         (15u)
#define PREI_SPI1           (16u)
#define PREI_SPI2           (17u)
#define PREI_SPI3           (18u)
#define PREI_SPI4           (19u)
#define PREI_SDIO           (20u)
#define PREI_ADC1           (21u)
#define PREI_USART1         (22u)
#define PREI_USART2         (23u)
#define PREI_USART6         (24u)
#define PREI_PWR            (25u)
#define PREI_I2C1           (26u)
#define PREI_I2C2           (27u)
#define PREI_I2C3           (28u)
#define PREI_WWDG           (29u)


void RCC_voidInitSysClk(void);

/* 
 * Function	: RCC_voidEnablePeripheralClk	: Enables the clock for a certain peripheral
 * Input1 	: Copy_u8PeripheralID	        : The ID of that specific peripheral		: PREI_USBFS -> PREI_WWDG
 * Return 	: ErrorStatus		            : Error Status of function
 */
ErrorStatus RCC_voidEnablePeripheralClk(u8 Copy_u8PeripheralID);

/* 
 * Function	: RCC_voidDisablePeripheralClk	: Disables the clock for a certain peripheral
 * Input1 	: Copy_u8PeripheralID	        : The ID of that specific peripheral		: PREI_USBFS -> PREI_WWDG
 * Return 	: ErrorStatus		            : Error Status of function
 */
ErrorStatus RCC_voidDisablePeripheralClk(u8 Copy_u8PeripheralID);

#endif /*RCC_INTERFACE_H_*/