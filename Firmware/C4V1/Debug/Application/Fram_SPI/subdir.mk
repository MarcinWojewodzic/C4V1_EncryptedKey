################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/Fram_SPI/Fram_spi.c 

OBJS += \
./Application/Fram_SPI/Fram_spi.o 

C_DEPS += \
./Application/Fram_SPI/Fram_spi.d 


# Each subdirectory must supply rules for building sources it contributes
Application/Fram_SPI/%.o Application/Fram_SPI/%.su Application/Fram_SPI/%.cyclo: ../Application/Fram_SPI/%.c Application/Fram_SPI/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DUSER_VECT_TAB_ADDRESS -DUSE_HAL_DRIVER -DSTM32G4A1xx -c -I../Core/Inc -I../Application/Fram_SPI -I../Application/Aes -I../Application/Crc -I../Config -I../Application/USB_KeyboardKeyDescriptor -I../Application/Led -I../Application/Supp -I../Application/Buttons -I../Application/SM -I../Application/Data -I../Application/Buckup_procedure -I../Application/SSD1331 -I../Application/WS2812B -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I../USB_Device/App -I../USB_Device/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-Fram_SPI

clean-Application-2f-Fram_SPI:
	-$(RM) ./Application/Fram_SPI/Fram_spi.cyclo ./Application/Fram_SPI/Fram_spi.d ./Application/Fram_SPI/Fram_spi.o ./Application/Fram_SPI/Fram_spi.su

.PHONY: clean-Application-2f-Fram_SPI

