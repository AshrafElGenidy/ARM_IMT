/************************************************************************/
/* SWC  	    : GPIO Driver											*/
/* Author	    : Ashraf Ehab											*/
/* Version	    : V1.0													*/
/* Date 	    : 24 Aug 2023											*/
/* Description  : SWC for SysTick Timer									*/
/************************************************************************/


#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MACROS.h"

/* 
 * Function	: STK_esInit				: Initializes the SysTick Timer
 * Return 	: Error Status of function
 */
ErrorStatus STK_esInit(void);

/* 
 * Function	: STK_esSetWait				: Stops the processor for a certain amount of timer ticks (ISRs will still be triggered)
 * Input1 	: Copy_u32TickCount			: Number of ticks to stop for							: 0 -> (2^24)- 1
 * Return 	: Error Status of function
 */
ErrorStatus STK_esSetWait(u32 Copy_u32TickCount);

/* 
 * Function	: STK_esSetIntervalSingle	: Triggers a callback function after a certain amount of timer ticks
 * Input1 	: Copy_u32TickCount			: Number of ticks to trigger after						: 0 -> (2^24)- 1
 * Input2 	: Inptr_vdCallbackFunction	: Pointer to the function to get called by the user		: 0 -> (2^24)- 1
 * Return 	: Error Status of function
 */
ErrorStatus STK_esSetIntervalSingle(u32 Copy_u32TickCount, void (* Inptr_vdCallbackFunction)(void));

/* 
 * Function	: STK_esSetIntervalPeriodic	: Triggers a callback function every certain amount of timer ticks
 * Input1 	: Copy_u32TickCount			: Number of ticks to trigger after periodically			: 0 -> (2^24)- 1
 * Input2 	: Inptr_vdCallbackFunction	: Pointer to the function to get called by the user		: 0 -> (2^24)- 1
 * Return 	: Error Status of function
 */
ErrorStatus STK_esSetIntervalPeriodic(u32 Copy_u32TickCount, void (* Inptr_vdCallbackFunction)(void));

/* 
 * Function	: STK_esGetElapsedTicks		: Gets the elapsed timer ticks since timer started
 * Output1 	: Outptr_u32ElapsedTicks	: Number of ticks elapsed since timer started			: 0 -> (2^24)- 1
 * Return 	: Error Status of function
 */
ErrorStatus STK_esGetElapsedTicks(u32* Outptr_u32ElapsedTicks);

/* 
 * Function	: STK_esGetRemainingTicks	: Gets the remaining timer ticks until timer stops
 * Output1 	: Outptr_u32RemainingTicks	: Number of ticks remaining until timer stops			: 0 -> (2^24)- 1
 * Return 	: Error Status of function
 */
ErrorStatus STK_esGetRemainingTicks(u32* Outptr_u32RemainingTicks);

/* 
 * Function	: STK_esStop				: Stop the timer
 * Return 	: Error Status of function
 */
ErrorStatus STK_esStop(void);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*STK_INTERFACE_H*/
