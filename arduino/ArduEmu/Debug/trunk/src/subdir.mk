################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../trunk/src/main.c 

OBJS += \
./trunk/src/main.o 

C_DEPS += \
./trunk/src/main.d 


# Each subdirectory must supply rules for building sources it contributes
trunk/src/%.o: ../trunk/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/mark/Workspace Eclipse C Linux/ArduEmu/trunk/includes" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


