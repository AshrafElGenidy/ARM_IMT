/************************************************************************/
/* SWC  	    : NVIC Driver                                           */
/* Author	    : Ashraf Ehab                                           */
/* Version	    : V1.0                                                  */
/* Date 	    : 12 Aug 2023                                           */
/* Description  : SWC for Nested Vectored Interrupt Controller          */
/************************************************************************/
#include "NVIC_Private.h"


void NVIC_vdInit()
{
	SCB_Init();
}

ErrorStatus NVIC_esEnablePerInt(IRQn_t copy_enPerID)
{
	if(NOT_A_PERIPHERAL <= copy_enPerID)
	{
		return INVALID_PARAMETERS;
	}
	NVIC->ISER[copy_enPerID >> 5] = 1 << (copy_enPerID%32);
	return NO_ERROR;
}

ErrorStatus NVIC_esDisablePerInt(IRQn_t copy_enPerID)
{
	if(NOT_A_PERIPHERAL <= copy_enPerID)
	{
		return INVALID_PARAMETERS;
	}
	NVIC->ICER[copy_enPerID >> 5] = 1 << (copy_enPerID%32);
	return NO_ERROR;
}

ErrorStatus NVIC_esSetPendingFlag(IRQn_t copy_enPerID)
{
	if(NOT_A_PERIPHERAL <= copy_enPerID)
	{
		return INVALID_PARAMETERS;
	}
	NVIC->ISPR[copy_enPerID >> 5] = 1 << (copy_enPerID%32);
	return NO_ERROR;
}

ErrorStatus NVIC_esClearPendingFlag(IRQn_t copy_enPerID)
{
	if(NOT_A_PERIPHERAL <= copy_enPerID)
	{
		return INVALID_PARAMETERS;
	}
	NVIC->ICPR[copy_enPerID >> 5] = 1 << (copy_enPerID%32);
	return NO_ERROR;
}

ErrorStatus NVIC_esSetPerPriority(IRQn_t copy_enPerID, u8 copy_u8Group, u8 copy_u8SubGroup)
{
	u8 Loc_u8Priority = 0;
	u8 Loc_u8BitRange = 0;
	if(NOT_A_PERIPHERAL <= copy_enPerID)
	{
		return INVALID_PARAMETERS;
	}
	#if GP16_SBP01 == PRIORITY_TYPE
	if((16 <= copy_u8Group) || (0 < copy_u8SubGroup))
	{
		return INVALID_PARAMETERS;
	}
	#elif GP08_SBP02 == PRIORITY_TYPE
	if((8 <= copy_u8Group) || (2 <= copy_u8SubGroup))
	{
		return INVALID_PARAMETERS;
	}
	#elif GP04_SBP04 == PRIORITY_TYPE
	if((4 <= copy_u8Group) || (4 <= copy_u8SubGroup))
	{
		return INVALID_PARAMETERS;
	}
	#elif GP02_SBP08 == PRIORITY_TYPE
	if((2 <= copy_u8Group) || (8 <= copy_u8SubGroup))
	{
		return INVALID_PARAMETERS;
	}
	#elif GP01_SBP16 == PRIORITY_TYPE
	if((0 < copy_u8Group) || (16 <= copy_u8SubGroup))
	{
		return INVALID_PARAMETERS;
	}
	#else 
		#error 'PRIORITY_TYPE' can only be 'GP16_SBP01','GP08_SBP02','GP04_SBP04','GP02_SBP08' or 'GP01_SBP16'
	#endif
	Loc_u8Priority = copy_u8SubGroup | (copy_u8Group << PRIORITY_TYPE);
	Loc_u8BitRange = (((copy_enPerID % 4) << 3) + 4);
	CLR_NIBBLE(NVIC->IPR[copy_enPerID >> 2], Loc_u8BitRange);
	NVIC->IPR[copy_enPerID >> 2] |= Loc_u8Priority << Loc_u8BitRange;
	return NO_ERROR;
}