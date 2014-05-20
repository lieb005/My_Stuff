################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../simpliciti/Components/nwk_applications/nwk_freq.c \
../simpliciti/Components/nwk_applications/nwk_ioctl.c \
../simpliciti/Components/nwk_applications/nwk_join.c \
../simpliciti/Components/nwk_applications/nwk_link.c \
../simpliciti/Components/nwk_applications/nwk_mgmt.c \
../simpliciti/Components/nwk_applications/nwk_ping.c \
../simpliciti/Components/nwk_applications/nwk_security.c 

OBJS += \
./simpliciti/Components/nwk_applications/nwk_freq.o \
./simpliciti/Components/nwk_applications/nwk_ioctl.o \
./simpliciti/Components/nwk_applications/nwk_join.o \
./simpliciti/Components/nwk_applications/nwk_link.o \
./simpliciti/Components/nwk_applications/nwk_mgmt.o \
./simpliciti/Components/nwk_applications/nwk_ping.o \
./simpliciti/Components/nwk_applications/nwk_security.o 

C_DEPS += \
./simpliciti/Components/nwk_applications/nwk_freq.d \
./simpliciti/Components/nwk_applications/nwk_ioctl.d \
./simpliciti/Components/nwk_applications/nwk_join.d \
./simpliciti/Components/nwk_applications/nwk_link.d \
./simpliciti/Components/nwk_applications/nwk_mgmt.d \
./simpliciti/Components/nwk_applications/nwk_ping.d \
./simpliciti/Components/nwk_applications/nwk_security.d 


# Each subdirectory must supply rules for building sources it contributes
simpliciti/Components/nwk_applications/%.o: ../simpliciti/Components/nwk_applications/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	msp430-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


