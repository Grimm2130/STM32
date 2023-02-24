/*
 * Registers.h
 *
 *  Created on: Feb 20, 2023
 *      Author: chimaochiagha
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef REGISTERS_H_
#define REGISTERS_H_

/**
 * Struct for the RCC_AHB1_CLK_EN register
 *
 * Description:
 * 	This Struct serves to interface the RCC_AHB1_CLK_EN,
 * 	providing convenient access to the bits in the address space
 *
 * Features:
 * 	- addr_vals: bulk access to the 32 bits of data available in address spaces
 * 	- bitFields (struct): bit-wise access to the address at location
 */
typedef struct {

	uint32_t GPIOA_EN 		: 		1;		// portA_en
	uint32_t GPIOB_EN 		: 		1;		// portB_en
	uint32_t GPIOC_EN 		:		1;		// portC_en
	uint32_t GPIOD_EN		:		1;		// portD_en
	uint32_t GPIOE_EN		:		1;		// portE_en
	uint32_t GPIOF_EN		:		1;		// portF_en
	uint32_t GPIOG_EN		:		1;		// portG_en
	uint32_t GPIOH_EN		:		1;		// portH_en
	uint32_t GPIOI_EN		:		1;		// portI_en
	uint32_t res_1			:		3;		// reserved group 1
	uint32_t CRC_EN			:		1;		// CRC clock_en
	uint32_t res_2			:		5;		// reserved group 2
	uint32_t BKPSRAM_EN		:		1;		// Backup SRAM interface clock
	uint32_t res_3			:		1;		// reserved group 3
	uint32_t CCMDATARAM_EN	:		1;		// CCM data RAM
	uint32_t DMA1_EN		:		1;		// DMA1 clock en
	uint32_t DMA2_EN		:		1;		// DMA2 clock en
	uint32_t res_4			:		2;		// reserved group 4
	uint32_t ETHMAC_EN		:		1;		// Ethernet MAC clock enable
	uint32_t ETHMACTX_EN	:		1;		// Ethernet Transmission clock enable
	uint32_t ETHMACRX_EN	:		1;		// Ethernet Reception clock enable
	uint32_t ETHMACPTP_EN	:		1;		// Ethernet PTP clock enable
	uint32_t OTGHS_EN		:		1;		// USB OTG HS clock enable
	uint32_t OTGHSULPI_EN	:		1;		// USB OTG HSULPI clock enable
	uint32_t res_5			:		1;		// reserved group 5

} RCC_AHB1_CLK_EN_t;


// Port output mode register
typedef struct{
	uint32_t MODE_0 		: 		2;		// Port mode register for GPIOx port 0
	uint32_t MODE_1 		: 		2;		// Port mode register for GPIOx port 1
	uint32_t MODE_2 		: 		2;		// Port mode register for GPIOx port 2
	uint32_t MODE_3 		: 		2;		// Port mode register for GPIOx port 3
	uint32_t MODE_4 		: 		2;		// Port mode register for GPIOx port 4
	uint32_t MODE_5 		: 		2;		// Port mode register for GPIOx port 5
	uint32_t MODE_6 		: 		2;		// Port mode register for GPIOx port 6
	uint32_t MODE_7 		: 		2;		// Port mode register for GPIOx port 7
	uint32_t MODE_8 		: 		2;		// Port mode register for GPIOx port 8
	uint32_t MODE_9 		: 		2;		// Port mode register for GPIOx port 9
	uint32_t MODE_10 		: 		2;		// Port mode register for GPIOx port 10
	uint32_t MODE_11		: 		2;		// Port mode register for GPIOx port 11
	uint32_t MODE_12 		: 		2;		// Port mode register for GPIOx port 12
	uint32_t MODE_13		: 		2;		// Port mode register for GPIOx port 13
	uint32_t MODE_14 		: 		2;		// Port mode register for GPIOx port 14
	uint32_t MODE_15		: 		2;		// Port mode register for GPIOx port 15
} GPIOxMODER_t;


// Output port register
typedef struct{
	uint32_t ODR_0 			: 		1; 		// Output port for GPIOx port 0
	uint32_t ODR_1 			: 		1; 		// Output port for GPIOx port 1
	uint32_t ODR_2 			: 		1; 		// Output port for GPIOx port 2
	uint32_t ODR_3 			: 		1; 		// Output port for GPIOx port 3
	uint32_t ODR_4 			: 		1; 		// Output port for GPIOx port 4
	uint32_t ODR_5 			: 		1; 		// Output port for GPIOx port 5
	uint32_t ODR_6 			: 		1; 		// Output port for GPIOx port 6
	uint32_t ODR_7 			: 		1; 		// Output port for GPIOx port 7
	uint32_t ODR_8 			: 		1; 		// Output port for GPIOx port 8
	uint32_t ODR_9 			: 		1; 		// Output port for GPIOx port 9
	uint32_t ODR_10 		: 		1; 		// Output port for GPIOx port 10
	uint32_t ODR_11 		: 		1; 		// Output port for GPIOx port 11
	uint32_t ODR_12 		: 		1; 		// Output port for GPIOx port 12
	uint32_t ODR_13 		: 		1; 		// Output port for GPIOx port 13
	uint32_t ODR_14 		: 		1; 		// Output port for GPIOx port 14
	uint32_t ODR_15 		: 		1; 		// Output port for GPIOx port 15
	uint32_t reserved		: 		16;		// reserved bits
} GPIOx_ODR_t;

#endif /* REGISTERS_H_ */
