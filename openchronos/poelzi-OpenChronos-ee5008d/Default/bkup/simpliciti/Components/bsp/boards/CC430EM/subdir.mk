################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../bkup/simpliciti/Components/bsp/boards/CC430EM/bsp_board.c \
../bkup/simpliciti/Components/bsp/boards/CC430EM/bsp_drivers.c 

OBJS += \
./bkup/simpliciti/Components/bsp/boards/CC430EM/bsp_board.o \
./bkup/simpliciti/Components/bsp/boards/CC430EM/bsp_drivers.o 

C_DEPS += \
./bkup/simpliciti/Components/bsp/boards/CC430EM/bsp_board.d \
./bkup/simpliciti/Components/bsp/boards/CC430EM/bsp_drivers.d 


# Each subdirectory must supply rules for building sources it contributes
bkup/simpliciti/Components/bsp/boards/CC430EM/%.o: ../bkup/simpliciti/Components/bsp/boards/CC430EM/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: mspgcc GCC C++ Compiler'
	msp430-g++ -O3 -Wall -c -fmessage-length=0 -o "$@" "$<" && \
	echo -n '$(@:%.o=%.d)' $(dir $@) > '$(@:%.o=%.d)' && \
	msp430-g++ -MM -MG -P -w -O3 -Wall -c -fmessage-length=0   "$<" >> '$(@:%.o=%.d)'
	@echo 'Finished building: $<'
	@echo ' '


