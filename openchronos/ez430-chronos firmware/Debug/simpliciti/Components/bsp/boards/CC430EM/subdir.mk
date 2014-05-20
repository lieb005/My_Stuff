################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../simpliciti/Components/bsp/boards/CC430EM/bsp_board.c \
../simpliciti/Components/bsp/boards/CC430EM/bsp_drivers.c 

OBJS += \
./simpliciti/Components/bsp/boards/CC430EM/bsp_board.o \
./simpliciti/Components/bsp/boards/CC430EM/bsp_drivers.o 

C_DEPS += \
./simpliciti/Components/bsp/boards/CC430EM/bsp_board.d \
./simpliciti/Components/bsp/boards/CC430EM/bsp_drivers.d 


# Each subdirectory must supply rules for building sources it contributes
simpliciti/Components/bsp/boards/CC430EM/%.o: ../simpliciti/Components/bsp/boards/CC430EM/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	msp430-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


