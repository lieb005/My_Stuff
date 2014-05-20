################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../simpliciti/Components/bsp/bsp.c 

OBJS += \
./simpliciti/Components/bsp/bsp.o 

C_DEPS += \
./simpliciti/Components/bsp/bsp.d 


# Each subdirectory must supply rules for building sources it contributes
simpliciti/Components/bsp/%.o: ../simpliciti/Components/bsp/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	msp430-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


