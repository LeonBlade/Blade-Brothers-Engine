################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Toolkit/main.cpp \
../Toolkit/mainwindow.cpp 

OBJS += \
./Toolkit/main.o \
./Toolkit/mainwindow.o 

CPP_DEPS += \
./Toolkit/main.d \
./Toolkit/mainwindow.d 


# Each subdirectory must supply rules for building sources it contributes
Toolkit/%.o: ../Toolkit/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/opt/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


