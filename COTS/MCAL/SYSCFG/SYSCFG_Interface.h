/************************************************************************/
/* SWC			: SYSCFG Driver											*/
/* Author		: Ashraf Ehab											*/
/* Version		: V1.0													*/
/* Date			: 25 Aug 2023											*/
/* Description	: SWC for System Configuration Controller				*/
/************************************************************************/
#ifndef SYSCFG_INTERFACE_H_
#define SYSCFG_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MACROS.h"

/*EXTI Interrupt Lines*/
#define EXTI_LINE0		(0u)
#define EXTI_LINE1		(1u)
#define EXTI_LINE2		(2u)
#define EXTI_LINE3		(3u)
#define EXTI_LINE4		(4u)
#define EXTI_LINE5		(5u)
#define EXTI_LINE6		(6u)
#define EXTI_LINE7		(7u)
#define EXTI_LINE8		(8u)
#define EXTI_LINE9		(9u)
#define EXTI_LINE10		(10u)
#define EXTI_LINE11		(11u)
#define EXTI_LINE12		(12u)
#define EXTI_LINE13		(13u)
#define EXTI_LINE14		(14u)
#define EXTI_LINE15		(15u)

/*Ports on micro-controller*/
#define EXTI_PORTA		(0u)
#define EXTI_PORTB		(1u)
#define EXTI_PORTC		(2u)

/*__________________________________________________________________________________________________________________________________________*/

/* 
 * Function	: SYSCFG_Init				: Initializes the system to use the System Configuration Controller
 * Return 	: Error Status of function
 */
ErrorStatus SYSCFG_Init(void);

/* 
 * Function	: SYSCFG_EXTI_PortSelection	: Chooses the Port that affects a certain EXTI Interrupt Line
 * Input1 	: cpy_u8IntLine				: The Line number to affect				: EXTI_LINE0 -> EXTI_LINE15
 * Input2 	: cpy_u8Port				: The port chosen for the operation		: EXTI_PORTA -> EXTI_PORTC
 * Return 	: Error Status of function
 */
ErrorStatus SYSCFG_EXTI_PortSelection(u8 cpy_u8IntLine, u8 cpy_u8Port);

#endif  /*SYSCFG_INTERFACE_H_*/