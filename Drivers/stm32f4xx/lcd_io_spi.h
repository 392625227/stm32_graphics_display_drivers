/*
 * SPI LCD driver STM32F4
 * k�szit�: Roberto Benjami
 * verzio:  2019.05
*/

#ifndef __LCD_IO_SPI_H
#define __LCD_IO_SPI_H

//=============================================================================
/* SPI kiv�laszt�sa (0, 1, 2, 3, 4, 5, 6)
   - 0: szoftveres SPI driver (a l�bhozz�rendel�s szabadon kiv�laszthato)
   - 1..6: hardver SPI driver (az LCD_SCK, LCD_MOSI, LCD_MISO l�bak k�t�ttek) */
#define LCD_SPI           2

/* SPI �zemmod
   - 0: csak SPI TX (csak irni lehet a kijelz�t, LCD_MISO l�bat nem sz�ks�ges megadni, nem lesz haszn�latban)
   - 1: half duplex (LCD_MOSI l�b k�t ir�nyban lesz m�k�dtetve, LCD_MISO l�b nem lesz haszn�lva)
   - 2: full duplex (SPI TX: LCD_MOSI, SPI RX: LCD_MISO) */
#define LCD_SPI_MODE      1

/* SPI sebess�ge
   - hardver SPI: oszto: fPCLK/oszto, 0=/2, 1=/4, 2=/8, 3=/16, 4=/32, 5=/64, 6=/128, 7=/256
   - szoftver SPI: LCD_IO_Delay(LCD_SPI_SPD - 1), 0 eset�n a f�ggv�ny hiv�sa is elmarad */
#define LCD_SPI_SPD       1
/* Megadhato az olvas�shoz tartozo orajel (ha azonos vagy nincs megadva akkor nem v�lt sebess�get olvas�skor) */
#define LCD_SPI_SPD_READ  3

/* SPI l�b melyik alternativ funkciohoz tartozik (0..15), (csak hardver SPI) */
#define LCD_SPI_AFR       5

/* Lcd vez�rl� l�bak hozz�rendel�se ((A..M, 0..15)
   - LCD_MISO megad�sa csak full duplex �zemmodban sz�ks�ges, TX �s half duplex modban nem lesz haszn�lva
   - hardver SPI eset�n az SCK, MOSI, MISO l�bak hozz�rendel�se k�t�tt */
#define LCD_RST           C, 5
#define LCD_RS            D, 13

#define LCD_CS            B, 12  // D7
#define LCD_SCK           B, 13  // D4
#define LCD_MOSI          B, 15  // D5
#define LCD_MISO          X, 0   // csak LCD_SPI_MODE 2 eset�n

/* H�tt�rvil�git�s vez�rl�s
   - BL: A..M, 0..15 (ha nem haszn�ljuk, akkor rendelj�k hozz� az X, 0 �rt�ket)
   - BL_ON: 0 vagy 1, a bekapcsolt �llapothoz tartoz� logikai szint */
#define LCD_BL            B, 1   // ha nem akarjuk haszn�lni X, 0 -t adjunk
#define LCD_BLON          0

/* DMA be�llit�sok (csak hardver SPI)
   - 0..2: 0 = nincs DMA, 1 = DMA1, 2 = DMA2
   - 0..7: DMA csatorna (DMA request mapping)
   - 0..7: Stream (DMA request mapping)
   - 1..3: DMA priorit�s (0=low..3=very high) */
#define LCD_DMA_TX        1, 0, 4, 0
#define LCD_DMA_RX        1, 0, 3, 2

/* DMA RX buffer [byte] (csak a ...24to16 f�ggv�nyek eset�ben lesz haszn�latban) */
#define LCD_DMA_RX_BUFSIZE 1024

/* DMA RX buffer helye
   - 0: stack
   - 1: static buffer */
#define LCD_DMA_RX_BUFMODE 1

#endif // __LCD_IO_SPI_H