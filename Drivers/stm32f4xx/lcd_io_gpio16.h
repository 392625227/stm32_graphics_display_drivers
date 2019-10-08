/*
 * 16 bites p�rhuzamos LCD GPIO driver STM32F4-re
 * 5 vez�rl�l�b (CS, RS, WR, RD, RST) + 16 adatl�b + h�tt�rvil�git�s vez�rl�s
 */
#ifndef __LCD_IO16P_GPIO_H
#define __LCD_IO16P_GPIO_H

//=============================================================================
/* Lcd vez�rl� l�bak hozz�rendel�se (A..M, 0..15) */
#define LCD_CS            X, 0
#define LCD_RS            X, 0
#define LCD_WR            X, 0
#define LCD_RD            X, 0
#define LCD_RST           X, 0

/* Lcd adat l�bak hozz�rendel�se (A..M, 0..15) */
#define LCD_D0            X, 0
#define LCD_D1            X, 0
#define LCD_D2            X, 0
#define LCD_D3            X, 0
#define LCD_D4            X, 0
#define LCD_D5            X, 0
#define LCD_D6            X, 0
#define LCD_D7            X, 0
#define LCD_D8            X, 0
#define LCD_D9            X, 0
#define LCD_D10           X, 0
#define LCD_D11           X, 0
#define LCD_D12           X, 0
#define LCD_D13           X, 0
#define LCD_D14           X, 0
#define LCD_D15           X, 0

/* H�tt�rvil�git�s vez�rl�s
   - BL: A..M, 0..15 (ha nem haszn�ljuk, akkor rendelj�k hozz� az X, 0 �rt�ket)
   - BL_ON: 0 vagy 1, a bekapcsolt �llapothoz tartoz� logikai szint */
#define LCD_BL            X, 0
#define LCD_BLON          0

/* nsec nagys�grend� v�rakoz�s az LCD ir�si �s az olvas�si impulzus
   - kezd� �rt�knek �rdemes 10 illetve 20-bol elindulni, azt�n lehet cs�kkenteni a sebess�g n�vel�se �rdek�ben
     (az �rt�kek f�ggnek a processzor orajel�t�l �s az LCD kijelz� sebess�g�t�l is)
*/
#define LCD_WRITE_DELAY   10
#define LCD_READ_DELAY    20

/*=============================================================================
I/O csoport optimaliz�ci�, hogy ne bitenk�nt t�rt�njenek a GPIO m�veletek:
Megj: ha az adat l�bakat egy porton bel�l emelked� sorrendben defini�ljuk
      automatikusan optimaliz�lva fognak t�rt�nni a GPIO m�veletek akkor is, ha
      itt nem defini�ljuk az optimaliz�lt m�k�d�shez sz�ks�ges elj�r�sokat
A lenti p�lda a k�vetkez� l�bakhoz optimaliz�l:
      LCD_D0<-D14,  LCD_D1<-D15,  LCD_D2<-D0,   LCD_D3<-D1
      LCD_D4<-E7,   LCD_D5<-E8,   LCD_D6<-E9,   LCD_D7<-E10
      LCD_D8<-E11,  LCD_D9<-E12,  LCD_D10<-E13, LCD_D11<-E14
      LCD_D12<-E15, LCD_D13<-D8,  LCD_D14<-D9,  LCD_D15<-D10 */
#if 0
// datapins setting to output (data direction: STM32 -> LCD)
#define LCD_DIRWRITE { /* D0..D1, D8..D10, D14..D15, E7..E15 <- 0b01 */ \
GPIOD->MODER = (GPIOD->MODER & ~0b11110000001111110000000000001111) | 0b01010000000101010000000000000101; \
GPIOE->MODER = (GPIOE->MODER & ~0b11111111111111111100000000000000) | 0b01010101010101010100000000000000; }
// datapins setting to input (data direction: STM32 <- LCD)
#define LCD_DIRREAD { /* D0..D1, D8..D10, D14..D15, E7..E15 <- 0b00 */ \
GPIOD->MODER = (GPIOD->MODER & ~0b11110000001111110000000000001111); \
GPIOE->MODER = (GPIOE->MODER & ~0b11111111111111111100000000000000); }
// datapins write, STM32 -> LCD (write I/O pins from dt data)
#define LCD_WRITE(dt) { /* D14..15 <- dt0..1, D0..1 <- dt2..3, D8..10 <- dt13..15, E7..15 <- dt4..12 */ \
GPIOD->ODR = (GPIOD->ODR & ~0b1100011100000011) | (((dt & 0b11) << 14) | ((dt & 0b1100) >> 2) | ((dt & 0b1110000000000000) >> 5)); \
GPIOE->ODR = (GPIOE->ODR & ~0b1111111110000000) | ((dt & 0b0001111111110000) << 3); }
// datapins read, STM32 <- LCD (read from I/O pins and store to dt data)
#define LCD_READ(dt) { /* dt0..1 <- D14..15, dt2..3 <- D0..1, dt13..15 <- D8..10, dt4..12 <- E7..15 */ \
dt = ((GPIOD->IDR & 0b1100000000000000) >> 14) | ((GPIOD->IDR & 0b0000000000000011) << 2) | \
     ((GPIOD->IDR & 0b0000011100000000) << 5)  | ((GPIOE->IDR & 0b1111111110000000) >> 3); }
#endif

#endif // __LCD_IO16P_GPIO_H
