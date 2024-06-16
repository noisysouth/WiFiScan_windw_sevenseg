/*************************************************** 
  This is a library for our I2C LED Backpacks

  Designed specifically to work with the Adafruit LED 7-Segment backpacks 
  ----> http://www.adafruit.com/products/881
  ----> http://www.adafruit.com/products/880
  ----> http://www.adafruit.com/products/879
  ----> http://www.adafruit.com/products/878

  These displays use I2C to communicate, 2 pins are required to 
  interface. There are multiple selectable I2C addresses. For backpacks
  with 2 Address Select pins: 0x70, 0x71, 0x72 or 0x73. For backpacks
  with 3 Address Select pins: 0x70 thru 0x77

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h> // Enable this line if using Arduino Uno, Mega, etc.
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_7segment matrix[2];

void sevenseg_setup(void) {
  matrix[0] = Adafruit_7segment();
  matrix[1] = Adafruit_7segment();
  Serial.println("7 Segment Backpack Initialized");
  matrix[0].begin(0x70);
  matrix[1].begin(0x71);
  matrix[0].drawColon(true);
  matrix[0].writeDisplay();
}

void sevenseg_loop(void) {
  struct timeval tv_now;
  struct tm now_tm;
  int _12hour;
  int mtx0_int;
  int mtx1_int;

  gettimeofday(&tv_now, NULL);
  if(!getLocalTime(&now_tm)){
    Serial.println("Failed to obtain time");
    return;
  }
  _12hour = now_tm.tm_hour % 12;
  mtx0_int = (_12hour * 100) + 
              now_tm.tm_min;

  mtx1_int =  (now_tm.tm_sec * 100) +
              (tv_now.tv_usec / 10000);

  matrix[0].print(mtx0_int, DEC);
  matrix[0].drawColon(true);

  // doesn't work for me?
  //matrix[1].writeDigitRaw(0xc, 0x3); // left colon: both bits (0x8 + 0x4 = 0xc;  0x2 + 0x1 = 0x3)
  // Source: https://forums.adafruit.com/viewtopic.php?t=53654
  // https://learn.adafruit.com/adafruit-led-backpack/1-2-inch-7-segment-backpack-arduino-wiring-and-setup
  //matrix[1].print(mtx1_int, DEC);
  matrix[1].writeDigitNum(0, now_tm.tm_sec/10);
  matrix[1].writeDigitNum(1, now_tm.tm_sec%10);
  //matrix[1].writeDigitRaw(2, true); // middle colon; // doesn't work for me?
  matrix[1].writeDigitNum(3, tv_now.tv_usec/100000);
  matrix[1].writeDigitNum(4, (tv_now.tv_usec/10000) % 10);

  matrix[0].writeDisplay();
  matrix[1].writeDisplay();
}
