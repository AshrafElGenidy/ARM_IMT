/************************************************************************/
/* SWC  	    : RCC Driver                                            */
/* Author	    : Ashraf Ehab                                           */
/* Version	    : V1.0                                                  */
/* Date 	    : 21 Jul 2023                                           */
/* Description  : SWC for Reset and Control Clock                       */
/************************************************************************/
#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_


#define RCC_SYSCLK_SRC     RCC_HSI              /*System CLK Source --- options: RCC_HSI, RCC_HSE, RCC_PLL*/

/*HSE Configurations*/
#define RCC_HSE_BYPASSED    TRUE                /*HSE oscillator bypassed with an external clock --- options: TRUE, FALSE*/

/************************************ PLL Configurations -- Calculating PLL frequency ************************************************
 * IMPORTANT :- User must check these values in their own system and ensure all the ranges below are met or the module will not work properly
 * PLL Input Frequency = Frecuency of PLL input source      (chosen in RCC_PLL_SRC) 
 * VCO input frequency = PLL input clock frequency / PLLM   (ensure that VCO input frequency ranges from 1 to 2 MHz. It is recommended to select a frequency of 2 MHz to limit PLL jitter)
 * VCO output frequency = VCO input frequency × PLLN        (ensure that VCO output frequency ranges from 192 to 432 MHz)
 * PLL output frequency = VCO frequency / PLLP              (ensure that PLL output clock frequency does not exceed 84 MHz)
 * USB OTG FS clock frequency = VCO frequency / PLLQ        (ensure that USB OTG FS clock frequency does not exceed 48 MHz) */
    #define RCC_PLL_SRC         RCC_HSI             /*PLL input source --- options: RCC_HSI, RCC_HSE*/
    #define RCC_PLL_M           50                  /*PLL M value --- options:   2 ≤ M ≤ 63  */
    #define RCC_PLL_N           200                 /*PLL N Value --- options: 192 ≤ N ≤ 432 */
    #define RCC_PLL_Q           2                   /*PLL Q Value --- options:   2 ≤ Q ≤ 15 */
    #define RCC_PLL_P           2                   /*PLL P Value --- options:   2,4,6,8 */
/***********************************************************************************************************************************/

/*Prescalar configurations*/
#define RCC_AHB_PRESCALAR       PRE_SYSCLK_1
#define RCC_APB1_PRESCALAR      PRE_AHB_1
#define RCC_APB2_PRESCALAR      PRE_AHB_1

#endif /*RCC_CONFIG_H_*/