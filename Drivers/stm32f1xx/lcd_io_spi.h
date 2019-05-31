/*
 * SPI LCD driver STM32F1
 * k�szit�: Roberto Benjami
 * verzio:  2019.05
*/

#ifndef __LCD_IO_SPI_H
#define __LCD_IO_SPI_H

//=============================================================================
// SPI kiv�laszt�sa (0, 1, 2 3)
// - 0: szoftveres SPI driver (a l�bhozz�rendel�s szabadon kiv�laszthato)
// - 1..3: hardver SPI driver (az LCD_SCK, LCD_MOSI, LCD_MISO l�bak k�t�ttek)
#define LCD_SPI           2

// SPI �zemmod
// - 0: csak SPI TX (csak irni lehet a kijelz�t, LCD_MISO l�bat nem sz�ks�ges megadni, nem lesz haszn�latban)
// - 1: half duplex (LCD_MOSI l�b k�t ir�nyban lesz m�k�dtetve, LCD_MISO l�b nem lesz haszn�lva)
// - 2: full duplex (SPI TX: LCD_MOSI, SPI RX: LCD_MISO)
#define LCD_SPI_MODE      1

// SPI sebess�ge (csak hardver SPI eset�n: az SPI orajele fPCLK / oszto (2..256) �ltal meghat�rozott)
// - oszto: 0=/2, 1=/4, 2=/8, 3=/16, 4=/32, 5=/64, 6=/128, 7=/256
#define LCD_SPI_SPD       1
// - megadhato az olvas�shoz tartozo orajel (ha azonos vagy nincs megadva akkor nem v�lt sebess�get olvas�skor)
#define LCD_SPI_SPD_READ  4

// Lcd vez�rl� l�bak hozz�rendel�se (reset, command/data, blacklight, blacklight bekapcsolt �llapothoz tartozo szint)
#define LCD_RST           B, 11
#define LCD_RS            B, 14
#define LCD_BL            C, 13
#define LCD_BLON          0

// LCD_MISO megad�sa csak full duplex �zemmodban sz�ks�ges, TX �s half duplex modban nem lesz haszn�lva
#define LCD_CS            B, 12
#define LCD_SCK           B, 13
#define LCD_MOSI          B, 15
// #define LCD_MISO          B, 14

// Ha a kijelz� nem k�pes 16 bit/pixel adatokat szolg�ltatni, akkor r�pt�ben konvert�lni kell (pl. ST7735)
// - 0: nem kell olvas�skor 24 bit/pixel-r�l 16 bit/pixel-re konvert�lni
// - 1: olvas�skor 24 bit/pixel-r�l 16 bit/pixel-re kell konvert�lni
#define LCD_READMULTIPLEDATA24TO16   1

#endif // __LCD_IO_SPI_H