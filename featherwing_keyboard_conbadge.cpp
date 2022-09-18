#include "featherwing_keyboard_conbadge.h"


  
Conbadge::Conbadge(Adafruit_ILI9341 *tft, BBQ10Keyboard *keyboard, Adafruit_ImageReader *reader, String dispName, int acc_color, int bg_color, int border){
    this->tft = tft;
    this->keyboard = keyboard;
    this->reader = reader;

    this->dispName = dispName;
    this->acc_color = acc_color;
    this->bg_color = bg_color;
    this->border = border;
  }
  
void Conbadge::badge_init(){
  
}

void Conbadge::draw_badge() {

  this->keyboard->setBacklight(0);
  this->tft->setRotation(3);

  if (this->haveSdCard) {
//    Adafruit_Image badge;
//    badge = tft.loadImage("badge1.bmp");
    //this->reader->drawBMP("/badge1.bmp", this->tft, 0, 0);
  }
  else{
    this->tft->fillScreen(this->acc_color);
    
    this->tft->setCursor(this->border * 4, 240 - (20*this->border));
    this->tft->setTextColor(this->bg_color);  
    this->tft->setTextSize(5);
    this->tft->println(this->dispName);

    this->tft->setCursor(this->border * 5, 240 - (19*this->border));
    this->tft->setTextColor(ILI9341_WHITE);  
    this->tft->setTextSize(5);
    this->tft->println(this->dispName);
  }
}
