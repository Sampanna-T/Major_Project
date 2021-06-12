/**
 * @file Ultrasonic.cpp
 * 
 * @author Sampanna T (kashi16sadan@gmail.com)
 * 
 * @brief contain implementaion of function/s to measure distance using ultrasonic sensor
 * 
 * @version 0.1
 * 
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Ultrasonic.h"


/**
 * @brief Construct a new Ultrasonic:: Ultrasonic object
 *        sets the state of echo and trigger pin along with the buzzer
 * @param echo 
 * @param trigger 
 */
Ultrasonic::Ultrasonic(uint8_t echo, uint8_t trigger, uint8_t buzzer){
    /*configuring all the pins as either INPUT or OUTPUT*/
    this->echo = echo;
    this->trigger = trigger;
    this->buzzer = buzzer;

    pinMode(echo, INPUT);
    pinMode(trigger, OUTPUT);
    pinMode(buzzer, OUTPUT);
    digitalWrite(trigger, LOW);

}

/**
 * @brief returns distance between sensor and detected object
 * 
 * 
 * @return float 
 */
float Ultrasonic::get_distance(){
    /*generating a pulse of duration 10 micro seconds*/

    digitalWrite(trigger,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger,LOW);

    float time = pulseIn(echo,HIGH);//checks for how long the echo pin is HIGH

    distance = (time/2.0)*0.0343;//calculates the distance between the obstacle and the sensor


    return distance;
}


/**
* @brief prints the distance value in the lcd at given row,column
* 
* @param lcd
* @param row 
* @param col
* 
*/
void Ultrasonic::print(LiquidCrystal_I2C lcd, uint8_t row, uint8_t col){
   
        String d = "";//creating a string so that it can be passed in lcd.print function
        d += distance;
        lcd.setCursor(col,row);//initialize the position from where the printing is done
        lcd.print(d);

}


/**
* @brief buzzer turns off if state = 0 and turns on otherwise
*         
* @param state
*
*/
void Ultrasonic::set_buzzer(uint8_t state){
     if(state==LOW){
     	digitalWrite(buzzer,LOW);
     }
     else{
     	digitalWrite(buzzer,HIGH);
     }
}