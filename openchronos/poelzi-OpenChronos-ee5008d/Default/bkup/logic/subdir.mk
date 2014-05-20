################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../bkup/logic/acceleration.o \
../bkup/logic/alarm.o \
../bkup/logic/altitude.o \
../bkup/logic/battery.o \
../bkup/logic/clock.o \
../bkup/logic/date.o \
../bkup/logic/dst.o \
../bkup/logic/eggtimer.o \
../bkup/logic/gps.o \
../bkup/logic/menu.o \
../bkup/logic/phase_clock.o \
../bkup/logic/prout.o \
../bkup/logic/rfbsl.o \
../bkup/logic/rfsimpliciti.o \
../bkup/logic/sequence.o \
../bkup/logic/sidereal.o \
../bkup/logic/stopwatch.o \
../bkup/logic/strength.o \
../bkup/logic/temperature.o \
../bkup/logic/test.o \
../bkup/logic/user.o \
../bkup/logic/vario.o 

C_SRCS += \
../bkup/logic/MYsimpliciti.c \
../bkup/logic/acceleration.c \
../bkup/logic/alarm.c \
../bkup/logic/altitude.c \
../bkup/logic/battery.c \
../bkup/logic/bluerobin.c \
../bkup/logic/clock.c \
../bkup/logic/date.c \
../bkup/logic/dst.c \
../bkup/logic/eggtimer.c \
../bkup/logic/gps.c \
../bkup/logic/menu.c \
../bkup/logic/phase_clock.c \
../bkup/logic/prout.c \
../bkup/logic/rfbsl.c \
../bkup/logic/rfsimpliciti.c \
../bkup/logic/sequence.c \
../bkup/logic/sidereal.c \
../bkup/logic/stopwatch.c \
../bkup/logic/strength.c \
../bkup/logic/temperature.c \
../bkup/logic/test.c \
../bkup/logic/user.c \
../bkup/logic/vario.c 

OBJS += \
./bkup/logic/MYsimpliciti.o \
./bkup/logic/acceleration.o \
./bkup/logic/alarm.o \
./bkup/logic/altitude.o \
./bkup/logic/battery.o \
./bkup/logic/bluerobin.o \
./bkup/logic/clock.o \
./bkup/logic/date.o \
./bkup/logic/dst.o \
./bkup/logic/eggtimer.o \
./bkup/logic/gps.o \
./bkup/logic/menu.o \
./bkup/logic/phase_clock.o \
./bkup/logic/prout.o \
./bkup/logic/rfbsl.o \
./bkup/logic/rfsimpliciti.o \
./bkup/logic/sequence.o \
./bkup/logic/sidereal.o \
./bkup/logic/stopwatch.o \
./bkup/logic/strength.o \
./bkup/logic/temperature.o \
./bkup/logic/test.o \
./bkup/logic/user.o \
./bkup/logic/vario.o 

C_DEPS += \
./bkup/logic/MYsimpliciti.d \
./bkup/logic/acceleration.d \
./bkup/logic/alarm.d \
./bkup/logic/altitude.d \
./bkup/logic/battery.d \
./bkup/logic/bluerobin.d \
./bkup/logic/clock.d \
./bkup/logic/date.d \
./bkup/logic/dst.d \
./bkup/logic/eggtimer.d \
./bkup/logic/gps.d \
./bkup/logic/menu.d \
./bkup/logic/phase_clock.d \
./bkup/logic/prout.d \
./bkup/logic/rfbsl.d \
./bkup/logic/rfsimpliciti.d \
./bkup/logic/sequence.d \
./bkup/logic/sidereal.d \
./bkup/logic/stopwatch.d \
./bkup/logic/strength.d \
./bkup/logic/temperature.d \
./bkup/logic/test.d \
./bkup/logic/user.d \
./bkup/logic/vario.d 


# Each subdirectory must supply rules for building sources it contributes
bkup/logic/%.o: ../bkup/logic/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: mspgcc GCC C++ Compiler'
	msp430-g++ -O3 -Wall -c -fmessage-length=0 -o "$@" "$<" && \
	echo -n '$(@:%.o=%.d)' $(dir $@) > '$(@:%.o=%.d)' && \
	msp430-g++ -MM -MG -P -w -O3 -Wall -c -fmessage-length=0   "$<" >> '$(@:%.o=%.d)'
	@echo 'Finished building: $<'
	@echo ' '


