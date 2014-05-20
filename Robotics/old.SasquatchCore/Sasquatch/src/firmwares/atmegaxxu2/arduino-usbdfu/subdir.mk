################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/firmwares/atmegaxxu2/arduino-usbdfu/Arduino-usbdfu.c \
../src/firmwares/atmegaxxu2/arduino-usbdfu/Descriptors.c 

OBJS += \
./src/firmwares/atmegaxxu2/arduino-usbdfu/Arduino-usbdfu.o \
./src/firmwares/atmegaxxu2/arduino-usbdfu/Descriptors.o 

C_DEPS += \
./src/firmwares/atmegaxxu2/arduino-usbdfu/Arduino-usbdfu.d \
./src/firmwares/atmegaxxu2/arduino-usbdfu/Descriptors.d 


# Each subdirectory must supply rules for building sources it contributes
src/firmwares/atmegaxxu2/arduino-usbdfu/%.o: ../src/firmwares/atmegaxxu2/arduino-usbdfu/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I/usr/share/arduino/libraries/EEPROM -I/usr/share/arduino/hardware/arduino/bootloaders/stk500v2 -I/usr/share/arduino/hardware/sasquatch/variants/sasquatch -I/usr/share/arduino/hardware/arduino/cores/robot -I/usr/share/arduino/hardware/arduino/cores/arduino -I/usr/share/arduino/libraries/Wire -I/usr/share/arduino/libraries/WiFi -I/usr/share/arduino/libraries/TFT -I/usr/share/arduino/libraries/Stepper -I/usr/share/arduino/libraries/SPI -I/usr/share/arduino/libraries/SoftwareSerial -I/usr/share/arduino/libraries/Servo -I/usr/share/arduino/libraries/SD -I/usr/share/arduino/libraries/RobotOpen -I/usr/share/arduino/libraries/Robot_Motor -I/usr/share/arduino/libraries/Robot_Control -I/usr/share/arduino/libraries/LiquidCrystal -I/usr/share/arduino/libraries/GSM -I/usr/share/arduino/libraries/Firmata -I/usr/share/arduino/libraries/Ethernet -I/usr/share/arduino/libraries/Esplora -Wall -g2 -gstabs -Os -ffunction-sections -fdata-sections -std=gnu99 -mmcu=atmega2560 -DF_CPU=1600000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


