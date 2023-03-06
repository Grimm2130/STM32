/*
 * led.c
 *
 *  Created on: Mar 6, 2023
 *      Author: chimaochiagha
 */
#include <stdint.h>
#include <stdio.h>
#include "led.h"

/** -------------------------------------------------------------- **/
/**------------------- Struct Pointer Instantiation -------------- **/
/** -------------------------------------------------------------- **/

// AHB1 clock enable
rcc_ahb1_enr_t* const ahb1_reg = (rcc_ahb1_enr_t*) RCC_AHB1ENR;

// Mode register
gpiox_mode_t* const gpioD_mode = (gpiox_mode_t*) (GPIO_BASE_ADDR + GPIO_D_MODER_OFFSET);

// Output Port registers
gpiox_odr_t* const gpioD_odr = (gpiox_odr_t*) (GPIO_BASE_ADDR + GPIO_D_ODR_OFFSET);


/** -------------------------------------------------------------- **/
/**-------------------Function Definition Definition ------------- **/
/** -------------------------------------------------------------- **/

void init_leds(){
	// Enable the clock registers
	ahb1_reg->gpio_D = 0x1;

	// Set the port as output
	gpioD_mode->port_12 = 0x01;
	gpioD_mode->port_13 = 0x01;
	gpioD_mode->port_14 = 0x01;
	gpioD_mode->port_15 = 0x01;

	// initiate the LED states
	gpioD_odr->port_12 = 0x0;
	gpioD_odr->port_13 = 0x0;
	gpioD_odr->port_14 = 0x0;
	gpioD_odr->port_15 = 0x0;
}

void GreenSwitch(uint8_t state){
	switch(state){
	case 0:
		// turn off
		gpioD_odr->port_12 = 0x0;
		break;
	case 1:
		gpioD_odr->port_12 = 0x1;
		break;
	}
}

void OrangeSwitch(uint8_t state){
	switch(state){
	case 0:
		// turn off
		gpioD_odr->port_13 = 0x0;
		break;
	case 1:
		gpioD_odr->port_13 = 0x1;
		break;
	}
}

void RedSwitch(uint8_t state){
	switch(state){
	case 0:
		// turn off
		gpioD_odr->port_14 = 0x0;
		break;
	case 1:
		gpioD_odr->port_14 = 0x1;
		break;
	}
}


void BlueSwitch(uint8_t state){
	switch(state){
	case 0:
		// turn off
		gpioD_odr->port_15 = 0x0;
		break;
	case 1:
		gpioD_odr->port_15 = 0x1;
		break;
	}
}
