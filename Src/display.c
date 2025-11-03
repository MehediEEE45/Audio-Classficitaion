#include <stdio.h>
#include <string.h>
#include <ctype.h>   // for tolower()
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_ts.h"


void LCD_Config(void)
{
  /* LCD Initialization */
  BSP_LCD_Init();

  /* LCD Initialization */
  BSP_LCD_LayerDefaultInit(0, LCD_FB_START_ADDRESS);
  BSP_LCD_LayerDefaultInit(1, LCD_FB_START_ADDRESS+(BSP_LCD_GetXSize()*BSP_LCD_GetYSize()*4));

  /* Enable the LCD */
  BSP_LCD_DisplayOn();

  /* Select the LCD Background Layer  */
  BSP_LCD_SelectLayer(0);

  /* Clear the Background Layer */
  BSP_LCD_Clear(LCD_COLOR_BLACK);

  /* Select the LCD Foreground Layer  */
  BSP_LCD_SelectLayer(1);

  /* Clear the Foreground Layer */
  BSP_LCD_Clear(LCD_COLOR_BLACK);
  BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
  /* Configure the transparency for foreground and background :
     Increase the transparency */
}


void setFont(char size)
{
    size = tolower(size); // supports 'S' or 's', etc.

    switch (size)
    {
    case 's': // small
        BSP_LCD_SetFont(&Font12);
        break;
    case 'm': // medium
        BSP_LCD_SetFont(&Font16);
        break;
    case 'l': // large
        BSP_LCD_SetFont(&Font24);
        break;
    default: // default font
        BSP_LCD_SetFont(&Font20);
        break;
    }
}


void text(int x, int y, char ps, char text_str[], char text_color, char scr_color)
{
    char buf[64]; // temporary text buffer

    // Convert inputs to lowercase so it works with small or capital letters
    ps = tolower(ps);
    text_color = tolower(text_color);
    scr_color = tolower(scr_color);

    // ----- Clear Screen -----
    if (scr_color == 'b')
        BSP_LCD_Clear(LCD_COLOR_BLUE);
    else if (scr_color == 'r')
        BSP_LCD_Clear(LCD_COLOR_RED);
    else if (scr_color == 'g')
        BSP_LCD_Clear(LCD_COLOR_GREEN);
    else
        BSP_LCD_Clear(LCD_COLOR_BLACK);

    // ----- Set Text Color -----
    if (text_color == 'b')
        BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
    else if (text_color == 'r')
        BSP_LCD_SetTextColor(LCD_COLOR_RED);
    else if (text_color == 'g')
        BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
    else
        BSP_LCD_SetTextColor(LCD_COLOR_WHITE);

    // ----- Copy and Display Text -----
    snprintf(buf, sizeof(buf), "%s", text_str);

    if (ps == 'l')
        BSP_LCD_DisplayStringAt(x, y, (uint8_t*)buf, LEFT_MODE);
    else if (ps == 'r')
        BSP_LCD_DisplayStringAt(x, y, (uint8_t*)buf, RIGHT_MODE);
    else
        BSP_LCD_DisplayStringAt(x, y, (uint8_t*)buf, CENTER_MODE);
}




void multitext(int x, int y, char ps, char text_str[], char text_color)
{
    char buf[64];
    ps = tolower(ps);
    text_color = tolower(text_color);

    // ----- Set Text Color -----
    if (text_color == 'b')
        BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
    else if (text_color == 'r')
        BSP_LCD_SetTextColor(LCD_COLOR_RED);
    else if (text_color == 'g')
        BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
    else
        BSP_LCD_SetTextColor(LCD_COLOR_WHITE);

    // ----- Display each line -----
    int line_y = y; // starting y position
    char *line = strtok(text_str, "\n"); // split by \n

    while(line != NULL)
    {
        snprintf(buf, sizeof(buf), "%s", line);

        if(ps == 'l')
            BSP_LCD_DisplayStringAt(x, line_y, (uint8_t*)buf, LEFT_MODE);
        else if(ps == 'r')
            BSP_LCD_DisplayStringAt(x, line_y, (uint8_t*)buf, RIGHT_MODE);
        else
            BSP_LCD_DisplayStringAt(x, line_y, (uint8_t*)buf, CENTER_MODE);

        line_y += BSP_LCD_GetFont()->Height; // move down for next line
        line = strtok(NULL, "\n");
    }
}
