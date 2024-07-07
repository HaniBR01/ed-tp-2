#include "clareira.hpp"
#include <cmath>

Clareira::Clareira(){
}

void Clareira::SET_XY(float x, float y){
    _x = x;
    _y = y;
}

Clareira::~Clareira(){
}

float Clareira::get_x(){
    return _x;
}

float Clareira::get_y(){
    return _y;
}

float Clareira::Distancia(Clareira &clareira){
    return sqrt((_x - clareira.get_x())**2 (_y - clareira.get_y())**2);
}
