#include <iostream>

using namespace std;

#ifndef FILA_H
#define FILA_H

struct TipoItem{
    int vertice;
    int portais;
    int distancia;
    TipoItem():vertice(0),portais(0),distancia(0){}
    TipoItem(int v,int p,int d):vertice(v),portais(p),distancia(d){}
    void imprime();
}typedef TipoItem;


class Min_heap{
    private:
        int tamanho,qtd;
        TipoItem* Arr;
    public:
        Min_heap();
        ~Min_heap();

        TipoItem GetAncestral(TipoItem item);
        TipoItem GetEsq(TipoItem item);
        TipoItem GetDir(TipoItem item);

        void Insere(TipoItem item);
        TipoItem RemoveMin();
        void Imprime();

        bool Vazio();
        void Limpa();

};


#endif