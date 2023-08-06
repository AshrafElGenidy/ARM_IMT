/************************************************************************/
/* SWC  	    : Seven Segment Driver                                  */
/* Author	    : Ashraf Ehab                                           */
/* Version	    : V1.0                                                  */
/* Date 	    : 28 Jul 2023                                           */
/* Description  : SWC for Seven Segment Display		                    */
/************************************************************************/

#ifndef SSEG_INTERFACE_H_
#define SSEG_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MACROS.h"

/*MACROS*/
#define DOT_OFF	(0u)
#define DOT_ON	(1u)

/*Types of Seven Segment*/
#define SSEG_Comm_CATHODE 		0
#define SSEG_Comm_ANODE      	1

/*Ports and Pins Imported from GPIO*/
#define SSEG_PortA 			GPIO_PORTA
#define SSEG_PortB 			GPIO_PORTB
#define SSEG_PortC 			GPIO_PORTC
#define Comm_Not_Connected	GPIO_NOT_A_PORT

#define SSEG_Pin0 			GPIO_PIN0
#define SSEG_Pin1 			GPIO_PIN1
#define SSEG_Pin2 			GPIO_PIN2
#define SSEG_Pin3 			GPIO_PIN3
#define SSEG_Pin4 			GPIO_PIN4
#define SSEG_Pin5 			GPIO_PIN5
#define SSEG_Pin6 			GPIO_PIN6
#define SSEG_Pin7 			GPIO_PIN7
#define SSEG_Pin8 			GPIO_PIN8
#define SSEG_Pin9 			GPIO_PIN9
#define SSEG_Pin10 			GPIO_PIN10
#define SSEG_Pin11 			GPIO_PIN11
#define SSEG_Pin12 			GPIO_PIN12
#define SSEG_Pin13 			GPIO_PIN13
#define SSEG_Pin14 			GPIO_PIN14
#define SSEG_Pin15 			GPIO_PIN15

/*Seven Segment Configuration Structure*/
typedef struct{
	u8 Loc_u8SEGPort;	/*The port the Seven Segment is connected to       ----- options: SSEG_PortA,..,SSEG_PortC*/
	u8 Loc_u8CommType;	/*Type of Seven Segment                            ----- options: SSEG_Comm_CATHODE, SSEG_Comm_ANODE*/
	u8 Loc_u8CommPort;	/*The port the Seven Segment Common is connected to----- options: SSEG_PortA,..,SSEG_PortC,Comm_Not_Connected*/
	u8 Loc_u8CommPin;	/*The pin the Seven Segment Common is connected to ----- options: SSEG_Pin0,..,SSEG_Pin15*/
}SSEG_Config;


/*Function Declerations*/
/* 
 * Function	: SSEG_esInitSSEG			: Initialize the Seven Segment Display
 * Input1 	: copy_SSEGConfig_Input   : Configuration Structure of the Seven Segment to control
 * Return 	: 					        : Error Status of function
 */
ErrorStatus SSEG_esInitSSEG(SSEG_Config copy_SSEGConfig_Input);

/* 
 * Function	: SSEG_esSetNumber			: Displays a number on a Seven Segment Display
 * Input1 	: copy_SSEGConfig_Input  	: Configuration Structure of the Seven Segment to control
 * Input2 	: copy_u8Number			   	: Number to display on Seven Segment
 * Input3 	: copy_u8DOT_stat		   	: Whether or not to print the dot
 * Return 	: 					        : Error Status of function
 */
ErrorStatus SSEG_esSetNumber(SSEG_Config copy_SSEGConfig_Input, u8 copy_u8Number, u8 copy_u8DOT_stat);

/* 
 * Function	: SSEG_esClrNumber			: Clears all LEDs on the Seven Segment
 * Input1 	: copy_SSEGConfig_Input  	: Configuration Structure of the Seven Segment to control
 * Return 	: 					        : Error Status of function
 */
ErrorStatus SSEG_esClrNumber(SSEG_Config copy_SSEGConfig_Input);

#endif /*SSEG_INTERFACE_H_*/
