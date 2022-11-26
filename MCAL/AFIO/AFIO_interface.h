/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : MCAL					******************/
/*************	 SWC   	 : AFIO  				******************/
/*************	 Date    : 18 Nov 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/


#ifndef MCAL_AFIO_AFIO_INTERFACE_H_
#define MCAL_AFIO_AFIO_INTERFACE_H_


typedef enum
{
	AFIO_LINE0,
	AFIO_LINE1,
	AFIO_LINE2,
	AFIO_LINE3,
	AFIO_LINE4,
	AFIO_LINE5,
	AFIO_LINE6,
	AFIO_LINE7,
	AFIO_LINE8,
	AFIO_LINE9,
	AFIO_LINE10,
	AFIO_LINE11,
	AFIO_LINE12,
	AFIO_LINE13,
	AFIO_LINE14,
	AFIO_LINE15,
}AFIO_Line_t;

void AFIO_vSetExtiPin(u8 Copy_u8Port, AFIO_Line_t Copy_xExtiLine);



#endif /* MCAL_AFIO_AFIO_INTERFACE_H_ */
