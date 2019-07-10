/* Orient�cio:
   - 0: 240x320 Reset gomb fel�l (portrait)
   - 1: 320x240 Reset gomb bal oldalt (landscape)
   - 2: 240x320 Reset gomb alul (portrait)
   - 3: 320x240 Reset gomb jobb oldalt (landscape)
*/
#define  ILI9325_ORIENTATION       3

/* Color mode
   - 0: RGB565 (R:bit15..11, G:bit10..5, B:bit4..0)
   - 1: BRG565 (B:bit15..11, G:bit10..5, R:bit4..0)
*/
#define  ILI9325_COLORMODE         0

/* Analog touchscreen
   - 0: Touchscreen tiltva
   - 1: Touchscreen enged�lyezve
*/
#define  ILI9325_TOUCH             0

/* T�bbsz�las vagy megszak�t�sb�l t�rt�n� haszn�lat miatt az Lcd �s a Touchscreen
   egyidej� haszn�lata �sszeakad�st tud okozni (mivel k�z�s I/O er�forr�sokat haszn�l)
   Ezzel a mutex-el ki lehet z�rni az �sszeakad�st.
   Az Lcd f�ggv�nyei kiv�rj�k a Touchscreen fefejezt�t,
   a touchscreen lek�rdez�s meg nem hajtodik v�gre, ha az Lcd �ppen foglalt.
   Figyelem: Ha az Lcd priorit�sa magasabb mint a Touchscreen-�, v�gtelen ciklusba ker�lhet!
   - 0: nincs v�delem az LCD �s a touchscreen egyidej�s�g�nek kiz�r�s�ra
   - 1: van v�delem az LCD �s a touchscreen egyidej�s�g�nek kiz�r�s�ra
*/
#define  ILI9325_MULTITASK_MUTEX   0

/* ILI9325 Size (fizikai felbont�s, az alap�rtelmezett orient�ciora vonatkoztatva) */
#define  ILI9325_LCD_PIXEL_WIDTH   240
#define  ILI9325_LCD_PIXEL_HEIGHT  320
