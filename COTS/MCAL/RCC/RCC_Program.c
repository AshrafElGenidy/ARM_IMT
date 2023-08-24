/************************************************************************/
/* SWC  	    : RCC Driver											*/
/* Author	    : Ashraf Ehab											*/
/* Version	    : V1.0													*/
/* Date 	    : 24 Aug 2023											*/
/* Description  : SWC for Reset and Control Clock						*/
/************************************************************************/

#include "RCC_Private.h"

/* 
 * Function	: RCC_voidInitSysClk			: Initiates the clock for the micro-controller according to configurations in RCC_Config
 */
void RCC_voidInitSysClk(void)
{
    /*Setting Prescalars for the busses*/
    RCC[CFGR] = RCC_CFGR_EMPTY | (RCC_AHB_PRESCALAR << HPRE) | (RCC_APB1_PRESCALAR << PPRE1) | (RCC_APB2_PRESCALAR << PPRE2);

    #if RCC_SYSCLK_SRC == RCC_HSI
        SET_BIT(RCC[CR], HSION);      /*Turn on HSI*/
        while (!GET_BIT(RCC[CR], HSIRDY))
        {
            /*Wait for HSI to turn on*/
        }
        /*Select HSI as SYSCLK*/
        CLR_BIT(RCC[CFGR], SW0);
        CLR_BIT(RCC[CFGR], SW1);

    #elif RCC_SYSCLK_SRC == RCC_HSE
        SET_BIT(RCC[CR], HSEON);      /*Turn on HSE*/
        MAKE_BIT(RCC[CR], HSEBYP, RCC_HSE_BYPASSED);  /*Determine whether the HSE oscillator bypassed with an external clock*/
        while (!GET_BIT(RCC[CR], HSERDY))
        {
            /*Wait for HSE to turn on*/
        }
        /*Select HSE as SYSCLK*/
        SET_BIT(RCC[CFGR], SW0);
        CLR_BIT(RCC[CFGR], SW1);

    #elif RCC_SYSCLK_SRC == RCC_PLL
        CLR_BIT(RCC[CR], PLLON);   /*Turn off PLL before configuring*/
        /*Configure PLL variables*/
        RCC[PLLCFGR] = RCC_PLLCFGR_EMPTY | (RCC_PLL_M << PLLM0) | (RCC_PLL_N << PLLN0) | (RCC_PLL_P_REG_VAL << PLLP0) | (RCC_PLL_Q << PLLQ0);
        #if RCC_PLL_SRC == RCC_HSI
            SET_BIT(RCC[CR], HSION);      /*Turn on HSI*/
            while (!GET_BIT(RCC[CR], HSIRDY))
            {
                /*Wait for HSI to turn on*/
            }
            /*Select HSI as PLL source*/
            CLR_BIT(RCC[PLLCFGR], PLLSRC);

        #elif RCC_PLL_SRC == RCC_HSE
            SET_BIT(RCC[CR], HSEON);      /*Turn on HSE*/
            MAKE_BIT(RCC[CR], HSEBYP, RCC_HSE_BYPASSED);  /*Determine whether the HSE oscillator bypassed with an external clock*/
            while (!GET_BIT(RCC[CR], HSERDY))
            {
                /*Wait for HSE to turn on*/
            }
            /*Select HSE as PLL source*/
            SET_BIT(RCC[PLLCFGR], PLLSRC);

        #else
            #error 'RCC_PLL_SRC' can only be 'RCC_HSI' or 'RCC_HSE'
        #endif
        SET_BIT(RCC[CR], PLLON);       /*Turn on PLL*/
        while (!GET_BIT(RCC[CR], PLLRDY))
        {
            /*Wait for PLL to turn on*/
        }
        /*Select PLL as SYSCLK*/
        CLR_BIT(RCC[CFGR], SW0);
        SET_BIT(RCC[CFGR], SW1);

    #else
        #error 'RCC_SYSCLK_SRC' can only be 'RCC_HSI' or 'RCC_HSE' or 'RCC_PLL'
    #endif
}


/* 
 * Function	: RCC_voidEnablePeripheralClk	: Enables the clock for a certain peripheral
 * Input1 	: copy_enPeripheralID			: The ID of that specific peripheral		: PREI_USBFS -> PREI_WWDG
 * Return 	: Error Status of function
 */
ErrorStatus RCC_voidEnablePeripheralClk(PERI_t copy_enPeripheralID)
{
    switch (copy_enPeripheralID)
    {
    case USBFS:			SET_BIT(RCC[AHB2ENR], OTGFSEN);			break;
    case DMA1:			SET_BIT(RCC[AHB1ENR], DMA1EN);			break;
    case DMA2:			SET_BIT(RCC[AHB1ENR], DMA2EN);			break;
    case CRC:			SET_BIT(RCC[AHB1ENR], CRCEN);			break;
    case GPIOA:			SET_BIT(RCC[AHB1ENR], GPIOAEN);			break;
    case GPIOB:			SET_BIT(RCC[AHB1ENR], GPIOBEN);			break;
    case GPIOC:			SET_BIT(RCC[AHB1ENR], GPIOCEN);			break;
    case TIM1:			SET_BIT(RCC[APB2ENR], TIM1EN);			break;
    case TIM2:			SET_BIT(RCC[APB1ENR], TIM2EN);			break;
    case TIM3:			SET_BIT(RCC[APB1ENR], TIM3EN);			break;
    case TIM4:			SET_BIT(RCC[APB1ENR], TIM4EN);			break;
    case TIM5:			SET_BIT(RCC[APB1ENR], TIM5EN);			break;
    case TIM9:			SET_BIT(RCC[APB2ENR], TIM9EN);			break;
    case TIM10:			SET_BIT(RCC[APB2ENR], TIM10EN);			break;
    case TIM11:			SET_BIT(RCC[APB2ENR], TIM11EN);			break;
    case SYSCFG:		SET_BIT(RCC[APB2ENR], SYSCFGEN);		break;
    case SPI1:			SET_BIT(RCC[APB2ENR], SPI1EN);			break;
    case SPI2:			SET_BIT(RCC[APB1ENR], SPI2EN);			break;
    case SPI3:			SET_BIT(RCC[APB1ENR], SPI3EN);			break;
    case SPI4:			SET_BIT(RCC[APB2ENR], SPI4EN);			break;
    case SDIO:			SET_BIT(RCC[APB2ENR], SDIOEN);			break;
    case ADC1:			SET_BIT(RCC[APB2ENR], ADC1EN);			break;
    case USART1:		SET_BIT(RCC[APB2ENR], USART1EN);		break;
    case USART2:		SET_BIT(RCC[APB1ENR], USART2EN);		break;
    case USART6:		SET_BIT(RCC[APB2ENR], USART6EN);		break;
    case PWR:			SET_BIT(RCC[APB1ENR], PWREN);			break;
    case I2C1:			SET_BIT(RCC[APB1ENR], I2C1EN);			break;
    case I2C2:			SET_BIT(RCC[APB1ENR], I2C2EN);			break;
    case I2C3:			SET_BIT(RCC[APB1ENR], I2C3EN);			break;
    case WWDG:			SET_BIT(RCC[APB1ENR], WWDGEN);			break;
    default:			return INVALID_PARAMETERS;
    }
    return NO_ERROR;
}

/* 
 * Function	: RCC_voidDisablePeripheralClk	: Disables the clock for a certain peripheral
 * Input1 	: copy_enPeripheralID			: The ID of that specific peripheral		: PREI_USBFS -> PREI_WWDG
 * Return 	: Error Status of function
 */
ErrorStatus RCC_voidDisablePeripheralClk(PERI_t copy_enPeripheralID)
{
    switch (copy_enPeripheralID)
    {
    case USBFS:			CLR_BIT(RCC[AHB2ENR], OTGFSEN);			break;
    case DMA1:			CLR_BIT(RCC[AHB1ENR], DMA1EN);			break;
    case DMA2:			CLR_BIT(RCC[AHB1ENR], DMA2EN);			break;
    case CRC:			CLR_BIT(RCC[AHB1ENR], CRCEN);			break;
    case GPIOA:			CLR_BIT(RCC[AHB1ENR], GPIOAEN);			break;
    case GPIOB:			CLR_BIT(RCC[AHB1ENR], GPIOBEN);			break;
    case GPIOC:			CLR_BIT(RCC[AHB1ENR], GPIOCEN);			break;
    case TIM1:			CLR_BIT(RCC[APB2ENR], TIM1EN);			break;
    case TIM2:			CLR_BIT(RCC[APB1ENR], TIM2EN);			break;
    case TIM3:			CLR_BIT(RCC[APB1ENR], TIM3EN);			break;
    case TIM4:			CLR_BIT(RCC[APB1ENR], TIM4EN);			break;
    case TIM5:			CLR_BIT(RCC[APB1ENR], TIM5EN);			break;
    case TIM9:			CLR_BIT(RCC[APB2ENR], TIM9EN);			break;
    case TIM10:			CLR_BIT(RCC[APB2ENR], TIM10EN);			break;
    case TIM11:			CLR_BIT(RCC[APB2ENR], TIM11EN);			break;
    case SYSCFG:		CLR_BIT(RCC[APB2ENR], SYSCFGEN);		break;
    case SPI1:			CLR_BIT(RCC[APB2ENR], SPI1EN);			break;
    case SPI2:			CLR_BIT(RCC[APB1ENR], SPI2EN);			break;
    case SPI3:			CLR_BIT(RCC[APB1ENR], SPI3EN);			break;
    case SPI4:			CLR_BIT(RCC[APB2ENR], SPI4EN);			break;
    case SDIO:			CLR_BIT(RCC[APB2ENR], SDIOEN);			break;
    case ADC1:			CLR_BIT(RCC[APB2ENR], ADC1EN);			break;
    case USART1:		CLR_BIT(RCC[APB2ENR], USART1EN);		break;
    case USART2:		CLR_BIT(RCC[APB1ENR], USART2EN);		break;
    case USART6:		CLR_BIT(RCC[APB2ENR], USART6EN);		break;
    case PWR:			CLR_BIT(RCC[APB1ENR], PWREN);			break;
    case I2C1:			CLR_BIT(RCC[APB1ENR], I2C1EN);			break;
    case I2C2:			CLR_BIT(RCC[APB1ENR], I2C2EN);			break;
    case I2C3:			CLR_BIT(RCC[APB1ENR], I2C3EN);			break;
    case WWDG:			CLR_BIT(RCC[APB1ENR], WWDGEN);			break;
    default:			return INVALID_PARAMETERS;
    }
    return NO_ERROR;
}