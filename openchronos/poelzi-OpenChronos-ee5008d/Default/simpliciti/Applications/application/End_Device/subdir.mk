################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../simpliciti/Applications/application/End_Device/main_ED_BM.c 

OBJS += \
./simpliciti/Applications/application/End_Device/main_ED_BM.o 

C_DEPS += \
./simpliciti/Applications/application/End_Device/main_ED_BM.d 


# Each subdirectory must supply rules for building sources it contributes
simpliciti/Applications/application/End_Device/%.o: ../simpliciti/Applications/application/End_Device/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	msp430-gcc -O2 -g -Wall -c -fmessage-length=0 -Wl,-Map=output.map -Os -Wall -fomit-frame-pointer -fno-force-addr -finline-limit=1 -fno-schedule-insns -D__MSP430_6137__ -DMRFI_CC430 -D__CC430F6137__ -DELIMINATE_BLUEROBIN -mmcu=cc430x6137 -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/ -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/include/ -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/gcc/ -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/driver/ -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/logic/ -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/bluerobin/ -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/simpliciti/ -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/simpliciti/Components/bsp -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/simpliciti/Components/bsp/drivers -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/simpliciti/Components/bsp/boards/CC430EM -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/simpliciti/Components/mrfi -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/simpliciti/Components/nwk -I/home/mark/Workspace\ Eclipse\ C\ Linux/poelzi-OpenChronos-ee5008d/simpliciti/Components/nwk_applications -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


