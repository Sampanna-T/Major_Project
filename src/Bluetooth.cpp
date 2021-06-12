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

/*Declaring SoftwareSerial object*/
SoftwareSerial bluetooth_serial(0,0);

/**
 * @brief Construct a new Bluetooth object
 *        And initializes the SoftwareSerial object with given rx and tx
 * @param rx 
 * @param tx 
 */
Bluetooth::Bluetooth(uint8_t rx, uint8_t tx){
   bluetooth_serial=SoftwareSerial(rx,tx);//initializing the pins for SoftwareSerial
   bluetooth_serial.begin(9600);//setting up the default baud rate for bluetooth communication
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
void Bluetooth::start(Car car){

    //whenever there is data to be read by the bluetooth module this while loop will be executed
    while(bluetooth_serial.available()){//while(bluetooth.available()
       
        byte ascii_value = bluetooth_serial.read();//read the data if received any
        
        if(is_number(ascii_value)){//check if received data is number

            car.set_speed(ascii_value-48);
        
        }
        else if(is_character(ascii_value)){//check if received data is a character
            
            if(char(ascii_value)=='u'){
                car.move_forward();//car moves forward
            }
            else if(char(ascii_value)=='d'){
                car.move_backward();//car moves backward
            }
            else if(char(ascii_value)=='l'){
                car.move_left();//car moves left
            }
            else if(char(ascii_value)=='r'){
                car.move_right();//car moves right
            }
            else if(char(ascii_value)=='s'){
                car.stop_now();//car stops
            }
            else{
                Serial.println("Unknown Character!!!");//for testing purpose only
            }  

        }
        else{
            
            Serial.println("Unknown Character!!");//for testing purpose only
            
        }
            
        
    }//while(bluetooth.available())

}