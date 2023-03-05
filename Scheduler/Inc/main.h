/*
 * main.h
 *
 *  Created on: Mar 5, 2023
 *      Author: chimaochiagha
 */

#ifndef MAIN_H_
#define MAIN_H_

/** -------------------------------------------------------------- **/
/**------------------- Address Definition ----------------- **/
/** -------------------------------------------------------------- **/
// Sys-tick Control Register
#define SYST_CSR (* (uint32_t volatile*) 0xE000E010)
// Sys-tick Reload Value Register
#define SYST_RVR (* (uint32_t volatile*) 0xE000E014)
// SysTick Current Value Register
#define SYST_CVR (* (uint32_t volatile*) 0xE000E018)

// System Exceptions
#define SHCSR (* (uint32_t volatile*) 0xE000ED24)

/** -------------------------------------------------------------- **/
/**------------------- Constants Definition ----------------- **/
/** -------------------------------------------------------------- **/

#define CPU_FREQ 16000000U
#define CPU_PERIOD (1.0/CPU_FREQ)

// SRAM
#define SRAM_START 0x20000000U
#define SRAM_SIZE (1024 * 128)
#define SRAM_END (SRAM_START + SRAM_SIZE)
/// Tasks
#define TASK_SIZE 1024U
#define TASK_1_START (SRAM_END)
#define TASK_2_START (SRAM_END - (TASK_SIZE))
#define TASK_3_START ( (SRAM_END) - ((2) * (TASK_SIZE)) )
#define TASK_4_START (SRAM_END - ((3) * (TASK_SIZE)))
#define SCHED_TASK_START (SRAM_END - ((4) * (TASK_SIZE)))

#define MAX_TASKS 4


#endif /* MAIN_H_ */