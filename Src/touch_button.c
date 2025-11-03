#include "touch_button.h"
#include "stm32746g_discovery_ts.h"
#include "stm32746g_discovery_lcd.h"
#include <string.h>
#include <stdbool.h>

static TS_StateTypeDef TS_State;

void touchInit(void)
{
    // Initialize touchscreen
    BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());
}

void drawButton(TS_Button* btn)
{
    // Draw filled rectangle for button
    BSP_LCD_SetTextColor(btn->color);
    BSP_LCD_FillRect(btn->x, btn->y, btn->width, btn->height);

    // Draw border
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
    BSP_LCD_DrawRect(btn->x, btn->y, btn->width, btn->height);

    // Draw centered text
    BSP_LCD_SetTextColor(btn->textColor);
    uint16_t textX = btn->x + (btn->width / 2) - (strlen(btn->label) * BSP_LCD_GetFont()->Width / 2);
    uint16_t textY = btn->y + (btn->height / 2) - (BSP_LCD_GetFont()->Height / 2);
    BSP_LCD_DisplayStringAt(textX, textY, (uint8_t*)btn->label, LEFT_MODE);
}

bool isButtonPressed(TS_Button* btn)
{
    BSP_TS_GetState(&TS_State);

    if(TS_State.touchDetected > 0)
    {
        uint16_t tx = TS_State.touchX[0];
        uint16_t ty = TS_State.touchY[0];

        if(tx >= btn->x && tx <= (btn->x + btn->width) &&
           ty >= btn->y && ty <= (btn->y + btn->height))
        {
            return true;
        }
    }
    return false;
}



// Draw a Record button (convenience function)
void drawRecordButton(TS_Button* btn)
{
    btn->x = 150;
    btn->y = 100;
    btn->width = 180;
    btn->height = 60;
    btn->color = LCD_COLOR_RED;
    btn->textColor = LCD_COLOR_WHITE;
    strcpy(btn->label, "RECORD");

    drawButton(btn);
}
