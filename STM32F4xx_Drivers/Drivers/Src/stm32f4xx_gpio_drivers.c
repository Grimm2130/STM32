/*
 * stm32f4xx_gpio_drivers.c
 *
 *  Created on: Mar 13, 2023
 *      Author: chimaochiagha
 */


#include "stm32f4xx_gpio_driver.h"

/*
 * fn 			:
 *
 * des 			:	return an unsigned offset of the GPIO port relative to GPIO A
 *
 *
 * */
uint8_t get_gpio_addr_offset(gpio_hndlr_t* pGpio){
	// Define offset variable
	uint8_t offset = 0;
	for(uint32_t i = GPIO_A_BASE_ADDR; i <= GPIO_K_BASE_ADDR; i+= GPIOx_ADDR_OFF){
		// Check if at GPIO address
		if(i == (uint32_t) pGpio){
			break;
		}
		offset++;
	}
	return offset;
}

/**
 *	fn			: 	GPIO handler function
 *
 *	des 		: 	This is used to instnatiate a gpio pin to a spcified output mode
 *
 *	@param(1)	:	Pointer to struct of a GPIO address handler
 *	@param(2)	:	uint8_t representation of state (find under "MODES" in Header file's macros section)
 *
 *	note		: 	None
 *
 *	ret			: 	None
 */
uint8_t GPIOx_init(gpio_hndlr_t* pGpio, uint8_t pinNum, uint8_t state, uint8_t type){
	uint8_t fault = 0;
	// Set Mode of pin
	switch(state){

		// Mode : input
		case INPUT:
			pGpio->MODE_R &= ~(0x3 << (2*pinNum));
			if(type){
				// Set input config of pin
				pGpio->PU_PD_R |= (type << (2*pinNum));
			}
			break;

		// Mode : output
		case OUTPUT:
			pGpio->MODE_R |= (0x1 << (2*pinNum));
			if(type){
				pGpio->OTYPE_R |= (type << (pinNum));
			}
			break;

		// Mode : Alternate
		case ALT:
			pGpio->MODE_R |= (state << (2*pinNum));
			break;

		// Mode : Analog
		case ANLG:
			// #TODO
			break;

		// Fault : Invalid Mode
		default:
			fault = 1;
			break;
	}
	return fault;
}

/**
 *	fn			:		Enables the GPIO on the AHB1 bus
 *
 *	des 		:		Loops Checks for the address of the GPIO's Address offset on the memory map
 *						and enables the equivalent bit offset on the RCC_abh1_en register
 *
 *	@param(1)	:		Base Address of GPIO port
 *
 *	note		:		Port clock should be enabled before anything else is done
 *
 *	ret			:		none
 */
void GPIOx_clk_en(gpio_hndlr_t* pGpio){
	// define an instance of the RCC handler
	rcc_hndlr_t* pRcc_handler = (rcc_hndlr_t*) RCC_BASE_ADDR;

	// Loop through the gpio addresses
	uint8_t offset = get_gpio_addr_offset(pGpio);
	// enable the GPIO at that offset
	pRcc_handler->RCC_AHB1_ENR |= (EN << offset);
}


/**
 *	fn			:	GPIO read
 *
 *	des 		:	Read the state of an input pin on a GPIO port
 *
 *	@param(1)	:	Base Address of GPIO port
 *	@param(2)	:	Pin number of port
 *
 *	note		:	Port must be in INPUT mode
 *
 *	ret			:	1 or 0
 */
uint8_t Gpiox_read(gpio_hndlr_t* pGpio, uint8_t pinNum){
	return ( pGpio->ID_R & (1 << pinNum) );
}


/**
 *	fn			: 	GPIO pin write
 *
 *	des 		:	Function to write a state to a gpio output pin
 *
 *	@param(1)	:	Base address of GPIO
 *	@param(2)	:	Pin Number
 *	@param(3)	:	State of pin
 *
 *	note		:
 *
 *	ret			:
 */
void Gpiox_write(gpio_hndlr_t* pGpio, uint8_t pinNum, uint8_t state){
	switch(state){
	case ON:
		pGpio->OD_R |= TURN_ON(pinNum);
		break;
	case OFF:
		pGpio->OD_R &= TURN_OFF(pinNum);
		break;
	}
}

/**
 *	fn			:		GPIO toggle function
 *
 *	des 		:		Function to toggle the output of a GPIO pin
 *
 *	@param(1)	:		Base address of GPIO pin
 *	@param(2)	:		Pin Number on GPIO port
 *
 *	note		:		Pin Mode == OUTPUT
 *
 *	ret			:		None
 */
void Gpiox_toggle(gpio_hndlr_t* pGpio, uint8_t pinNum){
	pGpio->OD_R ^= (ON << pinNum);
}



/**
 *	fn			:		GPIO function enable
 *
 *	des 		:		Function to instantiate the alternate function of a GPIO port
 *
 *	@param(1)	:		Base address of GPIO register
 *	@param(2)	:		Pin Number of register
*	@param(3)	:		Alternate function number
 *
 *	note		:		Pin must be configured to alternate mode
 *
 *	ret			:		None
 */
void Gpiox_alt_en(gpio_hndlr_t* pGpio, uint8_t pinNum, uint8_t alt_fn){
	// Configure the alternate function of the pin
	if( (pinNum >= 0) && (pinNum <= 7) ){
		pGpio->AFL_R |= (alt_fn << (4*pinNum));
	}
	else{
		// Account for High set register
		pinNum -= 8;
		pGpio->AFH_R |= (alt_fn << (4*pinNum));
	}
}


/**
 *	fn			:		Initialize External interrupt for a pin
 *
 *	des 		:		Function to attach an external interrupt to a pin. Sets all the required
 *						Configurations for and external interrupt for a port's pin
 *
 *	@param(1)	:		Base address of GPIO port
 *	@param(2)	:		Pin number on port
 *	@param(4)	:		Edge type of interrupt: RISING, FALLING, CHANGE
 *
 *	note		:		Pin must be configured and set to INPUT mode.
 *
 *	ret			:		-1 if failed, else EXTI number. Other functionalities UNDEV
 */
int8_t Gpiox_init_ext_int(gpio_hndlr_t* pGpio, uint8_t pinNum, uint8_t edgeType){
	// Check for valid pin
	if(pinNum < 0 || pinNum > 15){
		return -1;
	}


	/*------------- Enable EXTIx line on the NVIC controller -------------*/
	nvic_iser_handler_t* nvic_iser = (nvic_iser_handler_t*) NVIC_ISER_BASE_ADDR;
	// EXTI lines 0 - 4
	if(pinNum >= 0 && pinNum <= 4){
		uint8_t nvic_pos = pinNum + 6;
		nvic_iser->NVIC_ISER_0 |= (1 << nvic_pos);
	}
	else if(pinNum >= 5 && pinNum <= 9){
		nvic_iser->NVIC_ISER_0 |= (1 << 23);
	}
	else{
		nvic_iser->NVIC_ISER_1 |= (1 << (40-32));
	}


	/*------------- Configure EXTI to be GPIO pin addressable-------------*/

	// Enable an instance of a sys_cnfg memory handler
	sys_cnfg_hndlr_t* sys_cnfg = (sys_cnfg_hndlr_t*) 0x40013800U;

	// Get the GPIO port offset
	uint32_t sys_pinOFF = (uint32_t) get_gpio_addr_offset(pGpio);

	// get the EXTIx index on syscnfg exti config register
	uint8_t exti_x_index = pinNum/4;
	// Get pin offset on EXTIx register in sysconfig exti register
	uint8_t exti_off = pinNum%4;

	// Enable the interrupt on the syscnfg controller
	switch(exti_x_index){
		case 0:
			sys_cnfg->SYSCFG_EXTI_CR1 |= (sys_pinOFF << (4*exti_off));
			break;
		case 1:
			sys_cnfg->SYSCFG_EXTI_CR2 |= (sys_pinOFF << (4*exti_off));
			break;
		case 2:
			sys_cnfg->SYSCFG_EXTI_CR3 |= (sys_pinOFF <= (4*exti_off));
			break;
		case 3:
			sys_cnfg->SYSCFG_EXTI_CR4 |= (sys_pinOFF << (4*exti_off));
			break;
		// Fault case
		default:
			return 1;
	}

	/* ---- Enable and Configure EXTI interrupt triggers --------*/
	// Un-mask the interrupt on the EXTI line
	exti_hndlr_t* exti = (exti_hndlr_t*) EXTI_BASE_ADDR;
	exti->EXT_IMR |= (1 << pinNum);

	// Select the trigger mode of the interrupt
	switch(edgeType){
	// Trigger on rising edge
	case RISING:
		exti->EXTI_RTSR |= (1 << pinNum);
		break;
	// Trigger on falling edge
	case FALLING:
		exti->EXTI_FTSR	|= (1 << pinNum);
		break;
	// Change in value
	case CHANGE:
		exti->EXTI_RTSR |= (1 << pinNum);
		exti->EXTI_FTSR	|= (1 << pinNum);
		break;
	}

	return pinNum;
}


/**
 *	fn			:		GPIOx de-initialization register
 *
 *	des 		:		Function to de-initialize the GPIO registers
 *
 *	@param(1)	:		Base address of GPIO register
 *
 *	note		:		None
 *
 *	ret			:		None
 */
void Gpiox_de_init(gpio_hndlr_t* pGpio){
	// Instantiate RCC pointer to base address
	rcc_hndlr_t* rcc_hndlr = (rcc_hndlr_t*) RCC_BASE_ADDR;
	// Loop for GPIO offset
	uint8_t offset = get_gpio_addr_offset(pGpio);
	// Reset GPIO port
	rcc_hndlr->RCC_AHB1_RSTR |= (EN << offset);
}
