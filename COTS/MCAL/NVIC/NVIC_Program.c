/************************************************************************/
/* SWC  	    : NVIC Driver                                           */
/* Author	    : Ashraf Ehab                                           */
/* Version	    : V1.0                                                  */
/* Date 	    : 12 Aug 2023                                           */
/* Description  : SWC for Nested Vectored Interrupt Controller          */
/************************************************************************/
#include "NVIC_Private.h"


void NVIC_esInit()
{
	SCB_AIRCR = VECTKEY | (PRIORITY_TYPE << PRIGROUP);
}

void NVIC_vdEnablePerInt(PER_t copy_enPerID)
{
	NVIC->ISER[copy_enPerID/32] = 1 << (copy_enPerID%32);
}

void NVIC_vdDisablePerInt(PER_t copy_enPerID)
{
	NVIC->ICER[copy_enPerID/32] = 1 << (copy_enPerID%32);
}

void NVIC_vdSetPendingFlag(PER_t copy_enPerID)
{
	NVIC->ISPR[copy_enPerID/32] = 1 << (copy_enPerID%32);
}

void NVIC_vdClearPendingFlag(PER_t copy_enPerID)
{
	NVIC->ICPR[copy_enPerID/32] = 1 << (copy_enPerID%32);
}

ErrorStatus NVIC_esSetPerPriority(PER_t copy_enPerID, u8 copy_u8Group, u8 copy_u8SubGroup)
{
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
	#endif
	u8 Loc_u8Priority = copy_u8SubGroup | (copy_u8Group << (PRIORITY_TYPE - 3));
	u8 Loc_u8BitRange = (((copy_enPerID%4)*8)+4);
	NVIC->IPR[copy_enPerID/4] &= ~(0b1111<<(Loc_u8BitRange));
	NVIC->IPR[copy_enPerID/4] |= Loc_u8Priority << Loc_u8BitRange;
	return NO_ERROR;
}