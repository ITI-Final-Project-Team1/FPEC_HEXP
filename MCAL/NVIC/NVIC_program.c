/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : MCAL					******************/
/*************	 SWC   	 : NVIC  				******************/
/*************	 Date    : 18 Nov 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/NVIC/NVIC_config.h"
#include "../../MCAL/NVIC/NVIC_interface.h"
#include "../../MCAL/NVIC/NVIC_private.h"


// Set the Grouping and SubG
void NVIC_vInit(void)
{
	SCB_AIRCR = SCB_NVIC_G0S16;
}



void NVIC_vEnable(NVIC_IRQ_t Copy_xIRQ)
{
	if(Copy_xIRQ <=31)
	{
		NVIC->ISER0 = (1 << Copy_xIRQ);
	}
	else if(Copy_xIRQ <=59)
	{
		NVIC->ISER1 = (1 << (Copy_xIRQ-32));
	}
	else
	{
		/* Error : Copy_xIRQ isn't valid*/
	}
}


void NVIC_vDisable(NVIC_IRQ_t Copy_xIRQ)
{
	if(Copy_xIRQ <=31)
	{
		NVIC->ICER0 = (1 << Copy_xIRQ);
	}
	else if(Copy_xIRQ <=59)
	{
		NVIC->ICER1 = (1 << (Copy_xIRQ-32));
	}
	else
	{
		/* Error : Copy_xIRQ isn't valid*/
	}
}


void NVIC_vSetPendingFlag(NVIC_IRQ_t Copy_xIRQ)
{
	if(Copy_xIRQ <=31)
	{
		NVIC->ISPR0 = (1 << Copy_xIRQ);
	}
	else if(Copy_xIRQ <=59)
	{
		NVIC->ISPR1 = (1 << (Copy_xIRQ-32));
	}
	else
	{
		/* Error : Copy_xIRQ isn't valid*/
	}
}


void NVIC_vClearPendingFlag(NVIC_IRQ_t Copy_xIRQ)
{
	if(Copy_xIRQ <=31)
	{
		//NVIC->ICPR0 = (1 << Copy_xIRQ);
	}
	else if(Copy_xIRQ <=59)
	{
		NVIC->ICPR1 = (1 << (Copy_xIRQ-32));
	}
	else
	{
		/* Error : Copy_xIRQ isn't valid*/
	}
}


u8   NVIC_u8getActiveFlag(NVIC_IRQ_t Copy_xIRQ)
{
	u8 Local_u8Status = -1;
	if(Copy_xIRQ <=31)
	{
		Local_u8Status = GET_BIT(NVIC->IABR0, Copy_xIRQ);
	}
	else if(Copy_xIRQ <=59)
	{
		Local_u8Status = GET_BIT(NVIC->IABR1, Copy_xIRQ);
	}
	else
	{
		/* Error : Copy_xIRQ isn't valid*/
	}
	return Local_u8Status;
}

void NVIC_vSetPriority(NVIC_IRQ_t Copy_xIRQ, u8 Copy_u8Priority)
{
	NVIC->IPR[Copy_xIRQ] &=~ (0b1111 << 4);
	NVIC->IPR[Copy_xIRQ] |=  (Copy_u8Priority << 4);
}




/*#if NVIC_CONFIG_TYPE == PREBUILD_CONFIG
	void NVIC_vInit(void)
	{

	}


#elif NVIC_CONFIG_TYPE == LINKTIME_CONFIG

#endif*/


