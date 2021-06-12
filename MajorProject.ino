#include <Bluetooth.h>
#include <Car.h>
#include <GPS.h>
#include <Ultrasonic.h>

/*defining all the pins*/
#define b_rx 2
#define b_tx 5
#define trigger 10
#define echo 9
#define buzzer 8
#define g_rx 7
#define g_tx 6
#define MIN_DISTANCE 2
#define MAX_DISTANCE 10
#define LCD_TIME 100

float distance = 0.0f;          //initialize the distance value
float latitude = 0.0f;          //initialize the latitude value
float longitude = 0.0f;         //initialize the longitude value
unsigned long lcd_update = 0;   //initialize the lcd_update to update lcd every LCD_TIME milli seconds

const int  en = 2, rw = 1, rs = 0, d4 = 4, d5 = 5, d6 = 6, d7 = 7, bl = 3;
const int i2c_addr = 0x27;      //initializing the I2C address
                                         
LiquidCrystal_I2C lcd(i2c_addr,en,rw,rs,d4,d5,d6,d7,bl,POSITIVE);   //initializing LCD
Car car;                                                            //creating instance of car
Bluetooth bluetooth(b_rx,b_tx);                                     //creating instance of bluetooth
Ultrasonic u_sensor(echo,trigger,buzzer);                           //creating instance of ultrasonic sensor
GPS gps(g_rx,g_tx);                                                 //creating instance of gps



void setup() {
  Serial.begin(9600);         //beginning serial communication at 9600 baud rate
  lcd.begin(16,2);            //initializing the lcd
  lcd_update = millis();      //initializing lcd_update variable
}

void loop() { 
  
  gps.update_h();           //updating the gps location values and reading it from hardware serial
  bluetooth.start(car);     //performing operations on the car when received u,d,l,r,s data
 
  distance= u_sensor.get_distance();    //getting value from ultrasonic sensor and storing it in distance variable
   
  if(distance <= MAX_DISTANCE && distance >= MIN_DISTANCE){
      if(lcd_update <= millis()){
          lcd.clear();                        //clearing the content of lcd
          u_sensor.print(lcd,0,0);            //printing the distance value at 0,0
          gps.print(lcd,1,0);                 //printing the latitutde and longitude values at 1,0
          u_sensor.set_buzzer(HIGH);          //turning the buzzer on 
          lcd_update = millis() + LCD_TIME;   //updating the lcd_update variable so that after every LCD_TIME this if block executes
      }
  }
  else{
      if(lcd_update <= millis()){
        u_sensor.set_buzzer(LOW);   //turning the buzzer off
      }
  }
   

  latitude = gps.get_latitude();         //updating the latitude value in the latitude variable
  longitude = gps.get_longitude();       //updating the longitude value in the longitude variable
 
}

