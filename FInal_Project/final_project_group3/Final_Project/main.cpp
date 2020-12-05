#include "src/Algo/Algo.h"
#include "src/LandBasedTracked/LandBasedTracked.h"
#include "src/LandBasedWheeled/LandBasedWheeled.h"
#include "src/Maze/Maze.h"


int main(){
//--Replace the use of raw pointers with smart pointers
fp::LandBasedRobot *wheeled = new fp::LandBasedWheeled("Husky");
fp::Algo algo;
algo.Solve(wheeled);
delete wheeled;
return 0;
}