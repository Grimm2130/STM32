/*
 * led.h
 *
 *  Created on: Mar 5, 2023
 *      Author: chimaochiagha
 */

#ifndef LED_H_
#define LED_H_

/** -------------------------------------------------------------- **/
/**----------------------- Address Definition -------------------- **/
/** -------------------------------------------------------------- **/
// RCC
#define RCC_BASE_ADDR 0x40023800U
#define RCC_AHB1ENR_OFFSET 0x30U
#define RCC_AHB1ENR  ((RCC_BASE_ADDR)+ (RCC_AHB1ENR_OFFSET))
// GPIO
#define GPIO_BASE_ADDR 0x40020C00U
#define GPIO_D_MODER_OFFSET 0x00U
#define GPIO_D_ODR_OFFSET 0x14U

/** -------------------------------------------------------------- **/
/**------------------- Struct Definition ----------------- **/
/** -------------------------------------------------------------- **/
typedef struct{
	uint32_t gpio_A : 1;
	uint32_t gpio_B : 1;
	uint32_t gpio_C : 1;
	uint32_t gpio_D : 1;
	uint32_t gpio_E : 1;
	uint32_t gpio_F : 1;
	uint32_t gpio_G : 1;
	uint32_t gpio_H : 1;
	uint32_t gpio_I : 1;
	uint32_t gpio_J : 1;
	uint32_t gpio_K : 1;
	uint32_t res : 21;
} rcc_ahb1_enr_t;

// AHB1 clock enable
extern rcc_ahb1_enr_t* const ahb1_reg;



// GPIO Mode Registers
typedef struct{
	uint32_t port_0 : 2;
	uint32_t port_1 : 2;
	uint32_t port_2 : 2;
	uint32_t port_3 : 2;
	uint32_t port_4 : 2;
	uint32_t port_5 : 2;
	uint32_t port_6 : 2;
	uint32_t port_7 : 2;
	uint32_t port_8 : 2;
	uint32_t port_9 : 2;
	uint32_t port_10 : 2;
	uint32_t port_11 : 2;
	uint32_t port_12 : 2;
	uint32_t port_13 : 2;
	uint32_t port_14 : 2;
	uint32_t port_15 : 2;

}gpiox_mode_t;

// Mode register
extern gpiox_mode_t* const gpioD_mode;


// GPIO Output Port registers
typedef struct{
	uint32_t port_0 : 1;
	uint32_t port_1 : 1;
	uint32_t port_2 : 1;
	uint32_t port_3 : 1;
	uint32_t port_4 : 1;
	uint32_t port_5 : 1;
	uint32_t port_6 : 1;
	uint32_t port_7 : 1;
	uint32_t port_8 : 1;
	uint32_t port_9 : 1;
	uint32_t port_10 : 1;
	uint32_t port_11 : 1;
	uint32_t port_12 : 1;
	uint32_t port_13 : 1;
	uint32_t port_14 : 1;
	uint32_t port_15 : 1;
	uint32_t reserved : 16;
} gpiox_odr_t;

// Output Port registers
extern gpiox_odr_t* const gpioD_odr;



/** -------------------------------------------------------------- **/
/**------------------- Function Definition ----------------- **/
/** -------------------------------------------------------------- **/


void init_leds();
void GreenSwitch(uint8_t state);
void OrangeSwitch(uint8_t state);
void RedSwitch(uint8_t state);
void BlueSwitch(uint8_t state);


#endif /* LED_H_ */
