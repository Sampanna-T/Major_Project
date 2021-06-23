/**
 * @file GPS.h
 * 
 * @author Sampanna T (kashi16sadan@gmail.com)
 * 
 * @brief contains definitions of function/s to get latitude and longitude values
 * 
 * @version 0.1
 * 
 * @date 2021-06-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef GPS_H__
#define GPS_H__

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <NeoSWSerial.h>
#include <TinyGPS++.h>

class GPS{

    private:
        /**
         * @brief holds latitude value obtained from GPS
	 * 
         */
        float latitude;


        /**
         * @brief holds longitude value obtained from GPS	
	 * 
         */
        float longitude;

	/**
	 *
	 * @brief holds the address of NeoSWSerial object
	 *
	 */
	NeoSWSerial *gpsSerialPtr;


    
    public:
	/**
	* @brief Construct a new GPS object and
	*        start serial communication at default baut rate using NeoSWSerial object address
	* 
	* @param gpsSerialPtr
	* @param baudrate
	*
	*/
        GPS(NeoSWSerial *gpsSerialPtr, int baudrate);

        /**
         * @brief updates latitude and longitude values
         * 
         */
        void update();


        /**
         * @brief returns latitude value
         * 
         * @return float 
         */
        float get_latitude();


        /**
         * @brief returns value 
         * 
         * @return float longitude
         */
        float get_longitude();

	/**
	 * @brief prints the latitude and longitude on lcd
	 *
	 * @param lcd
	 * @param row
	 * @param col
	 * 
	 */
	void print(LiquidCrystal_I2C lcd, uint8_t row, uint8_t col);
	 
};

#endif