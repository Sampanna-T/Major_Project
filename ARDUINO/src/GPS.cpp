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


/*Declaring TinyGPSPlus object*/
TinyGPSPlus tiny_gps;

/**
* @brief Construct a new GPS object and
*        start serial communication at default baut rate using NeoSWSerial object address
* 
* @param gpsSerialPtr
* @param baudrate
*
*/
GPS::GPS(NeoSWSerial *gpsSerialPtr, int baudrate){
    this->gpsSerialPtr = gpsSerialPtr;		//initializing the gpsSerialPtr with the address provided
    this->gpsSerialPtr->begin(baudrate);	//setting up the default baud rate for GPS communication
}

/**
* @brief updates latitude and longitude values
* 
*/
void GPS::update(){

    while(gpsSerialPtr->available()){//while(available())
  
        tiny_gps.encode(gpsSerialPtr->read());		//encodes the value and holds it in gps object

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







