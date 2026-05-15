/*Base addressed*/
#define BASE_ADDRESS_RCC 0x40023800 /*Base address for RCC (Reset and Clock Register)*/
#define BASE_ADDRESS_GPIOA 0x40020000 /*Base address for GPIOA register*/
#define BASE_ADDRESS_GPIOC 0x40020800  /*Base address for GPIOC register*/

/*Offsets*/
#define OFFSET_AHB1 0x30 /*offset for RCC AHB1 peripheral reset register (RCC_AHB1RSTR)*/
#define OFFSET_MODER_A 0x00 /*Offset for GPIO port mode register (GPIOx_MODER)*/
#define OFFSET_MODER_C 0x00 /*Offset for GPIO port mode register (GPIOx_MODER)*/
#define OFFSET_IDR 0x10 /*Offset for GPIO port input data register*/
#define OFFSET_ODR 0x14 /*Offset for GPIO port output data register*/

/*Pin  - Bit positon mapping*/
#define GPIOA_BIT 0
#define GPIOC_BIT 2
#define PA5 5
#define PC13 13

/*MODE for GPIOs*/
typedef enum mode_t
{
    INPUT=0,
    OUTPUT=1,
}MODE;
