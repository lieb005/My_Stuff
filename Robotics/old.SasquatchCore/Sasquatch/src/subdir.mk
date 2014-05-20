################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ATmegaBOOT.c \
../src/ATmegaBOOT_168.c \
../src/Arduino-usbdfu.c \
../src/Arduino-usbserial.c \
../src/Caterina.c \
../src/Descriptors.c \
../src/WInterrupts.c \
../src/ard_spi.c \
../src/ard_tcp.c \
../src/ard_utils.c \
../src/avr32_spi.c \
../src/board_init.c \
../src/clocks.c \
../src/cmd_wl.c \
../src/console.c \
../src/ctrl_access.c \
../src/debug.c \
../src/delay.c \
../src/eic.c \
../src/flash_fw.c \
../src/flashc.c \
../src/fw_download_extflash.c \
../src/glcdfont.c \
../src/gpio.c \
../src/intc.c \
../src/led.c \
../src/lwip_setup.c \
../src/main.c \
../src/malloc.c \
../src/nor_flash.c \
../src/nvram.c \
../src/optiboot.c \
../src/owl_os.c \
../src/pdca.c \
../src/ping.c \
../src/pm.c \
../src/pm_conf_clocks.c \
../src/power_clocks_lib.c \
../src/print_funcs.c \
../src/printf-stdarg.c \
../src/realloc.c \
../src/rtc.c \
../src/smc.c \
../src/socket.c \
../src/spi.c \
../src/startup.c \
../src/stk500boot.c \
../src/tc.c \
../src/timer.c \
../src/twi.c \
../src/usart.c \
../src/util.c \
../src/wiring.c \
../src/wiring_analog.c \
../src/wiring_digital.c \
../src/wiring_pulse.c \
../src/wiring_shift.c \
../src/wl_cm.c 

OBJS += \
./src/ATmegaBOOT.o \
./src/ATmegaBOOT_168.o \
./src/Arduino-usbdfu.o \
./src/Arduino-usbserial.o \
./src/Caterina.o \
./src/Descriptors.o \
./src/WInterrupts.o \
./src/ard_spi.o \
./src/ard_tcp.o \
./src/ard_utils.o \
./src/avr32_spi.o \
./src/board_init.o \
./src/clocks.o \
./src/cmd_wl.o \
./src/console.o \
./src/ctrl_access.o \
./src/debug.o \
./src/delay.o \
./src/eic.o \
./src/flash_fw.o \
./src/flashc.o \
./src/fw_download_extflash.o \
./src/glcdfont.o \
./src/gpio.o \
./src/intc.o \
./src/led.o \
./src/lwip_setup.o \
./src/main.o \
./src/malloc.o \
./src/nor_flash.o \
./src/nvram.o \
./src/optiboot.o \
./src/owl_os.o \
./src/pdca.o \
./src/ping.o \
./src/pm.o \
./src/pm_conf_clocks.o \
./src/power_clocks_lib.o \
./src/print_funcs.o \
./src/printf-stdarg.o \
./src/realloc.o \
./src/rtc.o \
./src/smc.o \
./src/socket.o \
./src/spi.o \
./src/startup.o \
./src/stk500boot.o \
./src/tc.o \
./src/timer.o \
./src/twi.o \
./src/usart.o \
./src/util.o \
./src/wiring.o \
./src/wiring_analog.o \
./src/wiring_digital.o \
./src/wiring_pulse.o \
./src/wiring_shift.o \
./src/wl_cm.o 

C_DEPS += \
./src/ATmegaBOOT.d \
./src/ATmegaBOOT_168.d \
./src/Arduino-usbdfu.d \
./src/Arduino-usbserial.d \
./src/Caterina.d \
./src/Descriptors.d \
./src/WInterrupts.d \
./src/ard_spi.d \
./src/ard_tcp.d \
./src/ard_utils.d \
./src/avr32_spi.d \
./src/board_init.d \
./src/clocks.d \
./src/cmd_wl.d \
./src/console.d \
./src/ctrl_access.d \
./src/debug.d \
./src/delay.d \
./src/eic.d \
./src/flash_fw.d \
./src/flashc.d \
./src/fw_download_extflash.d \
./src/glcdfont.d \
./src/gpio.d \
./src/intc.d \
./src/led.d \
./src/lwip_setup.d \
./src/main.d \
./src/malloc.d \
./src/nor_flash.d \
./src/nvram.d \
./src/optiboot.d \
./src/owl_os.d \
./src/pdca.d \
./src/ping.d \
./src/pm.d \
./src/pm_conf_clocks.d \
./src/power_clocks_lib.d \
./src/print_funcs.d \
./src/printf-stdarg.d \
./src/realloc.d \
./src/rtc.d \
./src/smc.d \
./src/socket.d \
./src/spi.d \
./src/startup.d \
./src/stk500boot.d \
./src/tc.d \
./src/timer.d \
./src/twi.d \
./src/usart.d \
./src/util.d \
./src/wiring.d \
./src/wiring_analog.d \
./src/wiring_digital.d \
./src/wiring_pulse.d \
./src/wiring_shift.d \
./src/wl_cm.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I/usr/share/arduino/libraries/EEPROM -I/usr/share/arduino/hardware/arduino/bootloaders/stk500v2 -I/usr/share/arduino/hardware/sasquatch/variants/sasquatch -I/usr/share/arduino/hardware/arduino/cores/robot -I/usr/share/arduino/hardware/arduino/cores/arduino -I/usr/share/arduino/libraries/Wire -I/usr/share/arduino/libraries/WiFi -I/usr/share/arduino/libraries/TFT -I/usr/share/arduino/libraries/Stepper -I/usr/share/arduino/libraries/SPI -I/usr/share/arduino/libraries/SoftwareSerial -I/usr/share/arduino/libraries/Servo -I/usr/share/arduino/libraries/SD -I/usr/share/arduino/libraries/RobotOpen -I/usr/share/arduino/libraries/Robot_Motor -I/usr/share/arduino/libraries/Robot_Control -I/usr/share/arduino/libraries/LiquidCrystal -I/usr/share/arduino/libraries/GSM -I/usr/share/arduino/libraries/Firmata -I/usr/share/arduino/libraries/Ethernet -I/usr/share/arduino/libraries/Esplora -Wall -g2 -gstabs -Os -ffunction-sections -fdata-sections -std=gnu99 -mmcu=atmega2560 -DF_CPU=1600000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


