################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/ST/STM32_USB_Device_Library/Class/HID/Src/usbd_hid.c 

OBJS += \
./Middlewares/ST/STM32_USB_Device_Library/Class/HID/Src/usbd_hid.o 

C_DEPS += \
./Middlewares/ST/STM32_USB_Device_Library/Class/HID/Src/usbd_hid.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/STM32_USB_Device_Library/Class/HID/Src/%.o Middlewares/ST/STM32_USB_Device_Library/Class/HID/Src/%.su Middlewares/ST/STM32_USB_Device_Library/Class/HID/Src/%.cyclo: ../Middlewares/ST/STM32_USB_Device_Library/Class/HID/Src/%.c Middlewares/ST/STM32_USB_Device_Library/Class/HID/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DUSER_VECT_TAB_ADDRESS -DUSE_HAL_DRIVER -DSTM32G4A1xx -c -I../Core/Inc -I../Application/Fram_SPI -I../Application/Aes -I../Application/Crc -I../Config -I../Application/USB_KeyboardKeyDescriptor -I../Application/Led -I../Application/Supp -I../Application/Buttons -I../Application/SM -I../Application/Data -I../Application/Buckup_procedure -I../Application/SSD1331 -I../Application/WS2812B -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I../USB_Device/App -I../USB_Device/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-ST-2f-STM32_USB_Device_Library-2f-Class-2f-HID-2f-Src

clean-Middlewares-2f-ST-2f-STM32_USB_Device_Library-2f-Class-2f-HID-2f-Src:
	-$(RM) ./Middlewares/ST/STM32_USB_Device_Library/Class/HID/Src/usbd_hid.cyclo ./Middlewares/ST/STM32_USB_Device_Library/Class/HID/Src/usbd_hid.d ./Middlewares/ST/STM32_USB_Device_Library/Class/HID/Src/usbd_hid.o ./Middlewares/ST/STM32_USB_Device_Library/Class/HID/Src/usbd_hid.su

.PHONY: clean-Middlewares-2f-ST-2f-STM32_USB_Device_Library-2f-Class-2f-HID-2f-Src

