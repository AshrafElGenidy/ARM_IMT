/************************************************************************/
/* SWC			: GPIO Driver											*/
/* Author		: Ashraf Ehab											*/
/* Version		: V1.0													*/
/* Date			: 24 Aug 2023											*/
/* Description	: SWC for General Purpose Input/Output					*/
/************************************************************************/
#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MACROS.h"

/*GPIO Ports*/
#define GPIO_PORTA			(0u)
#define GPIO_PORTB			(1u)
#define GPIO_PORTC			(2u)
#define GPIO_NOT_A_PORT		(3u)

/*GPIO Pins*/
#define GPIO_PIN0						(0u)
#define GPIO_PIN1						(1u)
#define GPIO_PIN2						(2u)
#define GPIO_PIN3						(3u)
#define GPIO_PIN4						(4u)
#define GPIO_PIN5						(5u)
#define GPIO_PIN6						(6u)
#define GPIO_PIN7						(7u)
#define GPIO_PIN8						(8u)
#define GPIO_PIN9						(9u)
#define GPIO_PIN10						(10u)
#define GPIO_PIN11						(11u)
#define GPIO_PIN12						(12u)
#define GPIO_PIN13						(13u)
#define GPIO_PIN14						(14u)
#define GPIO_PIN15						(15u)
#define GPIO_NOT_A_PIN					(16u)

/*GPIO modes*/
#define GPIO_INPUT						(0u)
#define GPIO_OUTPUT						(1u)
#define GPIO_ALTERNATIVE_FUNCTION		(2u)
#define GPIO_ANALOG						(3u)

/*GPIO Output Types*/
#define GPIO_PUSHPULL					(0u)
#define GPIO_OPENDRAIN					(1u)

/*GPIO Output Speed Options*/
#define GPIO_LOWSPEED					(0u)
#define GPIO_MEDIUMSPEED				(1u)
#define GPIO_HIGHSPEED					(2u)
#define GPIO_VERYHIGHSPEED				(3u)

/*GPIO Pullup/Pulldown Options*/
#define GPIO_FLOATING					(0u)
#define GPIO_PULLUP						(1u)
#define GPIO_PULLDOWN					(2u)

/*GPIO Pin Values*/
#define GPIO_LOW						BIT_LOW
#define GPIO_HIGH						BIT_HIGH

/*__________________________________________________________________________________________________________________________________________*/

/* 
 * Function	: GPIO_esPortInit			: Initializes the system for a port x
 * Input1 	: cpy_u8Port				: Port to initialize							: GPIO_PORTA -> GPIO_PORTC
 * Return 	: Error Status of function
 */
ErrorStatus GPIO_esPortInit(u8 cpy_u8Port);


/* 
 * Function	: GPIO_esSetPinMode			: Sets the mode for a pin n on port x
 * Input1 	: cpy_u8Port				: Port with pin n to set the mode of			: GPIO_PORTA -> GPIO_PORTC
 * Input2 	: cpy_u8Pin					: Pin n to set the mode of						: GPIO_PIN0  -> GPIO_PIN15
 * Input3 	: cpy_u8Mode				: mode chosen for the pin						: GPIO_INPUT -> GPIO_ANALOG
 * Return 	: Error Status of function
 */
ErrorStatus GPIO_esSetPinMode(u8 cpy_u8Port, u8 cpy_u8Pin, u8 cpy_u8Mode);

/* 
 * Function	: GPIO_esSetPinOutputType	: Sets the output type of a pin n on port x
 * Input1 	: cpy_u8Port				: Port with pin n to set the output type of		: GPIO_PORTA -> GPIO_PORTC
 * Input2 	: cpy_u8Pin					: Pin n to set the output type of				: GPIO_PIN0  -> GPIO_PIN15
 * Input3 	: cpy_u8OutputType			: output type chosen for the pin				: GPIO_PUSHPULL -> GPIO_OPENDRAIN
 * Return 	: Error Status of function
 */
ErrorStatus GPIO_esSetPinOutputType(u8 cpy_u8Port, u8 cpy_u8Pin, u8 cpy_u8OutputType);

/* 
 * Function	: GPIO_esSetPinSpeed		: Sets the output speed of a pin n on port x
 * Input1 	: cpy_u8Port				: Port with pin n to set the output speed of	: GPIO_PORTA -> GPIO_PORTC
 * Input2 	: cpy_u8Pin					: Pin n to set the speed of						: GPIO_PIN0  -> GPIO_PIN15
 * Input3 	: cpy_u8Speed				: speed chosen for the pin						: GPIO_LOWSPEED -> GPIO_VERYHIGHSPEED
 * Return 	: Error Status of function
 */
ErrorStatus GPIO_esSetPinSpeed(u8 cpy_u8Port, u8 cpy_u8Pin, u8 cpy_u8Speed);

/* 
 * Function	: GPIO_esSetPinPullUpDown	: Sets the pulling resistors of a pin n on port x
 * Input1 	: cpy_u8Port				: Port with pin n to set the resistors of		: GPIO_PORTA -> GPIO_PORTC
 * Input2 	: cpy_u8Pin					: Pin n to set the resistor mode of				: GPIO_PIN0  -> GPIO_PIN15
 * Input3 	: cpy_u8PullUpDown			: resistor mode chosen for the pin				: GPIO_FLOATING -> GPIO_PULLDOWN
 * Return 	: Error Status of function
 */
ErrorStatus GPIO_esSetPinPullUpDown(u8 cpy_u8Port, u8 cpy_u8Pin, u8 cpy_u8PullUpDown);

/* 
 * Function	: GPIO_esSetPinValue		: Sets the output value of a pin n on port x
 * Input1 	: cpy_u8Port				: Port with pin n to set the value of			: GPIO_PORTA -> GPIO_PORTC
 * Input2 	: cpy_u8Pin					: Pin n to set the value of						: GPIO_PIN0  -> GPIO_PIN15
 * Input3 	: cpy_u8Value				: value chosen for the pin						: GPIO_LOW -> GPIO_HIGH
 * Return 	: Error Status of function
 */
ErrorStatus GPIO_esSetPinValue(u8 cpy_u8Port, u8 cpy_u8Pin, u8 cpy_u8Value);

/* 
 * Function	: GPIO_esGetPinValue		: Reads the value inputted on a pin n on port x
 * Input1 	: cpy_u8Port				: Port with pin n to read the value of			: GPIO_PORTA -> GPIO_PORTC
 * Input2 	: cpy_u8Pin					: Pin n to read the value of					: GPIO_PIN0  -> GPIO_PIN15
 * Output1 	: Outptr_u8Value			: value present on the pin						: GPIO_LOW -> GPIO_HIGH
 * Return 	: Error Status of function
 */
ErrorStatus GPIO_esGetPinValue(u8 cpy_u8Port, u8 cpy_u8Pin, u8* Outptr_u8Value);

#endif  /*GPIO_INTERFACE_H_*/