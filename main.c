#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "rp2040.h"
#include "hal_gpio.h"

HAL_GPIO_PIN(LED, 25)

//-----------------------------------------------------------------------------
int main(void)
{
  resets_hw->reset &= ~(RESETS_RESET_IO_BANK0_BITS | RESETS_RESET_PADS_BANK0_BITS);

  HAL_GPIO_LED_out();
  HAL_GPIO_LED_clr();

  while (1)
  {
    volatile int wait = 1000000; while (wait--);
    HAL_GPIO_LED_toggle();
  }
  return 0;
}
