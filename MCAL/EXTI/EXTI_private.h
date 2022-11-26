/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : MCAL					******************/
/*************	 SWC   	 : EXTI  				******************/
/*************	 Date    : 18 Nov 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/


#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_


#define EXTI_BASE_ADDRESS		0x40010400

typedef struct
{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
}EXTI_MemMap_t;


#define EXTI			((volatile EXTI_MemMap_t*) EXTI_BASE_ADDRESS)


#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
