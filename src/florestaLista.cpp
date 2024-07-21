#include "florestaLista.hpp"
#include <cmath>

void ClareiraLista::imprime(){
    cout << "(" << _x << "," << _y << ")" << endl;
}

float ClareiraLista::distancia(ClareiraLista &clr){
    return sqrt(pow(_x - clr._x,2) + pow(_y - clr._y,2));
}

FlorestaLista::FlorestaLista(int clareiras, int trilhas, int portal){
    numVertices = clareiras;
    ClareirasLista = new ClareiraLista[clareiras];
    for(int i=0; i<clareiras; i++){
        float x,y;
        cin >> x >> y;
        ClareirasLista[i].set(x,y);
    }
    int s, d;
    for(int i=0;i<trilhas;i++){
        cin >> s >> d;
        ClareirasLista[s].addAresta(ClareirasLista,d,1);
    }
    for(int i=0;i<portal;i++){
        cin >> s >> d;
        ClareirasLista[s].addAresta(ClareirasLista,d,0);
    }
    float e;
    int p;
    cin >> e >> p;
    energia = e;
    portais = p;
}

FlorestaLista::~FlorestaLista(){
    for(int i=0;i<numVertices;i++){
        listaAdjacencia* atual = ClareirasLista[i].listaAdj;
        listaAdjacencia* exclui;
        while (atual!=nullptr){
            exclui = atual;
            atual = atual->proximo;
            delete exclui;
        }
    }
    delete [] ClareirasLista;
}

int FlorestaLista::dijkstra(){
    Min_heap heap;
    Caminho vizitados;
    heap.Insere(TipoItem(0,0,0,0));
    TipoItem atual;
    while (!heap.Vazio()){
        atual = heap.RemoveMin();
        if(atual.vertice==(numVertices-1)){
            return 1;
        }
        listaAdjacencia* current = ClareirasLista[atual.vertice].listaAdj;
        if(!vizitados.vizitado(atual)){
            vizitados.Insere(atual);
            while(current != nullptr){
                float dist = current->distancia;
                if(dist >0 && dist + atual.distancia <= energia){
                    heap.Insere(TipoItem(current->destino,atual.portais,dist + atual.distancia,dist + atual.distancia));
                }else if(dist == 0 && atual.portais < portais){
                    heap.Insere(TipoItem(current->destino,atual.portais+1,atual.distancia,dist + atual.distancia));
                }
                current = current->proximo;
            }
        }
    }
    
    if(vizitados.vizitado(numVertices-1)){
        return 1;
    }
    
    return 0;
}

int FlorestaLista::estrela(){
   Min_heap heap;
    Caminho vizitados;
    heap.Insere(TipoItem(0,0,0,0));
    TipoItem atual;
    while (!heap.Vazio()){
        atual = heap.RemoveMin();
        if(atual.vertice==(numVertices-1)){
            return 1;
        }
        listaAdjacencia* current = ClareirasLista[atual.vertice].listaAdj;
        if(!vizitados.vizitado(atual)){
            vizitados.Insere(atual);
            while(current != nullptr){
                float dist = current->distancia;
                float heur = ClareirasLista[current->destino].distancia(ClareirasLista[numVertices-1]);
                if(dist >0 && dist + atual.distancia <= energia){
                    heap.Insere(TipoItem(current->destino,atual.portais,dist + atual.distancia,dist + atual.distancia+heur));
                }else if(dist == 0 && atual.portais < portais){
                    heap.Insere(TipoItem(current->destino,atual.portais+1,atual.distancia,dist + atual.distancia+heur));
                }
                current = current->proximo;
            }
        }
    }
    
    if(vizitados.vizitado(numVertices-1)){
        return 1;
    }
    
    return 0;
}

