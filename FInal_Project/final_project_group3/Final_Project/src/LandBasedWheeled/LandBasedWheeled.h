#pragma once
#include "../LandBasedRobot/LandBasedRobot.h"
#include "../API/API.h"
#include <string>
#include <iostream>



/**
* @file LandBasedWheeled.h
* @section DESCRIPTION
* .h file containing the prototype of the functions in LandBasedWheedled class.
*/

namespace fp{
    
    /*! \class LandBasedWheeled
    \brief  Inherited class 

    This class is a concrete class. It has a pointer as a data attribute.It has a deep copy constructor.Has all overriden methods.
*/
class LandBasedWheeled : public LandBasedRobot, public API
{
	public:
        //Constructor
        
        /**
       * Constructor implementation.
       * @see LandBasedWheeled
       * @brief Inititalizes the class attributes with default values.
       * @param name.
       * @param x.
       * @param y.
       * @param wheel_number.
       * @param wheel_type
       */
		LandBasedWheeled(std::string name, int x, int y, char direction, int wheel_number_param = 0, std::string wheel_type_param = "default");
		
        //Deep Copy
        
        /**
       * Deep Copy Constructor implementation.
       * @see LandBasedWheeled
       * @brief Copy constructor for LandBasedWheel objects using deep copy
       * @param source Object of LandBasedWheel class
       */
        //LandBasedWheeled(const LandBasedWheeled &source): LandBasedRobot {*source.wheel_type} {}
        
        LandBasedWheeled(std::string name);
        LandBasedWheeled();
        //Member function prototype
        /**
       * An overriden member.
       * @see GoUp()
       * @brief A function that moves robot in up direction called by LandBasedWheeled
       * @param x  position is the first argument.
       * @param y position is the second argument.
       */
		virtual void MoveForward(int x_,int y_) override;
        
        /**
       * An overriden member.
       * @see TurnLeft()
       * @brief A function that moves robot in left direction called by LandBasedWheeled
       * @param x  position is the first argument.
       * @param y position is the second argument.
       */
		virtual void TurnLeft(int x_,int y_) override;
        /**
       * An overriden member.
       * @see TurnRight()
       * @brief A function that moves robot in right direction called by LandBasedWheeled
       * @param x  position is the first argument.
       * @param y position is the second argument.
       */
		virtual void TurnRight(int x_,int y_) override;
       
        
        /**
       * A method to increase speed.
       * @see Release()
       * @brief A function that releases the object called by LandBasedWheeled
       * @param int x is the only argument.
       * @return increased speed int type
       */
        void SpeedUp();
        
        //Mutators / Setters
        
        /**
       * @see set_wheel_number
       * @brief set the number of wheels of the robot
       * @param wheels Number of wheels of the robot
       */
        void set_wheel_number(int wheels){
            wheel_number = wheels;
        }
        
        /**
       * @see set_wheel_type
       * @brief set the wheel type of the robot
       * @param wheel_type_param Wheel type of the robot
       */
        void set_wheel_type(std::string wheel_type_param){
            *wheel_type = wheel_type_param;
        }
		
        //Accessors / Getters
        
        /**
       * @see get_wheel_number
       * @brief get the number of wheels of the robot
       */
        int get_wheel_number() const{
            return wheel_number;
        }
        
        /**
       * @see get_wheel_type
       * @brief get the wheel type of the robot
       */
        std::string* get_wheel_type() const{
            return wheel_type;
        }
		    
        //Destructor
        /**
       * Virtual destructor for LandBasedWheeled class
       * @see LandBasedWheeled
       */
        virtual ~LandBasedWheeled();
       
    //Class attributes
	public:
		int wheel_number;
        /**< Robot wheels*/
		std::string *wheel_type;
        /**< string pointer to wheeltype */

};//--class LandBasedWheeled
} //--namespace fp