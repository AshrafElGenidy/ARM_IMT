/************************************************************************/
/* SWC  	    : GPIO Driver                                           */
/* Author	    : Ashraf Ehab                                           */
/* Version	    : V1.0                                                  */
/* Date 	    : 28 Jul 2023                                           */
/* Description  : SWC for General Purpose Input/Output                  */
/************************************************************************/
#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

#include "GPIO_Interface.h"
#include "GPIO_Config.h"

/*Registers and Bits*/
#define GPIOA       ((volatile u32*)0x40020000)
#define GPIOB       ((volatile u32*)0x40020400)
#define GPIOC       ((volatile u32*)0x40020800)

#define MODER               0
#define OTYPER              1
#define OSPEEDR             2
#define PUPDR               3
#define IDR                 4
#define ODR                 5
#define BSRR                6
#define LCKR                7
#define AFRL                8
#define AFRH                9


#endif  /*GPIO_PRIVATE_H_*/