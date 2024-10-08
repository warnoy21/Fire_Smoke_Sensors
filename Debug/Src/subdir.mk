################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/flame_sensor.c \
../Src/main.c \
../Src/smoke_adc.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/systick_delay.c \
../Src/uart_pi.c 

OBJS += \
./Src/flame_sensor.o \
./Src/main.o \
./Src/smoke_adc.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/systick_delay.o \
./Src/uart_pi.o 

C_DEPS += \
./Src/flame_sensor.d \
./Src/main.d \
./Src/smoke_adc.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/systick_delay.d \
./Src/uart_pi.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -DSTM32F411xE -c -I../Inc -I"D:/RTOS_D/workspace/chip_headers/STM32Cube_FW_F4_V1.28.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/RTOS_D/workspace/chip_headers/STM32Cube_FW_F4_V1.28.0/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/flame_sensor.cyclo ./Src/flame_sensor.d ./Src/flame_sensor.o ./Src/flame_sensor.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/smoke_adc.cyclo ./Src/smoke_adc.d ./Src/smoke_adc.o ./Src/smoke_adc.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/systick_delay.cyclo ./Src/systick_delay.d ./Src/systick_delay.o ./Src/systick_delay.su ./Src/uart_pi.cyclo ./Src/uart_pi.d ./Src/uart_pi.o ./Src/uart_pi.su

.PHONY: clean-Src

