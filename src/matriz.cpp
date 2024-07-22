#include <iostream>
#include "florestaMatriz.hpp"
#include "excessoes.hpp"

using namespace std;

int main(){
    int clr, tri, por;
    //leitura inicial inicializa o grafo e começa a ler o restante das entradas
    cin >> clr >> tri >> por;
    florestaMatriz* F;

    try{
        F = new florestaMatriz(clr,tri,por);
    }catch (const GrafoVazio&e){
        std::cerr << e.what() << std::endl;
    }catch (const PortaisNegativos&e){
        std::cerr << e.what() << std::endl;
    }catch (const TrilhasNegativas&e){
        std::cerr << e.what() << std::endl;
    }catch (const EnergiaNegativos&e){
        std::cerr << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Erro desconhecido." << std::endl;
    }
    cout << F->dijkstra() << " " << F->estrela() << endl;
    delete F;
    return 0;
}