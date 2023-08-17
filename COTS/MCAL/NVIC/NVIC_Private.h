/************************************************************************/
/* SWC  	    : NVIC Driver                                           */
/* Author	    : Ashraf Ehab                                           */
/* Version	    : V1.0                                                  */
/* Date 	    : 12 Aug 2023                                           */
/* Description  : SWC for Nested Vectored Interrupt Controller          */
/************************************************************************/
#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

#include "NVIC_Interface.h"
#include "NVIC_Config.h"

/*Registers and Bits*/

typedef struct 
{
    volatile u32 ISER[32];
    volatile u32 ICER[32];
    volatile u32 ISPR[32];
    volatile u32 ICPR[32];
    volatile u32 IABR[64];
    volatile u32 IPR[32];
    volatile u32 STIR[32];
}NVIC_t;

#define NVIC       	((volatile NVIC_t*)0xE000EF00)

#define PRIGROUP 	(8u)

#define SCB_AIRCR	(*(volatile u32*)0xE000ED0C)
#define VECTKEY		(0x5FA0000)


#define GP16_SBP01		(3u)
#define GP08_SBP02		(4u)
#define GP04_SBP04		(5u)
#define GP02_SBP08		(6u)
#define GP01_SBP16		(7u)

#endif  /*NVIC_PRIVATE_H_*/