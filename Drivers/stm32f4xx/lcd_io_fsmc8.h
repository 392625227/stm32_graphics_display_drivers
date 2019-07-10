/*
8 bites p�rhuzamos LCD FSMC driver
5 vez�rl�l�b (CS, RS, WR, RD, RST) + 8 adatl�b + h�tt�rvil�git�s vez�rl�s
FSMC_NE1<-LCD_CS), FSMC_NOE<-LCD_RD, FSMC_NWE<-LCD_WR, FSMC_Ax<-LCD_RS
FSMC_D0<-LCD_D0, FSMC_D1<-LCD_D1, FSMC_D2<-LCD_D2, FSMC_D3<-LCD_D3
FSMC_D4<-LCD_D4, FSMC_D5<-LCD_D5, FSMC_D6<-LCD_D6, FSMC_D7<-LCD_D7 */

#ifndef __LCD_IO_FSMC8_H
#define __LCD_IO_FSMC8_H

//=============================================================================
/* Lcd vez�rl� l�bak hozz�rendel�se (A..M, 0..15, LCD_CS helye az FSMC �ltal k�t�tt) */
#define LCD_CS            D, 7
#define LCD_RST           C, 5

/* H�tt�rvil�git�s vez�rl�s
   - BL: A..M, 0..15 (ha nem haszn�ljuk, akkor rendelj�k hozz� az X, 0 �rt�ket)
   - BL_ON: 0 vagy 1, a bekapcsolt �llapothoz tartoz� logikai szint */
#define LCD_BL            B, 1
#define LCD_BLON          0

//=============================================================================
/* Memoria cimek hozz�rendel�se, tipikus �rt�kek:
  - Bank1 (NE1) 0x60000000
  - Bank2 (NE2) 0x64000000
  - Bank3 (NE3) 0x68000000
  - Bank4 (NE4) 0x6C000000
  - REGSELECT_BIT: ha pl. A18 l�bra van k�tve, akkor -> 18 */
#define LCD_ADDR_BASE     0x60000000
#define LCD_REGSELECT_BIT 18

/* DMA be�llit�sok
   - 0..2: 0 = nincs DMA, 1 = DMA1, 2 = DMA2 (DMA2-t kell haszn�lni!)
   - 0..7: DMA csatorna
   - 0..7: Stream
   - 1..3: DMA priorit�s (0=low..3=very high) */
#define LCD_DMA           2, 7, 7, 1

#endif // __LCD_IO_FSMC8_H