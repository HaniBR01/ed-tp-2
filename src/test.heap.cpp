#include <iostream>
#include "heap.hpp"

using namespace std;

int main(){
    Min_heap heap;
    heap.Insere(TipoItem(0,0,0));
    heap.Insere(TipoItem(4,0,4));
    heap.Insere(TipoItem(7,0,7));
    heap.Insere(TipoItem(1,0,1));
    heap.Insere(TipoItem(2,0,2));
    heap.Insere(TipoItem(3,0,3));
    heap.Insere(TipoItem(5,0,5));
    heap.Insere(TipoItem(6,0,6));

    heap.Imprime();

    heap.RemoveMin();

    heap.Imprime();

    return 0;
}