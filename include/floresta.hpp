#include <iostream>
#include "clareira.hpp"

using namespace std;

#ifndef FLORESTA_H
#define FLORESTA_H

class Floresta {
    private:
        Clareira * Clareiras;
        float ** MatrizAdjacencia;
    public:
        Floresta(int clareiras, int trilhas, int portal);
        ~Floresta();
};

#endif