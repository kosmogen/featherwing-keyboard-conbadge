/***********************************************
 * Use your Featherwing Keyboard as a con badge!
 * 
 * Reads an image from the SD card to display to the screen
 * 
 * Or can display a simple name as a backup if no image or SD card is found
 */

 #ifndef FW_KBD_CONBADGE
 #define FW_KBD_CONBADGE

#include <BBQ10Keyboard.h>
#include <Adafruit_ILI9341.h>
#include <SdFat.h>
#include <Adafruit_ImageReader.h>

class Conbadge
{
  public:
    Adafruit_ILI9341 *tft;
    BBQ10Keyboard *keyboard;
    Adafruit_ImageReader *reader;
  
    bool haveSdCard = true;
    String dispName;
    int acc_color;
    int bg_color;
    int border;

    Conbadge(Adafruit_ILI9341 *tft, BBQ10Keyboard *keyboard, Adafruit_ImageReader *reader, String dispName, int acc_color, int bg_color, int border);
    void badge_init();
    void draw_badge();
};
 


 #endif
