#include "excessoes.hpp"

const char *ExcecoesP::what() const throw(){
    return _message.c_str();
}