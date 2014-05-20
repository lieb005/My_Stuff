################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../bkup/driver/adc12.o \
../bkup/driver/buzzer.o \
../bkup/driver/display.o \
../bkup/driver/display1.o \
../bkup/driver/dsp.o \
../bkup/driver/infomem.o \
../bkup/driver/pmm.o \
../bkup/driver/ports.o \
../bkup/driver/radio.o \
../bkup/driver/rf1a.o \
../bkup/driver/timer.o \
../bkup/driver/vti_as.o \
../bkup/driver/vti_ps.o 

C_SRCS += \
../bkup/driver/adc12.c \
../bkup/driver/buzzer.c \
../bkup/driver/display.c \
../bkup/driver/display1.c \
../bkup/driver/dsp.c \
../bkup/driver/infomem.c \
../bkup/driver/pmm.c \
../bkup/driver/ports.c \
../bkup/driver/radio.c \
../bkup/driver/rf1a.c \
../bkup/driver/timer.c \
../bkup/driver/vti_as.c \
../bkup/driver/vti_ps.c 

OBJS += \
./bkup/driver/adc12.o \
./bkup/driver/buzzer.o \
./bkup/driver/display.o \
./bkup/driver/display1.o \
./bkup/driver/dsp.o \
./bkup/driver/infomem.o \
./bkup/driver/pmm.o \
./bkup/driver/ports.o \
./bkup/driver/radio.o \
./bkup/driver/rf1a.o \
./bkup/driver/timer.o \
./bkup/driver/vti_as.o \
./bkup/driver/vti_ps.o 

C_DEPS += \
./bkup/driver/adc12.d \
./bkup/driver/buzzer.d \
./bkup/driver/display.d \
./bkup/driver/display1.d \
./bkup/driver/dsp.d \
./bkup/driver/infomem.d \
./bkup/driver/pmm.d \
./bkup/driver/ports.d \
./bkup/driver/radio.d \
./bkup/driver/rf1a.d \
./bkup/driver/timer.d \
./bkup/driver/vti_as.d \
./bkup/driver/vti_ps.d 


# Each subdirectory must supply rules for building sources it contributes
bkup/driver/%.o: ../bkup/driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: mspgcc GCC C++ Compiler'
	msp430-g++ -O3 -Wall -c -fmessage-length=0 -o "$@" "$<" && \
	echo -n '$(@:%.o=%.d)' $(dir $@) > '$(@:%.o=%.d)' && \
	msp430-g++ -MM -MG -P -w -O3 -Wall -c -fmessage-length=0   "$<" >> '$(@:%.o=%.d)'
	@echo 'Finished building: $<'
	@echo ' '


