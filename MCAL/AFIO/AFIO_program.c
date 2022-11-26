/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : MCAL					******************/
/*************	 SWC   	 : AFIO  				******************/
/*************	 Date    : 18 Nov 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/AFIO/AFIO_config.h"
#include "../../MCAL/AFIO/AFIO_interface.h"
#include "../../MCAL/AFIO/AFIO_private.h"


// AFIO_vSetExtiPin(GPIO_PORTB, EXTI_LINE3); AFIO -> PB3
void AFIO_vSetExtiPin(u8 Copy_u8Port, AFIO_Line_t Copy_xExtiLine)
{
	u8 Local_u8index = Copy_xExtiLine/4;
	u8 Local_u8ShiftAmount = (4*(Copy_u8Port%4));
	AFIO->EXTICR[Local_u8index] &=~ (0b1111 << Local_u8ShiftAmount);
	AFIO->EXTICR[Local_u8index] |=  (Copy_u8Port << Local_u8ShiftAmount);

}
