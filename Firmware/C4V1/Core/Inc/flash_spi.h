/*
 * flash_spi.h
 *
 *  Created on: May 14, 2022
 *      Author: Marcin
 */

#ifndef INC_FLASH_SPI_H_
#define INC_FLASH_SPI_H_
#define MMEMORY_SYZE_BIT   16 // 16 Mbit
#define BYTES_IN_MEGABYTES 1024 * 1024
#define BITS_IN_BYTES      8
#define PAGE_SIZE          256
#define PAGES_IN_SECTOR    16
#define SECTOR_SIZE        (PAGE_SIZE * PAGES_IN_SECTOR)
#define NUMBER_OF_SECTORS  ((MMEMORY_SYZE_BIT * BYTES_IN_MEGABYTES) / BITS_IN_BYTES) / SECTOR_SIZE
#define NUMBER_OF_PAGES    ((MMEMORY_SYZE_BIT * BYTES_IN_MEGABYTES) / BITS_IN_BYTES) / PAGE_SIZE
#define WRITE_ENABLE       0x06
#define WRITE_DISABLE      0x04
#define READ_STATUS_REG1   0x05
#define READ_STATUS_REG2   0x35
#define WRITE_STATUS_REG   0x01
#define READ_DATA          0x03
#define PAGE_PROGRAM       0x02
#define SECTOR_ERASE       0x20
#define CHIP_ERASE         0xC7
#define ENABLE_RESET       0x66
#define RESET              0x99
#define JEDEC_ID           0x9f
#define READ_SR1           0x05
#define READ_SR2           0x35
#define BUSY_FLAG          0x01
#define WEL_BIT            0x02
typedef struct
{
   SPI_HandleTypeDef *flash_spi;
   uint32_t id;
   uint16_t flash_CsPin;
   GPIO_TypeDef *flash_CsPort;
} flash_t;
void flash_Init(flash_t *flash, SPI_HandleTypeDef *spi, GPIO_TypeDef *cs_port, uint16_t cs_pin);
void flash_ReadDataBytes(flash_t *flash, uint32_t addr, uint8_t *data, uint32_t size);
void flash_WritePage(flash_t *flash, uint32_t page_addr, uint8_t *data);
void flash_ClearSector(flash_t *flash, uint32_t addr);
void flash_ChipErase(flash_t *flash);
void flash_ReadPage(flash_t *flash, uint32_t page_addr, uint8_t *data);
#endif /* INC_FLASH_SPI_H_ */
