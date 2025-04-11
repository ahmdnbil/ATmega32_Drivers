CPU_CLK= 8000000UL
DEVICE= atmega32
CC= avr-gcc

dioCFile = Include/MCAL/DIO/DIO.c
dioOFile = Debug/$(subst .c,.o,$(dioCFile))
dioDFile = Debug/$(subst .c,.d,$(dioCFile))

extiCFile = Include/MCAL/EXTI/EXTI.c
extiOFile = Debug/$(subst .c,.o,$(extiCFile))
extiDFile = Debug/$(subst .c,.d,$(extiCFile))

adcCFile = Include/MCAL/ADC/ADC.c
adcOFile = Debug/$(subst .c,.o,$(adcCFile))
adcDFile = Debug/$(subst .c,.d,$(adcCFile))

timer0CFile = Include/MCAL/TIMER0/TIMER0.c
timer0OFile = Debug/$(subst .c,.o,$(timer0CFile))
timer0DFile = Debug/$(subst .c,.d,$(timer0CFile))

timer1CFile = Include/MCAL/TIMER1/TIMER1.c
timer1OFile = Debug/$(subst .c,.o,$(timer1CFile))
timer1DFile = Debug/$(subst .c,.d,$(timer1CFile))

timer2CFile = Include/MCAL/TIMER2/TIMER2.c
timer2OFile = Debug/$(subst .c,.o,$(timer2CFile))
timer2DFile = Debug/$(subst .c,.d,$(timer2CFile))

wdtCFile = Include/MCAL/WDT/WDT.c
wdtOFile = Debug/$(subst .c,.o,$(wdtCFile))
wdtDFile = Debug/$(subst .c,.d,$(wdtCFile))

uartCFile = Include/MCAL/UART/UART.c
uartOFile = Debug/$(subst .c,.o,$(uartCFile))
uartDFile = Debug/$(subst .c,.d,$(uartCFile))

spiCFile = Include/MCAL/SPI/SPI.c
spiOFile = Debug/$(subst .c,.o,$(spiCFile))
spiDFile = Debug/$(subst .c,.d,$(spiCFile))

twiCFile = Include/MCAL/TWI/TWI.c
twiOFile = Debug/$(subst .c,.o,$(twiCFile))
twiDFile = Debug/$(subst .c,.d,$(twiCFile))

ineepromCFile = Include/MCAL/InEEPROM/InEEPROM.c
ineepromOFile = Debug/$(subst .c,.o,$(ineepromCFile))
ineepromDFile = Debug/$(subst .c,.d,$(ineepromCFile))

ssdCFile = Include/HAL/SSD/SSD.c
ssdOFile = Debug/$(subst .c,.o,$(ssdCFile))
ssdDFile = Debug/$(subst .c,.d,$(ssdCFile))

lcdCFile = Include/HAL/LCD/LCD.c
lcdOFile = Debug/$(subst .c,.o,$(lcdCFile))
lcdDFile = Debug/$(subst .c,.d,$(lcdCFile))

keyCFile = Include/HAL/KEYPAD/KEYPAD.c
keyOFile = Debug/$(subst .c,.o,$(keyCFile))
keyDFile = Debug/$(subst .c,.d,$(keyCFile))

DCmotorCFile = Include/HAL/DCMOTOR/DCMOTOR.c
DCmotorOFile = Debug/$(subst .c,.o,$(DCmotorCFile))
DCmotorDFile = Debug/$(subst .c,.d,$(DCmotorCFile))

STEPCFile = Include/HAL/STEPPER/STEPPER.c
STEPOFile = Debug/$(subst .c,.o,$(STEPCFile))
STEPDFile = Debug/$(subst .c,.d,$(STEPCFile))

servoCFile = Include/HAL/SERVO/SERVO.c
servoOFile = Debug/$(subst .c,.o,$(servoCFile))
servoDFile = Debug/$(subst .c,.d,$(servoCFile))

ultraCFile = Include/HAL/ULTRASONIC/ULTRASONIC.c
ultraOFile = Debug/$(subst .c,.o,$(ultraCFile))
ultraDFile = Debug/$(subst .c,.d,$(ultraCFile))

rtcCFile = Include/HAL/RTC/RTC.c
rtcOFile = Debug/$(subst .c,.o,$(rtcCFile))
rtcDFile = Debug/$(subst .c,.d,$(rtcCFile))

exeepromCFile = Include/HAL/ExEEPROM/ExEEPROM.c
exeepromOFile = Debug/$(subst .c,.o,$(exeepromCFile))
exeepromDFile = Debug/$(subst .c,.d,$(exeepromCFile))

TservCFile = Include/SERVICES/TIMERs/Timers.c
TservOFile = Debug/$(subst .c,.o,$(TservCFile))
TservDFile = Debug/$(subst .c,.d,$(TservCFile))

UservCFile = Include/SERVICES/UART/UART_serv.c
UservOFile = Debug/$(subst .c,.o,$(UservCFile))
UservDFile = Debug/$(subst .c,.d,$(UservCFile))

mainCFile = main.c
mainOFile = Debug/main.o
mainDFile = Debug/main.d

# This variable is for making the layered architecture but for object files
PATHS := $(shell find . -name '*.c' | sed 's|^\./|Debug/|' | xargs -I {} dirname {})
# first thing, find command will get all paths of c files

# second thing, sed command will take find output as input and remove '.' at begining of path and add Debug
# for example ./Include/MCAL/DIO/DIO_Program.c ==> Debug/Include/MCAL/DIO/DIO_Program.c

# third thing, xargs will take output of sed as input and get the directory name of fil using dirname
# for example: Debug/Include/MCAL/DIO/DIO_Program.c ==> Debug/Include/MCAL/DIO/

#to make the name of output files as the name of current directroy [Project name]
currentFolder := $(shell basename $(CURDIR))
mapFile=Debug/$(currentFolder).map
elfFile=Debug/$(currentFolder).elf
lssFile=Debug/$(currentFolder).lss
hexFile=Debug/$(currentFolder).hex
