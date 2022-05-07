#include <LiquidCrystal.h> 
#include "MQ135.h"
#include <DHT.h>

#define DHT_SENSOR_TYPE DHT11

static const int DHT_SENSOR_PIN = 29;//pin sensor dht11
DHT dht( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );
const int ANALOGPIN=0; //pin MQ135
int Contrast=70;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
MQ135 MQ135Sensor = MQ135(ANALOGPIN, 212.70);

int red_light_pin= 39;
int green_light_pin = 37;
int blue_light_pin = 35;

void setup() {
  Serial.begin(9600); 
  analogWrite(6,Contrast);
  lcd.begin(16, 2);
  dht.begin();
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
}
  
void loop() { 
  
  // get temp&humidity and print on lcd
  
  float t = dht.readTemperature();
  int h = dht.readHumidity();
  String temp = String(t);
  String humidity= String(h);
  //Serial.println("Temp: "+temp);
  //Serial.println("Hum: "+humidity);
  lcd.setCursor(0,0);
  lcd.print("Temp    : ");
  lcd.print(t,1);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Umidita': ");
  lcd.print(humidity);
  lcd.print("%");
  delay(5000);
  
  // clear lcd
  
  lcd.clear();
  
  // PPM
  
  //float ppm = MQ135Sensor.getCorrectedRZero(t, h); // for calibration
  //float ppm = MQ135Sensor.getPPM();
  float ppm = MQ135Sensor.getCorrectedPPM(t, h);
  Serial.println("ppm: " +String(ppm));
  
  // print PPM on LCD
  
  lcd.setCursor(0, 0);
  lcd.print("Qta' Aria: ");
  lcd.setCursor(1, 1);
  lcd.print(ppm);
  lcd.setCursor(13,1);
  lcd.print("ppm");
  
  // set led color
  
  setLedColor(ppm);
  delay(5000);
  
  // clear lcd
  
  lcd.clear();

}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value) {
  
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
  
}

void setLedColor(float ppm){
  
  if (ppm <= 500) {
    RGB_color(255, 255, 255); // White
  }
  else if (ppm > 500 && ppm <= 700){
    RGB_color(102, 255, 255); // Cyan
  }
  else if (ppm > 700 && ppm <= 1000){
    RGB_color(0, 255, 0); // Green
  }
  else if (ppm > 1000 && ppm <= 1500){
    RGB_color(255, 255, 0); // Yellow
  }
  else if (ppm > 1500 && ppm <= 2000){
    RGB_color(255, 0, 0); // Red
  }
  else if (ppm > 2000){
    RGB_color(153, 0, 204); // Magenta
  }
  
}

    
