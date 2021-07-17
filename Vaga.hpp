#ifndef VAGA
#define VAGA

#include "Localizacao.hpp"
#include <list>

using namespace std;

class Vaga
{
    private:
        unsigned int idPostoVaga;
        bool ocupada;
        unsigned int idPessoaVaga;
        Localizacao localVaga;
    
    public:
        Vaga();
        Vaga(unsigned int idV, Localizacao lV);
        ~Vaga();
        unsigned int getIdPessoaVaga();
        void setIdPessoaVaga(unsigned int _id);
        bool isOcupada();
        void setOcupada(bool oc);
        Localizacao getLocalVaga();
        void setLocalVaga(double coordX, double coordY);
        unsigned int getIdPostoVaga();
};

#endif