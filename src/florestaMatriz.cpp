#include "florestaMatriz.hpp"
#include <cmath>

void Clareira::imprime(){
    cout << "(" << _x << "," << _y << ")" << endl;
}

float Clareira::distancia(Clareira &clr){
    return sqrt(pow(_x - clr._x,2) + pow(_y - clr._y,2));
}

florestaMatriz::florestaMatriz(int clareiras, int trilhas, int portal){
    numVertices = clareiras;
    Clareiras = new Clareira[clareiras];
    for(int i=0; i<clareiras; i++){
        float x,y;
        cin >> x >> y;
        Clareiras[i] = Clareira(x,y);
    }
    MatrizAdjacencia = new float*[clareiras];
    for(int i=0; i<clareiras; i++){
        MatrizAdjacencia[i] = new float[clareiras];
        for(int j=0;j<clareiras;j++){
            MatrizAdjacencia[i][j] = -1;
        }
    }

    for(int i=0; i<trilhas; i++){
        int u,v;
        cin >>u>>v;
        float dist = Clareiras[u].distancia(Clareiras[v]);
        MatrizAdjacencia[u][v] = dist;
    }

    for(int i=0; i<portal;i++){
        int u,v;
        cin >>u>>v;
        MatrizAdjacencia[u][v] = 0;
    }

    float s;
    int q;
    cin >> s >> q;
    energia = s;
    portais = q;
}

florestaMatriz::~florestaMatriz(){
    delete[] Clareiras;
    for(int i=0; i<numVertices;i++){
        delete[] MatrizAdjacencia[i];
    }
    delete[] MatrizAdjacencia;
}

void florestaMatriz::imprimeClareiras(){
    for(int i=0;i<numVertices;i++){
        Clareiras[i].imprime();
    }
    cout << endl;
}

void florestaMatriz::imprimeMatriz(){
    for(int i=0;i<numVertices;i++){
        cout << "["  << MatrizAdjacencia[i][0];
        for(int j=1; j<numVertices;j++){
            cout << "," << MatrizAdjacencia[i][j];
        }
        cout << "]" << endl;
    }
    cout << endl;
}

int florestaMatriz::dijkstra(){
    Min_heap heap;
    Caminho vizitados;
    heap.Insere(TipoItem(0,0,0,0));
    TipoItem atual;
    while (! heap.Vazio()){
        atual = heap.RemoveMin();
        if(atual.vertice==(numVertices-1)){
            if(atual.distancia <= energia && atual.portais <= portais)
                return 1;
            else
                return 0;
        }
        if(!vizitados.vizitado(atual)){
            vizitados.Insere(atual);
            for(int i=0;i<numVertices;i++){
                float dist = MatrizAdjacencia[atual.vertice][i];
                if(dist >0){
                    heap.Insere(TipoItem(i,atual.portais,dist + atual.distancia,dist + atual.distancia));
                }else if(dist == 0){
                    heap.Insere(TipoItem(i,atual.portais+1,atual.distancia,dist + atual.distancia));
                }
            }
        }
    }
    
    if(vizitados.vizitado(numVertices-1)){
        return 1;
    }
    
    return 0;
}

int florestaMatriz::estrela(){
    Min_heap heap;
    Caminho vizitados;
    heap.Insere(TipoItem(0,0,0,0));
    TipoItem atual;
    while (! heap.Vazio()){
        atual = heap.RemoveMin();
        if(atual.vertice==(numVertices-1)){
            if(atual.distancia <= energia && atual.portais <= portais)
                return 1;
            else
                return 0;
        }
        if(!vizitados.vizitado(atual)){
            vizitados.Insere(atual);
            for(int i=0;i<numVertices;i++){
                float dist = MatrizAdjacencia[atual.vertice][i];
                float heur = Clareiras[i].distancia(Clareiras[numVertices-1]);
                if(dist >0){
                    heap.Insere(TipoItem(i,atual.portais,dist + atual.distancia,dist + atual.distancia+heur));
                }else if(dist == 0){
                    heap.Insere(TipoItem(i,atual.portais+1,atual.distancia,dist + atual.distancia+heur));
                }
            }
        }
    }
    
    if(vizitados.vizitado(numVertices-1)){
        return 1;
    }
    
    return 0;
}
