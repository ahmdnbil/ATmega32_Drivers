################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Include/SERVICES/UART/subdir.mk
-include Include/SERVICES/RTOS/subdir.mk
-include Include/MCAL/WDT/subdir.mk
-include Include/MCAL/UART/subdir.mk
-include Include/MCAL/TWI/subdir.mk
-include Include/MCAL/TIMER2/subdir.mk
-include Include/MCAL/TIMER1/subdir.mk
-include Include/MCAL/TIMER0/subdir.mk
-include Include/MCAL/SPI/subdir.mk
-include Include/MCAL/EXTI/subdir.mk
-include Include/MCAL/DIO/subdir.mk
-include Include/MCAL/ADC/subdir.mk
-include Include/HAL/ULTRASONIC/subdir.mk
-include Include/HAL/STEPPER/subdir.mk
-include Include/HAL/SSD/subdir.mk
-include Include/HAL/SERVOMOTOR/subdir.mk
-include Include/HAL/LCD/subdir.mk
-include Include/HAL/KEYPAD/subdir.mk
-include Include/HAL/EEPROM/subdir.mk
-include Include/HAL/DCMOTOR/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ATmega32_Drivers.lss \

FLASH_IMAGE += \
ATmega32_Drivers.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: ATmega32_Drivers.elf secondary-outputs

# Tool invocations
ATmega32_Drivers.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ATmega32_Drivers.map -mmcu=atmega32 -o "ATmega32_Drivers.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ATmega32_Drivers.lss: ATmega32_Drivers.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ATmega32_Drivers.elf  >"ATmega32_Drivers.lss"
	@echo 'Finished building: $@'
	@echo ' '

ATmega32_Drivers.hex: ATmega32_Drivers.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ATmega32_Drivers.elf  "ATmega32_Drivers.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ATmega32_Drivers.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ATmega32_Drivers.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ATmega32_Drivers.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
