################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../trunk/src/dev/io/serial_adapter_win32.c \
../trunk/src/dev/io/serial_console.c 

OBJS += \
./trunk/src/dev/io/serial_adapter_win32.o \
./trunk/src/dev/io/serial_console.o 

C_DEPS += \
./trunk/src/dev/io/serial_adapter_win32.d \
./trunk/src/dev/io/serial_console.d 


# Each subdirectory must supply rules for building sources it contributes
trunk/src/dev/io/%.o: ../trunk/src/dev/io/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/mark/Workspace Eclipse C Linux/ArduEmu/trunk/includes" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


