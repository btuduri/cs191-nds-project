################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../graphics/menu0.c \
../graphics/menu1.c \
../graphics/menu2.c \
../graphics/menu3.c \
../graphics/minimashers.c \
../graphics/splash.c \
../graphics/title.c 

OBJS += \
./graphics/menu0.o \
./graphics/menu1.o \
./graphics/menu2.o \
./graphics/menu3.o \
./graphics/minimashers.o \
./graphics/splash.o \
./graphics/title.o 

C_DEPS += \
./graphics/menu0.d \
./graphics/menu1.d \
./graphics/menu2.d \
./graphics/menu3.d \
./graphics/minimashers.d \
./graphics/splash.d \
./graphics/title.d 


# Each subdirectory must supply rules for building sources it contributes
graphics/%.o: ../graphics/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	arm-eabi-gcc -Iinclude -O2 -g -Wall -c -fmessage-length=0 -ffast-math -fomit-frame-pointer -mthumb-interwork -mthumb -mcpu=arm9tdmi -mtune=arm9tdmi -DARM9 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


