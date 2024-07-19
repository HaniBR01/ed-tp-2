#include <iostream>
#include "floresta.hpp"

using namespace std;

int main(){
    int clr, tri, por;
    cin >> clr >> tri >> por;
    Floresta F = Floresta(clr,tri,por);
    cout << F.dikstra() << endl;

    return 0;
}