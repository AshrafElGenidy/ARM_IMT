/************************************************************************/
/* SWC			: SYSCFG Driver											*/
/* Author		: Ashraf Ehab											*/
/* Version		: V1.0													*/
/* Date			: 25 Aug 2023											*/
/* Description	: SWC for System Configuration Controller				*/
/************************************************************************/
#include "SYSCFG_Private.h"

/* 
 * Function	: SYSCFG_Init				: Initializes the system to use the System Configuration Controller
 * Return 	: Error Status of function
 */
ErrorStatus SYSCFG_Init(void)
{
	return RCC_voidEnablePeripheralClk(c_SYSCFG);
}

/* 
 * Function	: SYSCFG_EXTI_PortSelection	: Chooses the Port that affects a certain Interrupt EXTI Line
 * Input1 	: cpy_u8IntLine				: The Line number to affect				: EXTI_LINE0 -> EXTI_LINE15
 * Input2 	: cpy_u8Port				: The port chosen for the operation		: EXTI_PORTA -> EXTI_PORTC
 * Return 	: Error Status of function
 */
ErrorStatus SYSCFG_EXTI_PortSelection(u8 cpy_u8IntLine, u8 cpy_u8Port)
{
	u8 Loc_u8BitRange = 0;
	if ((EXTI_PORTC < cpy_u8Port) || (EXTI_LINE15 < cpy_u8IntLine))
	{
		return INVALID_PARAMETERS;
	}
	Loc_u8BitRange = (cpy_u8IntLine % 4) << 2;
	CLR_NIBBLE(SYSCFG_EXTICR[cpy_u8IntLine >> 2], Loc_u8BitRange);
	SYSCFG_EXTICR[cpy_u8IntLine >> 2] |= cpy_u8Port << Loc_u8BitRange;
	return NO_ERROR;
}