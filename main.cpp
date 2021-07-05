#include <iostream>
#include <vector>
#include "Pessoa.hpp"
#include "Posto.hpp"
#include "Localizacao.hpp"

using namespace std;

void bubbleSortPessoa(vector<Pessoa> vp, unsigned* lista, unsigned n)
{
    unsigned aux;
    for (unsigned k = 0; k < n; k++)
    {
        lista[k] = vp[k].getIdPessoa();
    }
    for (unsigned i = 0; i < n - 1; i++)
    {
        for (unsigned j = i + 1; j < n; j++)
        {
            if(vp[lista[i]].getIdade() < vp[lista[j]].getIdade())
            {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            } else if(vp[lista[i]].getIdade() == vp[lista[j]].getIdade())
            {
                if(vp[lista[i]].getIdPessoa() > vp[lista[j]].getIdPessoa())
                {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    unsigned int numeroPessoas = 0;
    unsigned int numeroPostos = 0;
    vector<Posto> arrayPostos;
    vector<Pessoa> arrayPessoas;
    unsigned int aux = 0;
    double temp1 = 0;
    double temp2 = 0;

    cin >> numeroPostos;
    for (unsigned int j = 0; j < numeroPostos; j++)
    {
        Posto posto;
        posto.setIdPosto(j);
        cin >> aux;
        posto.setLimitePessoas(aux);
        cin >> temp1;
        cin >> temp2;
        Localizacao coordenadasPosto(temp1, temp2);
        posto.setLocalPosto(coordenadasPosto);
        arrayPostos.push_back(posto);
    }

    cin >> numeroPessoas;
    for(unsigned int k = 0; k < numeroPessoas; k++)
    {
        Pessoa pessoa;
        pessoa.setIdPessoa(k);
        cin >> aux;
        pessoa.setIdade(aux);
        cin >> temp1;
        cin >> temp2;
        Localizacao coordenadasPessoa(temp1, temp2);
        pessoa.setLocalPessoa(coordenadasPessoa);
        arrayPessoas.push_back(pessoa);
    }

    unsigned pessoasMaisVelhasId[numeroPessoas];
    bubbleSortPessoa(arrayPessoas, pessoasMaisVelhasId, numeroPessoas);

    unsigned int vagas = 0;
    for (unsigned int i = 0; i < numeroPostos; i++)
    {
        vagas = vagas + arrayPostos[i].getLimitePessoas();
    }

    if(vagas < numeroPessoas)
    {
        
    }
    
    if(vagas == numeroPessoas)
    {

    }

    if(vagas > numeroPessoas)
    {
        
    }

    for (unsigned int j = 0; j < numeroPostos; j++)
    {
        cout << "(" << arrayPostos[j].getIdPosto() << ")" << endl;
        for (unsigned int k = 0; k < arrayPostos[j].getLimitePessoas(); k++)
        {
            cout << arrayPostos[j].getPessoasAgendadas()[k].getIdPessoa();
        }
        cout << endl;
    }
    
    return 0;
}