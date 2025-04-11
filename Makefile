include buildProcess.mk
	
defalut: flashImage	
clean:
	@rm -r Debug


.PHONY: folder
folder:
	@mkdir -p $(PATHS)

build: folder 
	@echo "Generate Include files for main"
	@$(CC) -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK) -std=c99   -o "$(mainOFile)" -c  "$(mainCFile)"


	@echo "Generate Include files for DIO"
	@$(CC) -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK)  -std=c99 -o "$(dioOFile)" -c "$(dioCFile)"

	@echo "Generate Include files for EXTI"
	@$(CC) -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK) -std=c99  -o "$(extiOFile)" -c "$(extiCFile)"

	@echo "Generate Include files for ADC"
	@$(CC) -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK) -std=c99  -o "$(adcOFile)" -c "$(adcCFile)"

	@echo "Generate Include files for TIMER0"
	@$(CC) -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK) -std=c99  -o "$(timer0OFile)" -c "$(timer0CFile)"

	@echo "Generate Include files for TIMER1"
	@$(CC) -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK) -std=c99  -o "$(timer1OFile)" -c "$(timer1CFile)"

	@echo "Generate Include files for TIMER2"
	@$(CC) -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK) -std=c99  -o "$(timer2OFile)" -c "$(timer2CFile)"

	@echo "Generate Include files for WDT"
	@$(CC) -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK) -std=c99  -o "$(wdtOFile)" -c "$(wdtCFile)"

	@echo "Generate Include files for UART"
	@$(CC) -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK) -std=c99  -o "$(uartOFile)" -c "$(uartCFile)"

	@echo "Generate Include files for SPI"
	@$(CC) -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK) -std=c99  -o "$(spiOFile)" -c "$(spiCFile)"

	@echo "Generate Include files for TWI"
	@$(CC) -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK) -std=c99  -o "$(twiOFile)" -c "$(twiCFile)"

	@echo "Generate Include files for InEEPROM"
	@$(CC) -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK) -std=c99  -o "$(ineepromOFile)" -c "$(ineepromCFile)"

	@echo "Generate Include files for SSD"
	@$(CC) -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK) -std=c99  -o "$(ssdOFile)" -c "$(ssdCFile)"

	@echo "Generate Include files for LCD"
	@$(CC) -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK) -std=c99  -o "$(lcdOFile)" -c "$(lcdCFile)"

	@echo "Generate Include files for KEYPAD"
	@$(CC) -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK) -std=c99  -o "$(keyOFile)" -c "$(keyCFile)"

	@echo "Generate Include files for DC MOTOR"
	@$(CC) -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK) -std=c99  -o "$(DCmotorOFile)" -c "$(DCmotorCFile)"

	@echo "Generate Include files for Stepper MOTOR"
	@$(CC) -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK) -std=c99  -o "$(STEPOFile)" -c "$(STEPCFile)"

	@echo "Generate Include files for Servo MOTOR"
	@$(CC) -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK) -std=c99  -o "$(servoOFile)" -c "$(servoCFile)"

	@echo "Generate Include files for ULTRASONIC"
	@$(CC) -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK) -std=c99  -o "$(ultraOFile)" -c "$(ultraCFile)"

	@echo "Generate Include files for RTC"
	@$(CC) -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK) -std=c99  -o "$(rtcOFile)" -c "$(rtcCFile)"

	@echo "Generate Include files for ExEEPROM"
	@$(CC) -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK) -std=c99  -o "$(exeepromOFile)" -c "$(exeepromCFile)"

	@echo "Generate Include files for Timers Services"
	@$(CC) -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK) -std=c99  -o "$(TservOFile)" -c "$(TservCFile)"

	@echo "Generate Include files for UART Services"
	@$(CC) -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK) -std=c99  -o "$(UservOFile)" -c "$(UservCFile)"

	


linker: build
	@echo "linking process..."
	@$(CC) -mmcu=$(DEVICE) -o "$(elfFile)"   $(mainOFile) $(dioOFile) $(extiOFile) $(ssdOFile) $(lcdOFile) $(keyOFile) $(DCmotorOFile) $(STEPOFile) $(adcOFile) $(timer0OFile) $(timer1OFile) $(servoOFile) $(timer2OFile) $(wdtOFile) $(TservOFile) $(ultraOFile) $(uartOFile) $(UservOFile) $(spiOFile) $(twiOFile) $(rtcOFile) $(exeepromOFile) $(ineepromOFile)    

Listing: linker
	@echo "Generating listing file..."
	@avr-objdump -h -S $(elfFile)  >"$(lssFile)"

flashImage: Listing
	@echo "Generating hex file..."
	@avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex $(elfFile)  "$(hexFile)"
