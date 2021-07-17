#include <math.h>
#include "Localizacao.hpp"
#include "Pessoa.hpp"

using namespace std;

Pessoa::Pessoa(){
    this->livre = true;
}

Pessoa::Pessoa(unsigned int id, unsigned int _idade, Localizacao local)
{
    this->idPessoa = id;
    this->idade = _idade;
    this->localPessoa = local;
    this->livre = true;
}

Pessoa::~Pessoa(){}

void Pessoa::setLivre(bool _livre)
{
    this->livre = _livre;
}
bool Pessoa::isLivre()
{
    return this->livre;
}

unsigned int Pessoa::getIdPessoa()
{
    return this->idPessoa;
}

unsigned int Pessoa::getIdVagaAtual()
{
    return this->idVagaAtual;
}

void Pessoa::setIdVagaAtual(unsigned int idV)
{
    this->idVagaAtual = idV;
}

unsigned int Pessoa::getIdade()
{
    return this->idade;
}

double Pessoa::calculaDistancia(Localizacao localPosto)
{
    return sqrt(pow(this->localPessoa.getX() - localPosto.getX(), 2) + pow(this->localPessoa.getY() - localPosto.getY(), 2));
}