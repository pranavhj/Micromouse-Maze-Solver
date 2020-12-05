#pragma once

#include "../Maze/Maze.h"
#include<string>



int* fp::Maze::get_dimensions()
    {
    int size[2];
    int *ptr=&size[0];
    int w=API::mazeWidth();
    int h=API::mazeHeight();
    size[0]=w;size[1]=h;
    return ptr;
}

void fp::Maze::check_wall(int x,int y,char direction)
    {if(x==0)
        {API::setWall(x,y,'w');Maze_[x][y].l==1;}
    if(x==15)
        {API::setWall(x,y,'e');Maze_[x][y].r==1;}
    if(y==0)
        {API::setWall(x,y,'s');Maze_[x][y].f==1;}
    if(y==15)
        {API::setWall(x,y,'n');Maze_[x][y].b==1;}
        
        
    if(direction=='n')            
        {Maze_[x][y].f=API::wallFront();if(y+1<=15) {Maze_[x][y+1].b= API::wallFront();}if(Maze_[x][y].f==1){API::setWall(x,y,'n');}                                         //checks the current nodes wall surrounding it
        Maze_[x][y].r=API::wallRight();if(x+1<=15) {Maze_[x+1][y].l=API::wallRight();}if(Maze_[x][y].r==1){API::setWall(x,y,'e');}
        Maze_[x][y].l=API::wallLeft(); if(x-1>=0) {Maze_[x-1][y].r=API::wallLeft();}if(Maze_[x][y].l==1){API::setWall(x,y,'w');}   
        //Maze_[x][y].b=API::wallFront();
        
        }
        
    else if(direction=='w')
        {Maze_[x][y].f=API::wallRight();if(y+1<=15)Maze_[x][y+1].b=API::wallRight();if(Maze_[x][y].f==1){API::setWall(x,y,'n');}
        //Maze_[x][y].r=API::wallRight();
        Maze_[x][y].l=API::wallFront();if(x-1>=0)Maze_[x-1][y].r=API::wallFront();if(Maze_[x][y].l==1){API::setWall(x,y,'w');}
        Maze_[x][y].b=API::wallLeft();if(y-1>=0)Maze_[x][y-1].f=API::wallLeft();if(Maze_[x][y].b==1){API::setWall(x,y,'s');}
        }
    else if(direction=='e')
        {Maze_[x][y].f=API::wallLeft();if(y+1<=15)Maze_[x][y+1].b=API::wallLeft();if(Maze_[x][y].f==1){API::setWall(x,y,'n');}
        Maze_[x][y].r=API::wallFront();if(x+1<=15) Maze_[x+1][y].l=API::wallFront();if(Maze_[x][y].r==1){API::setWall(x,y,'e');}
        //
        Maze_[x][y].b=API::wallRight();if(y-1>=0)Maze_[x][y-1].f=API::wallRight();if(Maze_[x][y].b==1){API::setWall(x,y,'s');}
        }
        
    else if(direction=='s')
        {//
        Maze_[x][y].r=API::wallLeft();if(x+1<=15) Maze_[x+1][y].l=API::wallLeft();if(Maze_[x][y].r==1){API::setWall(x,y,'e');}
        Maze_[x][y].l=API::wallRight(); if(x-1>=0) Maze_[x-1][y].r=API::wallRight();if(Maze_[x][y].l==1){API::setWall(x,y,'w');}
        Maze_[x][y].b=API::wallFront();if(y-1>=0)Maze_[x][y-1].f=API::wallFront();if(Maze_[x][y].b==1){API::setWall(x,y,'s');}
        
            }
            
            
        
    
                                             
}




/*void Maze::set_wall(int x,int y,string direc);
    {for(int i=0;i<direc.size();i++)
    {char direction=direc[i];
        if(direction=='f')
            Maze_[x][y].f=1;
        else if(direction=='l')
            Maze_[x][y].l=1;                                             //updates the nodes 
        else if(direction=='r')
            Maze_[x][y].r=1;    
    }
    }*/


void fp::Maze::set_color(int x,int y,char color) 
    {API::setColor(x, y, color);
     Maze_[x][y].color=color;}  
 
    
fp::Maze::Maze()
{for(int i=0;i<16;i++)
    {for(int j=0;j<16;j++)
        {Maze_[i][j].f=0;                               //Initializing the Maze as a empty maze
        Maze_[i][j].r=0;
        Maze_[i][j].l=0;
        Maze_[i][j].b=0;
        Maze_[i][j].checked=0;
        
        Maze_[i][j].color='b';
        }
    }
}




