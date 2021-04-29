#include <Car.h>
#include <Bluetooth.h>
#include <Ultrasonic.h>

/*defining all the pins*/
#define rx 2
#define tx 5
#define trigger 10
#define echo 9
#define buzzer 8

float distance=0.0f;//initialize the distance value

const int  en = 2, rw = 1, rs = 0, d4 = 4, d5 = 5, d6 = 6, d7 = 7, bl = 3;
const int i2c_addr = 0x27;                                                         
LiquidCrystal_I2C lcd(i2c_addr, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);//initializing LCD

Car car;//creating instance of car
Bluetooth bluetooth(rx,tx);//creating instance of bluetooth
Ultrasonic u_sensor(echo,trigger,buzzer);//creating instance of ultrasonic sensor



void setup() {
  Serial.begin(9600);//beginning serial communication at 9600 baud rate
  lcd.begin(16,2);//initializing the lcd
}

void loop() { 
  
 bluetooth.start(car);//performing operations on the car when received u,d,l,r,s data
 distance = u_sensor.get_distance(lcd);//getting value from ultrasonic sensor and storing it in distance variable
 
}


