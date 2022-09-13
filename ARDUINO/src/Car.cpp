/**
 * @file Car.cpp
 * 
 * @author Sampanna T (kashi16sadan@gmail.com)
 * 
 * @brief Contains implementation of all functions necessary to control 4 motors
 * 
 * @version 0.1
 * 
 * @date 2021-03-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Car.h"

/**
 * @brief Construct a new Car:: Car object
 * used to initialize the motor control pins with default pin numbers
 * 
 */
Car::Car(){
        initialize();
}

/**
 * @brief Construct a new Car:: Car object
 * used to initialize the motor control pins with user given pin numbers
 * 
 * @param motor_rightCTRL1 
 * @param motor_rightCTRL2 
 * @param motor_leftCTRL1 
 * @param motor_leftCTRL2 
 * @param pwm 
 */
Car::Car(uint8_t motor_rightCTRL1, uint8_t motor_rightCTRL2, uint8_t motor_leftCTRL1, uint8_t motor_leftCTRL2, uint8_t pwm){
        initialize(motor_rightCTRL1, motor_rightCTRL2, motor_leftCTRL1, motor_leftCTRL2, pwm);
}

/**
 * @brief performs default initialization of motor control pins
 * 
 */
void Car::initialize(){
/*initializing all the motor control pins along with the pwm pin*/
	motor_rightCTRL1 = 12;		//configuring rightCTRL1 pin(connected to pin7 of L293d)
	motor_rightCTRL2 = 11;		//configuring rightCTRL2 pin(connected to pin2 of L293d)
	motor_leftCTRL1 = 13;		//configuring leftCTRL1 pin(connected to pin10 of L293d)
	motor_leftCTRL2 = A0;		//configuring leftCTRL2 pin(connected to pin15 of L293d)
	
	pwm = 3;			//pin to control the speed of the motors

/*initialize the pwm pin as output and setting speed to 0*/	
//pinMode(pwm,OUTPUT);setting PWM pin as output
      	speed = 0;

/*initializing all the control pins as OUTPUT*/
        pinMode(motor_rightCTRL1,OUTPUT);
        pinMode(motor_rightCTRL2,OUTPUT);
        pinMode(motor_leftCTRL1,OUTPUT);
        pinMode(motor_leftCTRL2,OUTPUT);
}

/**
 * @brief performs intialization of motor control pins with given pin numbers
 * 
 */
void Car::initialize(uint8_t motor_rightCTRL1,uint8_t motor_rightCTRL2,uint8_t motor_leftCTRL1,uint8_t motor_leftCTRL2,uint8_t pwm){
/*initializing all the motor control pins along with the pwm pin*/
	this->motor_rightCTRL1 = motor_rightCTRL1;		//configuring rightCTRL pin1(connected to pin7 of L293d)
	this->motor_rightCTRL2 = motor_rightCTRL2;		//configuring rightCTRL pin2(connected to pin2 of L293d)
	this->motor_leftCTRL1 = motor_leftCTRL1;		//configuring leftCTRL pin1(connected to pin10 of L293d)
	this->motor_leftCTRL2 = motor_leftCTRL2;		//configuring leftCTRL pin2(connected to pin15 of L293d)
	
        if(pwm!=3 || pwm!=5 || pwm!=6 || pwm!=9 || pwm!=10 || pwm!=11)
	this->pwm = pwm;		//deafault initialization of pwm pin if any pin other than 3,5,6,9,10,11 is chosen
        else
        this->pwm = pwm;	//set user given pwm pin as pwm pin

/*initialize the pwm pin as output and setting speed to 0*/	
	pinMode(pwm,OUTPUT);	//setting PWM pin as output
      	speed = 0;		//initializing the speed to 0

/*initializing all the control pins as OUTPUT*/
        pinMode(motor_rightCTRL1,OUTPUT);
        pinMode(motor_rightCTRL2,OUTPUT);
        pinMode(motor_leftCTRL1,OUTPUT);
        pinMode(motor_leftCTRL2,OUTPUT);
}

/**
 * @brief makes all the motors rotate in the forward direction w.r.t the driver
 * 
 */
void Car::move_forward(){
	/*Right wheels with respect to driver in clockwise direction*/
        digitalWrite(motor_rightCTRL1,HIGH);
        digitalWrite(motor_rightCTRL2,LOW);
	
	/*Left wheels with respect to driver in clockwise direction*/
        digitalWrite(motor_leftCTRL1,HIGH);
        digitalWrite(motor_leftCTRL2,LOW);
}

/**
 * @brief makes all the motors rotate in the backward direction w.r.t the driver
 * 
 */
void Car::move_backward(){
	/*Right wheels with respect to driver in anti-clockwise direction*/
        digitalWrite(motor_rightCTRL1,LOW);
        digitalWrite(motor_rightCTRL2,HIGH);

	/*Left wheels with respect to driver in anti-clockwise direction*/
        digitalWrite(motor_leftCTRL1,LOW);
        digitalWrite(motor_leftCTRL2,HIGH);
 
}  

/**
 * @brief makes the left motors rotate in forward direction 
 * 
 */
void Car::move_left(){
	/*Right wheels with respect to driver in clockwise direction*/
	digitalWrite(motor_rightCTRL1,HIGH);
        digitalWrite(motor_rightCTRL2,LOW);

	digitalWrite(motor_leftCTRL1,LOW);
	digitalWrite(motor_leftCTRL2,LOW);
}

/**
 * @brief makes the right motors rotate in forward direction
 * 
 */
void Car::move_right(){
	/*Left wheels with respect to driver in clockwise direction*/
	digitalWrite(motor_leftCTRL1,HIGH);
        digitalWrite(motor_leftCTRL2,LOW);
	
	digitalWrite(motor_rightCTRL1,LOW);
	digitalWrite(motor_rightCTRL1,LOW);
}

/**
 * @brief stops all the motors
 * 
 */
void Car::stop_now(){
        digitalWrite(motor_rightCTRL1,LOW);
        digitalWrite(motor_rightCTRL2,LOW);

        digitalWrite(motor_leftCTRL1,LOW);
        digitalWrite(motor_leftCTRL2,LOW);
}

/**
 * @brief Sets the speed of all the motors at once
 * 
 * @param speed 
 */
void Car::set_speed(int speed){
    this->speed = speed*255/9;		//mapping the values of speed from 0-9 to 0-255
    analogWrite(pwm,this->speed);	//outputting the speed to pwm pin
/* The frequecy for pwm is 976.56Hz for pins 4,13 whereas 490.20 for other pins(even in our case)*/
}


