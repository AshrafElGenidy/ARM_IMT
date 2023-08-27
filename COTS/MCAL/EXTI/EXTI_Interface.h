/************************************************************************/
/* SWC			: EXTI Driver											*/
/* Author		: Ashraf Ehab											*/
/* Version		: V1.0													*/
/* Date			: 25 Aug 2023											*/
/* Description	: SWC for External Hardware Interrupts					*/
/************************************************************************/
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MACROS.h"

/*EXTI Interrupt Lines*/
#define EXTI0		(0u)
#define EXTI1		(1u)
#define EXTI2		(2u)
#define EXTI3		(3u)
#define EXTI4		(4u)
#define EXTI5		(5u)
#define EXTI6		(6u)
#define EXTI7		(7u)
#define EXTI8		(8u)
#define EXTI9		(9u)
#define EXTI10		(10u)
#define EXTI11		(11u)
#define EXTI12		(12u)
#define EXTI13		(13u)
#define EXTI14		(14u)
#define EXTI15		(15u)

/*EXTI Edge Trigger Options*/
#define FALLING_EDGE_DETECTION		(0u)
#define RISING_EDGE_DETECTION		(1u)
#define DUAL_EDGE_DETECTION			(2u)

/*__________________________________________________________________________________________________________________________________________*/

/* 
 * Function	: EXTI_EnableInt			: Enables one of the 16 EXTI lines
 * Input1 	: cpy_u8IntLine				: Number of EXTI line to enable						: EXTI0 -> EXTI15
 * Return 	: Error Status of function
 */
ErrorStatus EXTI_EnableInt(u8 cpy_u8IntLine);

/* 
 * Function	: EXTI_EdgeSelection		: Select the edge type that triggers a certain EXTI line
 * Input1 	: cpy_u8IntLine				: Number of EXTI line to set the edge trigger of	: EXTI0 -> EXTI15
 * Input2 	: cpy_u8EdgeSelection		: Pin n to set the mode of							: FALLING_EDGE_DETECTION  -> DUAL_EDGE_DETECTION
 * Return 	: Error Status of function
 */
ErrorStatus EXTI_EdgeSelection(u8 cpy_u8IntLine, u8 cpy_u8EdgeSelection);

/* 
 * Function	: EXTI_SetCallBackFunction	: Sets the call back function to call after an EXTI line has been triggered
 * Input1 	: cpy_u8IntLine				: Number of EXTI line to set the function of		: EXTI0 -> EXTI15
 * Input2 	: inptr_vdCallbackFunction	: pointer to the user-defined call back function	: set to NULL to delete the pointer
 * Return 	: Error Status of function
 */
ErrorStatus EXTI_SetCallBackFunction(u8 cpy_u8IntLine, void (* inptr_vdCallbackFunction)(void));

/* 
 * Function	: EXTI_EnableInt			: Disables one of the 16 EXTI lines
 * Input1 	: cpy_u8IntLine				: Number of EXTI line to disable					: EXTI0 -> EXTI15
 * Return 	: Error Status of function
 */
ErrorStatus EXTI_DisableInt(u8 cpy_u8IntLine);

#endif  /*EXTI_INTERFACE_H_*/