/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
/** Addresses **/

// RCC
#define RCC_BASE_ADDR 		0x40023800U

#define RCC_AHB1ENR 		(*(uint32_t volatile*) ((RCC_BASE_ADDR) + (0x30)) )

// Clock config.
#define RCC_CFGR 			(*(uint32_t volatile*) ((RCC_BASE_ADDR) + (0x08)) )		// Selecting clock (HSI == 00)
// GPIO
#define GPIO_A_BASE_ADDR  	0x40020000U
#define GPIO_A_MODER 		(*(uint32_t volatile*) (GPIO_A_BASE_ADDR) )
#define GPIO_A_OSPEEDR 		(*(uint32_t volatile*) ((GPIO_A_BASE_ADDR) + (0x8)) )	// port speed [16 : 17] = 11 -> high speed
#define GPIO_A_AFRH 		(*(uint32_t volatile*) ((GPIO_A_BASE_ADDR) + (0x24)) )		// Alternate function


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	// Configure the MCO1
	RCC_CFGR &= ~(0x3 << 21);	// read from HSI
	RCC_CFGR |=	(0x7 << 27);	// (no pre-scaler)

    // Enable PORT A in ABH1 bus
	RCC_AHB1ENR |= 0x1;

	// Set GPIO_A mode as alternate function
	GPIO_A_MODER &= ~(0x3 << 16);		// clear
	GPIO_A_MODER |= (0x2 << 16);		// Set

	// Select for alternate function in PA8
	GPIO_A_AFRH &= ~(0xF << 0);

	/* Loop forever */
	for(;;);
}