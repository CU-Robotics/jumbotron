#include "TFT_eSPI.h"
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ESPDash.h>
#include <qrcode_espi.h>
//#include <lvgl.h>

int run = 0;

TFT_eSPI tft = TFT_eSPI();
uint16_t x, y;
QRcode_eSPI qrcode (&tft);

AsyncWebServer server(80);
ESPDash dashboard(&server); 

Card statusCard(&dashboard, STATUS_CARD, "Status", "success");


void setup() {

statusCard.update("Test");
WiFi.softAP("Jumbotron", "password", 12, 1);
server.begin();


 Serial.begin(9600);
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);

  qrcode.init();
  qrcode.create("WIFI:S:Jumbotron;T:WPA;P:password;;");
  tft.setRotation(0);
  tft.drawString("Connect", 5, 5, 4);


}
  
void loop() {

  if(tft.getTouch(&x, &y)) {
    if(run == 0) {
      run++;
      tft.fillScreen(TFT_BLACK);
      tft.setRotation(1);
      qrcode.create("http://192.168.4.1");
      tft.setRotation(0);
      tft.drawString("Dashboard", 5, 5, 4);
      delay(500);
    }else if (run == 1) {
      tft.setRotation(1);
      run++;
      tft.fillScreen(TFT_BLACK);
    }
    else{
      
    Serial.print("X = "); Serial.print(x);
    Serial.print(", Y = "); Serial.println(y);
    tft.drawString("X: "+String(x)+"  Y: "+String(y)+"                ", 10, 10, 4);
    }
    
  }

}