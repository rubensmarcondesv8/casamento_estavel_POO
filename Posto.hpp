#ifndef POSTO
#define POSTO

#include "Pessoa.hpp"
#include "Localizacao.hpp"
#include <vector>

using namespace std;

class Posto
{
    private:
        unsigned int idPosto;
        unsigned int limitePessoas;
        unsigned int idProximaPessoa;
        Localizacao localPosto;
        vector<Pessoa> pessoasAgendadas;

    public:
        Posto();
        ~Posto();
        unsigned int getIdPosto();
        void setIdPosto(unsigned int id);
        unsigned int getLimitePessoas();
        void setLimitePessoas(unsigned int limite);
        Localizacao getLocalPosto();
        void setLocalPosto(Localizacao local);
        vector<Pessoa> getPessoasAgendadas();
        void setPessoasAgendadas(Pessoa p);
        unsigned int getIdProximaPessoa();
        void setIdProximaPessoa(unsigned int valor);
};

#endif