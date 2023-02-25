EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L STM32G4A1KEU6:STM32G4A1KEU6 U3
U 1 1 63FA1A66
P 3000 3300
F 0 "U3" H 3750 2800 50  0000 L CNN
F 1 "STM32G4A1KEU6" H 3500 2600 50  0000 L CNN
F 2 "QFN50P500X500X60-33N-D" H 4450 4000 50  0001 L CNN
F 3 "https://www.st.com/en/microcontrollers-microprocessors/stm32g4a1ke.html" H 4450 3900 50  0001 L CNN
F 4 "ARM Microcontrollers - MCU Mainstream Arm Cortex-M4+ MCU 170MHz with 512Kbytes of Flash memory" H 4450 3800 50  0001 L CNN "Description"
F 5 "0.6" H 4450 3700 50  0001 L CNN "Height"
F 6 "STMicroelectronics" H 4450 3600 50  0001 L CNN "Manufacturer_Name"
F 7 "STM32G4A1KEU6" H 4450 3500 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "511-STM32G4A1KEU6" H 4450 3400 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/STMicroelectronics/STM32G4A1KEU6?qs=eP2BKZSCXI7sopW1JQ5%252BSQ%3D%3D" H 4450 3300 50  0001 L CNN "Mouser Price/Stock"
F 10 "STM32G4A1KEU6" H 4450 3200 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/stm32g4a1keu6/stmicroelectronics?region=nac" H 4450 3100 50  0001 L CNN "Arrow Price/Stock"
	1    3000 3300
	1    0    0    -1  
$EndComp
$Comp
L LDLN050PU33:LDNL050PU33 U1
U 1 1 63FA526B
P 7150 900
F 0 "U1" H 7150 1175 50  0000 C CNN
F 1 "LDLN050PU33" H 7150 1084 50  0000 C CNN
F 2 "Package_DFN_QFN:DFN-8-1EP_3x3mm_P0.65mm_EP1.55x2.4mm" H 6950 1200 50  0001 C CNN
F 3 "" H 6950 1200 50  0001 C CNN
	1    7150 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 950  7450 1000
Wire Wire Line
	7450 1000 7800 1000
Connection ~ 7450 1000
Wire Wire Line
	7450 1000 7450 1050
Wire Wire Line
	6850 950  6500 950 
Wire Wire Line
	6850 1150 6850 1350
Wire Wire Line
	6500 950  6500 1150
Wire Wire Line
	7800 1000 7800 1250
$Comp
L power:GND #PWR0101
U 1 1 63FA73FC
P 7800 1350
F 0 "#PWR0101" H 7800 1100 50  0001 C CNN
F 1 "GND" H 7805 1177 50  0000 C CNN
F 2 "" H 7800 1350 50  0001 C CNN
F 3 "" H 7800 1350 50  0001 C CNN
	1    7800 1350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 63FA7B73
P 6850 1350
F 0 "#PWR0102" H 6850 1100 50  0001 C CNN
F 1 "GND" H 6855 1177 50  0000 C CNN
F 2 "" H 6850 1350 50  0001 C CNN
F 3 "" H 6850 1350 50  0001 C CNN
	1    6850 1350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 63FA7E1D
P 7150 1300
F 0 "#PWR0103" H 7150 1050 50  0001 C CNN
F 1 "GND" H 7155 1127 50  0000 C CNN
F 2 "" H 7150 1300 50  0001 C CNN
F 3 "" H 7150 1300 50  0001 C CNN
	1    7150 1300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 63FA80C5
P 6500 1350
F 0 "#PWR0104" H 6500 1100 50  0001 C CNN
F 1 "GND" H 6505 1177 50  0000 C CNN
F 2 "" H 6500 1350 50  0001 C CNN
F 3 "" H 6500 1350 50  0001 C CNN
	1    6500 1350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 63FA82F1
P 6650 1200
F 0 "C2" H 6600 650 50  0000 L CNN
F 1 "10n/X5R/10V" H 6450 750 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6688 1050 50  0001 C CNN
F 3 "~" H 6650 1200 50  0001 C CNN
	1    6650 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 63FA90A0
P 6250 1000
F 0 "C1" V 6000 950 50  0000 L CNN
F 1 "4.7u/X5R/10V" V 6100 750 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6288 850 50  0001 C CNN
F 3 "~" H 6250 1000 50  0001 C CNN
	1    6250 1000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 63FA9662
P 7950 1000
F 0 "C3" V 8100 950 50  0000 L CNN
F 1 "4.7u/X5R/10V" V 8200 700 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 7988 850 50  0001 C CNN
F 3 "~" H 7950 1000 50  0001 C CNN
	1    7950 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 850  7600 850 
Wire Wire Line
	7950 1150 7950 1250
Wire Wire Line
	7950 1250 7800 1250
Connection ~ 7800 1250
Wire Wire Line
	7800 1250 7800 1350
Wire Wire Line
	6250 850  6850 850 
Wire Wire Line
	6250 1150 6500 1150
Connection ~ 6500 1150
Wire Wire Line
	6500 1150 6500 1350
$Comp
L power:GND #PWR0105
U 1 1 63FAA9BA
P 6650 1350
F 0 "#PWR0105" H 6650 1100 50  0001 C CNN
F 1 "GND" H 6655 1177 50  0000 C CNN
F 2 "" H 6650 1350 50  0001 C CNN
F 3 "" H 6650 1350 50  0001 C CNN
	1    6650 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6850 1050 6650 1050
Wire Wire Line
	7450 1150 7600 1150
Wire Wire Line
	7600 1150 7600 850 
Connection ~ 7600 850 
Wire Wire Line
	7600 850  7950 850 
$Comp
L Connector:USB_A J1
U 1 1 63FAE1F1
P 1150 1500
F 0 "J1" H 1207 1967 50  0000 C CNN
F 1 "48037-2100" H 1207 1876 50  0000 C CNN
F 2 "C4V1:480372100" H 1300 1450 50  0001 C CNN
F 3 " ~" H 1300 1450 50  0001 C CNN
	1    1150 1500
	1    0    0    -1  
$EndComp
$Comp
L ESDALCL6-2SC6:ESDALCL6-2SC6 U2
U 1 1 63FB4150
P 1800 1400
F 0 "U2" H 2450 1665 50  0000 C CNN
F 1 "ESDALCL6-2SC6" H 2450 1574 50  0000 C CNN
F 2 "SOT95P280X145-6N" H 2950 1500 50  0001 L CNN
F 3 "http://www.st.com/web/en/resource/technical/document/datasheet/DM00068844.pdf" H 2950 1400 50  0001 L CNN
F 4 "TVS Diode Uni-Directional ESDALCL6-2SC6 Array 17V, SOT-23 6-Pin" H 2950 1300 50  0001 L CNN "Description"
F 5 "1.45" H 2950 1200 50  0001 L CNN "Height"
F 6 "STMicroelectronics" H 2950 1100 50  0001 L CNN "Manufacturer_Name"
F 7 "ESDALCL6-2SC6" H 2950 1000 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "511-ESDALCL6-2SC6" H 2950 900 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/STMicroelectronics/ESDALCL6-2SC6?qs=uZT4uyn3SpyBaimojm4znA%3D%3D" H 2950 800 50  0001 L CNN "Mouser Price/Stock"
F 10 "ESDALCL6-2SC6" H 2950 700 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/esdalcl6-2sc6/stmicroelectronics" H 2950 600 50  0001 L CNN "Arrow Price/Stock"
	1    1800 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 1500 1650 1500
Wire Wire Line
	1050 1900 1150 1900
Wire Wire Line
	1650 1500 1650 1900
Connection ~ 1150 1900
Wire Wire Line
	1150 1900 1350 1900
Wire Wire Line
	1350 1900 1350 2050
Connection ~ 1350 1900
Wire Wire Line
	1350 1900 1650 1900
$Comp
L power:VBUS #PWR0106
U 1 1 63FB74C8
P 1450 800
F 0 "#PWR0106" H 1450 650 50  0001 C CNN
F 1 "VBUS" H 1465 973 50  0000 C CNN
F 2 "" H 1450 800 50  0001 C CNN
F 3 "" H 1450 800 50  0001 C CNN
	1    1450 800 
	1    0    0    -1  
$EndComp
$Comp
L power:VBUS #PWR0107
U 1 1 63FB85DF
P 3550 1200
F 0 "#PWR0107" H 3550 1050 50  0001 C CNN
F 1 "VBUS" H 3565 1373 50  0000 C CNN
F 2 "" H 3550 1200 50  0001 C CNN
F 3 "" H 3550 1200 50  0001 C CNN
	1    3550 1200
	1    0    0    -1  
$EndComp
Text GLabel 3100 1600 2    50   BiDi ~ 0
D+
Text GLabel 3100 1400 2    50   BiDi ~ 0
D-
$Comp
L power:GND #PWR0108
U 1 1 63FB8EE2
P 1350 2050
F 0 "#PWR0108" H 1350 1800 50  0001 C CNN
F 1 "GND" H 1355 1877 50  0000 C CNN
F 2 "" H 1350 2050 50  0001 C CNN
F 3 "" H 1350 2050 50  0001 C CNN
	1    1350 2050
	1    0    0    -1  
$EndComp
$Comp
L Device:Fuse F1
U 1 1 63FBA886
P 1450 950
F 0 "F1" H 1510 996 50  0000 L CNN
F 1 "SF-0603SA050M-2" H 1510 905 50  0000 L CNN
F 2 "Fuse:Fuse_0603_1608Metric" V 1380 950 50  0001 C CNN
F 3 "~" H 1450 950 50  0001 C CNN
	1    1450 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 1100 1450 1300
$Comp
L Device:Crystal_GND24_Small Y1
U 1 1 63FBE91E
P 2500 3450
F 0 "Y1" V 2650 3500 50  0000 R CNN
F 1 "ECS-80-8-33Q-ADS-TR3" V 2350 3650 20  0000 R CNN
F 2 "Crystal:Crystal_SMD_Abracon_ABM8G-4Pin_3.2x2.5mm" H 2500 3450 50  0001 C CNN
F 3 "~" H 2500 3450 50  0001 C CNN
	1    2500 3450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2500 3550 2850 3550
Wire Wire Line
	2850 3550 2850 3500
Wire Wire Line
	2850 3500 3000 3500
Wire Wire Line
	2500 3350 2850 3350
Wire Wire Line
	2850 3350 2850 3400
Wire Wire Line
	2850 3400 3000 3400
Wire Wire Line
	2500 3350 2350 3350
Connection ~ 2500 3350
Wire Wire Line
	2500 3550 2350 3550
Connection ~ 2500 3550
$Comp
L Device:C C4
U 1 1 63FC5752
P 2200 3350
F 0 "C4" V 2450 3300 50  0000 L CNN
F 1 "8p/C0G/10V" V 2350 3150 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2238 3200 50  0001 C CNN
F 3 "~" H 2200 3350 50  0001 C CNN
	1    2200 3350
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C5
U 1 1 63FC66A5
P 2200 3550
F 0 "C5" V 1950 3500 50  0000 L CNN
F 1 "8p/COG/10V" V 2050 3300 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2238 3400 50  0001 C CNN
F 3 "~" H 2200 3550 50  0001 C CNN
	1    2200 3550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2050 3350 2050 3450
Wire Wire Line
	2050 3450 1850 3450
Wire Wire Line
	1850 3450 1850 3550
Connection ~ 2050 3450
Wire Wire Line
	2050 3450 2050 3550
$Comp
L power:GND #PWR0109
U 1 1 63FC87B1
P 1850 3550
F 0 "#PWR0109" H 1850 3300 50  0001 C CNN
F 1 "GND" H 1855 3377 50  0000 C CNN
F 2 "" H 1850 3550 50  0001 C CNN
F 3 "" H 1850 3550 50  0001 C CNN
	1    1850 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C6
U 1 1 63FCA1D0
P 3550 1650
F 0 "C6" V 3800 1600 50  0000 L CNN
F 1 "4.7u/X5R/10V" V 3700 1350 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 3588 1500 50  0001 C CNN
F 3 "~" H 3550 1650 50  0001 C CNN
	1    3550 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 1500 3550 1500
Wire Wire Line
	3550 1500 3550 1200
Connection ~ 3550 1500
$Comp
L power:GND #PWR0110
U 1 1 63FCE39C
P 3550 1800
F 0 "#PWR0110" H 3550 1550 50  0001 C CNN
F 1 "GND" H 3555 1627 50  0000 C CNN
F 2 "" H 3550 1800 50  0001 C CNN
F 3 "" H 3550 1800 50  0001 C CNN
	1    3550 1800
	1    0    0    -1  
$EndComp
$Comp
L power:VBUS #PWR0111
U 1 1 63FCEF81
P 7950 850
F 0 "#PWR0111" H 7950 700 50  0001 C CNN
F 1 "VBUS" H 7965 1023 50  0000 C CNN
F 2 "" H 7950 850 50  0001 C CNN
F 3 "" H 7950 850 50  0001 C CNN
	1    7950 850 
	1    0    0    -1  
$EndComp
Connection ~ 7950 850 
$Comp
L power:+3.3V #PWR0112
U 1 1 63FD0597
P 6250 850
F 0 "#PWR0112" H 6250 700 50  0001 C CNN
F 1 "+3.3V" H 6265 1023 50  0000 C CNN
F 2 "" H 6250 850 50  0001 C CNN
F 3 "" H 6250 850 50  0001 C CNN
	1    6250 850 
	1    0    0    -1  
$EndComp
Connection ~ 6250 850 
$Comp
L Device:C C7
U 1 1 63FD0C19
P 4900 1450
F 0 "C7" H 5015 1496 50  0000 L CNN
F 1 "100u/X7R/10V" H 5015 1405 50  0000 L CNN
F 2 "Capacitor_SMD:C_1210_3225Metric" H 4938 1300 50  0001 C CNN
F 3 "~" H 4900 1450 50  0001 C CNN
	1    4900 1450
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0113
U 1 1 63FD16E2
P 4900 1300
F 0 "#PWR0113" H 4900 1150 50  0001 C CNN
F 1 "+3.3V" H 4915 1473 50  0000 C CNN
F 2 "" H 4900 1300 50  0001 C CNN
F 3 "" H 4900 1300 50  0001 C CNN
	1    4900 1300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0114
U 1 1 63FD215D
P 4900 1600
F 0 "#PWR0114" H 4900 1350 50  0001 C CNN
F 1 "GND" H 4905 1427 50  0000 C CNN
F 2 "" H 4900 1600 50  0001 C CNN
F 3 "" H 4900 1600 50  0001 C CNN
	1    4900 1600
	1    0    0    -1  
$EndComp
$Comp
L W25Q16JVSNIQ:W25Q16JVSNIQ IC1
U 1 1 63FD3D3D
P 1600 5950
F 0 "IC1" H 2700 6215 50  0000 C CNN
F 1 "W25Q16JVSNIQ" H 2700 6124 50  0000 C CNN
F 2 "SOIC127P600X175-8N" H 3650 6050 50  0001 L CNN
F 3 "https://www.winbond.com/hq/search-resource-file.jsp?partNo=W25Q16JVSNIQ&type=datasheet" H 3650 5950 50  0001 L CNN
F 4 "16M-bit Serial Flash Memory with uniform 4KB sectors and Dual/Quad SPI" H 3650 5850 50  0001 L CNN "Description"
F 5 "1.75" H 3650 5750 50  0001 L CNN "Height"
F 6 "Winbond" H 3650 5650 50  0001 L CNN "Manufacturer_Name"
F 7 "W25Q16JVSNIQ" H 3650 5550 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "454-W25Q16JVSNIQ" H 3650 5450 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Winbond/W25Q16JVSNIQ?qs=qSfuJ%252Bfl%2Fd5tzEnNt99V4A%3D%3D" H 3650 5350 50  0001 L CNN "Mouser Price/Stock"
F 10 "W25Q16JVSNIQ" H 3650 5250 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/w25q16jvsniq/winbond-electronics?region=nac" H 3650 5150 50  0001 L CNN "Arrow Price/Stock"
	1    1600 5950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 63FD756E
P 4100 5900
F 0 "R2" H 4170 5946 50  0000 L CNN
F 1 "10k/5%/0.1W" H 4170 5855 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4030 5900 50  0001 C CNN
F 3 "~" H 4100 5900 50  0001 C CNN
	1    4100 5900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 63FD9017
P 1050 6000
F 0 "R1" H 900 5750 50  0000 L CNN
F 1 "10k/5%/0.1W" V 950 5800 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 980 6000 50  0001 C CNN
F 3 "~" H 1050 6000 50  0001 C CNN
	1    1050 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 6050 4100 6050
Wire Wire Line
	1050 5850 1050 5650
Wire Wire Line
	4100 5750 4100 5650
Wire Wire Line
	3800 5950 3800 5650
$Comp
L power:+3.3V #PWR0115
U 1 1 63FE0A34
P 1050 5650
F 0 "#PWR0115" H 1050 5500 50  0001 C CNN
F 1 "+3.3V" H 1065 5823 50  0000 C CNN
F 2 "" H 1050 5650 50  0001 C CNN
F 3 "" H 1050 5650 50  0001 C CNN
	1    1050 5650
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0116
U 1 1 63FE1783
P 4100 5650
F 0 "#PWR0116" H 4100 5500 50  0001 C CNN
F 1 "+3.3V" H 4115 5823 50  0000 C CNN
F 2 "" H 4100 5650 50  0001 C CNN
F 3 "" H 4100 5650 50  0001 C CNN
	1    4100 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 5650 3800 5650
Connection ~ 4100 5650
$Comp
L power:GND #PWR0117
U 1 1 63FE418F
P 1600 6250
F 0 "#PWR0117" H 1600 6000 50  0001 C CNN
F 1 "GND" H 1605 6077 50  0000 C CNN
F 2 "" H 1600 6250 50  0001 C CNN
F 3 "" H 1600 6250 50  0001 C CNN
	1    1600 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1050 6150 1600 6150
Text GLabel 1600 5950 0    50   Input ~ 0
FLASH_CS
Text GLabel 1600 6050 0    50   Output ~ 0
MISO
Text GLabel 3800 6150 2    50   Input ~ 0
CLK
Text GLabel 3800 6250 2    50   Input ~ 0
MOSI
$Comp
L MB85RS256TYPNF-G-AWERE2:MB85RS256TYPNF-G-AWERE2 IC2
U 1 1 63FE8014
P 6600 4900
F 0 "IC2" H 7150 5165 50  0000 C CNN
F 1 "MB85RS256TYPNF-G-AWERE2" H 7150 5074 50  0000 C CNN
F 2 "SOIC127P600X175-8N" H 7550 5000 50  0001 L CNN
F 3 "https://www.fujitsu.com/jp/group/fsm/en/documents/products/feram/lineup/MB85RS256TY-DS501-00049-3v0-E.pdf" H 7550 4900 50  0001 L CNN
F 4 "F-RAM 256kbit FRAM with SPI, 1.8 3.6V, 125C - SOP8 T&R" H 7550 4800 50  0001 L CNN "Description"
F 5 "1.75" H 7550 4700 50  0001 L CNN "Height"
F 6 "FUJITSU" H 7550 4600 50  0001 L CNN "Manufacturer_Name"
F 7 "MB85RS256TYPNF-G-AWERE2" H 7550 4500 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "249-MB85RS256TYPWRE2" H 7550 4400 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Fujitsu-Semiconductor/MB85RS256TYPNF-G-AWERE2?qs=MyNHzdoqoQKcLA8QAI9FYA%3D%3D" H 7550 4300 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 7550 4200 50  0001 L CNN "Arrow Part Number"
F 11 "" H 7550 4100 50  0001 L CNN "Arrow Price/Stock"
	1    6600 4900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 63FEDEC8
P 6050 4950
F 0 "R3" H 5900 4700 50  0000 L CNN
F 1 "10k/5%/0.1W" V 5950 4750 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5980 4950 50  0001 C CNN
F 3 "~" H 6050 4950 50  0001 C CNN
	1    6050 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 4800 6050 4600
$Comp
L power:+3.3V #PWR0118
U 1 1 63FEDED2
P 6050 4600
F 0 "#PWR0118" H 6050 4450 50  0001 C CNN
F 1 "+3.3V" H 6065 4773 50  0000 C CNN
F 2 "" H 6050 4600 50  0001 C CNN
F 3 "" H 6050 4600 50  0001 C CNN
	1    6050 4600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0119
U 1 1 63FEDEE0
P 6600 5200
F 0 "#PWR0119" H 6600 4950 50  0001 C CNN
F 1 "GND" H 6605 5027 50  0000 C CNN
F 2 "" H 6600 5200 50  0001 C CNN
F 3 "" H 6600 5200 50  0001 C CNN
	1    6600 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 5100 6600 5100
Text GLabel 6600 5000 0    50   Output ~ 0
MISO
Text GLabel 6600 4900 0    50   Input ~ 0
FRAM_CS
Text GLabel 7700 5200 2    50   Input ~ 0
MOSI
Text GLabel 7700 5100 2    50   Input ~ 0
CLK
Connection ~ 8000 4600
Wire Wire Line
	8000 4600 7700 4600
$Comp
L power:+3.3V #PWR0120
U 1 1 63FEDED8
P 8000 4600
F 0 "#PWR0120" H 8000 4450 50  0001 C CNN
F 1 "+3.3V" H 8015 4773 50  0000 C CNN
F 2 "" H 8000 4600 50  0001 C CNN
F 3 "" H 8000 4600 50  0001 C CNN
	1    8000 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 4900 7700 4600
Wire Wire Line
	8000 4700 8000 4600
Wire Wire Line
	7700 5000 8000 5000
$Comp
L Device:R R4
U 1 1 63FEDEC2
P 8000 4850
F 0 "R4" H 8070 4896 50  0000 L CNN
F 1 "10k/5%/0.1W" H 8070 4805 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7930 4850 50  0001 C CNN
F 3 "~" H 8000 4850 50  0001 C CNN
	1    8000 4850
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x20_Male J2
U 1 1 63FFD8EC
P 7550 3000
F 0 "J2" H 7658 4081 50  0000 C CNN
F 1 "Prawo" H 7658 3990 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x20_P2.54mm_Vertical" H 7550 3000 50  0001 C CNN
F 3 "~" H 7550 3000 50  0001 C CNN
	1    7550 3000
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x20_Male J3
U 1 1 640007CD
P 6500 2900
F 0 "J3" H 6608 3981 50  0000 C CNN
F 1 "Lewo" H 6608 3890 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x20_P2.54mm_Vertical" H 6500 2900 50  0001 C CNN
F 3 "~" H 6500 2900 50  0001 C CNN
	1    6500 2900
	-1   0    0    -1  
$EndComp
Text GLabel 6300 2300 0    50   Output ~ 0
UP
Text GLabel 6300 2400 0    50   Output ~ 0
CTRL
Text GLabel 6300 3000 0    50   Input ~ 0
LCD_DC
Text GLabel 6300 3100 0    50   Input ~ 0
~LCD_CS
Text GLabel 6300 3300 0    50   Input ~ 0
CLK
Text GLabel 6300 3400 0    50   Input ~ 0
MOSI
Text GLabel 6300 3500 0    50   Input ~ 0
LCD_RST
Text GLabel 6300 3600 0    50   Input ~ 0
LCD_BL
Text GLabel 6300 3900 0    50   Output ~ 0
A
Text GLabel 7350 3900 0    50   Output ~ 0
LEFT
Text GLabel 7350 3800 0    50   Output ~ 0
B
Text GLabel 7350 3600 0    50   Output ~ 0
DOWN
Text GLabel 7350 3500 0    50   Output ~ 0
X
Text GLabel 7350 3400 0    50   Output ~ 0
RIGHT
Text GLabel 7350 3300 0    50   Output ~ 0
Y
$Comp
L power:GND #PWR0121
U 1 1 64032EB9
P 5850 2200
F 0 "#PWR0121" H 5850 1950 50  0001 C CNN
F 1 "GND" H 5855 2027 50  0000 C CNN
F 2 "" H 5850 2200 50  0001 C CNN
F 3 "" H 5850 2200 50  0001 C CNN
	1    5850 2200
	0    1    1    0   
$EndComp
Wire Wire Line
	6300 2200 5850 2200
$Comp
L power:GND #PWR0122
U 1 1 6403787A
P 5850 2700
F 0 "#PWR0122" H 5850 2450 50  0001 C CNN
F 1 "GND" H 5855 2527 50  0000 C CNN
F 2 "" H 5850 2700 50  0001 C CNN
F 3 "" H 5850 2700 50  0001 C CNN
	1    5850 2700
	0    1    1    0   
$EndComp
Wire Wire Line
	6300 2700 5850 2700
$Comp
L power:GND #PWR0123
U 1 1 640389C3
P 5850 3700
F 0 "#PWR0123" H 5850 3450 50  0001 C CNN
F 1 "GND" H 5855 3527 50  0000 C CNN
F 2 "" H 5850 3700 50  0001 C CNN
F 3 "" H 5850 3700 50  0001 C CNN
	1    5850 3700
	0    1    1    0   
$EndComp
Wire Wire Line
	6300 3700 5850 3700
$Comp
L power:GND #PWR0124
U 1 1 6403BAE3
P 6900 2200
F 0 "#PWR0124" H 6900 1950 50  0001 C CNN
F 1 "GND" H 6905 2027 50  0000 C CNN
F 2 "" H 6900 2200 50  0001 C CNN
F 3 "" H 6900 2200 50  0001 C CNN
	1    6900 2200
	0    1    1    0   
$EndComp
Wire Wire Line
	7350 2200 6900 2200
$Comp
L power:GND #PWR0125
U 1 1 6403CD16
P 6900 2700
F 0 "#PWR0125" H 6900 2450 50  0001 C CNN
F 1 "GND" H 6905 2527 50  0000 C CNN
F 2 "" H 6900 2700 50  0001 C CNN
F 3 "" H 6900 2700 50  0001 C CNN
	1    6900 2700
	0    1    1    0   
$EndComp
Wire Wire Line
	7350 2700 6900 2700
$Comp
L power:GND #PWR0126
U 1 1 6403DFB8
P 6900 3200
F 0 "#PWR0126" H 6900 2950 50  0001 C CNN
F 1 "GND" H 6905 3027 50  0000 C CNN
F 2 "" H 6900 3200 50  0001 C CNN
F 3 "" H 6900 3200 50  0001 C CNN
	1    6900 3200
	0    1    1    0   
$EndComp
Wire Wire Line
	7350 3200 6900 3200
$Comp
L power:GND #PWR0127
U 1 1 6403F440
P 6900 3700
F 0 "#PWR0127" H 6900 3450 50  0001 C CNN
F 1 "GND" H 6905 3527 50  0000 C CNN
F 2 "" H 6900 3700 50  0001 C CNN
F 3 "" H 6900 3700 50  0001 C CNN
	1    6900 3700
	0    1    1    0   
$EndComp
Wire Wire Line
	7350 3700 6900 3700
Wire Wire Line
	7350 2100 7100 2100
Wire Wire Line
	7100 2100 7100 1850
$Comp
L power:+3.3V #PWR0128
U 1 1 64042384
P 7100 1850
F 0 "#PWR0128" H 7100 1700 50  0001 C CNN
F 1 "+3.3V" H 7115 2023 50  0000 C CNN
F 2 "" H 7100 1850 50  0001 C CNN
F 3 "" H 7100 1850 50  0001 C CNN
	1    7100 1850
	1    0    0    -1  
$EndComp
NoConn ~ 7350 2000
NoConn ~ 7350 2300
NoConn ~ 7350 2400
NoConn ~ 7350 2500
NoConn ~ 7350 2600
NoConn ~ 7350 2800
NoConn ~ 7350 2900
NoConn ~ 7350 3000
NoConn ~ 7350 3100
NoConn ~ 6300 2000
NoConn ~ 6300 2100
NoConn ~ 6300 2500
NoConn ~ 6300 2600
NoConn ~ 6300 2800
NoConn ~ 6300 2900
NoConn ~ 6300 3200
NoConn ~ 6300 3800
Text GLabel 4600 3500 2    50   BiDi ~ 0
D+
Text GLabel 4600 3600 2    50   BiDi ~ 0
D-
Wire Wire Line
	1450 1600 1550 1600
Wire Wire Line
	1550 1600 1550 1400
Wire Wire Line
	1550 1400 1800 1400
Wire Wire Line
	1450 1500 1600 1500
Wire Wire Line
	1600 1500 1600 1600
Wire Wire Line
	1600 1600 1800 1600
Text GLabel 3500 4700 3    50   Output ~ 0
CLK
Text GLabel 3700 4700 3    50   Output ~ 0
MOSI
Text GLabel 3600 4700 3    50   Input ~ 0
MISO
$Comp
L Device:C C10
U 1 1 6408126C
P 3950 5100
F 0 "C10" V 4200 5050 50  0000 L CNN
F 1 "4.7u/X5R/10V" V 4100 4800 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 3988 4950 50  0001 C CNN
F 3 "~" H 3950 5100 50  0001 C CNN
	1    3950 5100
	0    1    1    0   
$EndComp
Wire Wire Line
	4100 4850 4000 4850
Wire Wire Line
	4000 4850 4000 4700
$Comp
L Device:C C11
U 1 1 64086C54
P 4700 4550
F 0 "C11" V 4950 4500 50  0000 L CNN
F 1 "4.7u/X5R/10V" V 4850 4250 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 4738 4400 50  0001 C CNN
F 3 "~" H 4700 4550 50  0001 C CNN
	1    4700 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 4000 4700 4000
Wire Wire Line
	4700 4000 4700 4400
Wire Wire Line
	4100 4700 4700 4700
Wire Wire Line
	3900 4950 3800 4950
Wire Wire Line
	3800 4950 3800 5100
Wire Wire Line
	3900 4700 3900 4950
$Comp
L Device:C C9
U 1 1 64095833
P 2950 2550
F 0 "C9" V 3200 2500 50  0000 L CNN
F 1 "4.7u/X5R/10V" V 3100 2250 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2988 2400 50  0001 C CNN
F 3 "~" H 2950 2550 50  0001 C CNN
	1    2950 2550
	-1   0    0    1   
$EndComp
Wire Wire Line
	3500 2400 3400 2400
Wire Wire Line
	2950 2400 3400 2400
Connection ~ 3400 2400
Wire Wire Line
	2950 2700 2950 3100
Wire Wire Line
	2950 3300 3000 3300
$Comp
L power:+3.3V #PWR0129
U 1 1 6409DD67
P 2650 3100
F 0 "#PWR0129" H 2650 2950 50  0001 C CNN
F 1 "+3.3V" H 2665 3273 50  0000 C CNN
F 2 "" H 2650 3100 50  0001 C CNN
F 3 "" H 2650 3100 50  0001 C CNN
	1    2650 3100
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0130
U 1 1 640A07E2
P 5050 4000
F 0 "#PWR0130" H 5050 3850 50  0001 C CNN
F 1 "+3.3V" H 5065 4173 50  0000 C CNN
F 2 "" H 5050 4000 50  0001 C CNN
F 3 "" H 5050 4000 50  0001 C CNN
	1    5050 4000
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0131
U 1 1 640A2B01
P 4100 4850
F 0 "#PWR0131" H 4100 4700 50  0001 C CNN
F 1 "+3.3V" H 4115 5023 50  0000 C CNN
F 2 "" H 4100 4850 50  0001 C CNN
F 3 "" H 4100 4850 50  0001 C CNN
	1    4100 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 4850 4100 5100
Connection ~ 4100 4850
Wire Wire Line
	4700 4000 5050 4000
Connection ~ 4700 4000
Wire Wire Line
	2650 3100 2950 3100
Connection ~ 2950 3100
Wire Wire Line
	2950 3100 2950 3300
$Comp
L power:GND #PWR0132
U 1 1 640AD409
P 3100 2050
F 0 "#PWR0132" H 3100 1800 50  0001 C CNN
F 1 "GND" H 3105 1877 50  0000 C CNN
F 2 "" H 3100 2050 50  0001 C CNN
F 3 "" H 3100 2050 50  0001 C CNN
	1    3100 2050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0133
U 1 1 640AF5EB
P 4700 4700
F 0 "#PWR0133" H 4700 4450 50  0001 C CNN
F 1 "GND" H 4705 4527 50  0000 C CNN
F 2 "" H 4700 4700 50  0001 C CNN
F 3 "" H 4700 4700 50  0001 C CNN
	1    4700 4700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0134
U 1 1 640B1649
P 3800 5100
F 0 "#PWR0134" H 3800 4850 50  0001 C CNN
F 1 "GND" H 3805 4927 50  0000 C CNN
F 2 "" H 3800 5100 50  0001 C CNN
F 3 "" H 3800 5100 50  0001 C CNN
	1    3800 5100
	1    0    0    -1  
$EndComp
Connection ~ 3800 5100
Connection ~ 4700 4700
Wire Wire Line
	3400 2400 3400 2050
Wire Wire Line
	3400 2050 3100 2050
$Comp
L Device:R R6
U 1 1 640BAD9D
P 3450 2150
F 0 "R6" H 3520 2196 50  0000 L CNN
F 1 "10k/5%/0.1W" V 3350 1950 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3380 2150 50  0001 C CNN
F 3 "~" H 3450 2150 50  0001 C CNN
	1    3450 2150
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0135
U 1 1 640BFD14
P 3300 2150
F 0 "#PWR0135" H 3300 1900 50  0001 C CNN
F 1 "GND" H 3305 1977 50  0000 C CNN
F 2 "" H 3300 2150 50  0001 C CNN
F 3 "" H 3300 2150 50  0001 C CNN
	1    3300 2150
	0    1    1    0   
$EndComp
$Comp
L Device:R R5
U 1 1 640C27FC
P 2000 3950
F 0 "R5" H 1850 3700 50  0000 L CNN
F 1 "10k/5%/0.1W" V 1900 3750 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 1930 3950 50  0001 C CNN
F 3 "~" H 2000 3950 50  0001 C CNN
	1    2000 3950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3000 3600 2750 3600
Wire Wire Line
	2750 3600 2750 3650
Wire Wire Line
	2750 3650 2400 3650
Wire Wire Line
	2400 3650 2400 3950
Wire Wire Line
	1850 3950 1500 3950
Wire Wire Line
	1500 3950 1500 3750
$Comp
L power:+3.3V #PWR0136
U 1 1 640CAF4A
P 1500 3750
F 0 "#PWR0136" H 1500 3600 50  0001 C CNN
F 1 "+3.3V" H 1515 3923 50  0000 C CNN
F 2 "" H 1500 3750 50  0001 C CNN
F 3 "" H 1500 3750 50  0001 C CNN
	1    1500 3750
	1    0    0    -1  
$EndComp
$Comp
L Device:C C8
U 1 1 640CE51B
P 2400 4100
F 0 "C8" V 2650 4050 50  0000 L CNN
F 1 "100n/X5R/10V" V 2550 3800 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2438 3950 50  0001 C CNN
F 3 "~" H 2400 4100 50  0001 C CNN
	1    2400 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 3950 2400 3950
Connection ~ 2400 3950
$Comp
L power:GND #PWR0137
U 1 1 640D6C1A
P 2400 4250
F 0 "#PWR0137" H 2400 4000 50  0001 C CNN
F 1 "GND" H 2405 4077 50  0000 C CNN
F 2 "" H 2400 4250 50  0001 C CNN
F 3 "" H 2400 4250 50  0001 C CNN
	1    2400 4250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0138
U 1 1 640DC470
P 2400 3450
F 0 "#PWR0138" H 2400 3200 50  0001 C CNN
F 1 "GND" H 2405 3277 50  0000 C CNN
F 2 "" H 2400 3450 50  0001 C CNN
F 3 "" H 2400 3450 50  0001 C CNN
	1    2400 3450
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0139
U 1 1 640E29E3
P 2600 3450
F 0 "#PWR0139" H 2600 3200 50  0001 C CNN
F 1 "GND" H 2605 3277 50  0000 C CNN
F 2 "" H 2600 3450 50  0001 C CNN
F 3 "" H 2600 3450 50  0001 C CNN
	1    2600 3450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3600 2150 3600 2400
Text GLabel 4000 2400 1    50   Input ~ 0
DOWN
Text GLabel 3900 2400 1    50   Input ~ 0
X
Text GLabel 3800 2400 1    50   Input ~ 0
RIGHT
Text GLabel 3700 2400 1    50   Input ~ 0
Y
$EndSCHEMATC