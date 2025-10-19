#include "stm32f10x.h"  
#include "Delay.h"// Device header
#include "LED.h"
#include "Key.h"
uint8_t mode=0;//0为翻转，1为常亮
int main(void)
{
	LED_Init();
	Key_Init();
	while(1)
	{
		if(Key_GetNum()) //按键B
		{
			mode=!mode;//切换模式
			Delay_ms(200);
		}
			if(mode==0)
			{  
				if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1)==0)
			{  Delay_ms(200);
				LED1_Turn();
			}
		}
			if(mode==1)
			{   
			if(Key_State()==0)
			{
				GPIO_ResetBits(GPIOA,GPIO_Pin_1);
			}
			else 
			{
				GPIO_SetBits(GPIOA,GPIO_Pin_1);
			}
		}
	}
}
