/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : MCAL					******************/
/*************	 SWC   	 : EXTI  				******************/
/*************	 Date    : 18 Nov 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/EXTI/EXTI_config.h"
#include "../../MCAL/EXTI/EXTI_interface.h"
#include "../../MCAL/EXTI/EXTI_private.h"

typedef void (*GS_EXTI_CallBack) (void) ;
static GS_EXTI_CallBack EXTI_CallBacks[16];


void EXTI_vInit(EXTI_Config_t* Copy_xInt)
{
	EXTI_vEnable(Copy_xInt);
	EXTI_vSetTrigger(Copy_xInt);
}


void EXTI_vEnable(EXTI_Config_t* Copy_xInt)
{
	SET_BIT(EXTI->IMR, Copy_xInt->IntLine);
}

void EXTI_vDisable(EXTI_Config_t* Copy_xInt)
{
	CLEAR_BIT(EXTI->IMR, Copy_xInt->IntLine);
}

void EXTI_vSetTrigger(EXTI_Config_t* Copy_xInt)
{
	switch (Copy_xInt->IntTrigger) {
		case EXTI_FALLING:
			SET_BIT(EXTI->FTSR, Copy_xInt->IntLine);
			CLEAR_BIT(EXTI->RTSR, Copy_xInt->IntLine);
			break;
		case EXTI_RISING:
			SET_BIT(EXTI->RTSR, Copy_xInt->IntLine);
			CLEAR_BIT(EXTI->FTSR, Copy_xInt->IntLine);
			break;
		case EXTI_ONCHANGE:
			SET_BIT(EXTI->FTSR, Copy_xInt->IntLine);
			SET_BIT(EXTI->RTSR, Copy_xInt->IntLine);
			break;

		default:
			/* Error */
			break;
	}
}

void EXTI_vGenerateSWInterrupt(EXTI_Config_t* Copy_xInt)
{
	SET_BIT(EXTI->SWIER, Copy_xInt->IntLine);
}


void EXTI_vStopSwInterrupt(EXTI_Config_t* Copy_xInt)
{
	//Clearing the flag
	SET_BIT(EXTI->PR, Copy_xInt->IntLine);
}


void EXTI_vSetCallBack(EXTI_Config_t* Copy_xInt, void (*Copy_vFptr)(void))
{
	if(Copy_xInt->IntLine <= EXTI_LINE15) // for input validation
	{
		EXTI_CallBacks[Copy_xInt->IntLine] = Copy_vFptr;
	}
	else
	{
		/* Error */
	}
}

/*void EXTI0_IRQHandler(void)
{
	//clear pending register for specific EXTI line (clear by writing 1)
	EXTI->PR |= 1<<0;
	//Call EXTI_CallBacks
	if(EXTI_CallBacks[EXTI_LINE0]!=NULL) // for input validation
	{
		EXTI_CallBacks[EXTI_LINE0]();
	}
}*/

void EXTI1_IRQHandler(void)
{
	//clear pending register for specific EXTI line (clear by writing 1)
	EXTI->PR |= 1<<1;
	//Call EXTI_CallBacks
	if(EXTI_CallBacks[EXTI_LINE1]!=NULL) // for input validation
	{
		EXTI_CallBacks[EXTI_LINE1]();
	}
}

void EXTI2_IRQHandler(void)
{
	//clear pending register for specific EXTI line (clear by writing 1)
	EXTI->PR |= 1<<2 ;
	//Call EXTI_CallBacks
	if(EXTI_CallBacks[EXTI_LINE2]!=NULL) // for input validation
	{
		EXTI_CallBacks[EXTI_LINE2]();
	}
}


void EXTI3_IRQHandler(void)
{
	//clear pending register for specific EXTI line (clear by writing 1)
	EXTI->PR |= 1<<3 ;
	//Call EXTI_CallBacks
	if(EXTI_CallBacks[EXTI_LINE3]!=NULL) // for input validation
		{
			EXTI_CallBacks[EXTI_LINE3]();
		}
}


void EXTI4_IRQHandler(void)
{
	//clear pending register for specific EXTI line (clear by writing 1)
	EXTI->PR |= 1<<4 ;
	//Call EXTI_CallBacks
	if(EXTI_CallBacks[EXTI_LINE4]!=NULL) // for input validation
		{
			EXTI_CallBacks[EXTI_LINE4]();
		}
}


void EXTI5_9_IRQHandler(void)
{
	if(EXTI->PR & 1 << 5)
	{
		//clear pending register for specific EXTI line (clear by writing 1)
		EXTI->PR |= (1 << 5);
		//Call EXTI_CallBacks
		if(EXTI_CallBacks[EXTI_LINE5]!=NULL) // for input validation
		{
			EXTI_CallBacks[EXTI_LINE5]() ;
		}
	}
	if(EXTI->PR & 1 << 6)
	{
		//clear pending register for specific EXTI line (clear by writing 1)
		EXTI->PR |= (1 << 6);
		//Call EXTI_CallBacks
		if(EXTI_CallBacks[EXTI_LINE6]!=NULL) // for input validation
		{
			EXTI_CallBacks[EXTI_LINE6]() ;
		}
	}
	if(EXTI->PR & 1 << 7)
	{
		//clear pending register for specific EXTI line (clear by writing 1)
		EXTI->PR |= (1 << 7);
		//Call EXTI_CallBacks
		if(EXTI_CallBacks[EXTI_LINE7]!=NULL) // for input validation
		{
			EXTI_CallBacks[EXTI_LINE7]() ;
		}
	}

	if(EXTI->PR & 1 << 8)
	{
		//clear pending register for specific EXTI line (clear by writing 1)
		EXTI->PR |= (1 << 8);
		//Call EXTI_CallBacks
		if(EXTI_CallBacks[EXTI_LINE8]!=NULL) // for input validation
		{
			EXTI_CallBacks[EXTI_LINE8]() ;
		}
	}

	if(EXTI->PR & 1 << 9)
	{
		//clear pending register for specific EXTI line (clear by writing 1)
		EXTI->PR |= (1 << 9);
		//Call EXTI_CallBacks
		if(EXTI_CallBacks[EXTI_LINE9]!=NULL) // for input validation
		{
			EXTI_CallBacks[EXTI_LINE9]() ;
		}
	}
}

void EXTI10_15_IRQHandler(void)
{
	if(EXTI->PR & 1 << 10)
	{
		//clear pending register for specific EXTI line (clear by writing 1)
		EXTI->PR |= (1 << 10);
		//Call EXTI_CallBacks
		if(EXTI_CallBacks[EXTI_LINE10]!=NULL) // for input validation
		{
			EXTI_CallBacks[EXTI_LINE10]() ;
		}
	}
	if(EXTI->PR & 1 << 11)
	{
		//clear pending register for specific EXTI line (clear by writing 1)
		EXTI->PR |= (1 << 11);
		//Call EXTI_CallBacks
		if(EXTI_CallBacks[EXTI_LINE11]!=NULL) // for input validation
		{
			EXTI_CallBacks[EXTI_LINE11]() ;
		}
	}
	if(EXTI->PR & 1 << 12)
	{
		//clear pending register for specific EXTI line (clear by writing 1)
		EXTI->PR |= (1 << 12);
		//Call EXTI_CallBacks
		if(EXTI_CallBacks[EXTI_LINE12]!=NULL) // for input validation
		{
			EXTI_CallBacks[EXTI_LINE12]() ;
		}
	}

	if(EXTI->PR & 1 << 13)
	{
		//clear pending register for specific EXTI line (clear by writing 1)
		EXTI->PR |= (1 << 13);
		//Call EXTI_CallBacks
		if(EXTI_CallBacks[EXTI_LINE13]!=NULL) // for input validation
		{
			EXTI_CallBacks[EXTI_LINE13]() ;
		}
	}

	if(EXTI->PR & 1 << 14)
	{
		//clear pending register for specific EXTI line (clear by writing 1)
		EXTI->PR |= (1 << 14);
		//Call EXTI_CallBacks
		if(EXTI_CallBacks[EXTI_LINE14]!=NULL) // for input validation
		{
			EXTI_CallBacks[EXTI_LINE14]() ;
		}
	}

	if(EXTI->PR & 1 << 15)
	{
		//clear pending register for specific EXTI line (clear by writing 1)
		EXTI->PR |= (1 << 15);
		//Call EXTI_CallBacks
		if(EXTI_CallBacks[EXTI_LINE15]!=NULL) // for input validation
		{
			EXTI_CallBacks[EXTI_LINE15]() ;
		}
	}
}
