#ifndef POSTO_H
#define POSTO_H

#include "Localizacao.hpp"

using namespace std;

class Posto
{
    private:
        unsigned int idPosto;
        unsigned int limitePessoas;
        Localizacao localPosto;

    public:
        Posto();
        Posto(unsigned int id, 
                unsigned int qtdeVagas, 
                Localizacao local) : idPosto(id), limitePessoas(qtdeVagas), localPosto(local) {};

        unsigned int getIdPosto() const {return idPosto;}
        unsigned int getLimitePessoas() {return limitePessoas;}
        Localizacao getLocalPosto() {return localPosto;}
};

#endif