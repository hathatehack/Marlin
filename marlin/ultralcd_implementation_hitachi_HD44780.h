#ifndef ULTRA_LCD_IMPLEMENTATION_HITACHI_HD44780_H
#define ULTRA_LCD_IMPLEMENTATION_HITACHI_HD44780_H


#if LANGUAGE_CHOICE == 10
#include "LiquidCrystalChina.h"
#define LCD_CLASS LiquidCrystalChina
#else
#include <LiquidCrystal.h>
#define LCD_CLASS LiquidCrystal
#endif

/* Custom characters defined in the first 8 characters of the LCD */
#define LCD_STR_BEDTEMP     "B"
#define LCD_STR_DEGREE      "\x01"   //??
#define LCD_STR_THERMOMETER "H"   //??
#define LCD_STR_UPLEVEL     "\x18"
#define LCD_STR_REFRESH     "\x04"   //??
#define LCD_STR_FOLDER      "\x09"
#define LCD_STR_FEEDRATE    "F"
#define LCD_STR_CLOCK       "T"
#define LCD_STR_ARROW_RIGHT "\x1A"  /* from the default character set */

const unsigned char img[]={

 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xFF,0xFF,0x81,0xFF,0xFF,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xFF,0xFF,0x81,0xFF,0xFF,0xC0,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x80,0x7F,0x80,0x7F,0x07,0xF0,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFE,0x00,0xFF,0x00,0x7E,0x03,0xF8,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xF8,0x01,0xFE,0x00,0xFE,0x00,0xF8,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xF0,0x01,0xFC,0x00,0xFC,0x00,0xFC,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xC0,0x03,0xF8,0x00,0xFC,0x00,0x7C,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x80,0x07,0xF0,0x01,0xFC,0x00,0x7E,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x0F,0xE0,0x01,0xF8,0x00,0x7E,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x1F,0xE0,0x01,0xF8,0x00,0x7E,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xC0,0x03,0xF8,0x00,0x7E,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x80,0x03,0xF0,0x00,0x7E,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0x03,0xF0,0x00,0x7E,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,0x07,0xF0,0x00,0x7E,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFC,0x00,0x07,0xE0,0x00,0x7E,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xF8,0x00,0x0F,0xE0,0x00,0xFC,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xF8,0x00,0x0F,0xC0,0x00,0xFC,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x0F,0xC0,0x00,0xFC,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xE0,0x00,0x1F,0xC0,0x01,0xFC,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xC0,0x00,0x1F,0x80,0x01,0xF8,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x80,0x00,0x1F,0x80,0x01,0xF8,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0x00,0x3F,0x80,0x03,0xF8,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,0x00,0x3F,0x00,0x03,0xF0,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFE,0x00,0x00,0x3F,0x00,0x03,0xF0,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xFC,0x00,0x00,0x7F,0x00,0x07,0xF0,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xF8,0x00,0x00,0x7E,0x00,0x07,0xE0,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xF0,0x00,0x00,0x7E,0x00,0x0F,0xE0,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xE0,0x00,0x00,0xFE,0x00,0x0F,0xC0,0x00,
 0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x1F,0xC0,0x00,0x00,0xFC,0x00,0x1F,0xC0,0x00,
 0x00,0x00,0x07,0xFF,0xE0,0x00,0x00,0x3F,0x80,0x00,0x00,0xFC,0x00,0x1F,0x80,0x00,
 0x00,0x00,0x1F,0xFF,0xF8,0x00,0x00,0x7F,0x80,0x00,0x01,0xFC,0x00,0x3F,0x80,0x00,
 0x00,0x00,0x3F,0xFF,0xFC,0x00,0x00,0xFF,0x00,0x00,0x01,0xF8,0x00,0x3F,0x00,0x00,
 0x00,0x00,0x7F,0xFF,0xFE,0x00,0x01,0xFE,0x00,0x1E,0x01,0xF8,0x00,0x7E,0x00,0x00,
 0x00,0x00,0xFF,0xFF,0xFF,0x00,0x01,0xFC,0x00,0x3E,0x03,0xF8,0x00,0xFE,0x00,0x00,
 0x00,0x01,0xFF,0xFF,0xFF,0x80,0x03,0xF8,0x00,0x3C,0x03,0xF0,0x00,0xFC,0x00,0x00,
 0x00,0x03,0xFF,0xFF,0xFF,0xC0,0x07,0xF0,0x00,0x78,0x03,0xF0,0x01,0xF8,0x00,0x00,
 0x00,0x03,0xFF,0xFF,0xFF,0xC0,0x0F,0xE0,0x00,0xF8,0x07,0xF0,0x03,0xF0,0x00,0x00,
 0x00,0x07,0xFF,0xFF,0xFF,0xE0,0x1F,0xE0,0x01,0xF0,0x07,0xE0,0x0F,0xE0,0x00,0x00,
 0x00,0x07,0xFF,0xFF,0xFF,0xE0,0x3F,0xC0,0x03,0xE0,0x07,0xE0,0x1F,0xC0,0x00,0x00,
 0x00,0x07,0xFF,0xFF,0xFF,0xE0,0x7F,0x80,0x0F,0xE0,0x0F,0xE0,0x7F,0x80,0x00,0x00,
 0x00,0x0F,0xFF,0xC3,0xFF,0xF0,0x7F,0x00,0x3F,0xC0,0x1F,0xE3,0xFE,0x00,0x00,0x00,
 0x00,0x0F,0xFF,0x81,0xFF,0xF0,0xFF,0xFF,0xFF,0xC0,0x7F,0xFF,0xF8,0x00,0x00,0x00,
 0x00,0x09,0xFF,0x00,0x9F,0xF0,0xFF,0xFF,0xFF,0x80,0x7F,0xFF,0x80,0x00,0x00,0x00,
 0x00,0x08,0x3F,0x00,0x83,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x08,0x03,0x00,0x80,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x08,0x01,0x00,0x80,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x08,0x00,0x81,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x04,0x00,0x42,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x04,0x00,0x3C,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x02,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x02,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x01,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x80,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x40,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x20,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x18,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x07,0x00,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

LCD_CLASS lcd(LCD_PINS_RS, LCD_PINS_ENABLE, LCD_PINS_D4);
static void lcd_implementation_init()
{
    lcd.begin(8, 4);
    lcd.clear();
    
  {
   unsigned char i, j, k;
   const unsigned char *p = img;
   lcd.WriteCommand(0x34);  //扩充指令集
   for(i = 0; i < 2; i++)  //上半屏和下半屏
   {
     for(j = 0; j < 32; j++)  //上下半屏各32行
     {
       lcd.WriteCommand(0x80+j);  //写行地址（y地址）
       i ? lcd.WriteCommand(0x88) : lcd.WriteCommand(0x80);  //写列地址（x地址），上半屏列地址为0x80，下半屏列地址为0x88
       for(k = 0; k < 16; k++)  //写入列数据
        lcd.WriteData(*p++);
     }    
   }
   lcd.WriteCommand(0x36);  //显示图形
   lcd.WriteCommand(0x30);  //基本指令集
	 lcd.setCursor(3, 3);
	 for(i = 0; i < 10; i++)
	 {
	   delay(300);
	   lcd.print('.');
	 }
  }
  lcd.clear();
}
static void lcd_implementation_clear()
{
    lcd.clear();
}
/* Arduino < 1.0.0 is missing a function to print PROGMEM strings, so we need to implement our own */
static void lcd_printPGM(const char* str)
{
    char c;
    while((c = pgm_read_byte(str++)) != '\0')
    {
        lcd.write(c);
    }
}

/*
Possible status screens:
16x4   |0123456789012345|
       |000/000 B000/000|
       |SD100%    Z000.0|
       |F100%     T--:--|
       |Status line.....|
*/
static void lcd_implementation_status_screen()
{
    int tHotend=int(degHotend(0) + 0.5);
    int tTarget=int(degTargetHotend(0) + 0.5);
    lcd.setCursor(0, 0);
    lcd.print(LCD_STR_THERMOMETER[0]);
    lcd.print(itostr3(tHotend));
    lcd.print('/');
    lcd.print(itostr3left(tTarget));
    tHotend=int(degBed() + 0.5);
    tTarget=int(degTargetBed() + 0.5);
//    lcd.print(' ');  /* This may casue print incompletely!(Bxxx/xx[x]) */
    lcd.print(LCD_STR_BEDTEMP[0]);
    lcd.print(itostr3(tHotend));
    lcd.print('/');
    lcd.print(itostr3left(tTarget));
    lcd.print("   ");  /* For removing the possible residual printing last */

    lcd.setCursor(0, 1);
    lcd_printPGM(PSTR("SD"));
    if (IS_SD_PRINTING)
        lcd.print(itostr3(card.percentDone()));
    else
        lcd_printPGM(PSTR("---"));
    lcd.print('%');
    lcd_printPGM(PSTR("  Z"));
    lcd.print(ftostr32(current_position[Z_AXIS]));

    lcd.setCursor(0, 2);
    lcd.print(LCD_STR_FEEDRATE[0]);
    lcd.print(itostr3(feedmultiply));
    lcd.print('%');
    lcd_printPGM(PSTR("   "));
    lcd.print(LCD_STR_CLOCK[0]);
    if(starttime != 0)
    {
        uint16_t time = millis()/60000 - starttime/60000;
        lcd.print(itostr2(time/60));
        lcd.print(':');
        lcd.print(itostr2(time%60));
    }else{
        lcd_printPGM(PSTR("--:--"));
    }

    lcd.setCursor(0, 3);
    lcd.print(lcd_status_message);
/*
lcd.print( LCD_STR_BEDTEMP);
lcd.print( LCD_STR_DEGREE);
lcd.print( LCD_STR_THERMOMETER);
lcd.print( LCD_STR_UPLEVEL );
lcd.print( LCD_STR_REFRESH);
lcd.print( LCD_STR_FOLDER);
lcd.print( LCD_STR_FEEDRATE);
lcd.print( LCD_STR_CLOCK );
lcd.print( LCD_STR_ARROW_RIGHT );
*/

}

static void lcd_implementation_drawmenu_generic(uint8_t row, const char* pstr, char pre_char, char post_char)
{
    char c;
    //Use all characters in narrow LCDs
  #if LCD_WIDTH < 20
    	uint8_t n = LCD_WIDTH - 2 - 2;
    #else
    	uint8_t n = LCD_WIDTH - 1 - 2;
  #endif
    lcd.setCursor(0, row);
    lcd.print(pre_char);
    lcd.print(' ');
    while(((c = pgm_read_byte(pstr)) != '\0')&&(n>0))
    {
        lcd.print(c);
        pstr++;
        n--;
    }
    while(n--)
        lcd.print(' ');
    lcd.print(post_char);
    lcd.print(' ');
}
static void lcd_implementation_drawmenu_setting_edit_generic(uint8_t row, const char* pstr, char pre_char, char* data)
{
    char c;
    //Use all characters in narrow LCDs
  #if LCD_WIDTH < 20
    	uint8_t n = LCD_WIDTH - 2 - 2 - strlen(data);
    #else
    	uint8_t n = LCD_WIDTH - 1 - 2 - strlen(data);
  #endif
    lcd.setCursor(0, row);
    lcd.print(pre_char);
    lcd.print(' ');
    while(((c = pgm_read_byte(pstr)) != '\0')&&(n>0))
    {
        lcd.print(c);
        pstr++;
        n--;
    }
    lcd.print(':');
    while(n--)
        lcd.print(' ');
    lcd.print(data);
}
static void lcd_implementation_drawmenu_setting_edit_generic_P(uint8_t row, const char* pstr, char pre_char, const char* data)
{
    char c;
    //Use all characters in narrow LCDs
  #if LCD_WIDTH < 20
    	uint8_t n = LCD_WIDTH - 2 - 2 - strlen_P(data);
    #else
    	uint8_t n = LCD_WIDTH - 1 - 2 - strlen_P(data);
  #endif
    lcd.setCursor(0, row);
    lcd.print(pre_char);
    lcd.print(' ');
    while(((c = pgm_read_byte(pstr)) != '\0')&&(n>0))
    {
        lcd.print(c);
        pstr++;
        n--;
    }
    lcd.print(':');
    while(n--)
        lcd.print(' ');
    lcd_printPGM(data);
}
#define lcd_implementation_drawmenu_setting_edit_int3_selected(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, '>', itostr3(*(data)))
#define lcd_implementation_drawmenu_setting_edit_int3(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, ' ', itostr3(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float3_selected(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, '>', ftostr3(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float3(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, ' ', ftostr3(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float32_selected(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, '>', ftostr32(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float32(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, ' ', ftostr32(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float5_selected(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, '>', ftostr5(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float5(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, ' ', ftostr5(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float52_selected(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, '>', ftostr52(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_long5_selected(row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, '>', ftostr5(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float52(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, ' ', ftostr52(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_float52(row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, ' ', ftostr52(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_float52_selected(row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, '>', ftostr52(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float51_selected(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, '>', ftostr51(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float51(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, ' ', ftostr51(*(data)))
#define lcd_implementation_drawmenu_setting_edit_long5_selected(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, '>', ftostr5(*(data)))
#define lcd_implementation_drawmenu_setting_edit_long5(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, ' ', ftostr5(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_long5(row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, ' ', ftostr5(*(data)))
#define lcd_implementation_drawmenu_setting_edit_bool_selected(row, pstr, pstr2, data) lcd_implementation_drawmenu_setting_edit_generic_P(row, pstr, '>', (*(data))?PSTR(MSG_ON):PSTR(MSG_OFF))
#define lcd_implementation_drawmenu_setting_edit_bool(row, pstr, pstr2, data) lcd_implementation_drawmenu_setting_edit_generic_P(row, pstr, ' ', (*(data))?PSTR(MSG_ON):PSTR(MSG_OFF))
void lcd_implementation_drawedit(const char* pstr, char* value)
{
    lcd.setCursor(0, 1);
    lcd_printPGM(pstr);
    lcd.print(':');
    lcd.setCursor(1, 2);
    lcd.print(value);
}
static void lcd_implementation_drawmenu_sdfile_selected(uint8_t row, const char* pstr, const char* filename, char* longFilename)
{
    char c;
    uint8_t n = LCD_WIDTH - 2;
    lcd.setCursor(0, row);
    lcd.print('>');
    lcd.print(' ');
    if (longFilename[0] != '\0')
    {
        filename = longFilename;
        longFilename[LCD_WIDTH-1] = '\0';
    }
    while(((c = *filename) != '\0')&&(n>0))
    {
        lcd.print(c);
        filename++;
        n--;
    }
    while(n--)
        lcd.print(' ');
}
static void lcd_implementation_drawmenu_sdfile(uint8_t row, const char* pstr, const char* filename, char* longFilename)
{
    char c;
    uint8_t n = LCD_WIDTH - 2;
    lcd.setCursor(0, row);
    lcd.print(' ');
    lcd.print(' ');
    if (longFilename[0] != '\0')
    {
        filename = longFilename;
        longFilename[LCD_WIDTH-1] = '\0';
    }
    while(((c = *filename) != '\0')&&(n>0))
    {
        lcd.print(c);
        filename++;
        n--;
    }
    while(n--)
        lcd.print(' ');
}
static void lcd_implementation_drawmenu_sddirectory_selected(uint8_t row, const char* pstr, const char* filename, char* longFilename)
{
    char c;
    uint8_t n = LCD_WIDTH - 2;
    lcd.setCursor(0, row);
    lcd.print('>');
    lcd.print(LCD_STR_FOLDER[0]);
    if (longFilename[0] != '\0')
    {
        filename = longFilename;
        longFilename[LCD_WIDTH-2] = '\0';
    }
    while(((c = *filename) != '\0')&&(n>0))
    {
        lcd.print(c);
        filename++;
        n--;
    }
    while(n--)
        lcd.print(' ');
}
static void lcd_implementation_drawmenu_sddirectory(uint8_t row, const char* pstr, const char* filename, char* longFilename)
{
    char c;
    uint8_t n = LCD_WIDTH - 2;
    lcd.setCursor(0, row);
    lcd.print(' ');
    lcd.print(LCD_STR_FOLDER[0]);
    if (longFilename[0] != '\0')
    {
        filename = longFilename;
        longFilename[LCD_WIDTH-2] = '\0';
    }
    while(((c = *filename) != '\0')&&(n>0))
    {
        lcd.print(c);
        filename++;
        n--;
    }
    while(n--)
        lcd.print(' ');
}
#define lcd_implementation_drawmenu_back_selected(row, pstr, data) lcd_implementation_drawmenu_generic(row, pstr, LCD_STR_UPLEVEL[0], LCD_STR_UPLEVEL[0])
#define lcd_implementation_drawmenu_back(row, pstr, data) lcd_implementation_drawmenu_generic(row, pstr, ' ', LCD_STR_UPLEVEL[0])
#define lcd_implementation_drawmenu_submenu_selected(row, pstr, data) lcd_implementation_drawmenu_generic(row, pstr, '>', LCD_STR_ARROW_RIGHT[0])
#define lcd_implementation_drawmenu_submenu(row, pstr, data) lcd_implementation_drawmenu_generic(row, pstr, ' ', LCD_STR_ARROW_RIGHT[0])
#define lcd_implementation_drawmenu_gcode_selected(row, pstr, gcode) lcd_implementation_drawmenu_generic(row, pstr, '>', ' ')
#define lcd_implementation_drawmenu_gcode(row, pstr, gcode) lcd_implementation_drawmenu_generic(row, pstr, ' ', ' ')
#define lcd_implementation_drawmenu_function_selected(row, pstr, data) lcd_implementation_drawmenu_generic(row, pstr, '>', ' ')
#define lcd_implementation_drawmenu_function(row, pstr, data) lcd_implementation_drawmenu_generic(row, pstr, ' ', ' ')

static void lcd_implementation_quick_feedback()
{
#if BEEPER > -1
//    SET_OUTPUT(BEEPER);
    for(int8_t i=0;i<10;i++)
    {
		WRITE(BEEPER,HIGH);
		delay(1);
		WRITE(BEEPER,LOW);
		delay(1);
    }
#endif
}
#endif//ULTRA_LCD_IMPLEMENTATION_HITACHI_HD44780_H
