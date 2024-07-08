#include <iostream>

using namespace std;

#ifndef FLORESTA_H
#define FLORESTA_H

struct Clareira{
    public:

    float _x,_y;
    Clareira():_x(0),_y(0){}
    void Set_xy(float x,float y);

    void imprime();

    float distancia(Clareira &clr);
};


class Floresta {
    private:
        int numVertices;
        Clareira * Clareiras;
        float ** MatrizAdjacencia;
    public:
        void imprimeClareiras();
        void imprimeMatriz();
        Floresta(int clareiras, int trilhas, int portal);
        ~Floresta();
};

#endif