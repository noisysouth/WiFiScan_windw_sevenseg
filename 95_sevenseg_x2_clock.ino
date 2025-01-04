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

#define TIMET_1JAN2016 1451628000

Adafruit_7segment matrix[2];
Adafruit_AlphaNum4 alpha4[3];
char *dayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
char *monNames[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

void sevenseg_setup(void) {
  matrix[0] = Adafruit_7segment();
  matrix[1] = Adafruit_7segment();
  Serial.println("7 Segment Backpack Initialized");
  matrix[0].begin(0x70);
  matrix[1].begin(0x71);
  matrix[0].drawColon(true);
  matrix[0].writeDisplay();

  alpha4[0] = Adafruit_AlphaNum4();
  alpha4[1] = Adafruit_AlphaNum4();
  alpha4[2] = Adafruit_AlphaNum4();
  alpha4[0].begin(0x72);
  alpha4[1].begin(0x73);
  alpha4[2].begin(0x74);
}

void sevenseg_loop(void) {
  struct timeval tv_now;
  struct tm now_tm;
  int _12hour;
  char *mon_str;
  char *wday_str;
  int year_int;

  gettimeofday(&tv_now, NULL);
  //Serial.print("Time tv_now.tv_sec: ");
  //Serial.print(tv_now.tv_sec);
  //Serial.print(", tv_now.tv_usec: ");
  //Serial.println(tv_now.tv_usec);
  if (tv_now.tv_sec < TIMET_1JAN2016) {
    return; // quit early - don"t know what time it is
  }
  if(!getLocalTime(&now_tm)){ // this function will block for 5sec, if Real Time Clock < 1 Jan 2016
    Serial.println("Failed to obtain time");
    return;
  }
  _12hour = now_tm.tm_hour % 12;
  if (_12hour == 0) {
    _12hour = 12;
  }

  // Hours
  if (_12hour >= 10) {
    matrix[0].writeDigitNum(0, _12hour/10);
  } else {
    matrix[0].writeDigitRaw(0, 0 /* all segments off */);
  }
  matrix[0].writeDigitNum(1, _12hour%10);
  // Minutes
  matrix[0].writeDigitNum(3, now_tm.tm_min/10);
  matrix[0].writeDigitNum(4, now_tm.tm_min%10);

  matrix[0].drawColon(true);

  // doesn"t work for me?
  //matrix[1].writeDigitRaw(0xc, 0x3); // left colon: both bits (0x8 + 0x4 = 0xc;  0x2 + 0x1 = 0x3)
  // Source: https://forums.adafruit.com/viewtopic.php?t=53654
  // https://learn.adafruit.com/adafruit-led-backpack/1-2-inch-7-segment-backpack-arduino-wiring-and-setup
  // Seconds
  matrix[1].writeDigitNum(0, now_tm.tm_sec/10);
  matrix[1].writeDigitNum(1, now_tm.tm_sec%10, true /* draw decimal, 0.56" height only*/);
  //matrix[1].writeDigitRaw(2, true); // middle colon; // doesn"t work for me?
  // fractional seconds
  matrix[1].writeDigitNum(3, tv_now.tv_usec/100000);
  matrix[1].writeDigitNum(4, (tv_now.tv_usec/10000) % 10);

  // Month
  mon_str = monNames[now_tm.tm_mon];
  alpha4[0].writeDigitAscii(0, mon_str[0]);
  alpha4[0].writeDigitAscii(1, mon_str[1]);
  alpha4[0].writeDigitAscii(2, mon_str[2]);

  // Day of Month
  if (now_tm.tm_mday >= 10) {
    alpha4[0].writeDigitAscii(3, '0' + (now_tm.tm_mday/10));
  } else {
    alpha4[0].writeDigitRaw(3, 0 /* all segments off */);
  }
  alpha4[1].writeDigitAscii(0, '0' + (now_tm.tm_mday%10));

  // Day of Week
  wday_str = dayNames[now_tm.tm_wday];
  alpha4[1].writeDigitAscii(1, wday_str[0]);
  alpha4[1].writeDigitAscii(2, wday_str[1]);
  alpha4[1].writeDigitAscii(3, wday_str[2]);

  // Year
  year_int = now_tm.tm_year + 1900;
  alpha4[2].writeDigitAscii(0, '0' + ( year_int/1000));
  alpha4[2].writeDigitAscii(1, '0' + ((year_int/ 100)%10));
  alpha4[2].writeDigitAscii(2, '0' + ((year_int/  10)%10));
  alpha4[2].writeDigitAscii(3, '0' + ( year_int      %10));

  matrix[0].writeDisplay();
  matrix[1].writeDisplay();
  alpha4[0].writeDisplay();
  alpha4[1].writeDisplay();
  alpha4[2].writeDisplay();
}
