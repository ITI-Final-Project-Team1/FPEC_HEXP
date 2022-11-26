/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : MCAL					******************/
/*************	 SWC   	 : EXTI  				******************/
/*************	 Date    : 18 Nov 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/



#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

typedef enum
{
	EXTI_FALLING,
	EXTI_RISING,
	EXTI_ONCHANGE
}EXTI_Trigger_t;

typedef enum
{
	EXTI_LINE0,
	EXTI_LINE1,
	EXTI_LINE2,
	EXTI_LINE3,
	EXTI_LINE4,
	EXTI_LINE5,
	EXTI_LINE6,
	EXTI_LINE7,
	EXTI_LINE8,
	EXTI_LINE9,
	EXTI_LINE10,
	EXTI_LINE11,
	EXTI_LINE12,
	EXTI_LINE13,
	EXTI_LINE14,
	EXTI_LINE15,
}EXTI_Line_t;

typedef struct
{
	EXTI_Trigger_t IntTrigger;
	EXTI_Line_t IntLine;
}EXTI_Config_t;



void EXTI_vInit(EXTI_Config_t* Copy_xInt);

void EXTI_vEnable(EXTI_Config_t* Copy_xInt);

void EXTI_vDisable(EXTI_Config_t* Copy_xInt);

void EXTI_vSetTrigger(EXTI_Config_t* Copy_xInt);

void EXTI_vSetCallBack(EXTI_Config_t* Copy_xInt, void (*Copy_vFptr)(void));

void EXTI_vGenerateSWInterrupt(EXTI_Config_t* Copy_xInt);

void EXTI_vStopSwInterrupt(EXTI_Config_t* Copy_xInt);



#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
