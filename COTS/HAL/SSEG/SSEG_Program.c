/************************************************************************/
/* SWC  	    : Seven Segment Driver                                  */
/* Author	    : Ashraf Ehab                                           */
/* Version	    : V1.0                                                  */
/* Date 	    : 28 Jul 2023                                           */
/* Description  : SWC for Seven Segment Display		                    */
/************************************************************************/

#include "SSEG_Private.h"

/* 
 * Function	: SSEG_esInitSSEG			: Initialize the Seven Segment Display
 * Input1 	: copy_SSEGConfig_Input   : Configuration Structure of the Seven Segment to control
 * Return 	: 					        : Error Status of function
 */
ErrorStatus SSEG_esInitSSEG(SSEG_Config copy_SSEGConfig_Input)
{
	ErrorStatus Loc_esReturn = NO_ERROR;

	if (Comm_Not_Connected > copy_SSEGConfig_Input.Loc_u8CommPort)
	{
		/*Enable Peripheral for the Port the Common is connected to*/
		Loc_esReturn = RCC_voidEnablePeripheralClk(Loc_u8Prei[copy_SSEGConfig_Input.Loc_u8CommPort]);
		RETURN_IF_ERROR(Loc_esReturn);

		/*Set the pin the Common is connected to as output*/
		Loc_esReturn = GPIO_esSetPinMode (copy_SSEGConfig_Input.Loc_u8CommPort, copy_SSEGConfig_Input.Loc_u8CommPin, GPIO_PIN_OUTPUT);
		RETURN_IF_ERROR(Loc_esReturn);
		Loc_esReturn = GPIO_esSetPinOutputType(copy_SSEGConfig_Input.Loc_u8CommPort, copy_SSEGConfig_Input.Loc_u8CommPin, GPIO_PIN_OUTPUT_PUSHPULL);
		RETURN_IF_ERROR(Loc_esReturn);
		Loc_esReturn = GPIO_esSetPinSpeed(copy_SSEGConfig_Input.Loc_u8CommPort, copy_SSEGConfig_Input.Loc_u8CommPin, GPIO_PIN_LOWSPEED);
		RETURN_IF_ERROR(Loc_esReturn);

		/*Set Value as LOW(if common cathod)/HIGH(if common anode) to Enable the Seven Segment*/
		switch (copy_SSEGConfig_Input.Loc_u8CommType)
		{
		case SSEG_Comm_CATHODE:		Loc_esReturn = GPIO_esSetPinValue (copy_SSEGConfig_Input.Loc_u8CommPort, copy_SSEGConfig_Input.Loc_u8CommPin, GPIO_PIN_LOW);	break;
		case SSEG_Comm_ANODE:		Loc_esReturn = GPIO_esSetPinValue (copy_SSEGConfig_Input.Loc_u8CommPort, copy_SSEGConfig_Input.Loc_u8CommPin, GPIO_PIN_HIGH);	break;
		default:					return INVALID_PARAMETERS;		break;
		}
		RETURN_IF_ERROR(Loc_esReturn);
	}
	else if (Comm_Not_Connected == copy_SSEGConfig_Input.Loc_u8CommPort)
	{
		/*Do nothing*/
	}
	else
	{
		return INVALID_PARAMETERS;
	}
	
	/*Enable Peripheral for the Port the Seven Segment is connected to*/
	Loc_esReturn = RCC_voidEnablePeripheralClk(Loc_u8Prei[copy_SSEGConfig_Input.Loc_u8SEGPort]);
	RETURN_IF_ERROR(Loc_esReturn);
	/*Set the pins the Seven Segment is connected to as output*/
	for (u8 i=0; i<8; i++)
	{
		Loc_esReturn = GPIO_esSetPinMode (copy_SSEGConfig_Input.Loc_u8SEGPort,i,GPIO_PIN_OUTPUT);
		RETURN_IF_ERROR(Loc_esReturn);
		Loc_esReturn = GPIO_esSetPinOutputType(copy_SSEGConfig_Input.Loc_u8SEGPort, i, GPIO_PIN_OUTPUT_PUSHPULL);
		RETURN_IF_ERROR(Loc_esReturn);
		Loc_esReturn = GPIO_esSetPinSpeed(copy_SSEGConfig_Input.Loc_u8SEGPort, i, GPIO_PIN_LOWSPEED);
		RETURN_IF_ERROR(Loc_esReturn);
	}
	return NO_ERROR;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/* 
 * Function	: SSEG_esSetNumber			: Displays a number on a Seven Segment Display
 * Input1 	: copy_SSEGConfig_Input  	: Configuration Structure of the Seven Segment to control
 * Input2 	: copy_u8Number			   	: Number to display on Seven Segment
 * Input3 	: copy_u8DOT_stat		   	: Whether or not to print the dot
 * Return 	: 					        : Error Status of function
 */
ErrorStatus SSEG_esSetNumber(SSEG_Config copy_SSEGConfig_Input, u8 copy_u8Number, u8 copy_u8DOT_stat)
{
	switch (copy_SSEGConfig_Input.Loc_u8CommType)
	{
	case SSEG_Comm_CATHODE:
		switch (copy_u8DOT_stat)
		{
		case DOT_OFF:	return SSEG_esWriteNum(copy_SSEGConfig_Input.Loc_u8SEGPort, Loc_u8Num[copy_u8Number]);			break;
		case DOT_ON:	return SSEG_esWriteNum(copy_SSEGConfig_Input.Loc_u8SEGPort, Loc_u8NumwDOT[copy_u8Number]);		break;
		default:		return INVALID_PARAMETERS;
		}
		break;
	case SSEG_Comm_ANODE:
		switch (copy_u8DOT_stat)
		{
		case DOT_OFF:	return SSEG_esWriteNum(copy_SSEGConfig_Input.Loc_u8SEGPort, ~Loc_u8Num[copy_u8Number]);			break;
		case DOT_ON:	return SSEG_esWriteNum(copy_SSEGConfig_Input.Loc_u8SEGPort, ~Loc_u8NumwDOT[copy_u8Number]);		break;
		default:		return INVALID_PARAMETERS;
		}
		break;
	default:			return INVALID_PARAMETERS;
	}
	return NO_ERROR;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/* 
 * Function	: SSEG_esClrNumber			: Clears all LEDs on the Seven Segment
 * Input1 	: copy_SSEGConfig_Input  	: Configuration Structure of the Seven Segment to control
 * Return 	: 					        : Error Status of function
 */
ErrorStatus SSEG_esClrNumber(SSEG_Config copy_SSEGConfig_Input)
{
	switch (copy_SSEGConfig_Input.Loc_u8CommPort)
	{
	case SSEG_Comm_CATHODE:		return SSEG_esWriteNum(copy_SSEGConfig_Input.Loc_u8SEGPort, CLEAR);			break;
	case SSEG_Comm_ANODE:		return SSEG_esWriteNum(copy_SSEGConfig_Input.Loc_u8SEGPort, ~CLEAR);		break;
	default:					return INVALID_PARAMETERS;
	}
	return NO_ERROR;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/* 
 * Function	: SSEG_esWriteNum	: Turns on/off The appropriate LEDs in the SSEG based on the required number
 * Input1 	: Copy_u8Port		: Port where the Seven Segment is connected 
 * Input2 	: Copy_u8Number		: The number to display on the Seven Segment 
 * Return 	: 				    : Error Status of function
 */
ErrorStatus SSEG_esWriteNum(u8 Copy_u8Port, u8 Copy_u8Number)
{
	ErrorStatus Loc_esReturn = NO_ERROR;
	for (u8 i = 0; i < 8; i++)
	{
		Loc_esReturn = GPIO_esSetPinValue(Copy_u8Port, i, GET_BIT(Copy_u8Number,i));
		RETURN_IF_ERROR(Loc_esReturn);
	}
	return NO_ERROR;
}
