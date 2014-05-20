################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../simpliciti/Components/mrfi/radios/family5/mrfi_radio.c \
../simpliciti/Components/mrfi/radios/family5/mrfi_radio_interface.c 

OBJS += \
./simpliciti/Components/mrfi/radios/family5/mrfi_radio.o \
./simpliciti/Components/mrfi/radios/family5/mrfi_radio_interface.o 

C_DEPS += \
./simpliciti/Components/mrfi/radios/family5/mrfi_radio.d \
./simpliciti/Components/mrfi/radios/family5/mrfi_radio_interface.d 


# Each subdirectory must supply rules for building sources it contributes
simpliciti/Components/mrfi/radios/family5/%.o: ../simpliciti/Components/mrfi/radios/family5/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	msp430-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


