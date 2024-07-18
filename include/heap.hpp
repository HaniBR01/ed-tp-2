#include <iostream>

using namespace std;

#ifndef FILA_H
#define FILA_H

struct TipoItem{
    int vertice;
    int portais;
    int distancia;
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

        void Limpa();

};


#endif