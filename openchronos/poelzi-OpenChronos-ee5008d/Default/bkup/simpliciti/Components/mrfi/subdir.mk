################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../bkup/simpliciti/Components/mrfi/mrfi.o 

C_SRCS += \
../bkup/simpliciti/Components/mrfi/mrfi.c 

OBJS += \
./bkup/simpliciti/Components/mrfi/mrfi.o 

C_DEPS += \
./bkup/simpliciti/Components/mrfi/mrfi.d 


# Each subdirectory must supply rules for building sources it contributes
bkup/simpliciti/Components/mrfi/%.o: ../bkup/simpliciti/Components/mrfi/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: mspgcc GCC C++ Compiler'
	msp430-g++ -O3 -Wall -c -fmessage-length=0 -o "$@" "$<" && \
	echo -n '$(@:%.o=%.d)' $(dir $@) > '$(@:%.o=%.d)' && \
	msp430-g++ -MM -MG -P -w -O3 -Wall -c -fmessage-length=0   "$<" >> '$(@:%.o=%.d)'
	@echo 'Finished building: $<'
	@echo ' '

