/************************************************************************/
/* SWC			: SCB Driver											*/
/* Author		: Ashraf Ehab											*/
/* Version		: V1.0													*/
/* Date			: 25 Aug 2023											*/
/* Description	: SWC for System Control Block							*/
/************************************************************************/
#ifndef SCB_PRIVATE_H_
#define SCB_PRIVATE_H_

#include "SCB_Interface.h"
#include "SCB_Config.h"

/*Registers*/
#define SCB_AIRCR	(*(volatile u32*)0xE000ED0C)
/*Bits*/
#define PRIGROUP 	(8u)
/*__________________________________________________________________________________________________________________________________________*/

#define VECTKEY		(0x5FA0000)

#endif  /*SCB_PRIVATE_H_*/