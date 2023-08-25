/************************************************************************/
/* SWC  	    : GPIO Driver											*/
/* Author	    : Ashraf Ehab											*/
/* Version	    : V1.0													*/
/* Date 	    : 24 Aug 2023											*/
/* Description  : SWC for SysTick Timer									*/
/************************************************************************/

#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

#include "STK_Config.h"
#include "STK_Interface.h"

/*Registers*/
#define STK_CTRL			(*((volatile u32*)0xE000E010))
#define STK_LOAD			(*((volatile u32*)0xE000E014))
#define STK_VAL				(*((volatile u32*)0xE000E018))
#define STK_CALIB 			(*((volatile u32*)0xE000E01C))
/*Bits*/
/*STK_CTRL*/
#define STK_CTRL_ENABLE		(0u)
#define STK_CTRL_TICKINT	(1u)
#define STK_CTRL_CLKSOURCE	(2u)
#define STK_CTRL_COUNTFLAG	(16u)
/*__________________________________________________________________________________________________________________________________________*/

/*Configuration options*/
/*STK_CLK_SRC Options*/
#define SRC_AHB			(1u)
#define SRC_AHB_DIV_8	(2u)
/*Glob_u8IntervalFlag Options*/
#define INTERVAL_FLAG_SINGLE_MODE			(0u)
#define INTERVAL_FLAG_PERIODIC_MODE			(1u)
/*__________________________________________________________________________________________________________________________________________*/

static void (* Globptr_vdCallbackFunction)(void) = NULL;
static u8 Glob_u8IntervalFlag = INTERVAL_FLAG_SINGLE_MODE;
/*__________________________________________________________________________________________________________________________________________*/


#endif /*STK_PRIVATE_H*/
