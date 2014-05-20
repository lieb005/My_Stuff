################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/src/core/dhcp.c \
../src/src/core/dns.c \
../src/src/core/init.c \
../src/src/core/mem.c \
../src/src/core/memp.c \
../src/src/core/netif.c \
../src/src/core/pbuf.c \
../src/src/core/raw.c \
../src/src/core/stats.c \
../src/src/core/tcp.c \
../src/src/core/tcp_in.c \
../src/src/core/tcp_out.c \
../src/src/core/udp.c 

OBJS += \
./src/src/core/dhcp.o \
./src/src/core/dns.o \
./src/src/core/init.o \
./src/src/core/mem.o \
./src/src/core/memp.o \
./src/src/core/netif.o \
./src/src/core/pbuf.o \
./src/src/core/raw.o \
./src/src/core/stats.o \
./src/src/core/tcp.o \
./src/src/core/tcp_in.o \
./src/src/core/tcp_out.o \
./src/src/core/udp.o 

C_DEPS += \
./src/src/core/dhcp.d \
./src/src/core/dns.d \
./src/src/core/init.d \
./src/src/core/mem.d \
./src/src/core/memp.d \
./src/src/core/netif.d \
./src/src/core/pbuf.d \
./src/src/core/raw.d \
./src/src/core/stats.d \
./src/src/core/tcp.d \
./src/src/core/tcp_in.d \
./src/src/core/tcp_out.d \
./src/src/core/udp.d 


# Each subdirectory must supply rules for building sources it contributes
src/src/core/%.o: ../src/src/core/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I/usr/share/arduino/libraries/EEPROM -I/usr/share/arduino/hardware/arduino/bootloaders/stk500v2 -I/usr/share/arduino/hardware/sasquatch/variants/sasquatch -I/usr/share/arduino/hardware/arduino/cores/robot -I/usr/share/arduino/hardware/arduino/cores/arduino -I/usr/share/arduino/libraries/Wire -I/usr/share/arduino/libraries/WiFi -I/usr/share/arduino/libraries/TFT -I/usr/share/arduino/libraries/Stepper -I/usr/share/arduino/libraries/SPI -I/usr/share/arduino/libraries/SoftwareSerial -I/usr/share/arduino/libraries/Servo -I/usr/share/arduino/libraries/SD -I/usr/share/arduino/libraries/RobotOpen -I/usr/share/arduino/libraries/Robot_Motor -I/usr/share/arduino/libraries/Robot_Control -I/usr/share/arduino/libraries/LiquidCrystal -I/usr/share/arduino/libraries/GSM -I/usr/share/arduino/libraries/Firmata -I/usr/share/arduino/libraries/Ethernet -I/usr/share/arduino/libraries/Esplora -Wall -g2 -gstabs -Os -ffunction-sections -fdata-sections -std=gnu99 -mmcu=atmega2560 -DF_CPU=1600000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


