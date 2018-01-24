################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../marlin/ConfigurationStore.cpp \
../marlin/LiquidCrystalChina.cpp \
../marlin/MarlinSerial.cpp \
../marlin/Marlin_main.cpp \
../marlin/Sd2Card.cpp \
../marlin/SdBaseFile.cpp \
../marlin/SdFatUtil.cpp \
../marlin/SdFile.cpp \
../marlin/SdVolume.cpp \
../marlin/cardreader.cpp \
../marlin/motion_control.cpp \
../marlin/planner.cpp \
../marlin/stepper.cpp \
../marlin/temperature.cpp \
../marlin/ultralcd.cpp \
../marlin/watchdog.cpp 

OBJS += \
./marlin/ConfigurationStore.o \
./marlin/LiquidCrystalChina.o \
./marlin/MarlinSerial.o \
./marlin/Marlin_main.o \
./marlin/Sd2Card.o \
./marlin/SdBaseFile.o \
./marlin/SdFatUtil.o \
./marlin/SdFile.o \
./marlin/SdVolume.o \
./marlin/cardreader.o \
./marlin/motion_control.o \
./marlin/planner.o \
./marlin/stepper.o \
./marlin/temperature.o \
./marlin/ultralcd.o \
./marlin/watchdog.o 

CPP_DEPS += \
./marlin/ConfigurationStore.d \
./marlin/LiquidCrystalChina.d \
./marlin/MarlinSerial.d \
./marlin/Marlin_main.d \
./marlin/Sd2Card.d \
./marlin/SdBaseFile.d \
./marlin/SdFatUtil.d \
./marlin/SdFile.d \
./marlin/SdVolume.d \
./marlin/cardreader.d \
./marlin/motion_control.d \
./marlin/planner.d \
./marlin/stepper.d \
./marlin/temperature.d \
./marlin/ultralcd.d \
./marlin/watchdog.d 


# Each subdirectory must supply rules for building sources it contributes
marlin/%.o: ../marlin/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -Dprintf=iprintf -DARDUINO=10708 -DF_CPU=72000000L -DARDUINO_STM32_F103VB -DARDUINO_ARCH_STM32F10X -DARDUINO_ARCH_STM32 -I"../marlin" -I"../som/variants/ST103VB" -I"../som/cores/arduino" -I"../som/cores/arduino/avr" -I"../som/system/stm32f10x" -I"../som/system/stm32f10x/CoreSupport" -I"../som/system/stm32f10x/DeviceSupport" -I"../som/system/stm32f10x/StdPeriphDriver/inc" -fabi-version=0 -fno-exceptions -fno-rtti -fno-threadsafe-statics -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


