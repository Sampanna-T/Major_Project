/**
 * @file Ultrasonic.cpp
 * 
 * @author Sampanna T (kashi16sadan@gmail.com)
 * 
 * @brief contains the overall execution of Accident detection and ambulance rescue
 * 
 * @version 0.1
 * 
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
 
#include <Bluetooth.h>
#include <Car.h>
#include <GPS.h>
#include <Ultrasonic.h>
#include <NeoSWSerial.h>

/*defining all the pins*/
#define trigger 10
#define echo 9
#define buzzer 8
#define g_rx 7
#define g_tx 6
#define MIN_DISTANCE 3
#define MAX_DISTANCE 10
#define LCD_TIME 500
#define BAUD_RATE 9600
#define ACCIDENT_PIN A1

float distance = 0.0f;          //initialize the distance value
float latitude = 0.0f;          //initialize the latitude value
float longitude = 0.0f;         //initialize the longitude value
unsigned long lcd_update = 0;   //initialize the lcd_update to update lcd every LCD_TIME milli seconds
bool accident_flag = false;     //initialize the accident_flag

const int  en = 2, rw = 1, rs = 0, d4 = 4, d5 = 5, d6 = 6, d7 = 7, bl = 3;
const int i2c_addr = 0x27;      //initializing the I2C address


NeoSWSerial GPS_serial(g_rx,g_tx);                                    //creating instance of NeoSWSerial for gps communication
LiquidCrystal_I2C lcd(i2c_addr,en,rw,rs,d4,d5,d6,d7,bl,POSITIVE);     //creating instance of LiquidCrystal_I2C
Car car;                                                              //creating instance of Car
Bluetooth bluetooth;                                                  //creating instance of Bluetooth
Ultrasonic u_sensor(echo,trigger,buzzer);                             //creating instance of Ultrasonic
GPS gps(&GPS_serial,BAUD_RATE);                                       //creating instance of GPS



void setup() {
  bluetooth.begin(BAUD_RATE);   //initializing the bluetooth module at default baudrate
  lcd.begin(16,2);              //initializing the lcd
  lcd_update = millis();        //initializing lcd_update variable
  pinMode(ACCIDENT_PIN,INPUT);  //initializing ACCIDENT_PIN as input
  pinMode(2,INPUT_PULLUP);
}

void loop() { 
  
  gps.update();                          //updating the gps location values and reading it from gps_rx pin
  bluetooth.start_h(&car);               //performing operations on the car when received u,d,l,r,s data
 
  distance = u_sensor.get_distance();    //getting value from ultrasonic sensor and storing it in distance variable

  if(analogRead(ACCIDENT_PIN)>500){
    accident_flag = true;
  }
  else{
    accident_flag=false;
  }
  
  if(lcd_update <= millis()){//trigger after LCD_TIME
      if(accident_flag==true){    
        lcd.setCursor(8,0);                 //sets the cursor to position 8,0
        gps.print(lcd,1,0);                 //printing the latitutde and longitude values at 1,0
        lcd.print("ACCIDENT");              //printing ACCIDENT on the lcd
      }

      if(distance <= MAX_DISTANCE && distance >= MIN_DISTANCE){
          if(accident_flag==false)lcd.clear();
          u_sensor.print(lcd,0,0);            //printing the distance value at 0,0
          u_sensor.set_buzzer(HIGH);          //turning the buzzer on 
          lcd_update = millis() + LCD_TIME;   //updating the lcd_update variable so that after every LCD_TIME this if block executes
      }
      else{
        u_sensor.set_buzzer(LOW);             //turning the buzzer off
      }
  }//trigger after LCD_TIME
   

  latitude = gps.get_latitude();         //updating the latitude value in the latitude variable
  longitude = gps.get_longitude();       //updating the longitude value in the longitude variable

 
 
    
 
}
