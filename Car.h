/**
 * @file Car.h
 * 
 * @author Sampanna T (kashi16sadan@gmail.com)
 * 
 * @brief contains all the functions definitions needed to control 4 motors 
 * 
 * @version 0.1
 * 
 * @date 2021-03-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef CAR_H__
#define CAR_H__


#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class Car{
private:
	int speed;//speed variable used to hold the speed value
	uint8_t pwm;//pwm variable holds the pwm pin number
	uint8_t motor_rightCTRL1;//pwm variable holds the motor_rightCTRL1 pin number
	uint8_t motor_rightCTRL2;//pwm variable holds the motor_rightCTRL2 pin number
	uint8_t motor_leftCTRL1;//pwm variable holds the motor_leftCTRL1 pin number
	uint8_t motor_leftCTRL2;//pwm variable holds the motor_leftCTRL2 pin number

public:
	
	/**
	 * @brief Construct a new Car:: Car object
	 * used to initialize the motor control pins with default pin numbers
	 * 
	 */
	Car();


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
	Car(uint8_t motor_rightCTRL1, uint8_t motor_rightCTRL2, uint8_t motor_leftCTRL1, uint8_t motor_leftCTRL2, uint8_t pwm);
	

	/**
	 * @brief performs default initialization of motor control pins
	 * 
	 */
	void initialize();


	/**
	 * @brief performs intialization of motor control pins with given pin numbers
	 * 
	 */
	void initialize(uint8_t motor_rightCTRL1, uint8_t motor_rightCTRL2, uint8_t motor_leftCTRL1, uint8_t motor_leftCTRL2, uint8_t pwm);
	

	/**
	 * @brief makes all the motors rotate in the forward direction w.r.t the driver
	 * 
	 */
	void move_forward();
	

	/**
	 * @brief makes all the motors rotate in the backward direction w.r.t the driver
	 * 
	 */
	void move_backward();
	

	/**
	 * @brief makes the left motors rotate in forward direction 
	 * 
	 */
	void move_left();


	/**
	 * @brief makes the right motors rotate in forward direction
	 * 
	 */
	void move_right();


	/**
	 * @brief stops all the motors
	 * 
	 */
	void stop_now();


	/**
	 * @brief Sets the speed of all the motors at once
	 * 
	 * @param speed 
	 */
	void set_speed(int speed);

};

#endif