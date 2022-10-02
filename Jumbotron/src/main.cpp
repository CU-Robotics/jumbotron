#include "TFT_eSPI.h"
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ESPDash.h>
//#include <lvgl.h>

TFT_eSPI tft = TFT_eSPI();
uint16_t x, y;


AsyncWebServer server(80);
ESPDash dashboard(&server); 

Card statusCard(&dashboard, STATUS_CARD, "Status", "success");


void setup() {

statusCard.update("Test");
WiFi.softAP("Jumbotron");
server.begin();


 Serial.begin(9600);
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);

}
  
void loop() {

  if(tft.getTouch(&x, &y)) {
    Serial.print("X = "); Serial.print(x);
    Serial.print(", Y = "); Serial.println(y);
    tft.drawString("X: "+String(x)+"  Y: "+String(y)+"                ", 10, 10, 4);
  }

}