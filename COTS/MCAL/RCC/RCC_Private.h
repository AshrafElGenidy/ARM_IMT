/************************************************************************/
/* SWC			: RCC Driver											*/
/* Author		: Ashraf Ehab											*/
/* Version		: V1.0													*/
/* Date			: 24 Aug 2023											*/
/* Description	: SWC for Reset and Control Clock						*/
/************************************************************************/
#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

#include "RCC_Interface.h"
#include "RCC_Config.h"

/*Segments*/
#define RCC			(((volatile u32*)0x40023800))
/*Registers*/
#define CR					(0u)
#define PLLCFGR				(1u)
#define CFGR				(2u)
#define CIR					(3u)
#define AHB1RSTR			(4u)
#define AHB2RSTR			(5u)
#define APB1RSTR			(8u)
#define APB2RSTR			(9u)
#define AHB1ENR				(12u)
#define AHB2ENR				(13u)
#define APB1ENR				(16u)
#define APB2ENR				(17u)
#define AHB1LPENR			(20u)
#define AHB2LPENR			(21u)
#define APB1LPENR			(24u)
#define APB2LPENR			(25u)
#define BDCR				(28u)
#define CSR					(29u)
#define SSCGR				(32u)
#define PLLI2SCFGR			(33u)
#define DCKCFGR				(35u)
/*Bits*/
/*RCC_CR*/
#define HSION				(0u)
#define HSIRDY				(1u)
#define HSEON				(16u)
#define HSERDY				(17u)
#define HSEBYP				(18u)
#define PLLON				(24u)
#define PLLRDY				(25u)
/*RCC_PLLCFGR*/     
#define PLLM0				(0u)
#define PLLN0				(6u)
#define PLLP0				(16u)
#define PLLSRC				(22u)
#define PLLQ0				(24u)
/*RCC_CFGR*/        
#define SW0					(0u)
#define SW1					(1u)
#define HPRE				(4u)
#define PPRE1				(10u)
#define PPRE2				(13u)
/*RCC_AHB1ENR*/
#define GPIOAEN				(0u)
#define GPIOBEN				(1u)
#define GPIOCEN				(2u)
#define CRCEN				(12u)
#define DMA1EN				(21u)
#define DMA2EN				(22u)
/*RCC_AHB2LENR*/
#define OTGFSEN				(7u)
/*RCC_APB1ENR*/
#define TIM2EN				(0u)
#define TIM3EN				(1u)
#define TIM4EN				(2u)
#define TIM5EN				(3u)
#define WWDGEN				(11u)
#define SPI2EN				(14u)
#define SPI3EN				(15u)
#define USART2EN			(17u)
#define I2C1EN				(21u)
#define I2C2EN				(22u)
#define I2C3EN				(23u)
#define PWREN				(28u)
/*RCC_APB2ENR*/
#define TIM1EN				(0u)
#define USART1EN			(4u)
#define USART6EN			(5u)
#define ADC1EN				(8u)
#define SDIOEN				(11u)
#define SPI1EN				(12u)
#define SPI4EN				(13u)
#define SYSCFGEN			(14u)
#define TIM9EN				(16u)
#define TIM10EN				(17u)
#define TIM11EN				(18u)
/*__________________________________________________________________________________________________________________________________________*/

/*Clocks in RCC*/
#define RCC_HSI				(1u)
#define RCC_HSE				(2u)
#define RCC_PLL				(3u)
/*Prescalar options*/
/*AHB*/
#define PRE_SYSCLK_1		(7u)
#define PRE_SYSCLK_2		(8u)
#define PRE_SYSCLK_4		(9u)
#define PRE_SYSCLK_8		(10u)
#define PRE_SYSCLK_16		(11u)
#define PRE_SYSCLK_64		(12u)
#define PRE_SYSCLK_128		(13u)
#define PRE_SYSCLK_256		(14u)
#define PRE_SYSCLK_512		(15u)
/*APB*/
#define PRE_AHB_1			(3u)
#define PRE_AHB_2			(4u)
#define PRE_AHB_4			(5u)
#define PRE_AHB_8			(6u)
#define PRE_AHB_16			(7u)
/*__________________________________________________________________________________________________________________________________________*/

#define RCC_PLLCFGR_EMPTY		(0x20000000)
#define RCC_CFGR_EMPTY			(0x00000000)
#define RCC_PLL_P_REG_VAL		((RCC_PLL_P - 2) >> 1)
/*__________________________________________________________________________________________________________________________________________*/

/*Checking if configuration options are done correctly*/
#if RCC_PLL_M < 2 || RCC_PLL_M > 63
    #error 'RCC_PLL_M' must in the range 2 <= M <= 63
#endif

#if RCC_PLL_N < 192 || RCC_PLL_N > 432
    #error 'RCC_PLL_N' must in the range 192 <= N <= 432
#endif

#if RCC_PLL_Q < 2 || RCC_PLL_Q > 15
    #error 'RCC_PLL_Q' must in the range 2 <= Q <= 15
#endif

#if (RCC_PLL_P != 2) && (RCC_PLL_P != 4) && (RCC_PLL_P != 6) && (RCC_PLL_P != 8)
    #error 'RCC_PLL_P' can only be 2, 4, 6 or 8
#endif

#if (RCC_HSE_BYPASSED != TRUE) && (RCC_HSE_BYPASSED != FALSE)
    #error 'RCC_HSE_BYPASSED' can only be 'TRUE' or 'FALSE'
#endif

#if RCC_AHB_PRESCALAR < PRE_SYSCLK_1 || RCC_AHB_PRESCALAR > PRE_SYSCLK_512
    #error 'RCC_AHB_PRESCALAR' must in the range 'PRE_SYSCLK_1' <= 'RCC_AHB_PRESCALAR' <= 'PRE_SYSCLK_512'
#endif

#if RCC_APB1_PRESCALAR < PRE_AHB_1 || RCC_APB1_PRESCALAR > PRE_AHB_16
    #error 'RCC_APB1_PRESCALAR' must in the range 'PRE_AHB_1' <= 'RCC_APB1_PRESCALAR' <= 'PRE_AHB_16'
#endif

#if RCC_APB2_PRESCALAR < PRE_AHB_1 || RCC_APB2_PRESCALAR > PRE_AHB_16
    #error 'RCC_APB2_PRESCALAR' must in the range 'PRE_AHB_1' <= 'RCC_APB2_PRESCALAR' <= 'PRE_AHB_16'
#endif

#endif /*RCC_PRIVATE_H_*/