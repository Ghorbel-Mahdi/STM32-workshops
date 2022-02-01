#include <stm32map.h>


//1- Define the GPIO Pins
#define GPIO_PIN_0                 ((uint16_t)0x0001)  
#define GPIO_PIN_1                 ((uint16_t)0x0002)  
#define GPIO_PIN_2                 ((uint16_t)0x0004)  
#define GPIO_PIN_3                 ((uint16_t)0x0008)  
#define GPIO_PIN_4                 ((uint16_t)0x0010)  
#define GPIO_PIN_5                 ((uint16_t)0x0020)  
#define GPIO_PIN_6                 ((uint16_t)0x0040)  
#define GPIO_PIN_7                 ((uint16_t)0x0080)
#define GPIO_PIN_8                 ((uint16_t)0x0100)  
#define GPIO_PIN_9                 ((uint16_t)0x0200)  
#define GPIO_PIN_10                ((uint16_t)0x0400)  
#define GPIO_PIN_11                ((uint16_t)0x0800)  
#define GPIO_PIN_12                ((uint16_t)0x1000)  
#define GPIO_PIN_13                ((uint16_t)0x2000)  
#define GPIO_PIN_14                ((uint16_t)0x4000)  
#define GPIO_PIN_15                ((uint16_t)0x8000)  


//2 - Define The Mode Values
#define GPIO_Mode_InputFloating 0x04
#define GPIO_Mode_OutputPP2Mhz 0x02
#define GPIO_Mode_OutputPP10Mhz 0x01
#define GPIO_Mode_OutputPP50Mhz 0x03


typedef struct {
	uint16_t GPIO_PIN ;
	uint8_t GPIO_Mode ;
} GPIO_Struct ;

//3- Functions Proyotypes

int GPIO_TestPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN);
void GPIO_SetPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN);
void GPIO_ResetPin (GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN);
void GPIO_Init (GPIO_TypeDef* GPIOx,  GPIO_Struct   GPIO_InitStruct);



