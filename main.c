#include "stm32f10x.h"
void SysClockConfig (void);	
void SysClockConfig (void)
{
  
  
  RCC->CR |= RCC_CR_HSEON;
  while(!(RCC->CR & RCC_CR_HSERDY));
  
  RCC->APB1ENR |= RCC_APB1ENR_PWREN;
  
  RCC->CFGR |= RCC_CFGR_HPRE_DIV1;
  
  RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;
  
  RCC->CFGR |= RCC_CFGR_PPRE2_DIV2;
  
  RCC->CR |= RCC_CR_PLLON;
  while(!(RCC->CR & RCC_CR_PLLRDY));
  
  RCC->CFGR |= RCC_CFGR_SW_PLL;
  while((RCC_CFGR_ADCPRE & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);
  
  
}
void GPIO_Config (void);
void GPIO_Config (void)
{
RCC->AHBENR |= (1<<0);
	GPIOC->CRH|= (1<<10);
}

void delay (uint32_t time)
{
	while(time--);
}
int main(void)
{
	SysClockConfig ();
	int a,b,c;
	a=2;
	b=3;
	c=a*b;
	
		//GPIOC->BSRR |=(1<<13);
		//delay(20000000);
		//GPIOC->BSRR |=((1<<13) <<16);
		//delay(20000000);
		//#include <stdint.h>

	int count;
	count=0;

	for(count=0;count<=1000;count++)
    {
        if((count%5==0))
        {
            count=count+1;
        }
    }
		
	return 0;
}