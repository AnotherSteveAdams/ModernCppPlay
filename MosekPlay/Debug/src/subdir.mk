################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/duality.cc \
../src/lo1.cc 

CPP_SRCS += \
../src/MosekPlay.cpp 

CC_DEPS += \
./src/duality.d \
./src/lo1.d 

OBJS += \
./src/MosekPlay.o \
./src/duality.o \
./src/lo1.o 

CPP_DEPS += \
./src/MosekPlay.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/adamsst/mosek/8/tools/platform/linux64x86/h -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/adamsst/mosek/8/tools/platform/linux64x86/h -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


