#include <iostream>
#include "clareira.hpp"

using namespace std;

int main(){
    Clareira clrs[10];
    for (int i=0; i < 10; i++){
        float x,y;
        cin >> x >> y;
        Clareira[i].SET_XY(x,y);
    }
    for(int i=0; i<10; i++){
        for(int j=i+1; j<10; j++){
            cout << "Distancia ()" << i << "," << j << "): " << clrs[i].Distancia(&clrs[j]) << endl;
        }
        cout << endl;
    }

    return 0;
}