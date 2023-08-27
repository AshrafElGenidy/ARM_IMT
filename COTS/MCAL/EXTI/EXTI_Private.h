/************************************************************************/
/* SWC			: EXTI Driver											*/
/* Author		: Ashraf Ehab											*/
/* Version		: V1.0													*/
/* Date			: 25 Aug 2023											*/
/* Description	: SWC for External Hardware Interrupts					*/
/************************************************************************/
#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#include "EXTI_Interface.h"
#include "EXTI_Config.h"

/*Registers*/
#define EXTI_IMR		(*(volatile u32*)0x40013C00)
#define EXTI_EMR		(*(volatile u32*)0x40013C04)
#define EXTI_RTSR		(*(volatile u32*)0x40013C08)
#define EXTI_FTSR		(*(volatile u32*)0x40013C0C)
#define EXTI_SWIER		(*(volatile u32*)0x40013C10)
#define EXTI_PR			(*(volatile u32*)0x40013C14)

/*__________________________________________________________________________________________________________________________________________*/

/*Private Global Variables Definitions*/
static void (* Globptr_vdCallbackFunction[16])(void) = {NULL};

#endif  /*EXTI_PRIVATE_H_*/