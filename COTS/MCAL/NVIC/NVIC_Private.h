/************************************************************************/
/* SWC			: NVIC Driver											*/
/* Author		: Ashraf Ehab											*/
/* Version		: V1.0													*/
/* Date			: 24 Aug 2023											*/
/* Description	: SWC for Nested Vectored Interrupt Controller			*/
/************************************************************************/
#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

#include "NVIC_Interface.h"
#include "NVIC_Config.h"

#include "SCB_Interface.h"

/*Segments*/
#define NVIC       	((volatile NVIC_t*)0xE000EF00)
/*Registers*/
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

#endif  /*NVIC_PRIVATE_H_*/