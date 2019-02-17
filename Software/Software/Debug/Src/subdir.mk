################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Kalman.c \
../Src/PID.c \
../Src/gy521.c \
../Src/main.c \
../Src/motion_control.c \
../Src/stm32f1xx_hal_msp.c \
../Src/stm32f1xx_it.c \
../Src/system_stm32f1xx.c 

OBJS += \
./Src/Kalman.o \
./Src/PID.o \
./Src/gy521.o \
./Src/main.o \
./Src/motion_control.o \
./Src/stm32f1xx_hal_msp.o \
./Src/stm32f1xx_it.o \
./Src/system_stm32f1xx.o 

C_DEPS += \
./Src/Kalman.d \
./Src/PID.d \
./Src/gy521.d \
./Src/main.d \
./Src/motion_control.d \
./Src/stm32f1xx_hal_msp.d \
./Src/stm32f1xx_it.d \
./Src/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F100xB -I"C:/Users/user/Documents/Projekty/Balancer/Software/Software/Inc" -I"C:/Users/user/Documents/Projekty/Balancer/Software/Software/Drivers/STM32F1xx_HAL_Driver/Inc" -I"C:/Users/user/Documents/Projekty/Balancer/Software/Software/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy" -I"C:/Users/user/Documents/Projekty/Balancer/Software/Software/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"C:/Users/user/Documents/Projekty/Balancer/Software/Software/Drivers/CMSIS/Include"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


