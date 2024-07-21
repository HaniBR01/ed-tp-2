#include <iostream>
#include "florestaMatriz.hpp"

using namespace std;

int main(){
    int clr, tri, por;
    cin >> clr >> tri >> por;
    florestaMatriz F = florestaMatriz(clr,tri,por);
    cout << F.dijkstra() << F.estrela() << endl;

    return 0;
}