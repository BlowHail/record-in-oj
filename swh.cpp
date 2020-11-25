#include <Adafruit_NeoPixel.h>
#define NUM_LEDS 64
#define LED_PIN 3
Adafruit_NeoPixel pixels(NUM_LEDS,LED_PIN, NEO_GRB + NEO_KHZ800);
 
//字模输入
#define CHAIN 2
const unsigned char table[][8] ={
  {0x00,0x22,0x3E,0x02},
  {0x36,0x2A,0x32,0x00}
};
//初始化
void setup() {
  Serial.begin(9600);
  pixels.begin();
}
//十六进制转二进制
int* getBin(int Dec ) {
  static int a[16];
  for (int i = 7 ; i >= 0 ; i--) {
    if (pow(2, i) <= Dec) {
      Dec = Dec - pow(2, i);
      a[7 - i] = 1;
    } else {
      a[7 - i] = 0;
    }
  }
 
  return a;
}
//字模数据扫描 
void loop() {
  int *lines;
  uint32_t  hsv;
  int count = 0;
  int r = 16, g = 16, b = 16;
  for(int ii=0;ii<CHAIN;ii++){
    for (int m = 0; m < 8; m++) {
        lines = getBin(table[ii][m]);
        if (m%2 == 0)
        {
          for (int i = 0; i < 8; i++) {
            if (lines[i] == 1)pixels.setPixelColor(count, r, g, b);
            count++;
          }
        }
        else {
          for (int i = 7; i >= 0 ; i--) {
            if (lines[i] == 1)  pixels.setPixelColor(count,  r, g, b);
            count++;
          }
        }
        pixels.show();
    }
    for(int jj=0;jj<256;jj++);
  }
}
