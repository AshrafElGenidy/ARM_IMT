/********************************************************************************/
/* SWC			: MCU Driver													*/
/* Author		: Ashraf Ehab													*/
/* Version		: V1.0															*/
/* Date			: 24 Aug 2023													*/
/* Description	: SWC for Configuring and initiallizing the micro-controller	*/
/********************************************************************************/
#ifndef MCU_CONFIG_H_
#define MCU_CONFIG_H_

#include "MCU_Private.h"

/*Number of Groups and subgroups in interrupt priorities: Options:- GP16_SGP01, GP08_SGP02, GP04_SGP04, GP02_SGP08, GP01_SGP16*/
#define INTERRUPT_PRIORITY_TYPE		GP16_SGP01	

#endif  /*MCU_CONFIG_H_*/