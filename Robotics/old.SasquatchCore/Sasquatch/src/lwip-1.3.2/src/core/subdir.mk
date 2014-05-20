################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lwip-1.3.2/src/core/dhcp.c \
../src/lwip-1.3.2/src/core/dns.c \
../src/lwip-1.3.2/src/core/init.c \
../src/lwip-1.3.2/src/core/mem.c \
../src/lwip-1.3.2/src/core/memp.c \
../src/lwip-1.3.2/src/core/netif.c \
../src/lwip-1.3.2/src/core/pbuf.c \
../src/lwip-1.3.2/src/core/raw.c \
../src/lwip-1.3.2/src/core/stats.c \
../src/lwip-1.3.2/src/core/tcp.c \
../src/lwip-1.3.2/src/core/tcp_in.c \
../src/lwip-1.3.2/src/core/tcp_out.c \
../src/lwip-1.3.2/src/core/udp.c 

OBJS += \
./src/lwip-1.3.2/src/core/dhcp.o \
./src/lwip-1.3.2/src/core/dns.o \
./src/lwip-1.3.2/src/core/init.o \
./src/lwip-1.3.2/src/core/mem.o \
./src/lwip-1.3.2/src/core/memp.o \
./src/lwip-1.3.2/src/core/netif.o \
./src/lwip-1.3.2/src/core/pbuf.o \
./src/lwip-1.3.2/src/core/raw.o \
./src/lwip-1.3.2/src/core/stats.o \
./src/lwip-1.3.2/src/core/tcp.o \
./src/lwip-1.3.2/src/core/tcp_in.o \
./src/lwip-1.3.2/src/core/tcp_out.o \
./src/lwip-1.3.2/src/core/udp.o 

C_DEPS += \
./src/lwip-1.3.2/src/core/dhcp.d \
./src/lwip-1.3.2/src/core/dns.d \
./src/lwip-1.3.2/src/core/init.d \
./src/lwip-1.3.2/src/core/mem.d \
./src/lwip-1.3.2/src/core/memp.d \
./src/lwip-1.3.2/src/core/netif.d \
./src/lwip-1.3.2/src/core/pbuf.d \
./src/lwip-1.3.2/src/core/raw.d \
./src/lwip-1.3.2/src/core/stats.d \
./src/lwip-1.3.2/src/core/tcp.d \
./src/lwip-1.3.2/src/core/tcp_in.d \
./src/lwip-1.3.2/src/core/tcp_out.d \
./src/lwip-1.3.2/src/core/udp.d 


# Each subdirectory must supply rules for building sources it contributes
src/lwip-1.3.2/src/core/%.o: ../src/lwip-1.3.2/src/core/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I/usr/share/arduino/libraries/EEPROM -I/usr/share/arduino/hardware/arduino/bootloaders/stk500v2 -I/usr/share/arduino/hardware/sasquatch/variants/sasquatch -I/usr/share/arduino/hardware/arduino/cores/robot -I/usr/share/arduino/hardware/arduino/cores/arduino -I/usr/share/arduino/libraries/Wire -I/usr/share/arduino/libraries/WiFi -I/usr/share/arduino/libraries/TFT -I/usr/share/arduino/libraries/Stepper -I/usr/share/arduino/libraries/SPI -I/usr/share/arduino/libraries/SoftwareSerial -I/usr/share/arduino/libraries/Servo -I/usr/share/arduino/libraries/SD -I/usr/share/arduino/libraries/RobotOpen -I/usr/share/arduino/libraries/Robot_Motor -I/usr/share/arduino/libraries/Robot_Control -I/usr/share/arduino/libraries/LiquidCrystal -I/usr/share/arduino/libraries/GSM -I/usr/share/arduino/libraries/Firmata -I/usr/share/arduino/libraries/Ethernet -I/usr/share/arduino/libraries/Esplora -Wall -g2 -gstabs -Os -ffunction-sections -fdata-sections -std=gnu99 -mmcu=atmega2560 -DF_CPU=1600000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


