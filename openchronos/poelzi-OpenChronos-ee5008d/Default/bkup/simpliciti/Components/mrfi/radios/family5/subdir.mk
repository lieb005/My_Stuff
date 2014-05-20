################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../bkup/simpliciti/Components/mrfi/radios/family5/mrfi_radio.c \
../bkup/simpliciti/Components/mrfi/radios/family5/mrfi_radio_interface.c 

OBJS += \
./bkup/simpliciti/Components/mrfi/radios/family5/mrfi_radio.o \
./bkup/simpliciti/Components/mrfi/radios/family5/mrfi_radio_interface.o 

C_DEPS += \
./bkup/simpliciti/Components/mrfi/radios/family5/mrfi_radio.d \
./bkup/simpliciti/Components/mrfi/radios/family5/mrfi_radio_interface.d 


# Each subdirectory must supply rules for building sources it contributes
bkup/simpliciti/Components/mrfi/radios/family5/%.o: ../bkup/simpliciti/Components/mrfi/radios/family5/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: mspgcc GCC C++ Compiler'
	msp430-g++ -O3 -Wall -c -fmessage-length=0 -o "$@" "$<" && \
	echo -n '$(@:%.o=%.d)' $(dir $@) > '$(@:%.o=%.d)' && \
	msp430-g++ -MM -MG -P -w -O3 -Wall -c -fmessage-length=0   "$<" >> '$(@:%.o=%.d)'
	@echo 'Finished building: $<'
	@echo ' '


