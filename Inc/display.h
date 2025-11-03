#ifndef DISPLAY_H
#define DISPLAY_H

#include "stm32746g_discovery_lcd.h"

/**
 * @brief Initialize the LCD and configure foreground/background layers
 */
void LCD_Config(void);

/**
 * @brief Display a string on the LCD
 *
 * @param x           X position on the screen
 * @param y           Y position on the screen
 * @param ps          Text alignment: 'L'/'l' = Left, 'R'/'r' = Right, 'C'/'c' = Center
 * @param text_str    The string to display
 * @param text_color  Text color: 'R'/'r' = Red, 'B'/'b' = Blue, 'G'/'g' = Green, default = White
 * @param scr_color   Background color: 'R'/'r' = Red, 'B'/'b' = Blue, 'G'/'g' = Green, default = Black
 */
void text(int x, int y, char ps, char text_str[], char text_color, char scr_color);

#endif // DISPLAY_H
