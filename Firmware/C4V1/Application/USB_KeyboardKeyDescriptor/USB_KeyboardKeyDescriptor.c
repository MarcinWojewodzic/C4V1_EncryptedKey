/*
 * USB_KeyboardKeyDescriptor.c
 *
 *  Created on: Apr 9, 2023
 *      Author: M
 */
#include "main.h"

#include "USB_KeyboardKeyDescriptor.h"

#include "usb_device.h"
#include "usbd_hid.h"
uint8_t UsbHidKeyboardReportBuffer[8] = { 0 };
extern USBD_HandleTypeDef hUsbDeviceFS;
void USB_KeyBoardKeyDescriptor(uint8_t ASCII)
{
   if(ASCII >= 97 && ASCII <= 122)
   {
      UsbHidKeyboardReportBuffer[2] = ASCII - 93;
   }
   else if(ASCII >= 65 && ASCII <= 90)
   {
      UsbHidKeyboardReportBuffer[0] = 0x02;
      UsbHidKeyboardReportBuffer[2] = ASCII - 61;
   }
   else if(ASCII >= 48 && ASCII <= 57)
   {
      UsbHidKeyboardReportBuffer[2] = ASCII - 18;
   }
   else if(ASCII == '!')
   {
      UsbHidKeyboardReportBuffer[0] = 0x02;
      UsbHidKeyboardReportBuffer[2] = 30;
   }
   else if(ASCII == '@')
   {
      UsbHidKeyboardReportBuffer[0] = 0x02;
      UsbHidKeyboardReportBuffer[2] = 31;
   }
   else if(ASCII == '#')
   {
      UsbHidKeyboardReportBuffer[0] = 0x02;
      UsbHidKeyboardReportBuffer[2] = 32;
   }
   else if(ASCII == '$')
   {
      UsbHidKeyboardReportBuffer[0] = 0x02;
      UsbHidKeyboardReportBuffer[2] = 33;
   }
   else if(ASCII == '%')
   {
      UsbHidKeyboardReportBuffer[0] = 0x02;
      UsbHidKeyboardReportBuffer[2] = 34;
   }
   else if(ASCII == '^')
   {
      UsbHidKeyboardReportBuffer[0] = 0x02;
      UsbHidKeyboardReportBuffer[2] = 35;
   }
   else if(ASCII == '&')
   {
      UsbHidKeyboardReportBuffer[0] = 0x02;
      UsbHidKeyboardReportBuffer[2] = 36;
   }
   else if(ASCII == '*')
   {
      UsbHidKeyboardReportBuffer[0] = 0x02;
      UsbHidKeyboardReportBuffer[2] = 37;
   }
   else if(ASCII == '(')
   {
      UsbHidKeyboardReportBuffer[0] = 0x02;
      UsbHidKeyboardReportBuffer[2] = 38;
   }
   else if(ASCII == ')')
   {
      UsbHidKeyboardReportBuffer[0] = 0x02;
      UsbHidKeyboardReportBuffer[2] = 39;
   }
   else if(ASCII == 0)
   {
      UsbHidKeyboardReportBuffer[0] = 0;
      UsbHidKeyboardReportBuffer[2] = 0;
   }
   USBD_HID_SendReport(&hUsbDeviceFS, UsbHidKeyboardReportBuffer, 8);
   UsbHidKeyboardReportBuffer[0] = 0;
   UsbHidKeyboardReportBuffer[2] = 0;
   HAL_Delay(10);
   USBD_HID_SendReport(&hUsbDeviceFS, UsbHidKeyboardReportBuffer, 8);
   HAL_Delay(10);
}
