################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include simpliciti/Components/nwk_applications/subdir.mk
-include simpliciti/Components/nwk/subdir.mk
-include simpliciti/Components/mrfi/radios/family5/subdir.mk
-include simpliciti/Components/mrfi/subdir.mk
-include simpliciti/Components/bsp/drivers/code/subdir.mk
-include simpliciti/Components/bsp/boards/CC430EM/subdir.mk
-include simpliciti/Components/bsp/subdir.mk
-include simpliciti/Applications/application/End\ Device/subdir.mk
-include logic/subdir.mk
-include driver/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: ez430-chronos\ firmware

# Tool invocations
ez430-chronos\ firmware: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	msp430-gcc  -o "ez430-chronos firmware" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) "ez430-chronos firmware"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
