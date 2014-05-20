################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../emulino-gui.cpp 

C_SRCS += \
../cpu.c \
../eeprom.c \
../emulino.c \
../loader.c \
../port.c \
../timer.c \
../usart.c 

OBJS += \
./cpu.o \
./eeprom.o \
./emulino-gui.o \
./emulino.o \
./loader.o \
./port.o \
./timer.o \
./usart.o 

C_DEPS += \
./cpu.d \
./eeprom.d \
./emulino.d \
./loader.d \
./port.d \
./timer.d \
./usart.d 

CPP_DEPS += \
./emulino-gui.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/usr/include/qt4/Qt -I/usr/include/qt4 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/qt4/Qt -I/usr/include/qt4 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


