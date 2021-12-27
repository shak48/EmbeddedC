################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driverss/Src/stm32f407xx_gpio_driver.c \
../driverss/Src/stm32f407xx_spi_driver.c 

OBJS += \
./driverss/Src/stm32f407xx_gpio_driver.o \
./driverss/Src/stm32f407xx_spi_driver.o 

C_DEPS += \
./driverss/Src/stm32f407xx_gpio_driver.d \
./driverss/Src/stm32f407xx_spi_driver.d 


# Each subdirectory must supply rules for building sources it contributes
driverss/Src/%.o: ../driverss/Src/%.c driverss/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-driverss-2f-Src

clean-driverss-2f-Src:
	-$(RM) ./driverss/Src/stm32f407xx_gpio_driver.d ./driverss/Src/stm32f407xx_gpio_driver.o ./driverss/Src/stm32f407xx_spi_driver.d ./driverss/Src/stm32f407xx_spi_driver.o

.PHONY: clean-driverss-2f-Src

