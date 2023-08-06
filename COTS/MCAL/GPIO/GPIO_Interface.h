/************************************************************************/
/* SWC  	    : GPIO Driver                                           */
/* Author	    : Ashraf Ehab                                           */
/* Version	    : V1.0                                                  */
/* Date 	    : 28 Jul 2023                                           */
/* Description  : SWC for General Purpose Input/Output                  */
/************************************************************************/
#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MACROS.h"


/*GPIO Ports*/
#define GPIO_PORTA	    	(0u)
#define GPIO_PORTB	    	(1u)
#define GPIO_PORTC	    	(2u)
#define GPIO_NOT_A_PORT		(3u)

/*GPIO Pins*/
#define GPIO_PIN0	    (0u)
#define GPIO_PIN1	    (1u)
#define GPIO_PIN2	    (2u)
#define GPIO_PIN3	    (3u)
#define GPIO_PIN4	    (4u)
#define GPIO_PIN5	    (5u)
#define GPIO_PIN6	    (6u)
#define GPIO_PIN7	    (7u)
#define GPIO_PIN8	    (8u)
#define GPIO_PIN9	    (9u)
#define GPIO_PIN10	    (10u)
#define GPIO_PIN11	    (11u)
#define GPIO_PIN12	    (12u)
#define GPIO_PIN13	    (13u)
#define GPIO_PIN14	    (14u)
#define GPIO_PIN15	    (15u)
#define GPIO_NOT_A_PIN  (16u)

/*GPIO Directions*/
#define GPIO_PIN_INPUT		                (0u)
#define GPIO_PIN_OUTPUT		                (1u)
#define GPIO_PIN_ALTERNATIVE_FUNCTION		(2u)
#define GPIO_PIN_ANALOG		                (3u)

/*GPIO Output Types*/
#define GPIO_PIN_OUTPUT_PUSHPULL            (0u)
#define GPIO_PIN_OUTPUT_OPENDRAIN           (1u)

/*GPIO Output Speed Options*/
#define GPIO_PIN_LOWSPEED                   (0u)
#define GPIO_PIN_MEDIUMSPEED                (1u)
#define GPIO_PIN_HIGHSPEED                  (2u)
#define GPIO_PIN_VERYHIGHSPEED              (3u)

/*GPIO Pullup/Pulldown Options*/
#define GPIO_PIN_FLOATING                   (0u)
#define GPIO_PIN_PULLUP                     (1u)
#define GPIO_PIN_PULLDOWN                   (2u)

/*GPIO Pin Values*/
#define GPIO_PIN_LOW                        BIT_LOW
#define GPIO_PIN_HIGH                       BIT_HIGH

/*GPIO Port Values*/
#define GPIO_PORT_LOW                       0x0000
#define GPIO_PORT_HIGH                      0x1111


ErrorStatus GPIO_esSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinMode);
ErrorStatus GPIO_esSetPinOutputType(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinOutputType);
ErrorStatus GPIO_esSetPinSpeed(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinSpeed);
ErrorStatus GPIO_esSetPinPullUpDown(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinPullUpDown);
ErrorStatus GPIO_esSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinValue);
ErrorStatus GPIO_esSetPortValue(u8 Copy_u8Port, u16 Copy_u16PortValue);
ErrorStatus GPIO_esGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Outptr_u8PinMode);

#endif  /*GPIO_INTERFACE_H_*/