################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/firmwares/wifishield/wifi_dnld/src/SOFTWARE_FRAMEWORK/UTILS/DEBUG/debug.c \
../src/firmwares/wifishield/wifi_dnld/src/SOFTWARE_FRAMEWORK/UTILS/DEBUG/print_funcs.c 

OBJS += \
./src/firmwares/wifishield/wifi_dnld/src/SOFTWARE_FRAMEWORK/UTILS/DEBUG/debug.o \
./src/firmwares/wifishield/wifi_dnld/src/SOFTWARE_FRAMEWORK/UTILS/DEBUG/print_funcs.o 

C_DEPS += \
./src/firmwares/wifishield/wifi_dnld/src/SOFTWARE_FRAMEWORK/UTILS/DEBUG/debug.d \
./src/firmwares/wifishield/wifi_dnld/src/SOFTWARE_FRAMEWORK/UTILS/DEBUG/print_funcs.d 


# Each subdirectory must supply rules for building sources it contributes
src/firmwares/wifishield/wifi_dnld/src/SOFTWARE_FRAMEWORK/UTILS/DEBUG/%.o: ../src/firmwares/wifishield/wifi_dnld/src/SOFTWARE_FRAMEWORK/UTILS/DEBUG/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I/usr/share/arduino/libraries/EEPROM -I/usr/share/arduino/hardware/arduino/bootloaders/stk500v2 -I/usr/share/arduino/hardware/sasquatch/variants/sasquatch -I/usr/share/arduino/hardware/arduino/cores/robot -I/usr/share/arduino/hardware/arduino/cores/arduino -I/usr/share/arduino/libraries/Wire -I/usr/share/arduino/libraries/WiFi -I/usr/share/arduino/libraries/TFT -I/usr/share/arduino/libraries/Stepper -I/usr/share/arduino/libraries/SPI -I/usr/share/arduino/libraries/SoftwareSerial -I/usr/share/arduino/libraries/Servo -I/usr/share/arduino/libraries/SD -I/usr/share/arduino/libraries/RobotOpen -I/usr/share/arduino/libraries/Robot_Motor -I/usr/share/arduino/libraries/Robot_Control -I/usr/share/arduino/libraries/LiquidCrystal -I/usr/share/arduino/libraries/GSM -I/usr/share/arduino/libraries/Firmata -I/usr/share/arduino/libraries/Ethernet -I/usr/share/arduino/libraries/Esplora -Wall -g2 -gstabs -Os -ffunction-sections -fdata-sections -std=gnu99 -mmcu=atmega2560 -DF_CPU=1600000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

