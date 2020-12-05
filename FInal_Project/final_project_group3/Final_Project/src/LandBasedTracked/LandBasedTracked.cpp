#include "../LandBasedTracked/LandBasedTracked.h"
#include <string>
#include <iostream>

/**
* @file LandBasedTracked.cpp
* @section DESCRIPTION
* .cpp file containing the implementation of the functions in LandBasedTracked class.
*/

    fp::LandBasedTracked::LandBasedTracked(std::string name,int x, int y, char direction, std::string track_type_param)
    : LandBasedRobot(name, x, y, direction) {
        track_type = new std::string;
        *track_type = track_type_param;
    }
    
    

	void fp::LandBasedTracked::MoveForward(int x_,int y_) {
		std::cout << "LandBasedTracked: MoveForward is called\n" << std::endl;
        API::moveForward();
    }
	
	void fp::LandBasedTracked::TurnLeft(int x ,int y) {
		std::cout << "LandBasedTracked: TurnLeft is called\n" << std::endl;
        API::turnLeft();
	}
	void fp::LandBasedTracked::TurnRight(int x_,int y_) {
		std::cout << "LandBasedTracked: TurnRight is called\n" << std::endl;
        API::turnRight();
	}
	
    fp::LandBasedTracked::~LandBasedTracked(){delete track_type;}