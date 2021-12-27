################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32f407vgtx.s 

C_SRCS += \
../Startup/syscalls.c \
../Startup/sysmem.c 

OBJS += \
./Startup/startup_stm32f407vgtx.o \
./Startup/syscalls.o \
./Startup/sysmem.o 

S_DEPS += \
./Startup/startup_stm32f407vgtx.d 

C_DEPS += \
./Startup/syscalls.d \
./Startup/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/%.o: ../Startup/%.s Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
Startup/%.o: ../Startup/%.c Startup/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"/home/shak48/Documents/local-repo/EmbeddedC/STM32F407/src/stm32f4xx_drivers/Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Startup

clean-Startup:
	-$(RM) ./Startup/startup_stm32f407vgtx.d ./Startup/startup_stm32f407vgtx.o ./Startup/syscalls.d ./Startup/syscalls.o ./Startup/sysmem.d ./Startup/sysmem.o

.PHONY: clean-Startup

