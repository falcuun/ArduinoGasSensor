#include <SPI.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define GAS_SENSOR_A0 A0

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup()
{
    pinMode(GAS_SENSOR_A0, INPUT);
    SPI.begin();
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void loop()
{
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(27, 30);
    display.print(analogRead(GAS_SENSOR_A0));
    display.display();
    delay(200);
}