#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <iostream>
#include <string>
#include <interface.h>
#include <XPT2046_Touchscreen.h>

#define CS 15
#define DC 2
#define SDI 13
#define SCK 14
#define MISO 12
#define RESET 5

#define T_CS 21
#define T_IRQ 27

/*
T_DO -> GPIO19 (VSPIMISO)
T_DIN -> GPIO23 (VPSIMOSI)
T_CLK -> GPIO18 (VSPI SCK)
*/

Adafruit_ILI9341 tft = Adafruit_ILI9341(CS, DC, SDI, SCK, RESET, MISO);
int16_t last_pos[2] = {0, 0};
Adafruit_GFX_Button btn;
XPT2046_Touchscreen ts(T_CS, T_IRQ);

TS_Point pt;
bool touched = false;
uint32_t timeTouch = 0;


// TODO:
// SPI QR CODE
// Learn how SPI works for fun
// FIGURE OUT WHAT CURRENT SENSOR IS AND WHAT IT DOES
// QRCODE_ESPI Library
// QRCODEDISPLAY Library


// 24 motors: yes or no


void setup() {
  Serial.begin(9600);
  tft.begin();
  tft.setRotation(1);
  mainMenu(tft);
  ts.setRotation(3);
  if(ts.begin()) {

  } else {
    tft.println("LOL");
  }

}

boolean wastouched = true;
int x_state = 0;
int y_state = 0;

void loop(void) {

  if(ts.touched()){
    TS_Point pt = ts.getPoint();
    Serial.print("X :");
    Serial.println(pt.x);
    Serial.print("Y :");
    Serial.println(pt.y);
    Serial.println("\n");
  }
  delay(100);
}


// Width: 800 Height: 800