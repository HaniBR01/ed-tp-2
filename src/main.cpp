#include <iostream>
#include "floresta.hpp"

using namespace std;

int main(){
    int clr, tri, por;
    cin >> clr >> tri >> por;
    Floresta F = Floresta(clr,tri,por);
    F.imprimeClareiras();
    F.imprimeMatriz();

    return 0;
}