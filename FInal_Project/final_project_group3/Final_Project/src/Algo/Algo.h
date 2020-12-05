#pragma once
#include "../LandBasedRobot/LandBasedRobot.h"
#include "../LandBasedTracked/LandBasedTracked.h"
#include "../LandBasedWheeled/LandBasedWheeled.h"
#include "../Maze/Maze.h"
#include "../API/API.h"
namespace fp
{

class Algo:public Maze
{
public:
    Algo();
    
void Solve(LandBasedRobot * wheeled);

char Move_to(int prev_x,int prev_y,int current_x,int current_y,char direction,char prev_direction,LandBasedRobot *wheeled);




    protected:
Maze Maze_1;




};

}

