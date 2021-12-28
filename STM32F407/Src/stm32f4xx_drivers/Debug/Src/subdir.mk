################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/003spi_cmd.c 

OBJS += \
./Src/003spi_cmd.o 

C_DEPS += \
./Src/003spi_cmd.d 


# Each subdirectory must supply rules for building sources it contributes
Src/003spi_cmd.o: ../Src/003spi_cmd.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"/home/shak48/Documents/local-repo/EmbeddedC/STM32F407/Src/stm32f4xx_drivers/Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/003spi_cmd.d ./Src/003spi_cmd.o

.PHONY: clean-Src

