################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../bkup/gcc/intrinsics.o 

C_SRCS += \
../bkup/gcc/intrinsics.c 

OBJS += \
./bkup/gcc/intrinsics.o 

C_DEPS += \
./bkup/gcc/intrinsics.d 


# Each subdirectory must supply rules for building sources it contributes
bkup/gcc/%.o: ../bkup/gcc/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: mspgcc GCC C++ Compiler'
	msp430-g++ -O3 -Wall -c -fmessage-length=0 -o "$@" "$<" && \
	echo -n '$(@:%.o=%.d)' $(dir $@) > '$(@:%.o=%.d)' && \
	msp430-g++ -MM -MG -P -w -O3 -Wall -c -fmessage-length=0   "$<" >> '$(@:%.o=%.d)'
	@echo 'Finished building: $<'
	@echo ' '


