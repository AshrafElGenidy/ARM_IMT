/************************************************************************/
/* SWC			: GPIO Driver											*/
/* Author		: Ashraf Ehab											*/
/* Version		: V1.0													*/
/* Date			: 24 Aug 2023											*/
/* Description	: SWC for SysTick Timer									*/
/************************************************************************/

#include "STK_Private.h"

/* 
 * Function	: STK_esInit				: Initializes the SysTick Timer
 * Return 	: Error Status of function
 */
ErrorStatus STK_esInit(void)
{
	/*1- Stop Timer*/
	CLR_BIT(STK_CTRL, STK_CTRL_ENABLE);

	/*2- Disable Interrupts*/
	CLR_BIT(STK_CTRL, STK_CTRL_TICKINT);

	/*3- Choose Clk Src*/
	#if (SRC_AHB == STK_CLK_SRC)
		SET_BIT(STK_CTRL, STK_CTRL_CLKSOURCE);
	#elif (SRC_AHB_DIV_8 == STK_CLK_SRC)
		CLR_BIT(STK_CTRL, STK_CTRL_CLKSOURCE);
	#else
		#error Error: Invalid STK_CLK_SRC Configuration
	#endif

	/*Returning Error Status*/
	return NO_ERROR;
}

/* 
 * Function	: STK_esSetWait				: Stops the processor for a certain amount of timer ticks (ISRs will still be triggered)
 * Input1 	: Copy_u32TickCount			: Number of ticks to stop for							: 0 -> (2^24)- 1
 * Return 	: Error Status of function
 */
ErrorStatus STK_esSetWait(u32 Copy_u32TickCount)
{
	/*I/p validation*/
	if (0xFFFFFF < Copy_u32TickCount)
	{
		return INVALID_PARAMETERS;
	}
	
	/*1- Load the TickCount into the LOAD Register*/
	STK_LOAD = Copy_u32TickCount;

	/*2- Initialize the VAL Register */
	STK_VAL = 0;

	/*3- Start Timer*/
	SET_BIT(STK_CTRL, STK_CTRL_ENABLE);

	/*4- Poll on the Count Flag*/
	while (!GET_BIT(STK_CTRL, STK_CTRL_COUNTFLAG))
	{
		/*Wait*/
	}
	
	/*5- Stop Timer*/
	CLR_BIT(STK_CTRL, STK_CTRL_ENABLE);

	/*Returning Error Status*/
	return NO_ERROR;
}

/* 
 * Function	: STK_esSetIntervalSingle	: Triggers a callback function after a certain amount of timer ticks
 * Input1 	: Copy_u32TickCount			: Number of ticks to trigger after						: 0 -> (2^24)- 1
 * Input2 	: inptr_vdCallbackFunction	: Pointer to the function to get called by the user		: 0 -> (2^24)- 1
 * Return 	: Error Status of function
 */
ErrorStatus STK_esSetIntervalSingle(u32 Copy_u32TickCount, void (* inptr_vdCallbackFunction)(void))
{
	/*I/p validation*/
	if (0xFFFFFF < Copy_u32TickCount)
	{
		return INVALID_PARAMETERS;
	}

	/*1- Load the TickCount*/
	STK_LOAD = Copy_u32TickCount;

	/*2- Initialize the VAL Register */
	STK_VAL = 0;

	/*3- Set Callback Function*/
	Globptr_vdCallbackFunction = inptr_vdCallbackFunction;

	/*4- Set Interval Flag*/
	Glob_u8IntervalFlag = INTERVAL_FLAG_SINGLE_MODE;

	/*5- Enable Interrupts*/
	SET_BIT(STK_CTRL, STK_CTRL_TICKINT);

	/*6- Start Timer*/
	SET_BIT(STK_CTRL, STK_CTRL_ENABLE);

	/*Returning Error Status*/
	return NO_ERROR;
}

/* 
 * Function	: STK_esSetIntervalPeriodic	: Triggers a callback function every certain amount of timer ticks
 * Input1 	: Copy_u32TickCount			: Number of ticks to trigger after periodically			: 0 -> (2^24)- 1
 * Input2 	: inptr_vdCallbackFunction	: Pointer to the function to get called by the user		: 0 -> (2^24)- 1
 * Return 	: Error Status of function
 */
ErrorStatus STK_esSetIntervalPeriodic(u32 Copy_u32TickCount, void (* inptr_vdCallbackFunction)(void))
{
	/*I/p validation*/
	if (0xFFFFFF < Copy_u32TickCount)
	{
		return INVALID_PARAMETERS;
	}

	/*1- Load the TickCount*/
	STK_LOAD = Copy_u32TickCount;

	/*2- Initialize the VAL Register */
	STK_VAL = 0;

	/*3- Set Callback Function*/
	Globptr_vdCallbackFunction = inptr_vdCallbackFunction;

	/*4- Set Interval Flag*/
	Glob_u8IntervalFlag = INTERVAL_FLAG_PERIODIC_MODE;

	/*5- Enable Interrupts*/
	SET_BIT(STK_CTRL, STK_CTRL_TICKINT);

	/*6- Start Timer*/
	SET_BIT(STK_CTRL, STK_CTRL_ENABLE);

	/*Returning Error Status*/
	return NO_ERROR;
}

/* 
 * Function	: STK_esGetElapsedTicks		: Gets the elapsed timer ticks since timer started
 * Output1 	: Outptr_u32ElapsedTicks	: Number of ticks elapsed since timer started			: 0 -> (2^24)- 1
 * Return 	: Error Status of function
 */
ErrorStatus STK_esGetElapsedTicks(u32* Outptr_u32ElapsedTicks)
{
	/*I/p Validation*/
	if (!Outptr_u32ElapsedTicks)
	{
		return NULL_POINTER_PASSED;
	}

	/*Outputting Elapsed Ticks*/
	*Outptr_u32ElapsedTicks = STK_LOAD - STK_VAL;

	/*Returning Error Status*/
	return NO_ERROR;
}

/* 
 * Function	: STK_esGetRemainingTicks	: Gets the remaining timer ticks until timer stops
 * Output1 	: Outptr_u32RemainingTicks	: Number of ticks remaining until timer stops			: 0 -> (2^24)- 1
 * Return 	: Error Status of function
 */
ErrorStatus STK_esGetRemainingTicks(u32* Outptr_u32RemainingTicks)
{
	/*I/p Validation*/
	if (!Outptr_u32RemainingTicks)
	{
		return NULL_POINTER_PASSED;
	}

	/*Outputting Remaining Ticks*/
	*Outptr_u32RemainingTicks = STK_VAL;

	/*Returning Error Status*/
	return NO_ERROR;
}

/* 
 * Function	: STK_esStop				: Stop the timer
 * Return 	: Error Status of function
 */
ErrorStatus STK_esStop(void)
{
	/*Stop Timer*/
	CLR_BIT(STK_CTRL, STK_CTRL_ENABLE);

	/*Stop Interrupts*/
	CLR_BIT(STK_CTRL, STK_CTRL_TICKINT);

	/*Returning Error Status*/
	return NO_ERROR;
}
/*__________________________________________________________________________________________________________________________________________*/

/* 
 * Function		: SysTick_Handler			: Handler for Systick Interrupts
 * Description	: This function calls the callback function, stops the timer if in single mode, and clears the interrupt flag.
 */
void SysTick_Handler(void)
{
	/*Variables Definitions*/
	u8 Loc_u8Temp = 0;

	/*1-Stopping Timer if Single Mode */
	if (INTERVAL_FLAG_SINGLE_MODE == Glob_u8IntervalFlag)
	{
		/*Stop Timer*/
		CLR_BIT(STK_CTRL, STK_CTRL_ENABLE);
		/*Stop Interrupts*/
		CLR_BIT(STK_CTRL, STK_CTRL_TICKINT);
	}

	/*2- Clear Interrupt Flag*/
	Loc_u8Temp = GET_BIT(STK_CTRL, STK_CTRL_COUNTFLAG);

	/*3- Call Callback Function*/
	if (Globptr_vdCallbackFunction)
	{
		Globptr_vdCallbackFunction();
	}
}
