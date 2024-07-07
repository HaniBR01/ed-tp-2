#include "floresta.hpp"

Floresta::Floresta(int clareiras, int trilhas, int portal){
    Clareiras = new Clareira[clareiras];
    for(int i=0; i<trilhas; i++){
        float x,y;
        cin >> x >> y;
        Clareiras[i].Set_XY(x,y);
    }
    MatrizAdjacencia = new float[clareiras][clareiras];
}

Floresta::~Floresta(){
    delete Clareiras;
    delete MatrizAdjacencia;
}