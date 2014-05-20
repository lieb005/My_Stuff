################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
OBJ_SRCS += \
../test/formats/atmel_object/avr1.obj 

ASM_SRCS += \
../test/formats/atmel_object/avr1.asm 

OBJS += \
./test/formats/atmel_object/avr1.o 


# Each subdirectory must supply rules for building sources it contributes
test/formats/atmel_object/%.o: ../test/formats/atmel_object/%.asm
	@echo 'Building file: $<'
	@echo 'Invoking: GCC Assembler'
	as -I"/home/mark/Workspace Eclipse C Linux/ArduEmu/trunk/includes" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


