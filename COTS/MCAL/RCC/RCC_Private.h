/************************************************************************/
/* SWC  	    : RCC Driver                                            */
/* Author	    : Ashraf Ehab                                           */
/* Version	    : V1.0                                                  */
/* Date 	    : 21 Jul 2023                                           */
/* Description  : SWC for Reset and Control Clock                       */
/************************************************************************/
#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/************************************************************************/
#include "RCC_Interface.h"
#include "RCC_Config.h"
/************************************************************************/

/*Segments, Registers and Bits*/
#define RCC_SEGMENT             (*((volatile u32*)0x40023800))

#define RCC_CR                  (*((volatile u32*)0x40023800))
#define RCC_PLLCFGR             (*((volatile u32*)0x40023804))
#define RCC_CFGR                (*((volatile u32*)0x40023808))
#define RCC_CIR                 (*((volatile u32*)0x4002380C))
#define RCC_AHB1RSTR            (*((volatile u32*)0x40023810))
#define RCC_AHB2RSTR            (*((volatile u32*)0x40023814))
#define RCC_APB1RSTR            (*((volatile u32*)0x40023820))
#define RCC_APB2RSTR            (*((volatile u32*)0x40023824))
#define RCC_AHB1ENR             (*((volatile u32*)0x40023830))
#define RCC_AHB2ENR             (*((volatile u32*)0x40023834))
#define RCC_APB1ENR             (*((volatile u32*)0x40023840))
#define RCC_APB2ENR             (*((volatile u32*)0x40023844))
#define RCC_AHB1LPENR           (*((volatile u32*)0x40023850))
#define RCC_AHB2LPENR           (*((volatile u32*)0x40023854))
#define RCC_APB1LPENR           (*((volatile u32*)0x40023860))
#define RCC_APB2LPENR           (*((volatile u32*)0x40023864))
#define RCC_BDCR                (*((volatile u32*)0x40023870))
#define RCC_CSR                 (*((volatile u32*)0x40023874))
#define RCC_SSCGR               (*((volatile u32*)0x40023880))
#define RCC_PLLI2SCFGR          (*((volatile u32*)0x40023884))
#define RCC_DCKCFGR             (*((volatile u32*)0x4002388C))

/*RCC_CR*/
#define RCC_CR_HSION                (0u)
#define RCC_CR_HSIRDY               (1u)
#define RCC_CR_HSEON                (16u)
#define RCC_CR_HSERDY               (17u)
#define RCC_CR_HSEBYP               (18u)
#define RCC_CR_PLLON                (24u)
#define RCC_CR_PLLRDY               (25u)
/*RCC_PLLCFGR*/     
#define RCC_PLLCFGR_PLLM0           (0u)
#define RCC_PLLCFGR_PLLN0           (6u)
#define RCC_PLLCFGR_PLLP0           (16u)
#define RCC_PLLCFGR_PLLSRC          (22u)
#define RCC_PLLCFGR_PLLQ0           (24u)
/*RCC_CFGR*/        
#define RCC_CFGR_SW0                (0u)
#define RCC_CFGR_SW1                (1u)
#define RCC_CFGR_HPRE               (4u)
#define RCC_CFGR_PPRE1              (10u)
#define RCC_CFGR_PPRE2              (13u)
/*RCC_AHB1ENR*/
#define RCC_AHB1ENR_GPIOAEN         (0u)
#define RCC_AHB1ENR_GPIOBEN         (1u)
#define RCC_AHB1ENR_GPIOCEN         (2u)
#define RCC_AHB1ENR_CRCEN           (12u)
#define RCC_AHB1ENR_DMA1EN          (21u)
#define RCC_AHB1ENR_DMA2EN          (22u)
/*RCC_AHB2LENR*/
#define RCC_AHB2ENR_OTGFSEN         (7u)
/*RCC_APB1ENR*/
#define RCC_APB1ENR_TIM2EN          (0u)
#define RCC_APB1ENR_TIM3EN          (1u)
#define RCC_APB1ENR_TIM4EN          (2u)
#define RCC_APB1ENR_TIM5EN          (3u)
#define RCC_APB1ENR_WWDGEN          (11u)
#define RCC_APB1ENR_SPI2EN          (14u)
#define RCC_APB1ENR_SPI3EN          (15u)
#define RCC_APB1ENR_USART2EN        (17u)
#define RCC_APB1ENR_I2C1EN          (21u)
#define RCC_APB1ENR_I2C2EN          (22u)
#define RCC_APB1ENR_I2C3EN          (23u)
#define RCC_APB1ENR_PWREN           (28u)
/*RCC_APB2ENR*/
#define RCC_APB2ENR_TIM1EN          (0u)
#define RCC_APB2ENR_USART1EN        (4u)
#define RCC_APB2ENR_USART6EN        (5u)
#define RCC_APB2ENR_ADC1EN          (8u)
#define RCC_APB2ENR_SDIOEN          (11u)
#define RCC_APB2ENR_SPI1EN          (12u)
#define RCC_APB2ENR_SPI4EN          (13u)
#define RCC_APB2ENR_SYSCFGEN        (14u)
#define RCC_APB2ENR_TIM9EN          (16u)
#define RCC_APB2ENR_TIM10EN         (17u)
#define RCC_APB2ENR_TIM11EN         (18u)
/************************************************************************/

/*Configuration options*/
/*Clocks in RCC*/
#define RCC_HSI         (1u)
#define RCC_HSE         (2u)
#define RCC_PLL         (3u)

/*Prescalar options*/
/*AHB*/
#define PRE_SYSCLK_1        (7u)
#define PRE_SYSCLK_2        (8u)
#define PRE_SYSCLK_4        (9u)
#define PRE_SYSCLK_8        (10u)
#define PRE_SYSCLK_16       (11u)
#define PRE_SYSCLK_64       (12u)
#define PRE_SYSCLK_128      (13u)
#define PRE_SYSCLK_256      (14u)
#define PRE_SYSCLK_512      (15u)
/*APB*/
#define PRE_AHB_1           (3u)
#define PRE_AHB_2           (4u)
#define PRE_AHB_4           (5u)
#define PRE_AHB_8           (6u)
#define PRE_AHB_16          (7u)
/************************************************************************/

/*Useful Macros*/
#define RCC_PLLCFGR_EMPTY   (0x20000000)
#define RCC_CFGR_EMPTY      (0x00000000)
#define RCC_PLL_P_REG_VAL   ((RCC_PLL_P -2) >> 1)
/************************************************************************/

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
/************************************************************************/

#endif /*RCC_PRIVATE_H_*/