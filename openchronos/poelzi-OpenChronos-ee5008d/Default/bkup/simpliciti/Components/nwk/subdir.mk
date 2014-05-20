################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../bkup/simpliciti/Components/nwk/nwk.o \
../bkup/simpliciti/Components/nwk/nwk_QMgmt.o \
../bkup/simpliciti/Components/nwk/nwk_api.o \
../bkup/simpliciti/Components/nwk/nwk_frame.o \
../bkup/simpliciti/Components/nwk/nwk_globals.o 

C_SRCS += \
../bkup/simpliciti/Components/nwk/nwk.c \
../bkup/simpliciti/Components/nwk/nwk_QMgmt.c \
../bkup/simpliciti/Components/nwk/nwk_api.c \
../bkup/simpliciti/Components/nwk/nwk_frame.c \
../bkup/simpliciti/Components/nwk/nwk_globals.c 

OBJS += \
./bkup/simpliciti/Components/nwk/nwk.o \
./bkup/simpliciti/Components/nwk/nwk_QMgmt.o \
./bkup/simpliciti/Components/nwk/nwk_api.o \
./bkup/simpliciti/Components/nwk/nwk_frame.o \
./bkup/simpliciti/Components/nwk/nwk_globals.o 

C_DEPS += \
./bkup/simpliciti/Components/nwk/nwk.d \
./bkup/simpliciti/Components/nwk/nwk_QMgmt.d \
./bkup/simpliciti/Components/nwk/nwk_api.d \
./bkup/simpliciti/Components/nwk/nwk_frame.d \
./bkup/simpliciti/Components/nwk/nwk_globals.d 


# Each subdirectory must supply rules for building sources it contributes
bkup/simpliciti/Components/nwk/%.o: ../bkup/simpliciti/Components/nwk/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: mspgcc GCC C++ Compiler'
	msp430-g++ -O3 -Wall -c -fmessage-length=0 -o "$@" "$<" && \
	echo -n '$(@:%.o=%.d)' $(dir $@) > '$(@:%.o=%.d)' && \
	msp430-g++ -MM -MG -P -w -O3 -Wall -c -fmessage-length=0   "$<" >> '$(@:%.o=%.d)'
	@echo 'Finished building: $<'
	@echo ' '


