/* 8 bites p�rhuzamos LCD/TOUCH GPIO driver STM32F1-re
5 vez�rl�l�b (CS, RS, WR, RD, RST) + 8 adatl�b + h�tt�rvil�git�s vez�rl�s

Figyelem: mivel azonos l�bakon van az Lcd �s a Touchscreen,
ez�rt ezek ki kell z�rni az Lcd �s a Touchscreen egyidej� haszn�lat�t!
T�bbsz�las/megszakit�sos k�rnyezetben igy gondoskodni kell az �sszeakad�sok megel�z�s�r�l! */

#ifndef __LCDTS_IO8P_GPIO_H
#define __LCDTS_IO8P_GPIO_H

//=============================================================================
// Lcd parancs hossz
// - 8: mindegyik LCD parancsot 8 bitesk�nt k�ldi az LCD-re
// - 16: mindegyik LCD parancsot 16 bitesk�nt (k�t b�jtban) k�ldi az LCD-re
#define LCD_CMD_SIZE      16

//=============================================================================
// Lcd vez�rl� l�bak hozz�rendel�se
#define LCD_CS            B, 5
#define LCD_RS            A, 0
#define LCD_WR            A, 1
#define LCD_RD            B, 1
#define LCD_RST           B, 0

// Lcd adat l�bak hozz�rendel�se
#define LCD_D0            B, 8
#define LCD_D1            B, 9
#define LCD_D2            B, 10
#define LCD_D3            B, 11
#define LCD_D4            B, 12
#define LCD_D5            B, 13
#define LCD_D6            B, 14
#define LCD_D7            B, 15

// H�tt�rvil�git�s vez�rl�s (opcion�lis, l�b hozz�rendel�s �s aktiv �llapot)
#define LCD_BL            C, 13
#define LCD_BLON          0

/*-----------------------------------------------------------------------------
Touch I/O l�bak �s A/D csatorn�k
A kijelz�n bel�l a k�vetkez� l�bak vannak p�rhuzamositva
 - TS_XM <- LCD_RS
 - TS_XP <- LCD_D6
 - TS_YM <- LCD_D7
 - TS_YP <- LCD_WR */

// ADC konverter sz�ma (�rt�ke lehet 1, 2, 3, vagy 0 ha nem haszn�ljuk)
// (ha null�t v�lasztunk, akkor az analog touchscreen driver nem lesz haszn�lva)
#define TS_ADC            0

// Itt kell megadni, hogy melyik csatorn�t kiv�lasztva lehet az adott l�bat az AD bemenet�re kapcsolni
#define TS_XM_ADCCH       0
#define TS_YP_ADCCH       1

// nsec nagys�grend� v�rakoz�s az LCD ir�si �s az olvas�si impulzusn�l �s a touchscreen AD �talakiton�l
// megj:
// - kezd� �rt�knek �rdemes 10 illetve 500-bol elindulni, azt�n lehet cs�kkenteni a sebess�g n�vel�se �rdek�ben
//   (az �rt�kek f�ggnek a processzor orajel�t�l �s az LCD kijelz� sebess�g�t�l is)
#define LCD_IO_RW_DELAY   0
#define TS_AD_DELAY     500

//=============================================================================
// I/O csoport optimaliz�ci�, hogy ne bitenk�nt t�rt�njenek a GPIO m�veletek:
// Megj: ha az adat l�bakat egy porton bel�l 0..7, vagy 8..15 l�bakra defini�ljuk
//       automatikusan optimaliz�lva fognak t�rt�nni a GPIO m�veletek akkor is, ha
//       itt nem defini�ljuk az optimaliz�lt m�k�d�shez sz�ks�ges elj�r�sokat

// 5 vez�rl�l�b kimenetre �ll�t�sa (mivel csak egyszer hajt�dik v�gre, ez nem kritikus)
// #define LCD_CTR_DIRWRITE  GPIOA->CRL = (GPIOA->CRL & 0xFFFFFF00) | 0x00000033; GPIOB->CRL = (GPIOB->CRL & 0xFF0FFF00) | 0x00300033;

// 8 adatl�b kimenetre �ll�t�sa (adatir�ny: STM32 -> LCD)
// #define LCD_DATA_DIRWRITE GPIOB->CRH = 0x33333333

// 8 adatl�b bemenetre �ll�t�sa (adatir�ny: STM32 <- LCD)
// #define LCD_DATA_DIRREAD  GPIOB->CRH = 0x44444444

// 8 adatl�b �r�sa (a kiirand� adat a makro dt param�ter�ben van)
// #define LCD_DATA_WRITE(dt) GPIOB->ODR = (GPIOB->ODR & 0x00FF) | (dt << 8)

// 8 adatl�b olvas�sa (az olvasott adat dt param�terben megadott v�ltozoba ker�l)
// #define LCD_DATA_READ(dt) dt = GPIOB->IDR >> 8

#endif // __LCDTS_IO8P_GPIO_H