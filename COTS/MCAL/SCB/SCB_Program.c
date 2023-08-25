/************************************************************************/
/* SWC			: SCB Driver											*/
/* Author		: Ashraf Ehab											*/
/* Version		: V1.0													*/
/* Date			: 25 Aug 2023											*/
/* Description	: SWC for System Control Block							*/
/************************************************************************/
#include "SCB_Private.h"

/* 
 * Function	: SCB_Init	: Initiates the SCB Module
 */
void SCB_Init(void)
{
	/*Set Group Priority Type according to MCU_Config*/
	SCB_AIRCR = VECTKEY | ((INTERRUPT_PRIORITY_TYPE + 3) << PRIGROUP);
}