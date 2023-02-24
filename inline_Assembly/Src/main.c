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

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


int main(){

#if 0

	// In-line assembly code without input and output operands
	__asm volatile("MOV R1, R15");		// Load in the stack pointer
	__asm volatile("MOV R2, R14");		// load in the link register
	__asm volatile("SUB R3, R2,R1");		// subtract the PC address from the next instruction address
	__asm volatile("STR R3, [R4]");		//	Store the value in the r

#elif 0

	// Inline assempbly code with input operands
	uint8_t val = 23;
	__asm volatile("MOV R0, %0"::"r"(val));	//Move val into R0 (use register)

#elif 0

	uint32_t control_val = 0;
	// Read from the control register to the control_val variable
	__asm volatile("MRS %0, CONTROL":"=r"(control_val):);

#elif 0

	int a = 10, b;
	// Copy the contents of a to b
	__asm volatile("MOV %0, %1" : "=r"(b) : "r"(a));

#endif

	// Copy the address contents of a pointer to a value
	int a, *ptr;
	ptr = (int*)0x20000008;
	*ptr = 32;
	__asm("LDR %0, [%1]" : "=r"(a) : "r"(ptr));

	return 0;
}
