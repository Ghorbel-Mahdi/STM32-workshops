#include <stdint.h>

#define Reg_Enable_RCC (uint32_t*) 0x40021018
#define GPIOC_CRL (uint32_t*) 0x40011000
#define GPIOC_CRH (uint32_t*) 0x40011004
#define Reg_BSRR_Led (uint32_t*) 0x40011010
#define Reg_BRR_Led (uint32_t*) 0x40011014

int main ()
{
int i;
// activer l'horloge du port C (relié aux leds)
*Reg_Enable_RCC |= 0x10;

 // Configurer les bits reliés aux leds
*GPIOC_CRH &= ~( (uint32_t)0xFF);
*GPIOC_CRH |= 0x22;
while (1)
{
// allumer les deux leds
*Reg_BSRR_Led = 3<<8; //0x300
for(i=0xFFFFF; i != 0; i--); // Delay
// Eteindre les deux leds.
*Reg_BRR_Led = 3<<8; //0x300
for(i=0xFFFFF; i != 0; i--); // Delay
}
}