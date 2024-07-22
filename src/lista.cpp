#include <iostream>
#include "florestaLista.hpp"
#include "excessoes.hpp"

using namespace std;

int main(){
    int clr, tri, por;
    //leitura inicial inicializa o grafo e começa a ler o restante das entradas
    cin >> clr >> tri >> por;
    FlorestaLista *F;
    try{
        F = new FlorestaLista(clr,tri,por);
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

    return 0;
}