/************************************************/
/* Title       : SSEG Interface Header File      */
/* Author      : Ashraf Ehab                    */
/* Release     : 1.0                            */
/* Last Update : Sep 04, 2022                   */
/************************************************/

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
	u8 Loc_u8SEGPort;	/*The port the Seven Segment is connected to       *//*options: SSEG_PortA, B,C*/
	u8 Loc_u8CommType;	/*Type of Seven Segment                            *//*options: SSEG_Comm_CATHODE, SSEG_Comm_ANODE*/
	u8 Loc_u8CommPort;	/*The port the Seven Segment Common is connected to*//*options: SSEG_PortA, B,C*/
	u8 Loc_u8CommPin;	/*The pin the Seven Segment Common is connected to *//*options: SSEG_Pin0, 1,2,..,15,Comm_Not_Connected*/
}SSEG_Config;


/*Function Declerations*/
/*Function: SSEG_u8InitSSEG: Initialize the Seven Segment Display
 * Input1 : copy_SSEGConfig_Current: Configuration Structure of the Seven Segment to control
 * Return : Loc_u8ErrorStatus: returns an error for the parent function if it encounters any issues
 */
ErrorStatus SSEG_esInitSSEG(SSEG_Config copy_SSEGConfig_Current);
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/*Function: SSEG_u8SetNumber: Displays a number on a Seven Segment Display
 * Input1 : copy_SSEGConfig_Current: Configuration Structure of the Seven Segment to control
 * Input2 : copy_u8Number: The number to be displayed on the Seven Segment
 * Input3 : copy_u8DOT_stat: Weather or not to print the dot
 * Return : Loc_u8ErrorStatus: returns an error for the parent function if it encounters any issues
 */
ErrorStatus SSEG_esSetNumber(SSEG_Config copy_SSEGConfig_Current, u8 copy_u8Number, u8 copy_u8DOT_stat);
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/*Function: SSEG_u8ClrNumber: Clears the numbers displayed on the Seven Segment
 * Input1 : copy_SSEGConfig_Current: Configuration Structure of the Seven Segment to control
 * Return : Loc_u8ErrorStatus: returns an error for the parent function if it encounters any issues
 */
ErrorStatus SSEG_esClrNumber(SSEG_Config copy_SSEGConfig_Current);
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/*Function: SSEG_u8DispDot: Only displays the dot on a Seven Segment Display
 * Input1 : copy_SSEGConfig_Current: Configuration Structure of the Seven Segment to control
 * Return : Loc_u8ErrorStatus: returns an error for the parent function if it encounters any issues
 */
//u8 SSEG_u8DispDot(SSEG_Config copy_SSEGConfig_Current);

#endif /*SSEG_INTERFACE_H_*/
