/************************************************************************/
/* SWC  	    : GPIO Driver                                           */
/* Author	    : Ashraf Ehab                                           */
/* Version	    : V1.0                                                  */
/* Date 	    : 28 Jul 2023                                           */
/* Description  : SWC for General Purpose Input/Output                  */
/************************************************************************/
#include "GPIO_Private.h"


ErrorStatus GPIO_esSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinMode)
{
    if(GPIO_NOT_A_PIN <= Copy_u8Pin || GPIO_PIN_ANALOG < Copy_u8PinMode)
    {
        return INVALID_PARAMETERS;
    }
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:    
        MAKE_BIT(GPIOA[MODER], Copy_u8Pin << 1, Copy_u8PinMode & 1);
        MAKE_BIT(GPIOA[MODER], (Copy_u8Pin << 1) +1 , (Copy_u8PinMode & 2) >> 1);
        break;
    case GPIO_PORTB:    
        MAKE_BIT(GPIOB[MODER], Copy_u8Pin << 1, Copy_u8PinMode & 1);
        MAKE_BIT(GPIOB[MODER], (Copy_u8Pin << 1) +1 , (Copy_u8PinMode & 2) >> 1);
        break;
    case GPIO_PORTC:    
        MAKE_BIT(GPIOC[MODER], Copy_u8Pin << 1, Copy_u8PinMode & 1);
        MAKE_BIT(GPIOC[MODER], (Copy_u8Pin << 1) +1 , (Copy_u8PinMode & 2) >> 1);
        break;
    
    default:
        return INVALID_PARAMETERS;
    }
    return NO_ERROR;
}

ErrorStatus GPIO_esSetPinOutputType(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinOutputType)
{
    if(GPIO_NOT_A_PIN <= Copy_u8Pin || GPIO_PIN_OUTPUT_OPENDRAIN < Copy_u8PinOutputType)
    {
        return INVALID_PARAMETERS;
    }
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:    MAKE_BIT(GPIOA[OTYPER], Copy_u8Pin, Copy_u8PinOutputType);  break;
    case GPIO_PORTB:    MAKE_BIT(GPIOB[OTYPER], Copy_u8Pin, Copy_u8PinOutputType);  break;
    case GPIO_PORTC:    MAKE_BIT(GPIOC[OTYPER], Copy_u8Pin, Copy_u8PinOutputType);  break;
    default:            return INVALID_PARAMETERS;
    }
    return NO_ERROR;
}

ErrorStatus GPIO_esSetPinSpeed(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinSpeed)
{
    if(GPIO_NOT_A_PIN <= Copy_u8Pin || GPIO_PIN_VERYHIGHSPEED < Copy_u8PinSpeed)
    {
        return INVALID_PARAMETERS;
    }
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:    
        MAKE_BIT(GPIOA[OSPEEDR], Copy_u8Pin << 1, Copy_u8PinSpeed & 1);
        MAKE_BIT(GPIOA[OSPEEDR], ((Copy_u8Pin << 1) +1) , (Copy_u8PinSpeed & 2) >> 1);
        break;
    case GPIO_PORTB:    
        MAKE_BIT(GPIOB[OSPEEDR], Copy_u8Pin << 1, Copy_u8PinSpeed & 1);
        MAKE_BIT(GPIOB[OSPEEDR], ((Copy_u8Pin << 1) +1) , (Copy_u8PinSpeed & 2) >> 1);
        break;
    case GPIO_PORTC:    
        MAKE_BIT(GPIOC[OSPEEDR], Copy_u8Pin << 1, Copy_u8PinSpeed & 1);
        MAKE_BIT(GPIOC[OSPEEDR], ((Copy_u8Pin << 1) +1) , (Copy_u8PinSpeed & 2) >> 1);
        break;
    
    default:
        return INVALID_PARAMETERS;
    }
    return NO_ERROR;
}

ErrorStatus GPIO_esSetPinPullUpDown(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinPullUpDown)
{
    if(GPIO_NOT_A_PIN <= Copy_u8Pin || GPIO_PIN_PULLDOWN < Copy_u8PinPullUpDown)
    {
        return INVALID_PARAMETERS;
    }
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:    
        MAKE_BIT(GPIOA[PUPDR], Copy_u8Pin << 1, Copy_u8PinPullUpDown & 1);
        MAKE_BIT(GPIOA[PUPDR], ((Copy_u8Pin << 1) +1) , (Copy_u8PinPullUpDown & 2) >> 1);
        break;
    case GPIO_PORTB:    
        MAKE_BIT(GPIOB[PUPDR], Copy_u8Pin << 1, Copy_u8PinPullUpDown & 1);
        MAKE_BIT(GPIOB[PUPDR], ((Copy_u8Pin << 1) +1) , (Copy_u8PinPullUpDown & 2) >> 1);
        break;
    case GPIO_PORTC:    
        MAKE_BIT(GPIOC[PUPDR], Copy_u8Pin << 1, Copy_u8PinPullUpDown & 1);
        MAKE_BIT(GPIOC[PUPDR], ((Copy_u8Pin << 1) +1) , (Copy_u8PinPullUpDown & 2) >> 1);
        break;
    
    default:
        return INVALID_PARAMETERS;
    }
    return NO_ERROR;
}

ErrorStatus GPIO_esSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinValue)
{
    if(GPIO_NOT_A_PIN <= Copy_u8Pin)
    {
        return INVALID_PARAMETERS;
    }
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:    
        switch (Copy_u8PinValue)
        {
        case GPIO_PIN_LOW:      GPIOA[BSRR] = 1 << (Copy_u8Pin + 16);      break;
        case GPIO_PIN_HIGH:     GPIOA[BSRR] = 1 << (Copy_u8Pin);           break;
        default:                return INVALID_PARAMETERS;
        }
        break;
    case GPIO_PORTB:    
        switch (Copy_u8PinValue)
        {
        case GPIO_PIN_LOW:      GPIOB[BSRR] = 1 << (Copy_u8Pin + 16);      break;
        case GPIO_PIN_HIGH:     GPIOB[BSRR] = 1 << (Copy_u8Pin);           break;
        default:                return INVALID_PARAMETERS;
        }
        break;
    case GPIO_PORTC:    
        switch (Copy_u8PinValue)
        {
        case GPIO_PIN_LOW:      GPIOC[BSRR] = 1 << (Copy_u8Pin + 16);      break;
        case GPIO_PIN_HIGH:     GPIOC[BSRR] = 1 << (Copy_u8Pin);           break;
        default:                return INVALID_PARAMETERS;
        }
        break;
    
    default:
        return INVALID_PARAMETERS;
    }
    return NO_ERROR;
}

ErrorStatus GPIO_esSetPortValue(u8 Copy_u8Port, u16 Copy_u16PortValue)
{
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:    GPIOA[ODR] = (u32)Copy_u16PortValue;    break;
    case GPIO_PORTB:    GPIOA[ODR] = (u32)Copy_u16PortValue;    break;
    case GPIO_PORTC:    GPIOA[ODR] = (u32)Copy_u16PortValue;    break;
    default:            return INVALID_PARAMETERS;
    }
    return NO_ERROR;
}

ErrorStatus GPIO_esGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Outptr_u8PinMode)
{
    if(NULL == Outptr_u8PinMode)
    {
        return NULL_POINTER_PASSED;
    }
    if(GPIO_NOT_A_PIN <= Copy_u8Pin)
    {
        return INVALID_PARAMETERS;
    }
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:    *Outptr_u8PinMode = GET_BIT(GPIOA[IDR], Copy_u8Pin);    break;
    case GPIO_PORTB:    *Outptr_u8PinMode = GET_BIT(GPIOB[IDR], Copy_u8Pin);    break;
    case GPIO_PORTC:    *Outptr_u8PinMode = GET_BIT(GPIOC[IDR], Copy_u8Pin);    break;
    default:            return INVALID_PARAMETERS;
    }
    return NO_ERROR;
}