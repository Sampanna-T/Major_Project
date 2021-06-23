/**
 * @file Ultrasonic.h
 * 
 * @author Sampanna T (kashi16sadan@gmail.com)
 * 
 * @brief contain definitions of function/s to measure distance using ultrasonic sensor
 * 
 * @version 0.1
 * 
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef ULTRASONIC_H__
#define ULTRASONIC_H__

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


#include <LiquidCrystal_I2C.h>
#include <Wire.h>

class Ultrasonic{

    private:
        /**
         * @brief holds distance between an obstancle and the transmitter of ultrasonic sensor
         * 
         */
        float distance;

        /**
         * @brief holds the pin number of echo pin
         * 
         */
        uint8_t echo;

        /**
         * @brief holds the pin number of trigger pin
         * 
         */
        uint8_t trigger;

        /**
         * @brief holds the pin number of buzzer pin
         * 
         */
        uint8_t buzzer;
    
    public:
        /**
         * @brief Construct a new Ultrasonic object
         *        sets the state of echo and trigger pin along with the buzzer
         * 
         * @param echo 
         * @param trigger 
	 * @param buzzer
	 *
         */
        Ultrasonic(uint8_t echo, uint8_t trigger, uint8_t buzzer);

        /**
         * @brief returns value in the distance variable
         * 
         * @return float 
	 *
         */
        float get_distance();


        /**
         * @brief prints the distance value in the lcd at given row,column
         * 
	 * @param lcd
         * @param row
	 * @param col
	 *
         */
	void print(LiquidCrystal_I2C lcd, uint8_t row, uint8_t col);

	/**
	* @brief buzzer turns off if state = 0 and turns on otherwise
	*        
	* @param state
	* 
	*/
	void Ultrasonic::set_buzzer(uint8_t state);
	
};

#endif