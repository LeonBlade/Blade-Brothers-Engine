################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Animation.cpp \
../Entity.cpp \
../FPS.cpp \
../Game.cpp \
../GameState.cpp \
../Graphics.cpp \
../Keyboard.cpp \
../Log.cpp \
../Map.cpp \
../Sprite.cpp \
../main.cpp 

OBJS += \
./Animation.o \
./Entity.o \
./FPS.o \
./Game.o \
./GameState.o \
./Graphics.o \
./Keyboard.o \
./Log.o \
./Map.o \
./Sprite.o \
./main.o 

CPP_DEPS += \
./Animation.d \
./Entity.d \
./FPS.d \
./Game.d \
./GameState.d \
./Graphics.d \
./Keyboard.d \
./Log.d \
./Map.d \
./Sprite.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/opt/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


