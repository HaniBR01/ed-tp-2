#include "floresta.hpp"
#include <cmath>

void Clareira::Set_xy(float x, float y){
    _x = x; 
    _y = y;
}

void Clareira::imprime(){
    cout << "(" << _x << "," << _y << ")" << endl;
}

float Clareira::distancia(Clareira &clr){
    return sqrt(pow(_x - clr._x,2) + pow(_y - clr._y,2));
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

Floresta::Floresta(int clareiras, int trilhas, int portal){
    numVertices = clareiras;
    Clareiras = new Clareira[clareiras];
    for(int i=0; i<clareiras; i++){
        float x,y;
        cin >> x >> y;
        Clareiras[i].Set_xy(x,y);
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
}

Floresta::~Floresta(){
    delete[] Clareiras;
    for(int i=0; i<numVertices;i++){
        delete[] MatrizAdjacencia[i];
    }
    delete[] MatrizAdjacencia;
}