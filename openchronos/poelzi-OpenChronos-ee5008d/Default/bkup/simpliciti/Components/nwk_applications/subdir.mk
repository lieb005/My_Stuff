################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../bkup/simpliciti/Components/nwk_applications/nwk_freq.o \
../bkup/simpliciti/Components/nwk_applications/nwk_ioctl.o \
../bkup/simpliciti/Components/nwk_applications/nwk_join.o \
../bkup/simpliciti/Components/nwk_applications/nwk_link.o \
../bkup/simpliciti/Components/nwk_applications/nwk_mgmt.o \
../bkup/simpliciti/Components/nwk_applications/nwk_ping.o \
../bkup/simpliciti/Components/nwk_applications/nwk_security.o 

C_SRCS += \
../bkup/simpliciti/Components/nwk_applications/nwk_freq.c \
../bkup/simpliciti/Components/nwk_applications/nwk_ioctl.c \
../bkup/simpliciti/Components/nwk_applications/nwk_join.c \
../bkup/simpliciti/Components/nwk_applications/nwk_link.c \
../bkup/simpliciti/Components/nwk_applications/nwk_mgmt.c \
../bkup/simpliciti/Components/nwk_applications/nwk_ping.c \
../bkup/simpliciti/Components/nwk_applications/nwk_security.c 

OBJS += \
./bkup/simpliciti/Components/nwk_applications/nwk_freq.o \
./bkup/simpliciti/Components/nwk_applications/nwk_ioctl.o \
./bkup/simpliciti/Components/nwk_applications/nwk_join.o \
./bkup/simpliciti/Components/nwk_applications/nwk_link.o \
./bkup/simpliciti/Components/nwk_applications/nwk_mgmt.o \
./bkup/simpliciti/Components/nwk_applications/nwk_ping.o \
./bkup/simpliciti/Components/nwk_applications/nwk_security.o 

C_DEPS += \
./bkup/simpliciti/Components/nwk_applications/nwk_freq.d \
./bkup/simpliciti/Components/nwk_applications/nwk_ioctl.d \
./bkup/simpliciti/Components/nwk_applications/nwk_join.d \
./bkup/simpliciti/Components/nwk_applications/nwk_link.d \
./bkup/simpliciti/Components/nwk_applications/nwk_mgmt.d \
./bkup/simpliciti/Components/nwk_applications/nwk_ping.d \
./bkup/simpliciti/Components/nwk_applications/nwk_security.d 


# Each subdirectory must supply rules for building sources it contributes
bkup/simpliciti/Components/nwk_applications/%.o: ../bkup/simpliciti/Components/nwk_applications/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: mspgcc GCC C++ Compiler'
	msp430-g++ -O3 -Wall -c -fmessage-length=0 -o "$@" "$<" && \
	echo -n '$(@:%.o=%.d)' $(dir $@) > '$(@:%.o=%.d)' && \
	msp430-g++ -MM -MG -P -w -O3 -Wall -c -fmessage-length=0   "$<" >> '$(@:%.o=%.d)'
	@echo 'Finished building: $<'
	@echo ' '


