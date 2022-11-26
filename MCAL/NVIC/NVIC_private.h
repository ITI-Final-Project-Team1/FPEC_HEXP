/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : MCAL					******************/
/*************	 SWC   	 : NVIC  				******************/
/*************	 Date    : 18 Nov 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/


#ifndef MCAL_NVIC_NVIC_PRIVATE_H_
#define MCAL_NVIC_NVIC_PRIVATE_H_

#include "../../LIB/STD_TYPES.h"

#define NVIC_BASE_ADDRESS		 0xE000E100

//#define NVIC_ISER0			*((volatile u32*) (NVIC_BASE + 0x000)) //enable external interrupt from 0 to 31
//#define NVIC_ISER1			*((volatile u32 *)(NVIC_BASE + 0x004)) //enable external interrupt from 32 to 63
//#define NVIC_ISER2			*((volatile u32 *)(NVIC_BASE + 0x008)) //enable external interrupt from 64 to 80
//#define NVIC_ICER0			*((volatile u32 *)(NVIC_BASE + 0x080)) //disable external interrupt from 0 to 31
//#define NVIC_ICER1			*((volatile u32 *)(NVIC_BASE + 0x084)) //disable external interrupt from 32 to 63
//#define NVIC_ICER2			*((volatile u32 *)(NVIC_BASE + 0x088)) //disable external interrupt from 64 to 80

//#define NVIC_ISPR0			*((volatile u32 *)(NVIC_BASE + 0x100))
//#define NVIC_ISPR1			*((volatile u32 *)(NVIC_BASE + 0x104))
//#define NVIC_ISPR2			*((volatile u32 *)(NVIC_BASE + 0x108))
//#define NVIC_ICPR0			*((volatile u32 *)(NVIC_BASE_ADDRESS + 0x100))
//#define NVIC_ICPR1			*((volatile u32 *)(NVIC_BASE + 0x184))
//#define NVIC_ICPR2			*((volatile u32 *)(NVIC_BASE + 0x188))

//#define NVIC_IABR0			*((volatile u32 *)(NVIC_BASE + 0x200))
//#define NVIC_IABR1			*((volatile u32 *)(NVIC_BASE + 0x204))
//#define NVIC_IABR2			*((volatile u32 *)(NVIC_BASE + 0x208))

//#define NVIC_IPR			((volatile u8 *)(NVIC_BASE + 0x300))



typedef struct{
	volatile u32 ISER0;
	volatile u32 ISER1;
	volatile u32 ISER2;
	u32 Res1[30];
	volatile u32 ICER0;
	volatile u32 ICER1;
	volatile u32 ICER2;
	u32 Res2[30];
	volatile u32 ISPR0;
	volatile u32 ISPR1;
	volatile u32 ISPR2;
	u32 Res3[30];
	volatile u32 ICPR0;
	volatile u32 ICPR1;
	volatile u32 ICPR2;
	u32 Res4[30];
	volatile u32 IABR0;
	volatile u32 IABR1;
	volatile u32 IABR2;
	u32 Res5[62];
	volatile u8 IPR[21]; // this register is byte accessible so I used u8 to make it easy to access

}NVIC_MemoryMap_t;

#define NVIC					((NVIC_MemoryMap_t*)(NVIC_BASE_ADDRESS))

/************************** SCB **************************/

#define SCB_AIRCR             	*((volatile u32*) 0xE000ED00 + 0x0C)

#define SCB_NVIC_G16S0     0x05FA0300 // Always have Nesting
#define SCB_NVIC_G8S2      0x05FA0400
#define SCB_NVIC_G46S4     0x05FA0500
#define SCB_NVIC_G26S8     0x05FA0600
#define SCB_NVIC_G0S16     0x05FA0700 // No Nesting

/*
#define LINKTIME_CONFIG				1
#define PREBUILD_CONFIG				2
*/

#endif /* MCAL_NVIC_NVIC_PRIVATE_H_ */
