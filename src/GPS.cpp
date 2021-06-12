/**
 * @file GPS.cpp
 * 
 * @author Sampanna T (kashi16sadan@gmail.com)
 * 
 * @brief Contains implementation of all functions necessary to control 4 motors
 * 
 * @version 0.1
 * 
 * @date 2021-07-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "GPS.h"

/*Declaring SoftwareSerial object*/
SoftwareSerial GPS_serial(0,0);

/*Declaring TinyGPSPlus object*/
TinyGPSPlus tiny_gps;

/**
* @brief Construct a new GPS object and
*        configure the tx and rx pins
* 
* @param rx
* @param tx
*
*/
GPS::GPS(uint8_t rx, uint8_t tx){
    GPS_serial = SoftwareSerial(rx,tx);		//initializing the pins for SoftwareSerial
    GPS_serial.begin(9600);			//setting up the default baud rate for GPS communication
}

/**
* @brief updates latitude and longitude values
* 
*/
void GPS::update(){

    while(GPS_serial.available()){//while(available())
  
        tiny_gps.encode(GPS_serial.read());		//encodes the value and holds it in gps object

        if(tiny_gps.location.isUpdated()){//if
            latitude = tiny_gps.location.lat();		//updating latitude value	
            longitude = tiny_gps.location.lng();	//updating longitude value
	}//if

    }//while(available())

}

/**
* @brief updates latitude and longitude values from hardware serial
* 
*/
void GPS::update_h(){

    while(Serial.available()){//while(available())
  
        tiny_gps.encode(Serial.read());			//encodes the value and holds it in gps object

        if(tiny_gps.location.isUpdated()){//if
            latitude = tiny_gps.location.lat();		//updating latitude value
            longitude = tiny_gps.location.lng();	//updating longitude value
	}//if

    }//while(available())

}

/**
* @brief returns latitude value
* 
* @return float 
*/
float GPS::get_latitude(){
   
return latitude;
    
}


/**
* @brief returns longitude value
* 
* @return float 
*/
float GPS::get_longitude(){

return longitude;

}


/**
* @brief prints the latitude and longitude on lcd
*
*/
void GPS::print(LiquidCrystal_I2C lcd, uint8_t row, uint8_t col){
        
	String d = "";
        d += latitude;
	d += " ";
	d += longitude;
        lcd.setCursor(col,row);		//initialize the position from where the printing is done
        lcd.print(d);
}







