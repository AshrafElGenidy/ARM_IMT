/************************************************************************/
/* SWC			: GPIO Driver											*/
/* Author		: Ashraf Ehab											*/
/* Version		: V1.0													*/
/* Date			: 24 Aug 2023											*/
/* Description	: SWC for General Purpose Input/Output					*/
/************************************************************************/
#include "GPIO_Private.h"

/* 
 * Function	: GPIO_esPortInit			: Initializes the system for a port x
 * Input1 	: cpy_u8Port				: Port to initialize							: GPIO_PORTA -> GPIO_PORTC
 * Return 	: Error Status of function
 */
ErrorStatus GPIO_esPortInit(u8 cpy_u8Port)
{
	switch (cpy_u8Port)
	{
	case GPIO_PORTA:	return RCC_voidEnablePeripheralClk(c_GPIOA);
	case GPIO_PORTB:	return RCC_voidEnablePeripheralClk(c_GPIOB);
	case GPIO_PORTC:	return RCC_voidEnablePeripheralClk(c_GPIOC);
	default:			return INVALID_PARAMETERS;
	}
}

/* 
 * Function	: GPIO_esSetPinMode			: Sets the mode for a pin n on port x
 * Input1 	: cpy_u8Port				: Port with pin n to set the mode of			: GPIO_PORTA -> GPIO_PORTC
 * Input2 	: cpy_u8Pin					: Pin n to set the mode of						: GPIO_PIN0  -> GPIO_PIN15
 * Input3 	: cpy_u8Mode				: mode chosen for the pin						: GPIO_INPUT -> GPIO_ANALOG
 * Return 	: Error Status of function
 */
ErrorStatus GPIO_esSetPinMode(u8 cpy_u8Port, u8 cpy_u8Pin, u8 cpy_u8Mode)
{
    if(GPIO_NOT_A_PIN <= cpy_u8Pin || GPIO_ANALOG < cpy_u8Mode)
    {
        return INVALID_PARAMETERS;
    }
    switch (cpy_u8Port)
    {
    case GPIO_PORTA:    
        MAKE_BIT(GPIOA[MODER], cpy_u8Pin << 1, cpy_u8Mode & 1);
        MAKE_BIT(GPIOA[MODER], (cpy_u8Pin << 1) +1 , (cpy_u8Mode & 2) >> 1);
        break;
    case GPIO_PORTB:    
        MAKE_BIT(GPIOB[MODER], cpy_u8Pin << 1, cpy_u8Mode & 1);
        MAKE_BIT(GPIOB[MODER], (cpy_u8Pin << 1) +1 , (cpy_u8Mode & 2) >> 1);
        break;
    case GPIO_PORTC:    
        MAKE_BIT(GPIOC[MODER], cpy_u8Pin << 1, cpy_u8Mode & 1);
        MAKE_BIT(GPIOC[MODER], (cpy_u8Pin << 1) +1 , (cpy_u8Mode & 2) >> 1);
        break;
    
    default:
        return INVALID_PARAMETERS;
    }
    return NO_ERROR;
}

/* 
 * Function	: GPIO_esSetPinOutputType	: Sets the output type of a pin n on port x
 * Input1 	: cpy_u8Port				: Port with pin n to set the output type of		: GPIO_PORTA -> GPIO_PORTC
 * Input2 	: cpy_u8Pin					: Pin n to set the output type of				: GPIO_PIN0  -> GPIO_PIN15
 * Input3 	: cpy_u8OutputType			: output type chosen for the pin				: GPIO_PUSHPULL -> GPIO_OPENDRAIN
 * Return 	: Error Status of function
 */
ErrorStatus GPIO_esSetPinOutputType(u8 cpy_u8Port, u8 cpy_u8Pin, u8 cpy_u8OutputType)
{
    if(GPIO_NOT_A_PIN <= cpy_u8Pin || GPIO_OPENDRAIN < cpy_u8OutputType)
    {
        return INVALID_PARAMETERS;
    }
    switch (cpy_u8Port)
    {
    case GPIO_PORTA:    MAKE_BIT(GPIOA[OTYPER], cpy_u8Pin, cpy_u8OutputType);  break;
    case GPIO_PORTB:    MAKE_BIT(GPIOB[OTYPER], cpy_u8Pin, cpy_u8OutputType);  break;
    case GPIO_PORTC:    MAKE_BIT(GPIOC[OTYPER], cpy_u8Pin, cpy_u8OutputType);  break;
    default:            return INVALID_PARAMETERS;
    }
    return NO_ERROR;
}

/* 
 * Function	: GPIO_esSetPinSpeed		: Sets the output speed of a pin n on port x
 * Input1 	: cpy_u8Port				: Port with pin n to set the output speed of	: GPIO_PORTA -> GPIO_PORTC
 * Input2 	: cpy_u8Pin					: Pin n to set the speed of						: GPIO_PIN0  -> GPIO_PIN15
 * Input3 	: cpy_u8Speed				: speed chosen for the pin						: GPIO_LOWSPEED -> GPIO_VERYHIGHSPEED
 * Return 	: Error Status of function
 */
ErrorStatus GPIO_esSetPinSpeed(u8 cpy_u8Port, u8 cpy_u8Pin, u8 cpy_u8Speed)
{
    if(GPIO_NOT_A_PIN <= cpy_u8Pin || GPIO_VERYHIGHSPEED < cpy_u8Speed)
    {
        return INVALID_PARAMETERS;
    }
    switch (cpy_u8Port)
    {
    case GPIO_PORTA:    
        MAKE_BIT(GPIOA[OSPEEDR], cpy_u8Pin << 1, cpy_u8Speed & 1);
        MAKE_BIT(GPIOA[OSPEEDR], ((cpy_u8Pin << 1) +1) , (cpy_u8Speed & 2) >> 1);
        break;
    case GPIO_PORTB:    
        MAKE_BIT(GPIOB[OSPEEDR], cpy_u8Pin << 1, cpy_u8Speed & 1);
        MAKE_BIT(GPIOB[OSPEEDR], ((cpy_u8Pin << 1) +1) , (cpy_u8Speed & 2) >> 1);
        break;
    case GPIO_PORTC:    
        MAKE_BIT(GPIOC[OSPEEDR], cpy_u8Pin << 1, cpy_u8Speed & 1);
        MAKE_BIT(GPIOC[OSPEEDR], ((cpy_u8Pin << 1) +1) , (cpy_u8Speed & 2) >> 1);
        break;
    
    default:
        return INVALID_PARAMETERS;
    }
    return NO_ERROR;
}

/* 
 * Function	: GPIO_esSetPinPullUpDown	: Sets the pulling resistors of a pin n on port x
 * Input1 	: cpy_u8Port				: Port with pin n to set the resistors of		: GPIO_PORTA -> GPIO_PORTC
 * Input2 	: cpy_u8Pin					: Pin n to set the resistor mode of				: GPIO_PIN0  -> GPIO_PIN15
 * Input3 	: cpy_u8PullUpDown			: resistor mode chosen for the pin				: GPIO_FLOATING -> GPIO_PULLDOWN
 * Return 	: Error Status of function
 */
ErrorStatus GPIO_esSetPinPullUpDown(u8 cpy_u8Port, u8 cpy_u8Pin, u8 cpy_u8PullUpDown)
{
    if(GPIO_NOT_A_PIN <= cpy_u8Pin || GPIO_PULLDOWN < cpy_u8PullUpDown)
    {
        return INVALID_PARAMETERS;
    }
    switch (cpy_u8Port)
    {
    case GPIO_PORTA:
        MAKE_BIT(GPIOA[PUPDR], cpy_u8Pin << 1, cpy_u8PullUpDown & 1);
        MAKE_BIT(GPIOA[PUPDR], ((cpy_u8Pin << 1) +1) , (cpy_u8PullUpDown & 2) >> 1);
        break;
    case GPIO_PORTB:
        MAKE_BIT(GPIOB[PUPDR], cpy_u8Pin << 1, cpy_u8PullUpDown & 1);
        MAKE_BIT(GPIOB[PUPDR], ((cpy_u8Pin << 1) +1) , (cpy_u8PullUpDown & 2) >> 1);
        break;
    case GPIO_PORTC:
        MAKE_BIT(GPIOC[PUPDR], cpy_u8Pin << 1, cpy_u8PullUpDown & 1);
        MAKE_BIT(GPIOC[PUPDR], ((cpy_u8Pin << 1) +1) , (cpy_u8PullUpDown & 2) >> 1);
        break;
    
    default:
        return INVALID_PARAMETERS;
    }
    return NO_ERROR;
}

/* 
 * Function	: GPIO_esSetPinValue		: Sets the output value of a pin n on port x
 * Input1 	: cpy_u8Port				: Port with pin n to set the value of			: GPIO_PORTA -> GPIO_PORTC
 * Input2 	: cpy_u8Pin					: Pin n to set the value of						: GPIO_PIN0  -> GPIO_PIN15
 * Input3 	: cpy_u8Value				: value chosen for the pin						: GPIO_LOW -> GPIO_HIGH
 * Return 	: Error Status of function
 */
ErrorStatus GPIO_esSetPinValue(u8 cpy_u8Port, u8 cpy_u8Pin, u8 cpy_u8Value)
{
    if(GPIO_NOT_A_PIN <= cpy_u8Pin)
    {
        return INVALID_PARAMETERS;
    }
    switch (cpy_u8Port)
    {
    case GPIO_PORTA:
        switch (cpy_u8Value)
        {
        case GPIO_LOW:      GPIOA[BSRR] = 1 << (cpy_u8Pin + 16);      break;
        case GPIO_HIGH:     GPIOA[BSRR] = 1 << (cpy_u8Pin);           break;
        default:                return INVALID_PARAMETERS;
        }
        break;
    case GPIO_PORTB:
        switch (cpy_u8Value)
        {
        case GPIO_LOW:      GPIOB[BSRR] = 1 << (cpy_u8Pin + 16);      break;
        case GPIO_HIGH:     GPIOB[BSRR] = 1 << (cpy_u8Pin);           break;
        default:                return INVALID_PARAMETERS;
        }
        break;
    case GPIO_PORTC:
        switch (cpy_u8Value)
        {
        case GPIO_LOW:      GPIOC[BSRR] = 1 << (cpy_u8Pin + 16);      break;
        case GPIO_HIGH:     GPIOC[BSRR] = 1 << (cpy_u8Pin);           break;
        default:                return INVALID_PARAMETERS;
        }
        break;
    
    default:
        return INVALID_PARAMETERS;
    }
    return NO_ERROR;
}

/* 
 * Function	: GPIO_esGetPinValue		: Reads the value inputted on a pin n on port x
 * Input1 	: cpy_u8Port				: Port with pin n to read the value of			: GPIO_PORTA -> GPIO_PORTC
 * Input2 	: cpy_u8Pin					: Pin n to read the value of					: GPIO_PIN0  -> GPIO_PIN15
 * Output1 	: Outptr_u8Value			: value present on the pin						: GPIO_LOW -> GPIO_HIGH
 * Return 	: Error Status of function
 */
ErrorStatus GPIO_esGetPinValue(u8 cpy_u8Port, u8 cpy_u8Pin, u8* Outptr_u8Value)
{
    if(NULL == Outptr_u8Value)
    {
        return NULL_POINTER_PASSED;
    }
    if(GPIO_NOT_A_PIN <= cpy_u8Pin)
    {
        return INVALID_PARAMETERS;
    }
    switch (cpy_u8Port)
    {
    case GPIO_PORTA:    *Outptr_u8Value = GET_BIT(GPIOA[IDR], cpy_u8Pin);    break;
    case GPIO_PORTB:    *Outptr_u8Value = GET_BIT(GPIOB[IDR], cpy_u8Pin);    break;
    case GPIO_PORTC:    *Outptr_u8Value = GET_BIT(GPIOC[IDR], cpy_u8Pin);    break;
    default:            return INVALID_PARAMETERS;
    }
    return NO_ERROR;
}