#include <iostream>
#include "florestaLista.hpp"

using namespace std;

int main(){
    int clr, tri, por;
    cin >> clr >> tri >> por;
    FlorestaLista F = FlorestaLista(clr,tri,por);
    cout << F.dijkstra() << endl;

    return 0;
}