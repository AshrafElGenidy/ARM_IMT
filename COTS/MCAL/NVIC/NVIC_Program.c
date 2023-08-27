/************************************************************************/
/* SWC			: NVIC Driver											*/
/* Author		: Ashraf Ehab											*/
/* Version		: V1.0													*/
/* Date			: 24 Aug 2023											*/
/* Description	: SWC for Nested Vectored Interrupt Controller			*/
/************************************************************************/
#include "NVIC_Private.h"

/* 
 * Function	: NVIC_esEnablePerInt		: Enables the Interrupt response of NVIC for a certain peripheral
 * Input1 	: cpy_enPeripheralID		: The ID of that specific peripheral IRQ	: WWDG -> SPI4
 * Return 	: Error Status of function
 */
ErrorStatus NVIC_esEnablePerInt(IRQ_t cpy_enPeripheralID)
{
	if(NOT_An_IRQ <= cpy_enPeripheralID)
	{
		return INVALID_PARAMETERS;
	}
	NVIC->ISER[cpy_enPeripheralID >> 5] = 1 << (cpy_enPeripheralID%32);
	return NO_ERROR;
}

/* 
 * Function	: NVIC_esDisablePerInt		: Disables the Interrupt response of NVIC for a certain peripheral
 * Input1 	: cpy_enPeripheralID		: The ID of that specific peripheral IRQ	: WWDG -> SPI4
 * Return 	: Error Status of function
 */
ErrorStatus NVIC_esDisablePerInt(IRQ_t cpy_enPeripheralID)
{
	if(NOT_An_IRQ <= cpy_enPeripheralID)
	{
		return INVALID_PARAMETERS;
	}
	NVIC->ICER[cpy_enPeripheralID >> 5] = 1 << (cpy_enPeripheralID%32);
	return NO_ERROR;
}

/* 
 * Function	: NVIC_esSetPendingFlag		: Sets the NVIC Pending flag of a certain peripheral
 * Input1 	: cpy_enPeripheralID		: The ID of that specific peripheral IRQ	: WWDG -> SPI4
 * Return 	: Error Status of function
 */
ErrorStatus NVIC_esSetPendingFlag(IRQ_t cpy_enPeripheralID)
{
	if(NOT_An_IRQ <= cpy_enPeripheralID)
	{
		return INVALID_PARAMETERS;
	}
	NVIC->ISPR[cpy_enPeripheralID >> 5] = 1 << (cpy_enPeripheralID%32);
	return NO_ERROR;
}

/* 
 * Function	: NVIC_esClearPendingFlag	: Clears the NVIC Pending flag of a certain peripheral
 * Input1 	: cpy_enPeripheralID		: The ID of that specific peripheral IRQ	: WWDG -> SPI4
 * Return 	: Error Status of function
 */
ErrorStatus NVIC_esClearPendingFlag(IRQ_t cpy_enPeripheralID)
{
	if(NOT_An_IRQ <= cpy_enPeripheralID)
	{
		return INVALID_PARAMETERS;
	}
	NVIC->ICPR[cpy_enPeripheralID >> 5] = 1 << (cpy_enPeripheralID%32);
	return NO_ERROR;
}

/* 
 * Function	: NVIC_esSetPerPriority		: Sets the priority group and subgroup for a certain peripheral IRQ
 * Input1 	: cpy_enPeripheralID		: The ID of that specific peripheral IRQ	: WWDG -> SPI4
 * Input2 	: cpy_u8Group				: The desired group number for that IRQ		: 0 -> Max number of groups chosen in MCU_Config
 * Input3 	: cpy_u8SubGroup			: The desired sub-group number for that IRQ	: 0 -> Max number of sub-groups chosen in MCU_Config
 * Return 	: Error Status of function
 */
ErrorStatus NVIC_esSetPerPriority(IRQ_t cpy_enPeripheralID, u8 cpy_u8Group, u8 cpy_u8SubGroup)
{
	u8 Loc_u8Priority = 0;
	u8 Loc_u8BitRange = 0;
	if(NOT_An_IRQ <= cpy_enPeripheralID)
	{
		return INVALID_PARAMETERS;
	}
	#if GP16_SBP01 == INTERRUPT_PRIORITY_TYPE
	if((16 <= cpy_u8Group) || (0 < cpy_u8SubGroup))
	{
		return INVALID_PARAMETERS;
	}
	#elif GP08_SBP02 == INTERRUPT_PRIORITY_TYPE
	if((8 <= cpy_u8Group) || (2 <= cpy_u8SubGroup))
	{
		return INVALID_PARAMETERS;
	}
	#elif GP04_SBP04 == INTERRUPT_PRIORITY_TYPE
	if((4 <= cpy_u8Group) || (4 <= cpy_u8SubGroup))
	{
		return INVALID_PARAMETERS;
	}
	#elif GP02_SBP08 == INTERRUPT_PRIORITY_TYPE
	if((2 <= cpy_u8Group) || (8 <= cpy_u8SubGroup))
	{
		return INVALID_PARAMETERS;
	}
	#elif GP01_SBP16 == INTERRUPT_PRIORITY_TYPE
	if((0 < cpy_u8Group) || (16 <= cpy_u8SubGroup))
	{
		return INVALID_PARAMETERS;
	}
	#else 
		#error 'INTERRUPT_PRIORITY_TYPE' can only be 'GP16_SBP01','GP08_SBP02','GP04_SBP04','GP02_SBP08' or 'GP01_SBP16'
	#endif
	Loc_u8Priority = cpy_u8SubGroup | (cpy_u8Group << INTERRUPT_PRIORITY_TYPE);
	Loc_u8BitRange = (((cpy_enPeripheralID % 4) << 3) + 4);
	CLR_NIBBLE(NVIC->IPR[cpy_enPeripheralID >> 2], Loc_u8BitRange);
	NVIC->IPR[cpy_enPeripheralID >> 2] |= Loc_u8Priority << Loc_u8BitRange;
	return NO_ERROR;
}