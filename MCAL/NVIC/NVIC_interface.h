/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : MCAL					******************/
/*************	 SWC   	 : NVIC  				******************/
/*************	 Date    : 18 Nov 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/


#ifndef MCAL_NVIC_NVIC_INTERFACE_H_
#define MCAL_NVIC_NVIC_INTERFACE_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"



/* enum for all external interrupt 0:59 */
typedef enum {
	WWDG_IRQ    = 0    ,
	PVD_IRQ            ,
	TAMPER_IRQ         ,
	RTC_IRQ            ,
	FLASH_IRQ          ,
	RCC_IRQ            ,
	EXTI0_IRQ          ,
	EXTI1_IRQ          ,
	EXTI2_IRQ          ,
	EXTI3_IRQ          ,
	EXTI4_IRQ          ,
	DMA1_Channel1_IRQ  ,
	DMA1_Channel2_IRQ  ,
	DMA1_Channel3_IRQ  ,
	DMA1_Channel4_IRQ  ,
	DMA1_Channel5_IRQ  ,
	DMA1_Channel6_IRQ  ,
	DMA1_Channel7_IRQ  ,
	ADC1_2_IRQ         ,
	USB_HP_CAN_IRQ     ,
	USB_LP_CAN_IRQ     ,
	CAN_RX1_IRQ        ,
	CAN_SCE_IRQ        ,
	EXTI9_5_IRQ        ,
	TIM1_BRK_IRQ       ,
	TIM1_UP_IRQ        ,
	TIM1_TRG_COM_IRQ   ,
	TIM1_CC_IRQ        ,
	TIM2_IRQ           ,
	TIM3_IRQ           ,
	TIM4_IRQ           ,
	I2C1_EV_IRQ        ,
	I2C1_ER_IRQ        ,
	I2C2_EV_IRQ        ,
	I2C2_ER_IRQ        ,
	SPI1_IRQ           ,
	SPI2_IRQ           ,
	USART1_IRQ         ,
	USART2_IRQ         ,
	USART3_IRQ         ,
	EXTI15_10_IRQ      ,
	RTCAlarm_IRQ       ,
	USBWakeup_IRQ      ,
	TIM8_BRK_IRQ       ,
	TIM8_UP_IRQ        ,
	TIM8_TRG_COM_IRQ   ,
	TIM8_CC_IRQ        ,
	ADC3_IRQ           ,
	FSMC_IRQ           ,
	SDIO_IRQ           ,
	TIM5_IRQ           ,
	SPI3_IRQ           ,
	UART4_IRQ          ,
	UART5_IRQ          ,
	TIM6_IRQ           ,
	TIM7_IRQ           ,
	DMA2_Channel1_IRQ  ,
	DMA2_Channel2_IRQ  ,
	DMA2_Channel3_IRQ  ,
	DMA2_Channel4_5_IRQ
}NVIC_IRQ_t;




// Set the Grouping and SubG
void NVIC_vInit(void);

void NVIC_vEnable			(NVIC_IRQ_t Copy_xIRQ);

void NVIC_vDisable			(NVIC_IRQ_t Copy_xIRQ);

void NVIC_vSetPendingFlag	(NVIC_IRQ_t Copy_xIRQ);

void NVIC_vClearPendingFlag	(NVIC_IRQ_t Copy_xIRQ);

u8   NVIC_u8getActiveFlag	(NVIC_IRQ_t Copy_xIRQ);

void NVIC_vSetPriority(NVIC_IRQ_t Copy_xIRQ, u8 Copy_u8Priority);




// try these ...
u32 NVIC_GetDevicePriority(NVIC_IRQ_t Copy_xIRQ);

u32 NVIC_GetPendingIRQ(NVIC_IRQ_t Copy_xIRQ);

















/*#if NVIC_CONFIG_TYPE == PREBUILD_CONFIG
	void NVIC_vInit(void);



#elif NVIC_CONFIG_TYPE == LINKTIME_CONFIG

	typedef struct
	{

	}NVIC_Config_t;

	void NVIC_vInit(NVIC_Config_t* P_xNvic);
#endif*/



#endif /* MCAL_NVIC_NVIC_INTERFACE_H_ */
