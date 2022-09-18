#include <Adafruit_GFX.h>
#include <SPI.h>
#include <SdFat.h>

#include "featherwing_keyboard_conbadge.h"

#define SD_CS  5
#define TFT_CS 9
#define TFT_DC 10

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

int bg_color = BLACK;
int acc_color = BLUE;
int text_color = WHITE;
int BORDER = 4;

Adafruit_ILI9341 tft(TFT_CS, TFT_DC);
BBQ10Keyboard keyboard;

SdFat SD;
Adafruit_ImageReader reader(SD);
Adafruit_Image img;

Conbadge badge(&tft, &keyboard, &reader, "UwU", acc_color, bg_color, BORDER);

void setup() {

  tft.begin();

  // -- SD Card init --- //   
  if (!SD.begin(SD_CS, SD_SCK_MHZ(1))){
    badge.haveSdCard = false;
  }

  badge.draw_badge();
}

void loop() {

}
