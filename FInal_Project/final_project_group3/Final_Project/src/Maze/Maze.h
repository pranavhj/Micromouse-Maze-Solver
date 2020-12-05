
#pragma once
#include "../API/API.h"
#include <string>
namespace fp
{

class Maze:public API{
public:
   
    
int *get_dimensions();

void check_wall(int x,int y,char direction);

void set_wall(int x,int y,std::string direc);

void set_color(int x,int y,char color);

Maze();





    

struct node{
    bool f,r,l,b;char color;
bool checked;
};


node Maze_[15][15];

};



}


