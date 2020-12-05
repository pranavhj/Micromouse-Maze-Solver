#include "../Algo/Algo.h"
#include<vector>
#include "../Maze/Maze.h"
#include "../API/API.h"
#include<string>



fp::Algo::Algo()
{std::cout<<"Algorithm Started"<<std::endl;}

char fp::Algo::Move_to(int prev_x,int prev_y,int current_x,int current_y,char direction,char prev_direction,fp::LandBasedRobot* wheeled)
{char direc_move='n';int d_m=0;
 if(prev_x==current_x)
 {if(current_y>prev_y)
     {direc_move='n';}
else
    {direc_move='s';}
 }
 
 else if(prev_y==current_y)
 {if(current_x>prev_x)
     {direc_move='e';}
else
    {direc_move='w';}}
    
if(direc_move=='n')d_m=0;                           
else if(direc_move=='w')d_m=1;
else if(direc_move=='s')d_m=2;
else if(direc_move=='e')d_m=3;

int d=0;
if(direction=='n')d=0;
else if(direction=='w')d=1;
else if(direction=='s')d=2;
else if(direction=='e')d=3;



if(direc_move==direction)
    {wheeled->MoveForward(current_x,current_y);}
else if(d_m-d==1)
    {wheeled->TurnLeft(current_x,current_y);
    wheeled->MoveForward(current_x,current_y);}
else if(d_m-d==2)
    {wheeled->TurnLeft(current_x,current_y);
    wheeled->TurnLeft(current_x,current_y);
    wheeled->MoveForward(current_x,current_y);}
else if(d_m-d==3)
    {wheeled->TurnRight(current_x,current_y);
    wheeled->MoveForward(current_x,current_y);
    }
else if(d_m-d==-1)
    {wheeled->TurnRight(current_x,current_y);
    wheeled->MoveForward(current_x,current_y);}
else if(d_m-d==-2)
    {wheeled->TurnRight(current_x,current_y);
    wheeled->TurnRight(current_x,current_y);
    wheeled->MoveForward(current_x,current_y);}
else if(d_m-d==-3)
    {wheeled->TurnLeft(current_x,current_y);
    wheeled->MoveForward(current_x,current_y);
        }
return direc_move;

}





void fp::Algo::Solve(fp::LandBasedRobot * wheeled)
{      
//color the center of the maze;


Maze_1.Maze::set_color(8,8,'r');
Maze_1.Maze::set_color(7,8,'r');
Maze_1.Maze::set_color(8,7,'r');
Maze_1.Maze::set_color(7,7,'r');

int current_x=0,current_y=0;char direction='n';
int prev_x=0,prev_y=0;char prev_direction='n';
//get the current cell of the robot; which is 0 0

std::vector<std::vector<int> >stack_;
std::vector<int>temp;temp.push_back(0);temp.push_back(0);                          //start from 0,0
stack_.push_back(temp);                          //push back 1st element into stack_

do
{
std::vector<int> arr=stack_.at(stack_.size()-1);
if((arr[0]==8  &&   arr[1]==8)  ||  (arr[0]==7  &&   arr[1]==8) ||(arr[0]==8  &&   arr[1]==7) ||(arr[0]==7  &&   arr[1]==7) )//goal
        break;
Maze_1.Maze::check_wall(current_x,current_y,direction);
//std::cerr<<current_x<<" "<<current_y<<Maze_1.Maze_[arr[0]][arr[1]].b<<" "<<Maze_1.Maze_[arr[0]][arr[1]].r<<" "<<Maze_1.Maze_[arr[0]][arr[1]].f<<" "<<Maze_1.Maze_[arr[0]][arr[1]].l<<std::endl;
stack_.erase(stack_.begin()+stack_.size()-1);

current_x=arr[0];current_y=arr[1];
prev_x=current_x;prev_y=current_y;//int t_x=stack_.at(stack_.size()-1).at(0);int t_y=stack_.at(stack_.size()-1).at(1);
int n=0;
if(Maze_1.Maze_[arr[0]][arr[1]].checked==0)
    {stack_.push_back(arr);
    Maze_1.Maze_[arr[0]][arr[1]].checked=1;API::setColor(arr[0],arr[1],'y');
        if(Maze_1.Maze_[arr[0]][arr[1]].b==0    &&    arr[1]>=1   &&   Maze_1.Maze_[arr[0]][arr[1]-1].checked==0)
            {std::vector<int>temp_;temp_.push_back(arr[0]);temp_.push_back(arr[1]-1);std::cerr<<"1"<<std::endl;
            stack_.push_back(temp_);
            }
        else if(Maze_1.Maze_[arr[0]][arr[1]].r==0    &&    arr[0]<=14  &&   Maze_1.Maze_[arr[0]+1][arr[1]].checked==0)
            {std::vector<int>temp_;temp_.push_back(arr[0]+1);temp_.push_back(arr[1]);std::cerr<<"2"<<std::endl;
            stack_.push_back(temp_);
            }
        else if(Maze_1.Maze_[arr[0]][arr[1]].f==0    &&    arr[1]<=14  &&   Maze_1.Maze_[arr[0]][arr[1]+1].checked==0)                       //nodes pushed in reverse order of preference so that the path generated will have last element as the 1st element in preference
            {std::vector<int>temp_;temp_.push_back(arr[0]);temp_.push_back(arr[1]+1);std::cerr<<"3"<<std::endl;
            stack_.push_back(temp_);}
        else if(Maze_1.Maze_[arr[0]][arr[1]].l==0    &&    arr[0]>=1  &&   Maze_1.Maze_[arr[0]-1][arr[1]].checked==0)
            {std::vector<int>temp_;temp_.push_back(arr[0]-1);temp_.push_back(arr[1]);std::cerr<<"4"<<std::endl;
            stack_.push_back(temp_);
            }
        else
            {//backtrack
            
            std::cerr<<"backtrack"<<std::endl;
            stack_.erase(stack_.begin()+stack_.size()-1);//s.pop();
            
            n++;
            }
            
    }
    else
        {n++;}
        
        current_x=stack_.at(stack_.size()-1).at(0);current_y=stack_.at(stack_.size()-1).at(1);if(n!=0){Maze_1.Maze_[current_x][current_y].checked=0;API::clearColor(arr[0],arr[1]);}
        std::cerr<<current_x<<" "<<current_y<<" "<<direction<<std::endl;
        direction=Move_to(prev_x,prev_y,current_x,current_y,direction,prev_direction,wheeled);                //gives direction and also moves the robot
        }


while(stack_.size()!=0);
if(stack_.size()==0)
{std::cout<<"Maze is Unsolvable<<std::endl";}

API::clearAllColor();
Maze_1.Maze::set_color(8,8,'r');
Maze_1.Maze::set_color(7,8,'r');
Maze_1.Maze::set_color(8,7,'r');
Maze_1.Maze::set_color(7,7,'r');
for(unsigned int i=0;i<stack_.size();i++)
    {std::vector<int> temp;
    temp.push_back(stack_.at(i).at(0));
    temp.push_back(stack_.at(i).at(1));
    API::setColor(temp[0],temp[1],'y');
    
    }

if(stack_.size()>0)
std::cerr<<"Destination Reached"<<std::endl;
API::ackReset();
}
