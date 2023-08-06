/************************************************/
/* Title       : SSEG Source File      			*/
/* Author      : Ashraf Ehab                    */
/* Release     : 1.0                            */
/* Last Update : Sep 04, 2022                   */
/************************************************/

#include "SSEG_Private.h"


/*Function: SSEG_u8InitSSEG: Initialize the Seven Segment Display
 * Input1 : copy_SSEGConfig_Current: Configuration Structure of the Seven Segment to control
 * Return : Loc_esReturn: returns an error for the parent function if it encounters any issues
 */
ErrorStatus SSEG_esInitSSEG(SSEG_Config copy_SSEGConfig_Current)
{
	ErrorStatus Loc_esReturn = NO_ERROR;

	if (Comm_Not_Connected > copy_SSEGConfig_Current.Loc_u8CommPort)
	{
		/*Set direction for the controller pin connected to the common pin as output then set it to Low*/
		Loc_esReturn = RCC_voidEnablePeripheralClk(Loc_u8Prei[copy_SSEGConfig_Current.Loc_u8CommPort]);
		RETURN_IF_ERROR(Loc_esReturn);
		Loc_esReturn = GPIO_esSetPinMode (copy_SSEGConfig_Current.Loc_u8CommPort, copy_SSEGConfig_Current.Loc_u8CommPin, GPIO_PIN_OUTPUT);
		RETURN_IF_ERROR(Loc_esReturn);
		switch (copy_SSEGConfig_Current.Loc_u8CommType)
		{
		case SSEG_Comm_CATHODE:		Loc_esReturn = GPIO_esSetPinValue (copy_SSEGConfig_Current.Loc_u8CommPort, copy_SSEGConfig_Current.Loc_u8CommPin, GPIO_PIN_LOW);	break;
		case SSEG_Comm_ANODE:		Loc_esReturn = GPIO_esSetPinValue (copy_SSEGConfig_Current.Loc_u8CommPort, copy_SSEGConfig_Current.Loc_u8CommPin, GPIO_PIN_HIGH);	break;
		default:					return INVALID_PARAMETERS;		break;
		}
		RETURN_IF_ERROR(Loc_esReturn);
	}
	else if (Comm_Not_Connected == copy_SSEGConfig_Current.Loc_u8CommPort)
	{
		/*Do nothing*/
	}
	else
	{
		return INVALID_PARAMETERS;
	}
	
	Loc_esReturn = RCC_voidEnablePeripheralClk(Loc_u8Prei[copy_SSEGConfig_Current.Loc_u8SEGPort]);
	RETURN_IF_ERROR(Loc_esReturn);
	for (u8 i=0; 1<7; i++)
	{
		Loc_esReturn = GPIO_esSetPinMode (copy_SSEGConfig_Current.Loc_u8SEGPort,i,GPIO_PIN_OUTPUT);
		RETURN_IF_ERROR(Loc_esReturn);
		Loc_esReturn = GPIO_esSetPinOutputType(copy_SSEGConfig_Current.Loc_u8SEGPort, i, GPIO_PIN_OUTPUT_PUSHPULL);
		RETURN_IF_ERROR(Loc_esReturn);
		Loc_esReturn = GPIO_esSetPinSpeed(copy_SSEGConfig_Current.Loc_u8SEGPort, i, GPIO_PIN_LOWSPEED);
		RETURN_IF_ERROR(Loc_esReturn);
	}
	return NO_ERROR;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------*/

/*Function: SSEG_u8SetNumber: Displays a number on a Seven Segment Display
 * Input1 : copy_SSEGConfig_Current: Configuration Structure of the Seven Segment to control
 * Input2 : copy_u8Number: The number to be displayed on the Seven Segment
 * Input3 : copy_u8DOT_stat: Weather or not to print the dot
 * Return : Loc_esReturn: returns an error for the parent function if it encounters any issues
 */
ErrorStatus SSEG_esSetNumber(SSEG_Config copy_SSEGConfig_Current, u8 copy_u8Number, u8 copy_u8DOT_stat)
{
	switch (copy_SSEGConfig_Current.Loc_u8CommType)
	{
	case SSEG_Comm_CATHODE:
		switch (copy_u8DOT_stat)
		{
		case DOT_OFF:	return SSEG_WriteNum(copy_SSEGConfig_Current.Loc_u8SEGPort, Loc_u8Num[copy_u8Number]);			break;
		case DOT_ON:	return SSEG_WriteNum(copy_SSEGConfig_Current.Loc_u8SEGPort, Loc_u8NumwDOT[copy_u8Number]);		break;
		default:		return INVALID_PARAMETERS;
		}
		break;
	case SSEG_Comm_ANODE:
		switch (copy_u8DOT_stat)
		{
		case DOT_OFF:	return SSEG_WriteNum(copy_SSEGConfig_Current.Loc_u8SEGPort, ~Loc_u8Num[copy_u8Number]);			break;
		case DOT_ON:	return SSEG_WriteNum(copy_SSEGConfig_Current.Loc_u8SEGPort, ~Loc_u8NumwDOT[copy_u8Number]);		break;
		default:		return INVALID_PARAMETERS;
		}
		break;
	default:			return INVALID_PARAMETERS;
	}
	return NO_ERROR;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/*Function: SSEG_u8ClrNumber: Clears the numbers displayed on the Seven Segment
 * Input1 : copy_SSEGConfig_Current: Configuration Structure of the Seven Segment to control
 * Return : Loc_esReturn: returns an error for the parent function if it encounters any issues
 */
ErrorStatus SSEG_esClrNumber(SSEG_Config copy_SSEGConfig_Current)
{
	switch (copy_SSEGConfig_Current.Loc_u8CommPort)
	{
	case SSEG_Comm_CATHODE:		return SSEG_WriteNum(copy_SSEGConfig_Current.Loc_u8SEGPort, CLEAR);			break;
	case SSEG_Comm_ANODE:		return SSEG_WriteNum(copy_SSEGConfig_Current.Loc_u8SEGPort, ~CLEAR);		break;
	default:					return INVALID_PARAMETERS;
	}
	return NO_ERROR;
}


ErrorStatus SSEG_WriteNum(u8 Copy_u8Port, u8 Copy_u8Number)
{
	ErrorStatus Loc_esReturn = NO_ERROR;
	for (u8 i = 0; i < 8; i++)
	{
		Loc_esReturn = GPIO_esSetPinValue(Copy_u8Port, i, GET_BIT(Copy_u8Number,i));
		RETURN_IF_ERROR(Loc_esReturn);
	}
	return NO_ERROR;
}
