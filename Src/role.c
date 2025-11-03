#include "role.h"
#include "display.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>   // for tolower()
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_ts.h"





ROLE_TypeDef role = RECORD_START;

#define SONG_NUMBER 0


void roleInit()
{
	FRESULT res; /* FatFs function common result code */


	/*init library serial*/
	serialInit(&vcp,USART1,usart1_buffer, sizeof(usart1_buffer));

	serialPrintln(&vcp,"mount logical drive and create a FAT volume");
	/*Mount a logical drive*/
	res = f_mount(&SDFatFS, (TCHAR const*)SDPath, 0);
	if(res != FR_OK)
	{
	  serialPrintln(&vcp,"error mount, code error : %d",res);
	}
//	else
//	{
//		/*create a FAT volume*/
//		res = f_mkfs((TCHAR const*)SDPath, FM_ANY, 0, rtext, sizeof(rtext));
//		if(res != FR_OK)
//		{
//			serialPrintln(&vcp,"error mkfs, code error : %d",res);
//		}
//	}

	LCD_Config();
//	BSP_TS_Init(480,272);
	HAL_Delay(500);

}
//void text(int x, int y, char ps,char text[], char text_color, char scr_color){
//
//	char buf[64];     // Temporary text buffer
//
//	if(scr_color==bl){
//		BSP_LCD_Clear(LCD_COLOR_BLUE);
//	}
//	else if(scr_color==r){
//		BSP_LCD_Clear(LCD_COLOR_RED);
//	}
//	else
//		BSP_LCD_Clear(LCD_COLOR_BLACK);
//	if(text_color==b){
//	     	BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
//		}
//		else if(scr_color==r){
//			BSP_LCD_SetTextColor(LCD_COLOR_RED);
//		}
//		else
//			BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
//
//
//    sprintf(buf, "Recording..");
//    if (ps == L){
//    	BSP_LCD_DisplayStringAt(x,y,(uint8_t*)buf,LEFT_MODE);
//    }
//     else if (ps==R)
//     {
//     	BSP_LCD_DisplayStringAt(x,y,(uint8_t*)buf,RIGHT_MODE);
//     }
//     else
//    	BSP_LCD_DisplayStringAt(x,y,(uint8_t*)buf,CENTER_MODE);
//}





void roleNode()
{
	char buf[25];
	switch(role)
	{
	case RECORD_START:
		recordStart();
		text(0, 0, 'c', "Recording..", 'R', 'B');
		role = RECORD_PROCESS;
		break;
	case RECORD_PROCESS:
		if(recordProcess() == AUDIO_ERROR_EOF)
			role = RECORD_STOP;
		break;
	case RECORD_STOP:
		recordStop();
		role = PLAY_START;
		break;
	case PLAY_START:
		BSP_LCD_Clear(LCD_COLOR_BLACK);
		BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
		sprintf(buf, "Play..");
		BSP_LCD_DisplayStringAt(0,150,(uint8_t*)buf,LEFT_MODE);
		playStart(SONG_NUMBER);
		role = PLAY_PROCESS;
		break;
	case PLAY_PROCESS:
		if(playProcess() == AUDIO_ERROR_EOF)
			role = PLAY_STOP;
		break;
	case PLAY_STOP:
		playStop();
		role = AUDIO_GRAPH;
		break;
	case AUDIO_GRAPH:
		BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
		BSP_LCD_DrawHLine(0, 136, 480);
		break;
	}
}
