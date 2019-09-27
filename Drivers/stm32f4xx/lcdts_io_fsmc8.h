/*
8 bites p�rhuzamos LCD/TOUCH FSMC driver
5 vez�rl�l�b (CS, RS, WR, RD, RST) + 8 adatl�b + h�tt�rvil�git�s vez�rl�s
FSMC_NE1<-LCD_CS), FSMC_NOE<-LCD_RD, FSMC_NWE<-LCD_WR, FSMC_Ax<-LCD_RS
FSMC_D0<-LCD_D0, FSMC_D1<-LCD_D1, FSMC_D2<-LCD_D2, FSMC_D3<-LCD_D3
FSMC_D4<-LCD_D4, FSMC_D5<-LCD_D5, FSMC_D6<-LCD_D6, FSMC_D7<-LCD_D7

Figyelem: mivel azonos l�bakon van az Lcd �s a Touchscreen,
ez�rt ezek ki kell z�rni az Lcd �s a Touchscreen egyidej� haszn�lat�t!
T�bbsz�las/megszakit�sos k�rnyezetben igy gondoskodni kell az �sszeakad�sok megel�z�s�r�l! */

//=============================================================================
/* Lcd vez�rl� l�bak hozz�rendel�se (A..M, 0..15, LCD_CS helye az FSMC �ltal k�t�tt) */
#define LCD_CS            X, 0
#define LCD_RST           X, 0

/* H�tt�rvil�git�s vez�rl�s
   - BL: A..M, 0..15 (ha nem haszn�ljuk, akkor rendelj�k hozz� az X, 0 �rt�ket)
   - BL_ON: 0 vagy 1, a bekapcsolt �llapothoz tartoz� logikai szint */
#define LCD_BL            X, 0
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
#define LCD_DMA           0, 0, 0, 0

/*=============================================================================
Touch I/O l�bak �s A/D csatorn�k
A kijelz�n bel�l a k�vetkez� l�bak vannak p�rhuzamositva:
 - TS_XM <- LCD_RS (FSMC_Ax)
 - TS_XP <- LCD_D6 (FSMC_D6)
 - TS_YM <- LCD_D7 (FSMC_D7)
 - TS_YP <- LCD_WR (FSMC_NWE)
*/

/* ADC konverter sz�ma (�rt�ke lehet 1, 2, 3, vagy 0 ha nem haszn�ljuk)
   - 0: analog touchscreen driver nem lesz haszn�lva
   - 1..3: a haszn�lni kiv�nt A/D konverter sz�ma
*/
#define TS_ADC            0

// Ezen l�bak helyzet�t az FSMC vez�rl� hat�rozza meg (f407: D13, D5, E9, E10)
#define TS_XM             X, 0
#define TS_YP             X, 0
#define TS_XP             X, 0
#define TS_YM             X, 0

// Mivel az FSMC l�bai jellemz�en nem haszn�lhatoak AD bemenetk�nt, p�rhuzamosan k�thetj�k valamelyik AD bemenetnek is haszn�lhato l�bbal.
// (ha nem adunk meg itt semmilyen l�bat, akkor az LCD_RS �s LCD_WR lesz a touchscreen kiv�lasztott AD l�ba)
#define TS_XM_AN          X, 0
#define TS_YP_AN          X, 0

// Itt kell megadni, hogy melyik csatorn�t kiv�lasztva lehet az adott l�bat az AD bemenet�re kapcsolni
#define TS_XM_ADCCH       0
#define TS_YP_ADCCH       0

/* nsec nagys�grend� v�rakoz�s a touchscreen AD �talakiton�l
   - kezd� �rt�knek �rdemes 500-bol elindulni, azt�n lehet cs�kkenteni a sebess�g n�vel�se �rdek�ben
     (az �rt�kek f�ggnek a processzor orajel�t�l �s az LCD kijelz� sebess�g�t�l is)
*/
#define TS_AD_DELAY     500
