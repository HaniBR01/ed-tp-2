#include <iostream>

using namespace std;

#ifndef CLAREIRA_H
#define CLAREIRA_H

class Clareira{
    private:
        float _x, _y;
    public:
        Clareira();
        void SET_XY(float x, float y);
        ~Clareira();
        float get_x();
        float get_y();
        float Distancia(Clareira & clareira);
};

#endif