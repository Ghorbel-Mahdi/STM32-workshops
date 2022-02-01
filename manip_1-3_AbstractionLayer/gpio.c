#include <gpio.h>

int GPIO_TestPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN)
{
	uint16_t test=  GPIOx->IDR & GPIO_PIN;
	if ( test==1 )
		return 0;
	else
		return 1;
}

void GPIO_SetPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN)
{
	GPIOx->BSRR=GPIO_PIN;
	
}

void GPIO_ResetPin (GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN)
{
	GPIOx->BRR=GPIO_PIN;
}


void GPIO_Init (GPIO_TypeDef* GPIOx, GPIO_Struct GPIO_InitStruct) 
{
	for (int i=0; i<16; i++)
	{
		uint16_t IsPin = (GPIO_InitStruct.GPIO_PIN) & (1<<i);
		if ( IsPin== i){
			if(i<8){
				GPIOx->CRL &= ~( (uint32_t)0xF<<i);
				GPIOC->CRL |= GPIO_InitStruct.GPIO_Mode<<i;
			}
			else{
				GPIOx->CRH &= ~( (uint32_t)0xF<<(i-7));
				GPIOC->CRH |= GPIO_InitStruct.GPIO_Mode<<(i-7);
			}
		}
	}
}	
