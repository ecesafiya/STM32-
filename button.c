#include <stdint.h>
#include "main.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	 HAL_Init();                // Initialize the HAL Library
	 SystemClock_Config();      // Configure the system clock
	 MX_GPIO_Init();            // Initialize all configured peripherals

	 while(1)
	 {
		 if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 0)
		 {
			 HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
		 }
		 else
		 {
			 HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
		 }
	 }

}
