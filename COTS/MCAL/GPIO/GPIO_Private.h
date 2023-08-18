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

#define MODER               (0u)
#define OTYPER              (1u)
#define OSPEEDR             (2u)
#define PUPDR               (3u)
#define IDR                 (4u)
#define ODR                 (5u)
#define BSRR                (6u)
#define LCKR                (7u)
#define AFRL                (8u)
#define AFRH                (9u)

#endif  /*GPIO_PRIVATE_H_*/