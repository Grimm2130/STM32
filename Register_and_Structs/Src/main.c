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


/* User instantiated headers */
#include "Registers.h"

// register addresses
#define RCC_BASE_ADDR 					0x40023800
#define RCC_AHB1_CLK_EN_BASE_ADDR 		0x40023830
#define GPIOD_MODER_BASE_ADDR			0x40020C00
#define GPIOD_ODR_BASE_ADDR				0x40020C14



// Function to set up the _AHB1_bus for GPIO for PORT D
void setupRCC_AHB1_bus(){
	/* Memory allocation*/
	// Set the pointer to ahb1_enable address
	RCC_AHB1_CLK_EN_t volatile * const rcc_ahb1_en = (RCC_AHB1_CLK_EN_t*) RCC_AHB1_CLK_EN_BASE_ADDR;

	//set the pointer for the gpio d port mode base address
	GPIOxMODER_t volatile * const mode = (GPIOxMODER_t*) GPIOD_MODER_BASE_ADDR;

	/* Bit manipulation */
	// Enable the clock for GPIOD
	rcc_ahb1_en->GPIOD_EN = 0x1;

	// Set the port12 as output
	mode->MODE_12 = 0x1;

}

int main(void)
{
	setupRCC_AHB1_bus();
	// Set the pointer for the GPIOD output data base address
	GPIOx_ODR_t volatile* const output = (GPIOx_ODR_t*) GPIOD_ODR_BASE_ADDR;
	// turn the led at port 12 on
	output->ODR_12 = 1;
	printf("Size of the GPIO output reg is: %d", sizeof(output));
	for(;;){
		output->ODR_12 ^= 1;
		for(uint32_t i = 0; i < 1000000; i++);
	}

}
