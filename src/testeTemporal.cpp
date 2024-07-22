#include <iostream>
#include <sys/time.h>
#include <fstream>
#include "excessoes.hpp"
#include "florestaLista.hpp"
#include "florestaMatriz.hpp"

using namespace std;

long long int getCurrentTimeMicros() {
    struct timeval tv;
    gettimeofday(&tv, nullptr);
    return (long long int)tv.tv_sec*1000000LL + (long long int)tv.tv_usec;
}

int main(){
    int clr, tri, por, teste;
    long long int valores[2][2]={0};
    long long int start, end;
    cin >> clr >> tri >> por;
    FlorestaLista* FL;
    try{
        FL = new FlorestaLista(clr,tri,por);
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
    start = getCurrentTimeMicros();
    teste = FL->dijkstra();
    end = getCurrentTimeMicros();
    valores[0][0] = end - start;
    
    start = getCurrentTimeMicros();
    teste = FL->estrela();
    end = getCurrentTimeMicros();
    valores[0][1] = end - start;

    delete FL;
    
    cin >> clr >> tri >> por;
    florestaMatriz* FM;
    try{
        FM = new florestaMatriz(clr,tri,por);
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
    start = getCurrentTimeMicros();
    teste = FM->dijkstra();
    end = getCurrentTimeMicros();
    valores[1][0] = end - start;
    
    start = getCurrentTimeMicros();
    teste = FM->estrela();
    end = getCurrentTimeMicros();
    valores[1][1] = end - start;
    delete FM;
    
    ofstream arquivo("./results/resultado.csv",ios::app);

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return 1;
    }

    arquivo << valores[0][0] << "," << valores[0][1] << "," << valores[1][0] << "," << valores[1][1] << "\n";

    arquivo.close();

    return 0;
}