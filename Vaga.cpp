#include "Vaga.hpp"
#include "Localizacao.hpp"
#include <list>

Vaga::Vaga(){
    this->ocupada = false;
}

Vaga::Vaga(unsigned int idV, Localizacao lV)
{
    this->idPostoVaga = idV;
    this->localVaga = lV;
    this->ocupada = false;
}

Vaga::~Vaga(){}

unsigned int Vaga::getIdPessoaVaga()
{
    return this->idPessoaVaga;
}
void Vaga::setIdPessoaVaga(unsigned int _id)
{
    this->idPessoaVaga = _id;
}
bool Vaga::isOcupada()
{
    return this->ocupada;
}
void Vaga::setOcupada(bool oc)
{
    this->ocupada = oc;
}

Localizacao Vaga::getLocalVaga()
{
    return this->localVaga;
}

void Vaga::setLocalVaga(double coordX, double coordY)
{
    Localizacao l(coordX, coordY);
    this->localVaga = l;
}

unsigned int Vaga::getIdPostoVaga()
{
    return this->idPostoVaga;
}