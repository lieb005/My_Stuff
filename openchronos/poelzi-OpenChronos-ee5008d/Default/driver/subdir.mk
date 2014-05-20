################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/adc12.c \
../driver/buzzer.c \
../driver/display.c \
../driver/display1.c \
../driver/dsp.c \
../driver/infomem.c \
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
./driver/dsp.o \
./driver/infomem.o \
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
./driver/dsp.d \
./driver/infomem.d \
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
	msp430-gcc -O2 -g -Wall -c -fmessage-length=0 -Wl,-Map=output.map -Os -Wall -fomit-frame-pointer -fno-force-addr -finline-limit=1 -fno-schedule-insns -D__MSP430_6137__ -DMRFI_CC430 -D__CC430F6137__ -DELIMINATE_BLUEROBIN -mmcu=cc430x6137 -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/ -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/include/ -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/gcc/ -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/driver/ -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/logic/ -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/bluerobin/ -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/simpliciti/ -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/simpliciti/Components/bsp -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/simpliciti/Components/bsp/drivers -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/simpliciti/Components/bsp/boards/CC430EM -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/simpliciti/Components/mrfi -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/simpliciti/Components/nwk -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/simpliciti/Components/nwk_applications -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


