################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/wifishield/wifiHD/src/ard_spi.c \
../src/wifishield/wifiHD/src/ard_tcp.c \
../src/wifishield/wifiHD/src/ard_utils.c \
../src/wifishield/wifiHD/src/avr32_spi.c \
../src/wifishield/wifiHD/src/board_init.c \
../src/wifishield/wifiHD/src/cmd_wl.c \
../src/wifishield/wifiHD/src/console.c \
../src/wifishield/wifiHD/src/fw_download_extflash.c \
../src/wifishield/wifiHD/src/lwip_setup.c \
../src/wifishield/wifiHD/src/main.c \
../src/wifishield/wifiHD/src/nvram.c \
../src/wifishield/wifiHD/src/owl_os.c \
../src/wifishield/wifiHD/src/ping.c \
../src/wifishield/wifiHD/src/printf-stdarg.c \
../src/wifishield/wifiHD/src/timer.c \
../src/wifishield/wifiHD/src/util.c \
../src/wifishield/wifiHD/src/wl_cm.c 

OBJS += \
./src/wifishield/wifiHD/src/ard_spi.o \
./src/wifishield/wifiHD/src/ard_tcp.o \
./src/wifishield/wifiHD/src/ard_utils.o \
./src/wifishield/wifiHD/src/avr32_spi.o \
./src/wifishield/wifiHD/src/board_init.o \
./src/wifishield/wifiHD/src/cmd_wl.o \
./src/wifishield/wifiHD/src/console.o \
./src/wifishield/wifiHD/src/fw_download_extflash.o \
./src/wifishield/wifiHD/src/lwip_setup.o \
./src/wifishield/wifiHD/src/main.o \
./src/wifishield/wifiHD/src/nvram.o \
./src/wifishield/wifiHD/src/owl_os.o \
./src/wifishield/wifiHD/src/ping.o \
./src/wifishield/wifiHD/src/printf-stdarg.o \
./src/wifishield/wifiHD/src/timer.o \
./src/wifishield/wifiHD/src/util.o \
./src/wifishield/wifiHD/src/wl_cm.o 

C_DEPS += \
./src/wifishield/wifiHD/src/ard_spi.d \
./src/wifishield/wifiHD/src/ard_tcp.d \
./src/wifishield/wifiHD/src/ard_utils.d \
./src/wifishield/wifiHD/src/avr32_spi.d \
./src/wifishield/wifiHD/src/board_init.d \
./src/wifishield/wifiHD/src/cmd_wl.d \
./src/wifishield/wifiHD/src/console.d \
./src/wifishield/wifiHD/src/fw_download_extflash.d \
./src/wifishield/wifiHD/src/lwip_setup.d \
./src/wifishield/wifiHD/src/main.d \
./src/wifishield/wifiHD/src/nvram.d \
./src/wifishield/wifiHD/src/owl_os.d \
./src/wifishield/wifiHD/src/ping.d \
./src/wifishield/wifiHD/src/printf-stdarg.d \
./src/wifishield/wifiHD/src/timer.d \
./src/wifishield/wifiHD/src/util.d \
./src/wifishield/wifiHD/src/wl_cm.d 


# Each subdirectory must supply rules for building sources it contributes
src/wifishield/wifiHD/src/%.o: ../src/wifishield/wifiHD/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I/usr/share/arduino/libraries/EEPROM -I/usr/share/arduino/hardware/arduino/bootloaders/stk500v2 -I/usr/share/arduino/hardware/sasquatch/variants/sasquatch -I/usr/share/arduino/hardware/arduino/cores/robot -I/usr/share/arduino/hardware/arduino/cores/arduino -I/usr/share/arduino/libraries/Wire -I/usr/share/arduino/libraries/WiFi -I/usr/share/arduino/libraries/TFT -I/usr/share/arduino/libraries/Stepper -I/usr/share/arduino/libraries/SPI -I/usr/share/arduino/libraries/SoftwareSerial -I/usr/share/arduino/libraries/Servo -I/usr/share/arduino/libraries/SD -I/usr/share/arduino/libraries/RobotOpen -I/usr/share/arduino/libraries/Robot_Motor -I/usr/share/arduino/libraries/Robot_Control -I/usr/share/arduino/libraries/LiquidCrystal -I/usr/share/arduino/libraries/GSM -I/usr/share/arduino/libraries/Firmata -I/usr/share/arduino/libraries/Ethernet -I/usr/share/arduino/libraries/Esplora -Wall -g2 -gstabs -Os -ffunction-sections -fdata-sections -std=gnu99 -mmcu=atmega2560 -DF_CPU=1600000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


