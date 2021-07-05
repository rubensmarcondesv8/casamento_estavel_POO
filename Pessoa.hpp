#ifndef PESSOA
#define PESSOA

#include <vector>
#include "Localizacao.hpp"

using namespace std;

class Pessoa
{
    private:
        unsigned int idPessoa;
        unsigned int idade;
        Localizacao localPessoa;
        double distanciaPostoAtual;
        bool livre = true;
        unsigned int idPostoAtual;
    
    public:
        Pessoa();
        ~Pessoa();
        void setIdPessoa(unsigned int id);
        unsigned int getIdPessoa();
        void setIdade(unsigned int idade);
        unsigned int getIdade();
        void setLocalPessoa(Localizacao local);
        Localizacao getLocalPessoa();
        double getDistanciaPostoAtual();
        void setDistanciaPostoAtual(double distancia);
        void setLivre(bool _livre);
        bool isLivre();
        unsigned int getIdPostoAtual();
        void setIdPostoAtual(unsigned int id);

        double calculaDistancia(Localizacao localPosto);
};

#endif