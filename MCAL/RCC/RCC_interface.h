/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : MCAL					******************/
/*************	 SWC   	 : RCC  				******************/
/*************	 Date    : 12 Oct. 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/


#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

typedef enum {
	AHB,
	APB1,
	APB2,
}Bus_ID_t;

typedef enum {
	HSI,
	HSE,
	PLL,
}System_Clock_t;

typedef enum
{
	/************************ AHB **************************/
	AHB_DMA1  = 0,
	AHB_DMA2  = 1,
	AHB_SRAM  = 2,
	AHB_FLITF = 4,
	AHB_CRC   = 6,
	AHB_FSMC  = 8,
	AHB_SDIO  = 10,
	/************************ APB1 **************************/
	APB1_TIM2   = 0,
	APB1_TIM3   = 1,
	APB1_TIM4   = 2,
	APB1_TIM5   = 3,
	APB1_TIM6   = 4,
	APB1_TIM7   = 1,
	APB1_TIM12  = 6,
	APB1_TIM13  = 7,
	APB1_TIM14  = 8,
	APB1_WWDG   = 11,
	APB1_SPI2   = 14,
	APB1_SPI3   = 15,
	APB1_USART2 = 17,
	APB1_USART3 = 18,
	APB1_USART4 = 19,
	APB1_USART5 = 20,
	APB1_I2C1   = 21,
	APB1_I2C2   = 22,
	APB1_USB    = 23,
	APB1_CAN    = 25,
	APB1_BKP    = 27,
	APB1_PWR    = 28,
	APB1_DAC    = 29,
	/************************ APB2 **************************/
	APB2_AFIO   = 0,
	APB2_IOPA   = 2,
	APB2_IOPB   = 3,
	APB2_IOPC   = 4,
	APB2_IOPD   = 5,
	APB2_IOPE   = 6,
	APB2_IOPF   = 7,
	APB2_IOPG   = 8,
	APB2_ADC1   = 9,
	APB2_ADC2   = 10,
	APB2_TIM1   = 11,
	APB2_SPI1   = 12,
	APB2_TIM8   = 13,
	APB2_USART1 = 14,
	APB2_ADC3   = 15,
	APB2_TIM9   = 19,
	APB2_TIM10  = 20,
	APB2_TIM11  = 21,
}Prepherial_EN_t;


void RCC_vInit(void);

/*
 * for Copy_u8busId choose from the options of the Bus_ID_t.
 *
 * for Copy_u16prepherial choose from the options of the Prepherial_EN_t .
 */
void RCC_vEnableClock(Bus_ID_t Copy_busId, Prepherial_EN_t Copy_prepherial);
void RCC_vDisableClock(Bus_ID_t Copy_busId, Prepherial_EN_t Copy_prepherial);

/*
 * for Copy_systemClock choose from the options of the System_Clock_t.
 */
void RCC_vSetSysClock(System_Clock_t Copy_systemClock);



#endif /* RCC_INTERFACE_H_ */
