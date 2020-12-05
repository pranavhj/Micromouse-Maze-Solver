#pragma once
#include <string>
#include <iostream>



namespace fp{
    


class LandBasedRobot{
	public:
    
        //Constructors
        
        /**
       * Constructor implementation.
       * @see LandBasedRobot
       * @brief Inititalizes all the calss attributes with default values.
       * @param name.
       * @param speed.
       * @param width.
       * @param length.
       * @param height.
       * @param capacity
       * @param x
       * @param y
       */
       LandBasedRobot();
       LandBasedRobot(std::string name, int x, int y, char direction);
       
        LandBasedRobot(std::string name = "name", double speed = 0.0, double width = 0.0, double length = 0.0, double height = 0.0, double capacity = 0.0, int x= 0, int y = 0, char direction = 'N');
		LandBasedRobot(std::string name);
        /**
       * Three parameter c
       * A pure virtual member.
       * @see TurnLeft()
       * @brief Make the robot turn left
       * @param x position is the first argument.
       * @param y position is the second argument.
       */
		virtual void TurnLeft(int x,int y) = 0;
        
        /**
       * A pure virtual member.
       * @see TurnRight()
       * @brief Makes the robot turn right
       * @param x  position is the first argument.
       * @param y position is the second argument.
       */
		virtual void TurnRight(int x,int y) = 0;
        virtual void MoveForward(int x,int y) = 0;
         
		
		//Mutators / Setters
        /**
       * @see set_name
       * @brief set the name of the robot
       * @param name Name of the robot
       */
        void set_name(std::string name){
            name_ = name;
        }
        
        /**
       * @see set_speed
       * @brief set the speed of the robot
       * @param speed Speed of the robot
       */
        void set_speed(double speed){
            speed_ = speed;
        }
        
        /**
       * @see set_width
       * @brief set the width of the robot
       * @param width Width of the robot
       */
        void set_width(double width){
            width_ = width;
        }
        
        /**
       * @see set_length
       * @brief set the length of the robot
       * @param length Length of the robot
       */
        void set_length(double length){
            length_ = length;
        }
        
        /**
       * @see set_height
       * @brief set the height of the robot
       * @param height Height of the robot
       */
        void set_height(double height){
            height_ = height;
        }
        
        /**
       * @see set_capacity
       * @brief set the capacity of the robot
       * @param capacity Capacity of the robot
       */
        void set_capacity(double capacity){
            capacity_ = capacity;
        }
        
        /**
       * @see set_x
       * @brief set the x poisition of the robot
       * @param x X position of the robot
       */
        void set_x(int x){
            x_ = x;
        }
        
        /**
       * @see set_y
       * @brief set the y position of the robot
       * @param y Y position of the robot
       */
		void set_y(int y){
            y_ = y;
        }
        
         /**
       * @see set_direction
       * @brief set the direction the robot is facing in the maze
       * @param direction Direction of the robot in the maze
       */
		void set_direction(int direction){
            direction_ = direction;
        }
        
        
        //Accessors / Getters
        /**
       * @see get_name
       * @brief get the name of the robot
       */
        std::string get_name() const{
            return name_;
        }
        
        /**
       * @see get_speed
       * @brief get the speed of the robot
       */
        double get_speed() const{
            return speed_;
        }
        
        /**
       * @see get_width
       * @brief get the width of the robot
       */
        double get_width() const{
            return width_;
        }
        
        /**
       * @see get_length
       * @brief get the length of the robot
       */
        double get_length() const{
            return length_;
        }
        
        /**
       * @see get_height
       * @brief get the height of the robot
       */
        double get_height() const{
            return height_;
        }
        
        /**
       * @see get_capacity
       * @brief get the capacity of the robot
       */
        double get_capacity() const{
            return capacity_;
        }
        
        /**
       * @see get_x
       * @brief get the x position of the robot
       */
        int get_x() const{
            return x_;
        }
        
        /**
       * @see get_y
       * @brief get the y position of the robot
       */
		int get_y() const{
            return y_;
        }
        
         /**
       * @see get_direction
       * @brief return the direction that the robot is facing in the maze
       */
		char get_direction() const{
            return direction_;
        }

        //Destructors
        /**
       * Virtual destructor for LandBasedRobot class
       * @see LandBasedRobot
       */
        virtual ~LandBasedRobot(){}

    //member attributes
	protected: 
		std::string name_;
        /**< Robot name */
		double speed_;
        /**< Robot speed */
		double width_;
        /**< Robot width */
		double length_;
        /**< Robot length */
		double height_;
        /**< Robot height */
		double capacity_;
        /**< Robot capacity */
        int x_;
        /**< Robot x position */
		int y_;
        /**< Robot y position */
        char direction_;
	
};//--class LandBasedRobot
} //--namespace fp
