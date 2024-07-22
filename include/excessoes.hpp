#include <exception>
#include <string>
#include "florestaLista.hpp"
#include "florestaMatriz.hpp"

class ExcecoesP : public std::exception {
        private:
            std::string _message;
        public:
            ExcecoesP(std::string message): _message(message){};
            const char* what() const throw();
};

class GrafoVazio : public ExcecoesP{
    public:
        GrafoVazio() : ExcecoesP("Esse grafo não possuí vertices"){};
};

class TrilhasNegativas : public ExcecoesP{
    public:
        TrilhasNegativas() : ExcecoesP("O numero de trilhas é negativo"){};
};

class PortaisNegativos : public ExcecoesP{
    public:
        PortaisNegativos() : ExcecoesP("O numero de portais é negativo"){};
};

class EnergiaNegativos : public ExcecoesP{
    public:
        EnergiaNegativos() : ExcecoesP("O numero de Energia é negativo"){};
};