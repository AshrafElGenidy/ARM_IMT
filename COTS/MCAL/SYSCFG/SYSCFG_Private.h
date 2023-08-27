/************************************************************************/
/* SWC			: SYSCFG Driver											*/
/* Author		: Ashraf Ehab											*/
/* Version		: V1.0													*/
/* Date			: 25 Aug 2023											*/
/* Description	: SWC for System Configuration Controller				*/
/************************************************************************/
#ifndef SYSCFG_PRIVATE_H_
#define SYSCFG_PRIVATE_H_

#include "SYSCFG_Interface.h"
#include "SYSCFG_Config.h"

#include "../RCC/RCC_Interface.h"

/*Registers*/
#define SYSCFG_EXTICR	((volatile u32*)0x40013808)

#endif  /*SYSCFG_PRIVATE_H_*/