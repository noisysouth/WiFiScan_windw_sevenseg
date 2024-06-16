#include <SPI.h>
#include <Wire.h> // for i2c keyboard, DRV2605 haptic feedback, FM RDS transmitter

#include "Adafruit_DRV2605.h" // haptic

Adafruit_DRV2605 drv; // haptic

bool haptic_found = false;

void setup_haptic(void) {
  // --------------------------------- Start haptic output ----------------------------
  haptic_found = drv.begin();
  if (!haptic_found) {
    Serial.println("DRV2605 not found - no haptic feedback will be used.");
  } else { // haptic_found
    drv.selectLibrary(1);
  
    // I2C trigger by sending 'go' command 
    // default, internal trigger when sending GO command
    drv.setMode(DRV2605_MODE_INTTRIG); 
  }
}

// ---------------- make a haptic rumble "click" ------------
void haptic_click(void) {
  if (!haptic_found) {
    return;
  }
  int effect = 1; // Strong Click - 100%

  // set the effect to play
  drv.setWaveform(0, effect);  // play effect 
  drv.setWaveform(1, 0);       // end waveform

  // play the effect!
  drv.go();
}