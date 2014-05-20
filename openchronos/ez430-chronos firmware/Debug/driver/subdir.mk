################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/adc12.c \
../driver/buzzer.c \
../driver/display.c \
../driver/display1.c \
../driver/pmm.c \
../driver/ports.c \
../driver/radio.c \
../driver/rf1a.c \
../driver/timer.c \
../driver/vti_as.c \
../driver/vti_ps.c 

OBJS += \
./driver/adc12.o \
./driver/buzzer.o \
./driver/display.o \
./driver/display1.o \
./driver/pmm.o \
./driver/ports.o \
./driver/radio.o \
./driver/rf1a.o \
./driver/timer.o \
./driver/vti_as.o \
./driver/vti_ps.o 

C_DEPS += \
./driver/adc12.d \
./driver/buzzer.d \
./driver/display.d \
./driver/display1.d \
./driver/pmm.d \
./driver/ports.d \
./driver/radio.d \
./driver/rf1a.d \
./driver/timer.d \
./driver/vti_as.d \
./driver/vti_ps.d 


# Each subdirectory must supply rules for building sources it contributes
driver/%.o: ../driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	msp430-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


