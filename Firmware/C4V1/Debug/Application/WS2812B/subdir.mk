################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/WS2812B/WS2812b.c 

OBJS += \
./Application/WS2812B/WS2812b.o 

C_DEPS += \
./Application/WS2812B/WS2812b.d 


# Each subdirectory must supply rules for building sources it contributes
Application/WS2812B/%.o Application/WS2812B/%.su Application/WS2812B/%.cyclo: ../Application/WS2812B/%.c Application/WS2812B/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DUSER_VECT_TAB_ADDRESS -DUSE_HAL_DRIVER -DSTM32G4A1xx -c -I../Core/Inc -I../Application/Fram_SPI -I../Application/Aes -I../Application/Crc -I../Config -I../Application/USB_KeyboardKeyDescriptor -I../Application/Led -I../Application/Supp -I../Application/Buttons -I../Application/SM -I../Application/Data -I../Application/Buckup_procedure -I../Application/SSD1331 -I../Application/WS2812B -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I../USB_Device/App -I../USB_Device/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-WS2812B

clean-Application-2f-WS2812B:
	-$(RM) ./Application/WS2812B/WS2812b.cyclo ./Application/WS2812B/WS2812b.d ./Application/WS2812B/WS2812b.o ./Application/WS2812B/WS2812b.su

.PHONY: clean-Application-2f-WS2812B

