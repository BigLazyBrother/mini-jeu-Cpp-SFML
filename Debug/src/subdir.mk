################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Gangster.cpp \
../src/Gentil.cpp \
../src/Mechant.cpp \
../src/ProjetLuckyLukeLocal.cpp \
../src/Sheriff.cpp 

OBJS += \
./src/Gangster.o \
./src/Gentil.o \
./src/Mechant.o \
./src/ProjetLuckyLukeLocal.o \
./src/Sheriff.o 

CPP_DEPS += \
./src/Gangster.d \
./src/Gentil.d \
./src/Mechant.d \
./src/ProjetLuckyLukeLocal.d \
./src/Sheriff.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1z -O0 -g3 -Wall -c -fmessage-length=0 -Wno-attributes -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


