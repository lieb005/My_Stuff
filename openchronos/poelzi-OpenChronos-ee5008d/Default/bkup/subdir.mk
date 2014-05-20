################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../bkup/even_in_range.o \
../bkup/ezchronos.o 

C_SRCS += \
../bkup/ezchronos.c 

S_SRCS += \
../bkup/even_in_range.s 

OBJS += \
./bkup/even_in_range.o \
./bkup/ezchronos.o 

C_DEPS += \
./bkup/ezchronos.d 


# Each subdirectory must supply rules for building sources it contributes
bkup/%.o: ../bkup/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: mspgcc GCC Assembler'
	msp430-as  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bkup/%.o: ../bkup/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: mspgcc GCC C++ Compiler'
	msp430-g++ -O3 -Wall -c -fmessage-length=0 -o "$@" "$<" && \
	echo -n '$(@:%.o=%.d)' $(dir $@) > '$(@:%.o=%.d)' && \
	msp430-g++ -MM -MG -P -w -O3 -Wall -c -fmessage-length=0   "$<" >> '$(@:%.o=%.d)'
	@echo 'Finished building: $<'
	@echo ' '


