################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm

# All of the sources participating in the build are defined here
-include sources.mk
-include simpliciti/Components/nwk_applications/subdir.mk
-include simpliciti/Components/nwk/subdir.mk
-include simpliciti/Components/mrfi/radios/family5/subdir.mk
-include simpliciti/Components/mrfi/subdir.mk
-include simpliciti/Components/bsp/drivers/code/subdir.mk
-include simpliciti/Components/bsp/boards/CC430EM/subdir.mk
-include simpliciti/Components/bsp/subdir.mk
-include simpliciti/Applications/application/End_Device/subdir.mk
-include logic/subdir.mk
-include gcc/subdir.mk
-include driver/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: poelzi-OpenChronos-ee5008d.elf

# Tool invocations
poelzi-OpenChronos-ee5008d.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	msp430-g++  -o "poelzi-OpenChronos-ee5008d.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C++_DEPS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) poelzi-OpenChronos-ee5008d.elf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
