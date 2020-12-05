#pragma once
#include <string>
#include "../LandBasedRobot/LandBasedRobot.h"
#include "../API/API.h"
#include <iostream>


namespace fp{
    
    /*! \class LandBasedTracked
    \brief  Inherited class 

    This class is a concrete class. It has a pointer as a data attribute.It has a deep copy constructor.Has all overriden methods.
*/
class LandBasedTracked : public LandBasedRobot ,public API {

	public:
        //Constructor
        
        /**
       * Constructor implementation.
       * @see LandBasedTracked
       * @brief Inititalizes the calss attributes with default values.
       * @param name.
       * @param x.
       * @param y.
       * @param track_type.
       */
		LandBasedTracked(std::string name,int x, int y, char direction, std::string track_type_param = "default");
		
        //Deep Copy
        
        /**
       * Deep Copy Constructor implementation.
       * @see LandBasedTracked
       * @brief Copy constructor for LandBasedTracked objects using deep copy
       * @param source Object of LandBasedTracked class
       */
        //LandBasedTracked(const LandBasedTracked &source): LandBasedRobot {*source.track_type} {}
		
        //Member function prototype
        /*
       * A overriden member.
       * @see GoUp()
       * @brief A function that moves robot in up direction called by LandBasedTracked
       * @param x  position is the first argument.
       * @param y position is the second argument.
       */
		virtual void MoveForward(int x, int y) override;
        
        /**
       * A overriden member.
       * @see TurnLeft()
       * @brief A function that moves robot in left direction called by LandBasedTracked
       * @param x  position is the first argument.
       * @param y position is the second argument.
       */
		virtual void TurnLeft(int x, int y) override;
        
         /**
       * A overriden member.
       * @see TurnRight()
       * @brief A function that moves robot in right direction called by LandBasedTracked
       * @param x  position is the first argument.
       * @param y position is the second argument.
       */
		virtual void TurnRight(int x_,int y_) override;
        
        
        //Mutators / Setters
        /**
       * @see set_track_type
       * @brief set the track type of the robot
       * @param trac_type_param Track type of the robot
       */
        void set_track_type(std::string track_type_param){
            *track_type = track_type_param;
        }
        
        //Accessors / Getters
        
        /**
       * @see get_track_type
       * @brief get the track type of the robot
       */
        std::string* get_track_type() const{
            return track_type;
        }
	
            
        //Destructor
        /**
       * Virtual destructor for LandBasedTracked class
       * @see LandBasedTracked
       */
        virtual ~LandBasedTracked();
        
	protected:
        std::string* track_type;
        /**< string pointer to Track type */
		
};//--class LandBasedTracked
} //--namespace fp