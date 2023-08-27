/************************************************************************/
/* SWC			: EXTI Driver											*/
/* Author		: Ashraf Ehab											*/
/* Version		: V1.0													*/
/* Date			: 25 Aug 2023											*/
/* Description	: SWC for External Hardware Interrupts					*/
/************************************************************************/
#include "EXTI_Private.h"

/* 
 * Function	: EXTI_EnableInt			: Enables one of the 16 EXTI lines
 * Input1 	: cpy_u8IntLine				: Number of EXTI line to enable						: EXTI0 -> EXTI15
 * Return 	: Error Status of function
 */
ErrorStatus EXTI_EnableInt(u8 cpy_u8IntLine)
{
	if(EXTI15 < cpy_u8IntLine)
	{
		return INVALID_PARAMETERS;
	}
	SET_BIT(EXTI_IMR,cpy_u8IntLine);		/*Enable corresponding interrupt*/
	return NO_ERROR;
}

/* 
 * Function	: EXTI_EdgeSelection		: Select the edge type that triggers a certain EXTI line
 * Input1 	: cpy_u8IntLine				: Number of EXTI line to set the edge trigger of	: EXTI0 -> EXTI15
 * Input2 	: cpy_u8EdgeSelection		: Pin n to set the mode of							: FALLING_EDGE_DETECTION  -> DUAL_EDGE_DETECTION
 * Return 	: Error Status of function
 */
ErrorStatus EXTI_EdgeSelection(u8 cpy_u8IntLine, u8 cpy_u8EdgeSelection)
{
	if(EXTI15 < cpy_u8IntLine)
	{
		return INVALID_PARAMETERS;
	}
	switch (cpy_u8EdgeSelection)
	{
	case FALLING_EDGE_DETECTION:	
		SET_BIT(EXTI_FTSR,cpy_u8IntLine);	
		CLR_BIT(EXTI_RTSR,cpy_u8IntLine);	
		break;
	case RISING_EDGE_DETECTION:		
		CLR_BIT(EXTI_FTSR,cpy_u8IntLine);	
		SET_BIT(EXTI_RTSR,cpy_u8IntLine);		
		break;
	case DUAL_EDGE_DETECTION:		
		SET_BIT(EXTI_FTSR,cpy_u8IntLine);
		SET_BIT(EXTI_RTSR,cpy_u8IntLine);		
		break;
	default:						return INVALID_PARAMETERS;
	}
	return NO_ERROR;
}


/* 
 * Function	: EXTI_SetCallBackFunction	: Sets the call back function to call after an EXTI line has been triggered
 * Input1 	: cpy_u8IntLine				: Number of EXTI line to set the function of		: EXTI0 -> EXTI15
 * Input2 	: inptr_vdCallbackFunction	: pointer to the user-defined call back function	: set to NULL to delete the pointer
 * Return 	: Error Status of function
 */
ErrorStatus EXTI_SetCallBackFunction(u8 cpy_u8IntLine, void (* inptr_vdCallbackFunction)(void))
{
	if(EXTI15 < cpy_u8IntLine)
	{
		return INVALID_PARAMETERS;
	}
	Globptr_vdCallbackFunction[cpy_u8IntLine] = inptr_vdCallbackFunction;		/*Save Call back function to corresponding pointer*/
	return NO_ERROR;
}


/* 
 * Function	: EXTI_EnableInt			: Disables one of the 16 EXTI lines
 * Input1 	: cpy_u8IntLine				: Number of EXTI line to disable					: EXTI0 -> EXTI15
 * Return 	: Error Status of function
 */
ErrorStatus EXTI_DisableInt(u8 cpy_u8IntLine)
{
	if(EXTI15 < cpy_u8IntLine)
	{
		return INVALID_PARAMETERS;
	}
	CLR_BIT(EXTI_IMR,cpy_u8IntLine);		/*Disable corresponding interrupt*/
	return NO_ERROR;
}
/*__________________________________________________________________________________________________________________________________________*/

/* 
 * Function		: EXTIn_IRQHandler			: Handler for EXTI Interrupts
 * Description	: This function calls the callback function defined by the user
 */
/*Interrupt Service Routines Defenitions*/
void EXTI0_IRQHandler(void)
{
	if (Globptr_vdCallbackFunction[0])
	{
		Globptr_vdCallbackFunction[0]();
	}

	SET_BIT(EXTI_PR,EXTI0);		/*Clear Pending Flag by writing 1 to it*/
}
void EXTI1_IRQHandler(void)
{
	if (Globptr_vdCallbackFunction[1])
	{
		Globptr_vdCallbackFunction[1]();
	}

	SET_BIT(EXTI_PR,EXTI1);		/*Clear Pending Flag by writing 1 to it*/
}
void EXTI2_IRQHandler(void)
{
	if (Globptr_vdCallbackFunction[2])
	{
		Globptr_vdCallbackFunction[2]();
	}

	SET_BIT(EXTI_PR,EXTI2);		/*Clear Pending Flag by writing 1 to it*/
}
void EXTI3_IRQHandler(void)
{
	if (Globptr_vdCallbackFunction[3])
	{
		Globptr_vdCallbackFunction[3]();
	}

	SET_BIT(EXTI_PR,EXTI3);		/*Clear Pending Flag by writing 1 to it*/
}
void EXTI4_IRQHandler(void)
{
	if (Globptr_vdCallbackFunction[4])
	{
		Globptr_vdCallbackFunction[4]();
	}

	SET_BIT(EXTI_PR,EXTI4);		/*Clear Pending Flag by writing 1 to it*/
}
void EXTI9_5_IRQHandler(void)
{
	for (u8 i = EXTI5; i <= EXTI9; i++)
	{
		if(GET_BIT(EXTI_IMR,i) && GET_BIT(EXTI_PR,i))
		{
			if (Globptr_vdCallbackFunction[i])
			{
				Globptr_vdCallbackFunction[i]();
			}
			SET_BIT(EXTI_PR,i);		/*Clear Pending Flag by writing 1 to it*/
		}
	}
}
void EXTI15_10_IRQHandler(void)
{
	for (u8 i = EXTI10; i <= EXTI15; i++)
	{
		if(GET_BIT(EXTI_IMR,i) && GET_BIT(EXTI_PR,i))
		{
			if (Globptr_vdCallbackFunction[i])
			{
				Globptr_vdCallbackFunction[i]();
			}
			SET_BIT(EXTI_PR,i);		/*Clear Pending Flag by writing 1 to it*/
		}
	}
}
