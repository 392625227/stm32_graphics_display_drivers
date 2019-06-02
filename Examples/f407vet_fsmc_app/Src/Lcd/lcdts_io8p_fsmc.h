/*
8 bites p�rhuzamos LCD/TOUCH FSMC driver
5 vez�rl�l�b (CS, RS, WR, RD, RST) + 8 adatl�b
FSMC_NE1<-LCD_CS), FSMC_NOE<-LCD_RD, FSMC_NWE<-LCD_WR, FSMC_Ax<-LCD_RS
FSMC_D0<-LCD_D0, FSMC_D1<-LCD_D1, FSMC_D2<-LCD_D2, FSMC_D3<-LCD_D3
FSMC_D4<-LCD_D4, FSMC_D5<-LCD_D5, FSMC_D6<-LCD_D6, FSMC_D7<-LCD_D7

Figyelem: mivel azonos l�bakon van az Lcd �s a Touchscreen,
ez�rt ezek ki kell z�rni az Lcd �s a Touchscreen egyidej� haszn�lat�t!
T�bbsz�las/megszakit�sos k�rnyezetben igy gondoskodni kell az �sszeakad�sok megel�z�s�r�l! */

#ifndef __LCDTS_IO8P_FSMC_H
#define __LCDTS_IO8P_FSMC_H

//=============================================================================
// Lcd vez�rl� l�bak hozz�rendel�se (A..M, 0..15, LCD_CS helye az FSMC �ltal k�t�tt)
#define LCD_CS            D, 7
#define LCD_RST           C, 5

// H�tt�rvil�git�s vez�rl�s (opcion�lis, l�b hozz�rendel�s �s aktiv �llapot)
#define LCD_BL            X, 0
#define LCD_BLON          0

// Memoria cimek hozz�rendel�se
#define LCD_ADDR_BASE     0x60000000
#define LCD_REGSELECT_BIT 18

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
#define TS_ADC            1

// Ezen l�bak helyzet�t az FSMC vez�rl� hat�rozza meg
#define TS_XM             D, 13
#define TS_YP             D, 5
#define TS_XP             E, 9
#define TS_YM             E, 10

// Mivel az FSMC l�bai jellemz�en nem haszn�lhatoak AD bemenetk�nt, p�rhuzamosan k�thetj�k valamelyik AD bemenetnek is haszn�lhato l�bbal.
// (ha nem adunk meg itt semmilyen l�bat, akkor az LCD_RS �s LCD_WR lesz a touchscreen kiv�lasztott AD l�ba)
#define TS_XM_AN          A, 0
#define TS_YP_AN          A, 1

// Itt kell megadni, hogy melyik csatorn�t kiv�lasztva lehet az adott l�bat az AD bemenet�re kapcsolni
#define TS_XM_ADCCH       0
#define TS_YP_ADCCH       1

/* nsec nagys�grend� v�rakoz�s a touchscreen AD �talakiton�l
   - kezd� �rt�knek �rdemes 500-bol elindulni, azt�n lehet cs�kkenteni a sebess�g n�vel�se �rdek�ben
     (az �rt�kek f�ggnek a processzor orajel�t�l �s az LCD kijelz� sebess�g�t�l is)
*/
#define TS_AD_DELAY     500

#endif // __LCDTS_IO8P_FSMC_H