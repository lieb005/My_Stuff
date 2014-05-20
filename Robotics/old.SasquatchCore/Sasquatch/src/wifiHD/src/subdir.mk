################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/wifiHD/src/ard_spi.c \
../src/wifiHD/src/ard_tcp.c \
../src/wifiHD/src/ard_utils.c \
../src/wifiHD/src/avr32_spi.c \
../src/wifiHD/src/board_init.c \
../src/wifiHD/src/cmd_wl.c \
../src/wifiHD/src/console.c \
../src/wifiHD/src/fw_download_extflash.c \
../src/wifiHD/src/lwip_setup.c \
../src/wifiHD/src/main.c \
../src/wifiHD/src/nvram.c \
../src/wifiHD/src/owl_os.c \
../src/wifiHD/src/ping.c \
../src/wifiHD/src/printf-stdarg.c \
../src/wifiHD/src/timer.c \
../src/wifiHD/src/util.c \
../src/wifiHD/src/wl_cm.c 

OBJS += \
./src/wifiHD/src/ard_spi.o \
./src/wifiHD/src/ard_tcp.o \
./src/wifiHD/src/ard_utils.o \
./src/wifiHD/src/avr32_spi.o \
./src/wifiHD/src/board_init.o \
./src/wifiHD/src/cmd_wl.o \
./src/wifiHD/src/console.o \
./src/wifiHD/src/fw_download_extflash.o \
./src/wifiHD/src/lwip_setup.o \
./src/wifiHD/src/main.o \
./src/wifiHD/src/nvram.o \
./src/wifiHD/src/owl_os.o \
./src/wifiHD/src/ping.o \
./src/wifiHD/src/printf-stdarg.o \
./src/wifiHD/src/timer.o \
./src/wifiHD/src/util.o \
./src/wifiHD/src/wl_cm.o 

C_DEPS += \
./src/wifiHD/src/ard_spi.d \
./src/wifiHD/src/ard_tcp.d \
./src/wifiHD/src/ard_utils.d \
./src/wifiHD/src/avr32_spi.d \
./src/wifiHD/src/board_init.d \
./src/wifiHD/src/cmd_wl.d \
./src/wifiHD/src/console.d \
./src/wifiHD/src/fw_download_extflash.d \
./src/wifiHD/src/lwip_setup.d \
./src/wifiHD/src/main.d \
./src/wifiHD/src/nvram.d \
./src/wifiHD/src/owl_os.d \
./src/wifiHD/src/ping.d \
./src/wifiHD/src/printf-stdarg.d \
./src/wifiHD/src/timer.d \
./src/wifiHD/src/util.d \
./src/wifiHD/src/wl_cm.d 


# Each subdirectory must supply rules for building sources it contributes
src/wifiHD/src/%.o: ../src/wifiHD/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I/usr/share/arduino/libraries/EEPROM -I/usr/share/arduino/hardware/arduino/bootloaders/stk500v2 -I/usr/share/arduino/hardware/sasquatch/variants/sasquatch -I/usr/share/arduino/hardware/arduino/cores/robot -I/usr/share/arduino/hardware/arduino/cores/arduino -I/usr/share/arduino/libraries/Wire -I/usr/share/arduino/libraries/WiFi -I/usr/share/arduino/libraries/TFT -I/usr/share/arduino/libraries/Stepper -I/usr/share/arduino/libraries/SPI -I/usr/share/arduino/libraries/SoftwareSerial -I/usr/share/arduino/libraries/Servo -I/usr/share/arduino/libraries/SD -I/usr/share/arduino/libraries/RobotOpen -I/usr/share/arduino/libraries/Robot_Motor -I/usr/share/arduino/libraries/Robot_Control -I/usr/share/arduino/libraries/LiquidCrystal -I/usr/share/arduino/libraries/GSM -I/usr/share/arduino/libraries/Firmata -I/usr/share/arduino/libraries/Ethernet -I/usr/share/arduino/libraries/Esplora -Wall -g2 -gstabs -Os -ffunction-sections -fdata-sections -std=gnu99 -mmcu=atmega2560 -DF_CPU=1600000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


