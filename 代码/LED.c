#include "stm32f10x.h"                  // Device header
#include "Key.h"
#include "Delay.h"
void LED_Init(void){
	
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_Initstructure;
	GPIO_Initstructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Initstructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Initstructure.GPIO_Pin=GPIO_Pin_1;
	GPIO_Init(GPIOA,&GPIO_Initstructure);
	GPIO_SetBits(GPIOA,GPIO_Pin_1);
}

void LED1_Turn(void)
{
	if(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_1)==0)//状态取反
	{   
		GPIO_SetBits(GPIOA,GPIO_Pin_1);
	}
	else
	{   
		GPIO_ResetBits(GPIOA,GPIO_Pin_1);
	}
}

		
