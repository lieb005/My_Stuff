################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lwip-1.3.2/src/core/ipv4/autoip.c \
../src/lwip-1.3.2/src/core/ipv4/icmp.c \
../src/lwip-1.3.2/src/core/ipv4/igmp.c \
../src/lwip-1.3.2/src/core/ipv4/inet.c \
../src/lwip-1.3.2/src/core/ipv4/inet_chksum.c \
../src/lwip-1.3.2/src/core/ipv4/ip.c \
../src/lwip-1.3.2/src/core/ipv4/ip_addr.c \
../src/lwip-1.3.2/src/core/ipv4/ip_frag.c 

OBJS += \
./src/lwip-1.3.2/src/core/ipv4/autoip.o \
./src/lwip-1.3.2/src/core/ipv4/icmp.o \
./src/lwip-1.3.2/src/core/ipv4/igmp.o \
./src/lwip-1.3.2/src/core/ipv4/inet.o \
./src/lwip-1.3.2/src/core/ipv4/inet_chksum.o \
./src/lwip-1.3.2/src/core/ipv4/ip.o \
./src/lwip-1.3.2/src/core/ipv4/ip_addr.o \
./src/lwip-1.3.2/src/core/ipv4/ip_frag.o 

C_DEPS += \
./src/lwip-1.3.2/src/core/ipv4/autoip.d \
./src/lwip-1.3.2/src/core/ipv4/icmp.d \
./src/lwip-1.3.2/src/core/ipv4/igmp.d \
./src/lwip-1.3.2/src/core/ipv4/inet.d \
./src/lwip-1.3.2/src/core/ipv4/inet_chksum.d \
./src/lwip-1.3.2/src/core/ipv4/ip.d \
./src/lwip-1.3.2/src/core/ipv4/ip_addr.d \
./src/lwip-1.3.2/src/core/ipv4/ip_frag.d 


# Each subdirectory must supply rules for building sources it contributes
src/lwip-1.3.2/src/core/ipv4/%.o: ../src/lwip-1.3.2/src/core/ipv4/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I/usr/share/arduino/libraries/EEPROM -I/usr/share/arduino/hardware/arduino/bootloaders/stk500v2 -I/usr/share/arduino/hardware/sasquatch/variants/sasquatch -I/usr/share/arduino/hardware/arduino/cores/robot -I/usr/share/arduino/hardware/arduino/cores/arduino -I/usr/share/arduino/libraries/Wire -I/usr/share/arduino/libraries/WiFi -I/usr/share/arduino/libraries/TFT -I/usr/share/arduino/libraries/Stepper -I/usr/share/arduino/libraries/SPI -I/usr/share/arduino/libraries/SoftwareSerial -I/usr/share/arduino/libraries/Servo -I/usr/share/arduino/libraries/SD -I/usr/share/arduino/libraries/RobotOpen -I/usr/share/arduino/libraries/Robot_Motor -I/usr/share/arduino/libraries/Robot_Control -I/usr/share/arduino/libraries/LiquidCrystal -I/usr/share/arduino/libraries/GSM -I/usr/share/arduino/libraries/Firmata -I/usr/share/arduino/libraries/Ethernet -I/usr/share/arduino/libraries/Esplora -Wall -g2 -gstabs -Os -ffunction-sections -fdata-sections -std=gnu99 -mmcu=atmega2560 -DF_CPU=1600000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


