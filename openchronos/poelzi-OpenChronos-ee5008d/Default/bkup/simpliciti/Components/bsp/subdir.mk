################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../bkup/simpliciti/Components/bsp/bsp.o 

C_SRCS += \
../bkup/simpliciti/Components/bsp/bsp.c 

OBJS += \
./bkup/simpliciti/Components/bsp/bsp.o 

C_DEPS += \
./bkup/simpliciti/Components/bsp/bsp.d 


# Each subdirectory must supply rules for building sources it contributes
bkup/simpliciti/Components/bsp/%.o: ../bkup/simpliciti/Components/bsp/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: mspgcc GCC C++ Compiler'
	msp430-g++ -O3 -Wall -c -fmessage-length=0 -o "$@" "$<" && \
	echo -n '$(@:%.o=%.d)' $(dir $@) > '$(@:%.o=%.d)' && \
	msp430-g++ -MM -MG -P -w -O3 -Wall -c -fmessage-length=0   "$<" >> '$(@:%.o=%.d)'
	@echo 'Finished building: $<'
	@echo ' '


