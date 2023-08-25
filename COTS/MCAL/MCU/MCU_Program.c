/********************************************************************************/
/* SWC			: MCU Driver													*/
/* Author		: Ashraf Ehab													*/
/* Version		: V1.0															*/
/* Date			: 24 Aug 2023													*/
/* Description	: SWC for Configuring and initiallizing the micro-controller	*/
/********************************************************************************/
#include "MCU_Interface.h"
#include "MCU_Config.h"
#include "MCU_Private.h"

#include "../RCC/RCC_Interface.h"
#include "../SCB/SCB_Interface.h"

/* 
 * Function	: MCU_Init 	: Initializes some system components for user convenience
 */
void MCU_Init(void)
{
	RCC_voidInitSysClk();
	SCB_Init();
}