#include "../LandBasedWheeled/LandBasedWheeled.h"
#include <iostream>
#include <string>

/**
* @file LandBasedWheeled.cpp
* @section DESCRIPTION
* .cpp file containing the implementation of the functions in LandBasedWheedled class.
*/

	fp::LandBasedWheeled::LandBasedWheeled(std::string name, int x, int y, char direction, int wheel_number_param, std::string wheel_type_param)
    : LandBasedRobot(name,x,y, direction), wheel_number {wheel_number_param} {
        wheel_type = new std::string;
        *wheel_type = wheel_type_param;
        }
        
    fp::LandBasedWheeled::LandBasedWheeled(std::string name): fp::LandBasedRobot::LandBasedRobot("name", 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0, 'N')
    {}
    
    //fp::LandBasedWheeled::LandBasedWheeled()
    //{}
 
    
    void fp::LandBasedWheeled::MoveForward(int x_,int y_) {
		std::cout << "LandBasedWheeled: MoveForward is called\n" << std::endl;
        API::moveForward();
	}
	void fp::LandBasedWheeled::TurnLeft(int x_,int y_) {
		std::cout << "LandBasedWheeled: TurnLeft is called\n" << std::endl;
        API::turnLeft();
        
	}
	void fp::LandBasedWheeled::TurnRight(int x_,int y_) {
		std::cout << "LandBasedWheeled: TurnRight is called\n" << std::endl;
        API::turnRight();
	}
    void fp::LandBasedWheeled::SpeedUp()
    
    {
        std::cout<<"Speed Up"<<std::endl;}
   
    
    
    fp::LandBasedWheeled::~LandBasedWheeled(){delete wheel_type;}
