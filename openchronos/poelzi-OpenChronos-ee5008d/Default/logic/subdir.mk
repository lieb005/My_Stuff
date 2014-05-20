################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../logic/MYsimpliciti.c \
../logic/acceleration.c \
../logic/alarm.c \
../logic/altitude.c \
../logic/altitude_.c \
../logic/altitude_accumulator.c \
../logic/altitude_math.c \
../logic/battery.c \
../logic/bluerobin.c \
../logic/calendar.c \
../logic/clock.c \
../logic/date.c \
../logic/dst.c \
../logic/eggtimer.c \
../logic/eggwatch.c \
../logic/globalfunctions.c \
../logic/gps.c \
../logic/menu.c \
../logic/metronome.c \
../logic/notes.c \
../logic/notes.prev.c \
../logic/pedometer.c \
../logic/phase_clock.c \
../logic/prout.c \
../logic/rfbsl.c \
../logic/rfsimpliciti.c \
../logic/schedule.c \
../logic/sequence.c \
../logic/sidereal.c \
../logic/stopwatch.c \
../logic/strength.c \
../logic/temperature.c \
../logic/test.c \
../logic/user.c \
../logic/vario.c 

OBJS += \
./logic/MYsimpliciti.o \
./logic/acceleration.o \
./logic/alarm.o \
./logic/altitude.o \
./logic/altitude_.o \
./logic/altitude_accumulator.o \
./logic/altitude_math.o \
./logic/battery.o \
./logic/bluerobin.o \
./logic/calendar.o \
./logic/clock.o \
./logic/date.o \
./logic/dst.o \
./logic/eggtimer.o \
./logic/eggwatch.o \
./logic/globalfunctions.o \
./logic/gps.o \
./logic/menu.o \
./logic/metronome.o \
./logic/notes.o \
./logic/notes.prev.o \
./logic/pedometer.o \
./logic/phase_clock.o \
./logic/prout.o \
./logic/rfbsl.o \
./logic/rfsimpliciti.o \
./logic/schedule.o \
./logic/sequence.o \
./logic/sidereal.o \
./logic/stopwatch.o \
./logic/strength.o \
./logic/temperature.o \
./logic/test.o \
./logic/user.o \
./logic/vario.o 

C_DEPS += \
./logic/MYsimpliciti.d \
./logic/acceleration.d \
./logic/alarm.d \
./logic/altitude.d \
./logic/altitude_.d \
./logic/altitude_accumulator.d \
./logic/altitude_math.d \
./logic/battery.d \
./logic/bluerobin.d \
./logic/calendar.d \
./logic/clock.d \
./logic/date.d \
./logic/dst.d \
./logic/eggtimer.d \
./logic/eggwatch.d \
./logic/globalfunctions.d \
./logic/gps.d \
./logic/menu.d \
./logic/metronome.d \
./logic/notes.d \
./logic/notes.prev.d \
./logic/pedometer.d \
./logic/phase_clock.d \
./logic/prout.d \
./logic/rfbsl.d \
./logic/rfsimpliciti.d \
./logic/schedule.d \
./logic/sequence.d \
./logic/sidereal.d \
./logic/stopwatch.d \
./logic/strength.d \
./logic/temperature.d \
./logic/test.d \
./logic/user.d \
./logic/vario.d 


# Each subdirectory must supply rules for building sources it contributes
logic/%.o: ../logic/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	msp430-gcc -O2 -g -Wall -c -fmessage-length=0 -Wl,-Map=output.map -Os -Wall -fomit-frame-pointer -fno-force-addr -finline-limit=1 -fno-schedule-insns -D__MSP430_6137__ -DMRFI_CC430 -D__CC430F6137__ -DELIMINATE_BLUEROBIN -mmcu=cc430x6137 -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/ -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/include/ -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/gcc/ -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/driver/ -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/logic/ -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/bluerobin/ -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/simpliciti/ -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/simpliciti/Components/bsp -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/simpliciti/Components/bsp/drivers -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/simpliciti/Components/bsp/boards/CC430EM -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/simpliciti/Components/mrfi -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/simpliciti/Components/nwk -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/simpliciti/Components/nwk_applications -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


