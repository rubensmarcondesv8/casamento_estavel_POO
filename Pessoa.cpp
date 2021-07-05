#include <vector>
#include <math.h>
#include "Localizacao.hpp"
#include "Pessoa.hpp"

using namespace std;

Pessoa::Pessoa()
{
    this->idPessoa = 0;
    this->idade = 0;
    this->distanciaPostoAtual = 0;
    this->livre = true;
}

Pessoa::~Pessoa(){}

void Pessoa::setIdPessoa(unsigned int id)
{
    this->idPessoa = id;
}

unsigned int Pessoa::getIdPessoa()
{
    return this->idPessoa;
}

void Pessoa::setIdade(unsigned int idade)
{
    this->idade = idade;
}

unsigned int Pessoa::getIdade()
{
    return this->idade;
}

void Pessoa::setLocalPessoa(Localizacao local)
{
    this->localPessoa = local;
}

Localizacao Pessoa::getLocalPessoa()
{
    return this->localPessoa;
}

double Pessoa::getDistanciaPostoAtual()
{
    return this->distanciaPostoAtual;
}

void Pessoa::setDistanciaPostoAtual(double distancia)
{
    this->distanciaPostoAtual = distancia;
}

void Pessoa::setLivre(bool _livre)
{
    this->livre = _livre;
}
bool Pessoa::isLivre()
{
    return this->livre;
}

unsigned int Pessoa::getIdPostoAtual()
{
    return this->idPostoAtual;
}
void Pessoa::setIdPostoAtual(unsigned int id)
{
    this->idPostoAtual = id;
}

double Pessoa::calculaDistancia(Localizacao localPosto)
{
    return sqrt(pow(this->localPessoa.getX() - localPosto.getX(), 2) + pow(this->localPessoa.getY() - localPosto.getY(), 2));
}