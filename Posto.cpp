#include "Posto.hpp"
#include "Localizacao.hpp"
#include <vector>
#include "Pessoa.hpp"

using namespace std;

Posto::Posto()
{
     this->idPosto = 0;
     this->limitePessoas = 0;
     this->idProximaPessoa = 0;
}

Posto::~Posto(){}

unsigned int Posto::getIdPosto()
{
    return this->idPosto;
}

void Posto::setIdPosto(unsigned int id)
{
    this->idPosto = id;
}

unsigned int Posto::getLimitePessoas()
{
    return this->limitePessoas;
}

void Posto::setLimitePessoas(unsigned int limite)
{
    this->limitePessoas = limite;
}

Localizacao Posto::getLocalPosto()
{
    return this->localPosto;
}

void Posto::setLocalPosto(Localizacao local)
{
    this->localPosto = local;
}

vector<Pessoa> Posto::getPessoasAgendadas()
{
    return this->pessoasAgendadas;
}

void Posto::setPessoasAgendadas(Pessoa p)
{
    this->pessoasAgendadas.push_back(p);    
}

unsigned int Posto::getIdProximaPessoa()
{
    return this->idProximaPessoa;
}

void Posto::setIdProximaPessoa(unsigned int valor)
{
    this->idProximaPessoa = valor;
}