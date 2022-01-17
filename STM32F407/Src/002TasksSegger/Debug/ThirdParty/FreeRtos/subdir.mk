################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ThirdParty/FreeRtos/croutine.c \
../ThirdParty/FreeRtos/event_groups.c \
../ThirdParty/FreeRtos/list.c \
../ThirdParty/FreeRtos/queue.c \
../ThirdParty/FreeRtos/stream_buffer.c \
../ThirdParty/FreeRtos/tasks.c \
../ThirdParty/FreeRtos/timers.c 

OBJS += \
./ThirdParty/FreeRtos/croutine.o \
./ThirdParty/FreeRtos/event_groups.o \
./ThirdParty/FreeRtos/list.o \
./ThirdParty/FreeRtos/queue.o \
./ThirdParty/FreeRtos/stream_buffer.o \
./ThirdParty/FreeRtos/tasks.o \
./ThirdParty/FreeRtos/timers.o 

C_DEPS += \
./ThirdParty/FreeRtos/croutine.d \
./ThirdParty/FreeRtos/event_groups.d \
./ThirdParty/FreeRtos/list.d \
./ThirdParty/FreeRtos/queue.d \
./ThirdParty/FreeRtos/stream_buffer.d \
./ThirdParty/FreeRtos/tasks.d \
./ThirdParty/FreeRtos/timers.d 


# Each subdirectory must supply rules for building sources it contributes
ThirdParty/FreeRtos/%.o: ../ThirdParty/FreeRtos/%.c ThirdParty/FreeRtos/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/shak48/Documents/shak48-repos/EmbeddedC/STM32F407/FreeRtos_Projects/ThirdParty/FreeRtos" -I"/home/shak48/Documents/shak48-repos/EmbeddedC/STM32F407/FreeRtos_Projects/ThirdParty/FreeRtos" -I"/home/shak48/Documents/shak48-repos/EmbeddedC/STM32F407/FreeRtos_Projects/ThirdParty/FreeRtos/include" -I"/home/shak48/Documents/shak48-repos/EmbeddedC/STM32F407/FreeRtos_Projects/ThirdParty/FreeRtos/portable/GCC/ARM_CM4F" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ThirdParty-2f-FreeRtos

clean-ThirdParty-2f-FreeRtos:
	-$(RM) ./ThirdParty/FreeRtos/croutine.d ./ThirdParty/FreeRtos/croutine.o ./ThirdParty/FreeRtos/event_groups.d ./ThirdParty/FreeRtos/event_groups.o ./ThirdParty/FreeRtos/list.d ./ThirdParty/FreeRtos/list.o ./ThirdParty/FreeRtos/queue.d ./ThirdParty/FreeRtos/queue.o ./ThirdParty/FreeRtos/stream_buffer.d ./ThirdParty/FreeRtos/stream_buffer.o ./ThirdParty/FreeRtos/tasks.d ./ThirdParty/FreeRtos/tasks.o ./ThirdParty/FreeRtos/timers.d ./ThirdParty/FreeRtos/timers.o

.PHONY: clean-ThirdParty-2f-FreeRtos

