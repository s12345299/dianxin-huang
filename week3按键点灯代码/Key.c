#include "stm32f10x.h"// Device header
#include "Delay.h"
void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_Initstructure;
	GPIO_Initstructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Initstructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Initstructure.GPIO_Pin=GPIO_Pin_1 | GPIO_Pin_11;
	GPIO_Init(GPIOB,&GPIO_Initstructure);
}
uint8_t Key_GetNum(void)//模式切换函数
{
	uint8_t KeyNum=0;
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11)==0)//按键按下
	{
		Delay_ms(20);//按键按下消抖
		if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11)==0)
		{
			
		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11)==0)
		{
		}//处于按键按下状态则卡在这个循环
		Delay_ms(20);//按键松开消抖
		return 1;
	}
}
		return 0;
}
uint8_t Key_State(void)//模式二
{
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1)==0)
	{
		Delay_ms(20);
		if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1)==0)
		{ 
			return 0;//按键按下
			Delay_ms(20);
		}
	}   
	   return 1;//按键松开
	Delay_ms(20);
}

	