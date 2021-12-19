################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/src/stm32f407xx_gpio_driver.c \
../driver/src/stm32f407xx_spi_driver.c 

OBJS += \
./driver/src/stm32f407xx_gpio_driver.o \
./driver/src/stm32f407xx_spi_driver.o 

C_DEPS += \
./driver/src/stm32f407xx_gpio_driver.d \
./driver/src/stm32f407xx_spi_driver.d 


# Each subdirectory must supply rules for building sources it contributes
driver/src/%.o: ../driver/src/%.c driver/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"/home/shak48/Documents/shak48-repos/EmbeddedC/STM32F407/src/stm32f4xx_drivers/driver/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-driver-2f-src

clean-driver-2f-src:
	-$(RM) ./driver/src/stm32f407xx_gpio_driver.d ./driver/src/stm32f407xx_gpio_driver.o ./driver/src/stm32f407xx_spi_driver.d ./driver/src/stm32f407xx_spi_driver.o

.PHONY: clean-driver-2f-src

