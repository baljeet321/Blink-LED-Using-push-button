#include <stdint.h>
#include "register.h"
#include <stdio.h>

void powerup_gpio(uint32_t base_address, uint32_t offset, uint8_t pin)
{
  volatile uint32_t *reg = (uint32_t *)(base_address + offset);
  *reg|=(1<<pin);
}

void configure_mode(uint32_t base_address, uint32_t offset, uint8_t pin, uint32_t mode_type)
{
	volatile uint32_t *reg = (uint32_t *)(base_address + offset);

    switch(mode_type)
    {
      case INPUT: /*value is 00, i.e 0 for both bit positions 2*pin+1, and 2*pin*/
          *reg &= (~(1<<(2*pin)));
          *reg &= (~(1<<(2*pin + 1)));
          break;

      case OUTPUT:/*value is 01, i.e 0 for bit positions 2*pin+1, 1 for bit position 2*pin*/
          *reg |= ((1<<(2*pin)));
          *reg &= (~(1<<(2*pin + 1)));
          break;
    }
}

uint32_t registerRead(uint32_t base_address, uint32_t offset)
{
	volatile uint32_t *reg = (uint32_t *)(base_address + offset);
    return (uint32_t)*reg;
}

void registerWriteBit(uint32_t base_address, uint32_t offset, uint32_t bit, uint8_t data)
{
	volatile uint32_t *reg = (uint32_t *)(base_address + offset);
    /*Clear exiting value*/

	*reg &=(~(1<<bit));

	/*Writing data to bit*/
	*reg|=(data<<bit);

}

int main(void)
{
  /*Enabling clock for GPIO A and C of AHB1 register*/
  powerup_gpio(BASE_ADDRESS_RCC, OFFSET_AHB1, GPIOA_BIT);
  powerup_gpio(BASE_ADDRESS_RCC, OFFSET_AHB1, GPIOC_BIT);

  /*Configuring Input Mode for PA5 on GPIOA */
  configure_mode(BASE_ADDRESS_GPIOA, OFFSET_MODER_A, PA5, OUTPUT);

  /*Configuring Output Mode for PC13 on GPIOC */
  configure_mode(BASE_ADDRESS_GPIOC, OFFSET_MODER_A, PC13, INPUT);

  /*to read data from a pin, we will use Input data register and to set output data, will use
  output data register*/

  while(1)
  {
      uint32_t data = registerRead(BASE_ADDRESS_GPIOC, OFFSET_IDR);

      uint8_t temp = 0;
      if(((data>>PC13) & 1) == 0)
      {
        temp = 1;
      }
      else 
      {
        temp = 0;
      }
      registerWriteBit(BASE_ADDRESS_GPIOA, OFFSET_ODR, PA5, temp&1);
  }

}
