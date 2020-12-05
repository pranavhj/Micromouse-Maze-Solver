#pragma once
#include "../LandBasedRobot/LandBasedRobot.h"
#include <iostream>
#include <string>

/**
* @file LandBasedRobot.cpp
* @section DESCRIPTION
* .cpp file containing the implementation of the functions in LandBasedRobot class.
*/

fp::LandBasedRobot::LandBasedRobot(std::string name, double speed, double width, double length, double height, double capacity, int x, int y, char direction)
: name_{name}, speed_{speed}, width_{width}, length_{length}, height_{height}, capacity_{capacity}, x_{x}, y_{y}, direction_{direction} {}


fp::LandBasedRobot::LandBasedRobot(std::string name)
{std::cout<<name<<std::endl;}


fp::LandBasedRobot::LandBasedRobot(std::string name, int x, int y, char direction)
: name_{name}, x_{x}, y_{y}, direction_{direction} {}

fp::LandBasedRobot::LandBasedRobot()
{}