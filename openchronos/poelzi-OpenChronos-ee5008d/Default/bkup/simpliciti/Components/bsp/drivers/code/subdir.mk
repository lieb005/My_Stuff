################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../bkup/simpliciti/Components/bsp/drivers/code/bsp_buttons.c \
../bkup/simpliciti/Components/bsp/drivers/code/bsp_leds.c 

OBJS += \
./bkup/simpliciti/Components/bsp/drivers/code/bsp_buttons.o \
./bkup/simpliciti/Components/bsp/drivers/code/bsp_leds.o 

C_DEPS += \
./bkup/simpliciti/Components/bsp/drivers/code/bsp_buttons.d \
./bkup/simpliciti/Components/bsp/drivers/code/bsp_leds.d 


# Each subdirectory must supply rules for building sources it contributes
bkup/simpliciti/Components/bsp/drivers/code/%.o: ../bkup/simpliciti/Components/bsp/drivers/code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: mspgcc GCC C++ Compiler'
	msp430-g++ -O3 -Wall -c -fmessage-length=0 -o "$@" "$<" && \
	echo -n '$(@:%.o=%.d)' $(dir $@) > '$(@:%.o=%.d)' && \
	msp430-g++ -MM -MG -P -w -O3 -Wall -c -fmessage-length=0   "$<" >> '$(@:%.o=%.d)'
	@echo 'Finished building: $<'
	@echo ' '


