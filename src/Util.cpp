#include "../include/Util.hpp"
#include <iostream>
#include <string>

void Draw(Point BlinkyPoint,Point InkyPoint,Point PinkyPoint,Point ClydePoint,Point PacmanPoint){
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            std::string name = ".....";
            if(BlinkyPoint.x == j && BlinkyPoint.y == i){
                name = "..B..";
            }
            if(InkyPoint.x == i && InkyPoint.y == j){
                name = "..I..";
            }
            if(PinkyPoint.x == j && PinkyPoint.y == i){
                name = "..P..";
            }
            if(ClydePoint.x == j && ClydePoint.y == i){
                name = "..C..";
            }
            if(PacmanPoint.x == j && PacmanPoint.y == i){
                name = "..O..";
            }
            std::cout<<"|"<<name;
            if(j == 15) std::cout<<"|\n";
        }
    }
}