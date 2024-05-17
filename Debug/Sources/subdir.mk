################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Broad.c \
../Sources/Events.c \
../Sources/exit.c \
../Sources/led_control.c \
../Sources/main.c 

OBJS += \
./Sources/Broad.o \
./Sources/Events.o \
./Sources/exit.o \
./Sources/led_control.o \
./Sources/main.o 

C_DEPS += \
./Sources/Broad.d \
./Sources/Events.d \
./Sources/exit.d \
./Sources/led_control.d \
./Sources/main.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"D:/CODE/Kinetis_WS/assignment/Static_Code/PDD" -I"D:/CODE/Kinetis_WS/assignment/Static_Code/IO_Map" -I"D:/CODE/Kinetis_WS/assignment/Sources" -I"D:/CODE/Kinetis_WS/assignment/Generated_Code" -I"D:/CODE/Kinetis_WS/assignment/Sources/TSS" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


