#ifndef PESSOA
#define PESSOA

#include "Localizacao.hpp"
#include <vector>

using namespace std;

class Pessoa
{
    private:
        unsigned int idPessoa;
        unsigned int idade;
        Localizacao localPessoa;
        bool livre = true;
        unsigned idVagaAtual;
    
    public:
        Pessoa();
        Pessoa(unsigned int id, unsigned int _idade, Localizacao local);
        ~Pessoa();
        unsigned int getIdade();
        double getDistanciaPostoAtual();
        void setDistanciaPostoAtual(double distancia);
        void setLivre(bool _livre);
        bool isLivre();
        unsigned int getIdPessoa();
        unsigned int getIdVagaAtual();
        void setIdVagaAtual(unsigned int idV);

        double calculaDistancia(Localizacao localPosto);
};

#endif