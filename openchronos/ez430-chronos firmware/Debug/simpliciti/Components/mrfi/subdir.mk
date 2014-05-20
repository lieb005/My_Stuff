################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../simpliciti/Components/mrfi/mrfi.c 

OBJS += \
./simpliciti/Components/mrfi/mrfi.o 

C_DEPS += \
./simpliciti/Components/mrfi/mrfi.d 


# Each subdirectory must supply rules for building sources it contributes
simpliciti/Components/mrfi/%.o: ../simpliciti/Components/mrfi/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	msp430-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


