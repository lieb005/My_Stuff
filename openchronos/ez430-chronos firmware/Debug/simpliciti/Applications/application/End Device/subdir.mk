################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../simpliciti/Applications/application/End\ Device/main_ED_BM.c 

OBJS += \
./simpliciti/Applications/application/End\ Device/main_ED_BM.o 

C_DEPS += \
./simpliciti/Applications/application/End\ Device/main_ED_BM.d 


# Each subdirectory must supply rules for building sources it contributes
simpliciti/Applications/application/End\ Device/main_ED_BM.o: ../simpliciti/Applications/application/End\ Device/main_ED_BM.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	msp430-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"simpliciti/Applications/application/End Device/main_ED_BM.d" -MT"simpliciti/Applications/application/End\ Device/main_ED_BM.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


