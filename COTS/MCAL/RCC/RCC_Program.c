/************************************************************************/
/* SWC  	    : RCC Driver                                            */
/* Author	    : Ashraf Ehab                                           */
/* Version	    : V1.0                                                  */
/* Date 	    : 21 Jul 2023                                           */
/* Description  : SWC for Reset and Control Clock                       */
/************************************************************************/

#include "RCC_Private.h"

void RCC_voidInitSysClk(void)
{
    /*Setting Prescalars for the busses*/
    RCC_CFGR = RCC_CFGR_EMPTY | (RCC_AHB_PRESCALAR << RCC_CFGR_HPRE) | (RCC_APB1_PRESCALAR << RCC_CFGR_PPRE1) | (RCC_APB2_PRESCALAR << RCC_CFGR_PPRE2);

    #if RCC_SYSCLK_SRC == RCC_HSI
        SET_BIT(RCC_CR, RCC_CR_HSION);      /*Turn on HSI*/
        while (!GET_BIT(RCC_CR, RCC_CR_HSIRDY))
        {
            /*Wait for HSI to turn on*/
        }
        /*Select HSI as SYSCLK*/
        CLR_BIT(RCC_CFGR, RCC_CFGR_SW0);
        CLR_BIT(RCC_CFGR, RCC_CFGR_SW1);

    #elif RCC_SYSCLK_SRC == RCC_HSE
        SET_BIT(RCC_CR, RCC_CR_HSEON);      /*Turn on HSE*/
        MAKE_BIT(RCC_CR, RCC_CR_HSEBYP, RCC_HSE_BYPASSED);  /*Determine whether the HSE oscillator bypassed with an external clock*/
        while (!GET_BIT(RCC_CR, RCC_CR_HSERDY))
        {
            /*Wait for HSE to turn on*/
        }
        /*Select HSE as SYSCLK*/
        SET_BIT(RCC_CFGR, RCC_CFGR_SW0);
        CLR_BIT(RCC_CFGR, RCC_CFGR_SW1);

    #elif RCC_SYSCLK_SRC == RCC_PLL
        CLR_BIT(RCC_CR,RCC_CR_PLLON);   /*Turn off PLL before configuring*/
        /*Configure PLL variables*/
        RCC_PLLCFGR = RCC_PLLCFGR_EMPTY | (RCC_PLL_M << RCC_PLLCFGR_PLLM0) | (RCC_PLL_N << RCC_PLLCFGR_PLLN0) | (RCC_PLL_P_REG_VAL << RCC_PLLCFGR_PLLP0) | (RCC_PLL_Q << RCC_PLLCFGR_PLLQ0);
        #if RCC_PLL_SRC == RCC_HSI
            SET_BIT(RCC_CR, RCC_CR_HSION);      /*Turn on HSI*/
            while (!GET_BIT(RCC_CR, RCC_CR_HSIRDY))
            {
                /*Wait for HSI to turn on*/
            }
            /*Select HSI as PLL source*/
            CLR_BIT(RCC_PLLCFGR, RCC_PLLCFGR_PLLSRC);

        #elif RCC_PLL_SRC == RCC_HSE
            SET_BIT(RCC_CR, RCC_CR_HSEON);      /*Turn on HSE*/
            MAKE_BIT(RCC_CR, RCC_CR_HSEBYP, RCC_HSE_BYPASSED);  /*Determine whether the HSE oscillator bypassed with an external clock*/
            while (!GET_BIT(RCC_CR, RCC_CR_HSERDY))
            {
                /*Wait for HSE to turn on*/
            }
            /*Select HSE as PLL source*/
            SET_BIT(RCC_PLLCFGR, RCC_PLLCFGR_PLLSRC);

        #else
            #error 'RCC_PLL_SRC' can only be 'RCC_HSI' or 'RCC_HSE'
        #endif
        SET_BIT(RCC_CR,RCC_CR_PLLON);       /*Turn on PLL*/
        while (!GET_BIT(RCC_CR, RCC_CR_PLLRDY))
        {
            /*Wait for PLL to turn on*/
        }
        /*Select PLL as SYSCLK*/
        CLR_BIT(RCC_CFGR, RCC_CFGR_SW0);
        SET_BIT(RCC_CFGR, RCC_CFGR_SW1);

    #else
        #error 'RCC_SYSCLK_SRC' can only be 'RCC_HSI' or 'RCC_HSE' or 'RCC_PLL'
    #endif
}


/* 
 * Function	: RCC_voidEnablePeripheralClk	: Enables the clock for a certain peripheral
 * Input1 	: Copy_u8PeripheralID	        : The ID of that specific peripheral		: PREI_USBFS -> PREI_WWDG
 * Return 	: ErrorStatus		            : Error Status of function
 */
ErrorStatus RCC_voidEnablePeripheralClk(u8 Copy_u8PeripheralID)
{
    switch (Copy_u8PeripheralID)
    {
    case PREI_USBFS:        SET_BIT(RCC_AHB2ENR, RCC_AHB2ENR_OTGFSEN);      break;
    case PREI_DMA1:         SET_BIT(RCC_AHB1ENR, RCC_AHB1ENR_DMA1EN);       break;
    case PREI_DMA2:         SET_BIT(RCC_AHB1ENR, RCC_AHB1ENR_DMA2EN);       break;
    case PREI_CRC:          SET_BIT(RCC_AHB1ENR, RCC_AHB1ENR_CRCEN);        break;
    case PREI_GPIOA :       SET_BIT(RCC_AHB1ENR, RCC_AHB1ENR_GPIOAEN);      break;
    case PREI_GPIOB :       SET_BIT(RCC_AHB1ENR, RCC_AHB1ENR_GPIOBEN);      break;
    case PREI_GPIOC :       SET_BIT(RCC_AHB1ENR, RCC_AHB1ENR_GPIOCEN);      break;
    case PREI_TIM1  :       SET_BIT(RCC_APB2ENR, RCC_APB2ENR_TIM1EN);       break;
    case PREI_TIM2  :       SET_BIT(RCC_APB1ENR, RCC_APB1ENR_TIM2EN);       break;
    case PREI_TIM3  :       SET_BIT(RCC_APB1ENR, RCC_APB1ENR_TIM3EN);       break;
    case PREI_TIM4  :       SET_BIT(RCC_APB1ENR, RCC_APB1ENR_TIM4EN);       break;
    case PREI_TIM5  :       SET_BIT(RCC_APB1ENR, RCC_APB1ENR_TIM5EN);       break;
    case PREI_TIM9  :       SET_BIT(RCC_APB2ENR, RCC_APB2ENR_TIM9EN);       break;
    case PREI_TIM10 :       SET_BIT(RCC_APB2ENR, RCC_APB2ENR_TIM10EN);      break;
    case PREI_TIM11 :       SET_BIT(RCC_APB2ENR, RCC_APB2ENR_TIM11EN);      break;
    case PREI_SYSCFG:       SET_BIT(RCC_APB2ENR, RCC_APB2ENR_SYSCFGEN);     break;
    case PREI_SPI1  :       SET_BIT(RCC_APB2ENR, RCC_APB2ENR_SPI1EN);       break;
    case PREI_SPI2  :       SET_BIT(RCC_APB1ENR, RCC_APB1ENR_SPI2EN);       break;
    case PREI_SPI3  :       SET_BIT(RCC_APB1ENR, RCC_APB1ENR_SPI3EN);       break;
    case PREI_SPI4  :       SET_BIT(RCC_APB2ENR, RCC_APB2ENR_SPI4EN);       break;
    case PREI_SDIO  :       SET_BIT(RCC_APB2ENR, RCC_APB2ENR_SDIOEN);       break;
    case PREI_ADC1  :       SET_BIT(RCC_APB2ENR, RCC_APB2ENR_ADC1EN);       break;
    case PREI_USART1:       SET_BIT(RCC_APB2ENR, RCC_APB2ENR_USART1EN);     break;
    case PREI_USART2:       SET_BIT(RCC_APB1ENR, RCC_APB1ENR_USART2EN);     break;
    case PREI_USART6:       SET_BIT(RCC_APB2ENR, RCC_APB2ENR_USART6EN);     break;
    case PREI_PWR   :       SET_BIT(RCC_APB1ENR, RCC_APB1ENR_PWREN);        break;
    case PREI_I2C1  :       SET_BIT(RCC_APB1ENR, RCC_APB1ENR_I2C1EN);       break;
    case PREI_I2C2  :       SET_BIT(RCC_APB1ENR, RCC_APB1ENR_I2C2EN);       break;
    case PREI_I2C3  :       SET_BIT(RCC_APB1ENR, RCC_APB1ENR_I2C3EN);       break;
    case PREI_WWDG  :       SET_BIT(RCC_APB1ENR, RCC_APB1ENR_WWDGEN);       break;
    default:                return INVALID_PARAMETERS;
    }
    return NO_ERROR;
}

/* 
 * Function	: RCC_voidDisablePeripheralClk	: Disables the clock for a certain peripheral
 * Input1 	: Copy_u8PeripheralID	        : The ID of that specific peripheral		: PREI_USBFS -> PREI_WWDG
 * Return 	: ErrorStatus		            : Error Status of function
 */
ErrorStatus RCC_voidDisablePeripheralClk(u8 Copy_u8PeripheralID)
{
    switch (Copy_u8PeripheralID)
    {
    case PREI_USBFS:        CLR_BIT(RCC_AHB2ENR, RCC_AHB2ENR_OTGFSEN);      break;
    case PREI_DMA1:         CLR_BIT(RCC_AHB1ENR, RCC_AHB1ENR_DMA1EN);       break;
    case PREI_DMA2:         CLR_BIT(RCC_AHB1ENR, RCC_AHB1ENR_DMA2EN);       break;
    case PREI_CRC:          CLR_BIT(RCC_AHB1ENR, RCC_AHB1ENR_CRCEN);        break;
    case PREI_GPIOA :       CLR_BIT(RCC_AHB1ENR, RCC_AHB1ENR_GPIOAEN);      break;
    case PREI_GPIOB :       CLR_BIT(RCC_AHB1ENR, RCC_AHB1ENR_GPIOBEN);      break;
    case PREI_GPIOC :       CLR_BIT(RCC_AHB1ENR, RCC_AHB1ENR_GPIOCEN);      break;
    case PREI_TIM1  :       CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_TIM1EN);       break;
    case PREI_TIM2  :       CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_TIM2EN);       break;
    case PREI_TIM3  :       CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_TIM3EN);       break;
    case PREI_TIM4  :       CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_TIM4EN);       break;
    case PREI_TIM5  :       CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_TIM5EN);       break;
    case PREI_TIM9  :       CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_TIM9EN);       break;
    case PREI_TIM10 :       CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_TIM10EN);      break;
    case PREI_TIM11 :       CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_TIM11EN);      break;
    case PREI_SYSCFG:       CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_SYSCFGEN);     break;
    case PREI_SPI1  :       CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_SPI1EN);       break;
    case PREI_SPI2  :       CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_SPI2EN);       break;
    case PREI_SPI3  :       CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_SPI3EN);       break;
    case PREI_SPI4  :       CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_SPI4EN);       break;
    case PREI_SDIO  :       CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_SDIOEN);       break;
    case PREI_ADC1  :       CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_ADC1EN);       break;
    case PREI_USART1:       CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_USART1EN);     break;
    case PREI_USART2:       CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_USART2EN);     break;
    case PREI_USART6:       CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_USART6EN);     break;
    case PREI_PWR   :       CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_PWREN);        break;
    case PREI_I2C1  :       CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_I2C1EN);       break;
    case PREI_I2C2  :       CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_I2C2EN);       break;
    case PREI_I2C3  :       CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_I2C3EN);       break;
    case PREI_WWDG  :       CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_WWDGEN);       break;
    default:                return INVALID_PARAMETERS;
    }
    return NO_ERROR;
}