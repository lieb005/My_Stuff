################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../trunk/src/util/atmel_obj_format.c \
../trunk/src/util/bin_utils.c \
../trunk/src/util/intel_hex.c \
../trunk/src/util/srec_format.c 

OBJS += \
./trunk/src/util/atmel_obj_format.o \
./trunk/src/util/bin_utils.o \
./trunk/src/util/intel_hex.o \
./trunk/src/util/srec_format.o 

C_DEPS += \
./trunk/src/util/atmel_obj_format.d \
./trunk/src/util/bin_utils.d \
./trunk/src/util/intel_hex.d \
./trunk/src/util/srec_format.d 


# Each subdirectory must supply rules for building sources it contributes
trunk/src/util/%.o: ../trunk/src/util/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/mark/Workspace Eclipse C Linux/ArduEmu/trunk/includes" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


