################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/DIO_Program.c \
../Src/KEYPAD_Program.c \
../Src/LCD4_Program.c \
../Src/LCD8_Program.c \
../Src/SSD_Program.c \
../Src/main.c 

OBJS += \
./Src/DIO_Program.o \
./Src/KEYPAD_Program.o \
./Src/LCD4_Program.o \
./Src/LCD8_Program.o \
./Src/SSD_Program.o \
./Src/main.o 

C_DEPS += \
./Src/DIO_Program.d \
./Src/KEYPAD_Program.d \
./Src/LCD4_Program.d \
./Src/LCD8_Program.d \
./Src/SSD_Program.d \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


