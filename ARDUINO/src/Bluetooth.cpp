/**
 * @file Bluetooth.cpp
 * 
 * @author Sampanna T (kashi16sadan@gmail.com)
 * 
 * @brief contains all the functions necessary to control the Bluetooth module
 * 
 * @version 0.1
 * 
 * @date 2021-03-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Bluetooth.h"



/**
* @brief Construct a new Bluetooth object
*        And begins serial communication using the address of NeoSWSerial object
*
* @param bluetoothSerialPtr
* @param baudrate
*/
Bluetooth::Bluetooth(NeoSWSerial *bluetoothSerialPtr, int baudrate){
    
    this->bluetoothSerialPtr = bluetoothSerialPtr;
    this->bluetoothSerialPtr->begin(baudrate);		//setting up the default baud rate for bluetooth communication
}


/**
* @brief Construct a new Bluetooth object
*        And begins serial communication using hardwareSerial
*
* 
* @param baudrate
*/
Bluetooth::Bluetooth(int baudrate){
    Serial.begin(baudrate);		//setting up the default baud rate for bluetooth communication
}


/**
 * @brief used to check whether the byte value is a number or not
 *        if the byte value is a number it returns true
 *        else it returns false
 * 
 * @param value 
 * @return true 
 * @return false 
 */
bool Bluetooth::is_number(byte value){
    //ASCII values of 0-9 are 48-57
    if(value>=48 && value<=57)
        return true; 
    else
        return false;
}


/**
 * @brief used to check whether the byte value is a character or not
 *        if the byte value is a character it returns true
 *        else it returns false
 * 
 * @param value 
 * @return true 
 * @return false 
 */
bool Bluetooth::is_character(byte value){
    //ASCII values of A-Z,a-z are 65-90,97-122
    if((value>=65 && value<=90) || (value>=97 && value<=122))
        return true; 
    else
        return false;
}


/**
 * @brief performs functions of car object based on the value received by the bluetooth module 
 * 
 * @param car 
 */
void Bluetooth::start(Car *car){

    //whenever there is data to be read by the bluetooth module this while loop will be executed
    while(bluetoothSerialPtr->available()){//while(bluetoothSerialPtr->available())
       
        byte ascii_value = bluetoothSerialPtr->read();	//read the data if received any
    
        if(is_number(ascii_value)){//check if received data is number

            car->set_speed(ascii_value-48);		//car speed is set
        
        }
        else if(is_character(ascii_value)){//check if received data is a character
            
            if(char(ascii_value)=='u'){
                car->move_forward();			//car moves forward
                Serial.println("movefront");		//for testing purpose only
            }
            else if(char(ascii_value)=='d'){
                car->move_backward();			//car moves backward
                Serial.println("moveback");		//for testing purpose only
            }
            else if(char(ascii_value)=='l'){
                car->move_left();			//car moves left
                Serial.println("moveleft");		//for testing purpose only
            }
            else if(char(ascii_value)=='r'){
                car->move_right();			//car moves right
                Serial.println("moveright");		//for testing purpose only
            }
            else if(char(ascii_value)=='s'){
                car->stop_now();			//car stops
                Serial.println("stop");			//for testing purpose only
            }
            else{
                Serial.println("Unknown Character!!!");	//for testing purpose only
            }  

        }
        else{
            
            Serial.println("Unknown Character!!");	//for testing purpose only
            
        }
            
        
    }//while(bluetoothSerialPtr->available())

}


/**
 * @brief performs functions of car object based on the value received by the bluetooth module 
 * 
 * @param car 
 */
void Bluetooth::start_h(Car *car){

    //whenever there is data to be read by the bluetooth module this while loop will be executed
    while(Serial.available()){//while(Serial.available())
       
        byte ascii_value = Serial.read();		//read the data if received any
    
        if(is_number(ascii_value)){//check if received data is number

            car->set_speed(ascii_value-48);		//car speed is set
        
        }
        else if(is_character(ascii_value)){//check if received data is a character
            
            if(char(ascii_value)=='u'){
                car->move_forward();			//car moves forward
		Serial.println("movefront");		//for testing purpose only
            }
            else if(char(ascii_value)=='d'){
                car->move_backward();			//car moves backward
		Serial.println("moveback");		//for testing purpose only
            }
            else if(char(ascii_value)=='l'){
                car->move_left();			//car moves left
		Serial.println("moveleft");		//for testing purpose only
	    }
            else if(char(ascii_value)=='r'){
                car->move_right();			//car moves right
		Serial.println("moveright");		//for testing purpose only
            }
            else if(char(ascii_value)=='s'){
                car->stop_now();			//car stops
		Serial.println("stop");			//for testing purpose only
            }
            else{
                Serial.println("Unknown Character!!!");	//for testing purpose only
            }  

        }
        else{
            
            Serial.println("Unknown Character!!");	//for testing purpose only
            
        }
            
        
    }//while(Serial.available())

}