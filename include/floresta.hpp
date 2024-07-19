#include <iostream>
#include "heap.hpp"

using namespace std;

#ifndef FLORESTA_H
#define FLORESTA_H

struct Clareira{
    public:

    float _x,_y;
    Clareira():_x(0),_y(0){}
    Clareira(float x,float y): _x(x),_y(y){}

    void imprime();

    float distancia(Clareira &clr);
}typedef Clareira;

struct Caminho{
    int tamanho, quantidade;
    TipoItem* Vizitados;
    Caminho();
    ~Caminho();
    void Insere(TipoItem vertice);
    bool vizitado(TipoItem vertice);
    bool vizitado(int);
}typedef Caminho;

class Floresta {
    private:
        int numVertices;
        Clareira * Clareiras;
        float ** MatrizAdjacencia;
        float energia;
        int portais;
    public:
        void imprimeClareiras();
        void imprimeMatriz();

        int dikstra();

        Floresta(int clareiras, int trilhas, int portal);
        ~Floresta();
};

#endif