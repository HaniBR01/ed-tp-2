#include <iostream>

using namespace std;

#ifndef FILA_H
#define FILA_H

struct TipoItem{
    int vertice;
    int portais;
    float distancia;
    float peso;
    TipoItem():vertice(0),portais(0),distancia(0),peso(0){}
    TipoItem(int v,int p,float d,float h):vertice(v),portais(p),distancia(d),peso(h){}
    void imprime();
}typedef TipoItem;

struct Caminho{
    int tamanho, quantidade;
    TipoItem* Vizitados;
    Caminho();
    ~Caminho();
    void Insere(TipoItem vertice);
    bool vizitado(TipoItem vertice);
    bool vizitado(int);
}typedef Caminho;

class Min_heap{
    private:
        int tamanho,qtd;
        TipoItem* Arr;
    public:
        Min_heap();
        ~Min_heap();

        void Insere(TipoItem item);
        TipoItem RemoveMin();
        void Imprime();

        bool Vazio();

};


#endif