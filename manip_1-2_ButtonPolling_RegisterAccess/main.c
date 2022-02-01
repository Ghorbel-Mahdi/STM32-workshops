#include <stdint.h>

 


#define Reg_Enable_RCC (uint32_t*) 0x40021018
#define GPIOC_CRL (uint32_t*) 0x40011000
#define GPIOC_CRH (uint32_t*) 0x40011004

 

 

 

#define Reg_BSRR_Led (uint32_t*) 0x40011010
#define Reg_BRR_Led (uint32_t*) 0x40011014

 

 

 

#define GPIOA_CRL (uint32_t*) 0x40010800
#define Reg_Button (uint32_t*) 0x40010808

 

 

 

int main ()
{
int i;
// activer l'horloge du port C (relié aux leds)
*Reg_Enable_RCC |= 0x14;

 

 

 

 // Configurer les bits reliés aux leds
*GPIOC_CRH &= ~( (uint32_t)0xFF);
*GPIOC_CRH |= 0x22;
*GPIOA_CRL &= ~( (uint32_t)0xF);
*GPIOA_CRL |= 0x04;
while (1)
{
    int btn;
    btn = *Reg_Button & 0x1;
    if (btn==0) *Reg_BRR_Led = 3<<8; //0x300 //eteinde le led
    else *Reg_BSRR_Led = 3<<8; //0x300 //Allumer le led

 

}
}