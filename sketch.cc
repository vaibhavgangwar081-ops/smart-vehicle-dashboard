#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


void setup() {
  Serial.begin(115200);

  Wire.begin(21, 22);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED Failed!");
    while (true);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.display();
}
void loop() {

  int fuel = 78;
  int battery = 92;
  int oil = 85;
  int temp = 72;
  int range = 245;

display.clearDisplay();
display.setTextSize(2);
display.setCursor(10,20);
display.print("IGNITION");
display.display();
delay(1500);

display.clearDisplay();
display.setCursor(35,20);
display.print("ON");
display.display();
delay(1000);

  // FUEL
display.clearDisplay();

display.drawRect(5,10,25,12,SSD1306_WHITE);
display.fillRect(30,13,3,6,SSD1306_WHITE);
display.fillRect(7,12,18,8,SSD1306_WHITE);

display.setTextSize(2);
display.setCursor(40,10);
display.print("BATT");

display.setCursor(35,35);
display.print(battery);
display.print("%");

display.display();
delay(2000);

  //  BATTERY

display.clearDisplay();

display.drawRect(5,10,25,12,SSD1306_WHITE);
display.fillRect(30,13,3,6,SSD1306_WHITE);
display.fillRect(7,12,18,8,SSD1306_WHITE);

display.setTextSize(2);
display.setCursor(40,10);
display.print("BATT");

display.setCursor(35,35);
display.print(battery);
display.print("%");

display.display();
delay(2000);

  // ENGINE OIL 
  display.clearDisplay();

display.drawCircle(15,18,6,SSD1306_WHITE);
display.drawLine(15,24,15,30,SSD1306_WHITE);

display.setTextSize(2);
display.setCursor(30,10);
display.print("ENG OIL");

display.setCursor(45,35);
display.print(oil);
display.print("%");

display.display();
delay(1500);

  //  TEMPERATURE 
  display.clearDisplay();
display.drawCircle(15,25,5,SSD1306_WHITE);
display.drawLine(15,20,15,8,SSD1306_WHITE);
display.drawCircle(15,20,5,SSD1306_WHITE);
display.drawLine(15,15,15,5,SSD1306_WHITE);

display.setTextSize(2);
display.setCursor(35,10);
display.print("TEMP");

display.setCursor(25,35);
display.print(temp);
display.print("C");

display.display();
delay(2000);
  // RANGE 
display.clearDisplay();

display.drawLine(5,30,25,10,SSD1306_WHITE);
display.drawLine(5,30,25,50,SSD1306_WHITE);

display.setTextSize(2);
display.setCursor(30,10);
display.print("KM LEFT");

display.setCursor(35,35);
display.print(range);

display.display();
delay(1500);

  //  LOADING SCREEN
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(10, 15);
  display.print("CHECKING SYSTEMS");

  display.drawRect(10, 35, 108, 12, SSD1306_WHITE);

  for(int i=0;i<=100;i+=10){
    display.fillRect(12, 37, i, 8, SSD1306_WHITE);
    display.display();
    delay(100);
  }

  delay(500);

  // FINAL DASHBOARD AISA DIKHEGA
  display.clearDisplay();

  display.setTextSize(1);

  display.setCursor(0,0);
  display.print("Fuel:");
  display.print(fuel);
  display.print("%");

  display.setCursor(70,0);
  display.print("Bat:");
  display.print(battery);
  display.print("%");

  display.setCursor(0,20);
  display.print("Oil:");
  display.print(oil);
  display.print("%");

  display.setCursor(70,20);
  display.print("Tmp:");
  display.print(temp);
  display.print("C");

  display.setCursor(0,45);
  display.print("Range:");
  display.print(range);
  display.print("KM");

  display.display();

  while(true);
}