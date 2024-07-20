#include "floresta.hpp"
#include <cmath>

void Clareira::imprime(){
    cout << "(" << _x << "," << _y << ")" << endl;
}

float Clareira::distancia(Clareira &clr){
    return sqrt(pow(_x - clr._x,2) + pow(_y - clr._y,2));
}

Floresta::Floresta(int clareiras, int trilhas, int portal){
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

Floresta::~Floresta(){
    delete[] Clareiras;
    for(int i=0; i<numVertices;i++){
        delete[] MatrizAdjacencia[i];
    }
    delete[] MatrizAdjacencia;
}

void Floresta::imprimeClareiras(){
    for(int i=0;i<numVertices;i++){
        Clareiras[i].imprime();
    }
    cout << endl;
}

void Floresta::imprimeMatriz(){
    for(int i=0;i<numVertices;i++){
        cout << "["  << MatrizAdjacencia[i][0];
        for(int j=1; j<numVertices;j++){
            cout << "," << MatrizAdjacencia[i][j];
        }
        cout << "]" << endl;
    }
    cout << endl;
}

int Floresta::dikstra(){
    Min_heap heap;
    Caminho vizitados;
    heap.Insere(TipoItem(0,0,0));
    TipoItem atual;
    while (! heap.Vazio()){
        atual = heap.RemoveMin();
        if(atual.vertice==(numVertices-1)){
            return 1;
        }
        if(!vizitados.vizitado(atual)){
            vizitados.Insere(atual);
            for(int i=0;i<numVertices;i++){
                float dist = MatrizAdjacencia[atual.vertice][i];
                if(dist >0 && dist + atual.distancia <= energia){
                    heap.Insere(TipoItem(i,atual.portais,dist + atual.distancia));
                }else if(dist == 0 && atual.portais < portais){
                    heap.Insere(TipoItem(i,atual.portais+1,atual.distancia));
                }
            }
        }
    }
    
    if(vizitados.vizitado(numVertices-1)){
        return 1;
    }
    
    return 0;
}

Caminho::Caminho(){
    tamanho = 8; quantidade=0;
    Vizitados = new TipoItem[tamanho];
}

Caminho::~Caminho(){
    delete Vizitados;
}

void Caminho::Insere(TipoItem vertice){
    if(quantidade==tamanho){
        TipoItem* velho=Vizitados;
        tamanho*=2;
        Vizitados = new TipoItem[tamanho];
        for(int i=1;i<quantidade;i++){
            Vizitados[i] = velho[i];
        }
        delete velho;
    }
    Vizitados[quantidade] = vertice;
    quantidade++;
}

bool Caminho::vizitado(TipoItem vertice){
    if(quantidade==0){
        return false;
    }
    for(int i=1;i<quantidade;i++){
        if(vertice.vertice == Vizitados[i].vertice && vertice.portais == Vizitados[i].portais){
            return true;
        }
    }
    return false;
}

bool Caminho::vizitado(int vertice){
    if(quantidade==0){
        return false;
    }
    for(int i=1;i<quantidade;i++){
        if(Vizitados[i].vertice == vertice){
            return true;
        }
    }
    return false;
}
