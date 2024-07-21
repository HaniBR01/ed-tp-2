#include <iostream>
#include "heap.hpp"

using namespace std;

#ifndef FLORESTA_LISTA_H
#define FLORESTA_LISTA_H

struct listaAdjacencia{
    int destino;
    float distancia;
    listaAdjacencia* proximo;

    listaAdjacencia(int d, float m): destino(d), distancia(m), proximo(nullptr){}

}typedef listaAdjacencia;

struct ClareiraLista{

    float _x,_y;
    listaAdjacencia* listaAdj;
    ClareiraLista():_x(0),_y(0), listaAdj(nullptr){}
    void set(float x, float y){
        _x = x; _y=y;
    }

    
    void imprime();
    void addAresta(ClareiraLista* clareirasLista, int d,int p){
        float dist = distancia(clareirasLista[d])*p;
        if(listaAdj==nullptr){
            listaAdj = new listaAdjacencia(d,dist);
        }else{
            listaAdjacencia* atual = listaAdj;
            while(atual->proximo != nullptr){
                atual = atual->proximo;
            }
            atual->proximo = new listaAdjacencia(d,dist);
        }
    }

    float distancia(ClareiraLista &clr);

}typedef ClareiraLista;

class FlorestaLista {
    private:
        int numVertices;
        ClareiraLista * ClareirasLista;
        float energia;
        int portais;
    public:

        int dijkstra();
        int estrela();

        FlorestaLista(int clareiras, int trilhas, int portal);
        ~FlorestaLista();
};

#endif