################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Src/stm32f4xx_gpio_drivers.c 

OBJS += \
./Drivers/Src/stm32f4xx_gpio_drivers.o 

C_DEPS += \
./Drivers/Src/stm32f4xx_gpio_drivers.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Src/%.o Drivers/Src/%.su: ../Drivers/Src/%.c Drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"/Users/chimaochiagha/STM32CubeIDE/MyWorkspace/Target/STM32F4xx_Drivers/Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-Src

clean-Drivers-2f-Src:
	-$(RM) ./Drivers/Src/stm32f4xx_gpio_drivers.d ./Drivers/Src/stm32f4xx_gpio_drivers.o ./Drivers/Src/stm32f4xx_gpio_drivers.su

.PHONY: clean-Drivers-2f-Src

