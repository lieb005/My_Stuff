################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../logic/acceleration.c \
../logic/agility.c \
../logic/alarm.c \
../logic/altitude.c \
../logic/battery.c \
../logic/bluerobin.c \
../logic/clock.c \
../logic/countdowntimer.c \
../logic/date.c \
../logic/display2.c \
../logic/menu.c \
../logic/miscellaneous.c \
../logic/random.c \
../logic/rfbsl.c \
../logic/rfsimpliciti.c \
../logic/stopwatch.c \
../logic/stubs.c \
../logic/temperature.c \
../logic/test.c \
../logic/user.c 

OBJS += \
./logic/acceleration.o \
./logic/agility.o \
./logic/alarm.o \
./logic/altitude.o \
./logic/battery.o \
./logic/bluerobin.o \
./logic/clock.o \
./logic/countdowntimer.o \
./logic/date.o \
./logic/display2.o \
./logic/menu.o \
./logic/miscellaneous.o \
./logic/random.o \
./logic/rfbsl.o \
./logic/rfsimpliciti.o \
./logic/stopwatch.o \
./logic/stubs.o \
./logic/temperature.o \
./logic/test.o \
./logic/user.o 

C_DEPS += \
./logic/acceleration.d \
./logic/agility.d \
./logic/alarm.d \
./logic/altitude.d \
./logic/battery.d \
./logic/bluerobin.d \
./logic/clock.d \
./logic/countdowntimer.d \
./logic/date.d \
./logic/display2.d \
./logic/menu.d \
./logic/miscellaneous.d \
./logic/random.d \
./logic/rfbsl.d \
./logic/rfsimpliciti.d \
./logic/stopwatch.d \
./logic/stubs.d \
./logic/temperature.d \
./logic/test.d \
./logic/user.d 


# Each subdirectory must supply rules for building sources it contributes
logic/%.o: ../logic/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	msp430-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


