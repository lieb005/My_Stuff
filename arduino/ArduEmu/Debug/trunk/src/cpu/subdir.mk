################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../trunk/src/cpu/atmel_cpu.c \
../trunk/src/cpu/atmel_decoder.c \
../trunk/src/cpu/atmel_operations.c 

OBJS += \
./trunk/src/cpu/atmel_cpu.o \
./trunk/src/cpu/atmel_decoder.o \
./trunk/src/cpu/atmel_operations.o 

C_DEPS += \
./trunk/src/cpu/atmel_cpu.d \
./trunk/src/cpu/atmel_decoder.d \
./trunk/src/cpu/atmel_operations.d 


# Each subdirectory must supply rules for building sources it contributes
trunk/src/cpu/%.o: ../trunk/src/cpu/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/mark/Workspace Eclipse C Linux/ArduEmu/trunk/includes" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


