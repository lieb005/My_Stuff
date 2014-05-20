################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../simpliciti/Components/nwk/nwk.c \
../simpliciti/Components/nwk/nwk_QMgmt.c \
../simpliciti/Components/nwk/nwk_api.c \
../simpliciti/Components/nwk/nwk_frame.c \
../simpliciti/Components/nwk/nwk_globals.c 

OBJS += \
./simpliciti/Components/nwk/nwk.o \
./simpliciti/Components/nwk/nwk_QMgmt.o \
./simpliciti/Components/nwk/nwk_api.o \
./simpliciti/Components/nwk/nwk_frame.o \
./simpliciti/Components/nwk/nwk_globals.o 

C_DEPS += \
./simpliciti/Components/nwk/nwk.d \
./simpliciti/Components/nwk/nwk_QMgmt.d \
./simpliciti/Components/nwk/nwk_api.d \
./simpliciti/Components/nwk/nwk_frame.d \
./simpliciti/Components/nwk/nwk_globals.d 


# Each subdirectory must supply rules for building sources it contributes
simpliciti/Components/nwk/%.o: ../simpliciti/Components/nwk/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	msp430-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


