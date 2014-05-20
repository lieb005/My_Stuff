################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../trunk/src/dev/mem/atmel_flash.c \
../trunk/src/dev/mem/atmel_sram.c 

OBJS += \
./trunk/src/dev/mem/atmel_flash.o \
./trunk/src/dev/mem/atmel_sram.o 

C_DEPS += \
./trunk/src/dev/mem/atmel_flash.d \
./trunk/src/dev/mem/atmel_sram.d 


# Each subdirectory must supply rules for building sources it contributes
trunk/src/dev/mem/%.o: ../trunk/src/dev/mem/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/mark/Workspace Eclipse C Linux/ArduEmu/trunk/includes" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


