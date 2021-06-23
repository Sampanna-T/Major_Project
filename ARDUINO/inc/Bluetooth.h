/**
 * @file Bluetooth.h
 * 
 * @author Sampanna T (kashi16sadan@gmail.com)
 * 
 * @brief contains all the functions definitions to control the bluetooth module
 * 
 * @version 0.1
 * 
 * @date 2021-03-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef BLUETOOTH_H__
#define BLUETOOTH_H__

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "Car.h"
#include <NeoSWSerial.h>

class Bluetooth{
    
    private:
	/**
	 *
	 * @brief holds the address of NeoSWSerial object
	 *
	 */
	NeoSWSerial *bluetoothSerialPtr;

        /**
         * @brief used to check whether the byte value is a number or not
         *        if the byte value is a number it returns true
         *        else it returns false
         * 
         * @param value 
         * @return true 
         * @return false 
         */
        bool is_number(byte value);

        /**
         * @brief used to check whether the byte value is a character or not
         *        if the byte value is a character it returns true
         *        else it returns false
         * 
         * @param value 
         * @return true 
         * @return false 
         */
        bool is_character(byte value);


    public:
        /**
         * @brief Construct a new Bluetooth object
         *        And begins serial communication using the address of NeoSWSerial object
	 *
         * @param bluetoothSerialPtr
         * @param baudrate
         */
        Bluetooth(NeoSWSerial *bluetoothSerialPtr, int baudrate);


	/**
	* @brief Construct a new Bluetooth object
	*        And begins serial communication using hardwareSerial
	*
	* 
	* @param baudrate
	*/
	Bluetooth::Bluetooth(int baudrate);

        
        /**
         * @brief performs functions of car object based on the value received by the bluetooth module 
         * 
         * @param car 
         */
        void start(Car *car);



	/**
 	* @brief performs functions of car object based on the value received by the bluetooth module 
 	* 
 	* @param car 
 	*/
	void Bluetooth::start_h(Car *car);


};

#endif