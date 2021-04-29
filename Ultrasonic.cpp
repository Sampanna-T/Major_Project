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

unsigned long end_time=0;//holds millis value for lcd to clear
unsigned long buzzer_time=0;//holds time for buzzer to turn off

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
    end_time=millis()+200;
}

/**
 * @brief returns distance between sensor and detected object
 * 
 * @param lcd 
 * @return float 
 */
float Ultrasonic::get_distance(LiquidCrystal_I2C lcd){
    /*generating a pulse of duration 10 micro seconds*/
    digitalWrite(trigger,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger,LOW);

    float time = pulseIn(echo,HIGH);//checks for how long the echo pin is HIGH

    distance = (time/2)*0.0343;//calculates the distance between the obstacle and the sensor

    if(distance>=2 && distance<=10){
        String d = "";
        d +=distance;
        
        if(millis()>=end_time){//update the lcd only after 200ms
             lcd.clear();
             lcd.setCursor(0,0);
             lcd.print("Distance = "+d);
             digitalWrite(buzzer,HIGH);
             buzzer_time=millis()+500;
             end_time = millis()+200;
        }
    }
    else{
        if(millis()>=buzzer_time){//turf off the buzzer only after 500ms once obstactle is identified
        digitalWrite(buzzer,LOW);
        lcd.clear();
        }
    }

    return distance;
}