//GPIO_LEDS PROJECT

#include "stm32f10x.h"

/* declaration des structures relatives aux periphs utilisés -----------------------------------------------------------*/
GPIO_InitTypeDef  GPIO_InitStructure;


/* Private functions ---------------------------------------------------------*/
void Delay(vu32 nCount);


int main(void)
{  /* activer l'horloge du port c connecté aux leds */
    RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOC, ENABLE );

    /* Configurer les pins PC8 et PC9 du port C */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ;// output Push Pull
  GPIO_Init(GPIOC, &GPIO_InitStructure );

while (1)
     {
       //allumer des deux leds reliées aux bits PC8 et PC9
 GPIO_SetBits(GPIOC, GPIO_Pin_8|GPIO_Pin_9);
 Delay (0xFFFFF);
	 
        // les éteindre
 GPIO_ResetBits(GPIOC,GPIO_Pin_8|GPIO_Pin_9);  
 Delay (0xFFFFF);
     }
}
/************** Function Name  : Delay  *****************/
void Delay(vu32 nCount)
{
  for(; nCount != 0; nCount--);
}
