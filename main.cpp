#include <iostream>
#include <vector>
#include "Pessoa.hpp"
#include "Posto.hpp"
#include "Localizacao.hpp"
#include "Vaga.hpp"
#include <algorithm>

using namespace std;

bool comparaIdade(Pessoa primeiro, Pessoa segundo)
{
    if (primeiro.getIdade() < segundo.getIdade())
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{
    unsigned numeroPessoas = 0;
    unsigned numeroPostos = 0;
    unsigned numeroVagas = 0;
    vector<Posto> vetorPostos;
    vector<Vaga> vetorVagas;
    vector<Pessoa> vetorPessoas;

    cin >> numeroPostos;
    for (unsigned int j = 0; j < numeroPostos; j++)
    {
        unsigned int a, b, c;
        cin >> a;
        cin >> b;
        cin >> c;
        Localizacao l(b, c);
        Posto posto(j, a, l);
        vetorPostos.push_back(posto);
        for (unsigned int k = 0; k < posto.getLimitePessoas(); k++)
        {
            Vaga v(j, posto.getLocalPosto());
            vetorVagas.push_back(v);
            numeroVagas++;
        }
    }

    cin >> numeroPessoas;
    for (unsigned int k = 0; k < numeroPessoas; k++)
    {
        unsigned a, b, c;
        cin >> a;
        cin >> b;
        cin >> c;
        Localizacao l(b, c);
        Pessoa pessoa(k, a, l);
        vetorPessoas.push_back(pessoa);
    }

    sort(vetorPessoas.begin(), vetorPessoas.end(), comparaIdade);
    vector<unsigned int> preferenciaPostoIdPessoa;
    for (unsigned int i = 0; i < vetorPessoas.size(); i++)
    {
        preferenciaPostoIdPessoa.push_back(vetorPessoas[i].getIdPessoa());
    }

    vector<double> matrizPreferenciaPessoaDistancia[numeroPessoas];

    for (unsigned int k = 0; k < numeroPessoas; k++)
    {
        for (unsigned int m = 0; m < vetorVagas.size(); m++)
        {
            matrizPreferenciaPessoaDistancia[k].push_back(vetorPessoas[k].calculaDistancia(vetorVagas[m].getLocalVaga()));
        }
    }

//FALTA IMPLEMENTAR O PROX PESSOA A RECEBER PROPOSTA DA VAGA

    if (numeroVagas < numeroPessoas)
    {
        unsigned int i = 0, j = 0;
        while (numeroVagas > 0)
        {
            if (!vetorVagas[i].isOcupada() && vetorPessoas[j].isLivre())
            {
                vetorVagas[i].setIdPessoaVaga(j);
                vetorPessoas[j].setIdVagaAtual(i);
                vetorVagas[i].setOcupada(true);
                i++;
                numeroVagas--;
            }
            if (!vetorVagas[i].isOcupada() &&
                matrizPreferenciaPessoaDistancia[j][i] <
                    matrizPreferenciaPessoaDistancia[j][vetorPessoas[j].getIdVagaAtual()])
            {
                vetorVagas[i].setOcupada(true);
                vetorVagas[vetorPessoas[j].getIdVagaAtual()].setOcupada(false);
                vetorVagas[i].setIdPessoaVaga(j);
                vetorPessoas[j].setIdVagaAtual(i);
                i++;
            }
            else if (!vetorVagas[i].isOcupada() &&
                     matrizPreferenciaPessoaDistancia[j][i] ==
                         matrizPreferenciaPessoaDistancia[j][vetorPessoas[j].getIdVagaAtual()] &&
                     i > vetorPessoas[j].getIdVagaAtual())
            {
                vetorVagas[i].setOcupada(true);
                vetorVagas[vetorPessoas[j].getIdVagaAtual()].setOcupada(false);
                vetorVagas[i].setIdPessoaVaga(j);
                vetorPessoas[j].setIdVagaAtual(i);
            }
        }
    }

    unsigned int aux = 0;
    for (unsigned int i = 0; i < vetorPostos.size(); i++)
    {
        cout << vetorPostos[i].getIdPosto() << endl;
        for (unsigned int j = aux; j < vetorVagas.size(); j++)
        {
            if(i == vetorVagas[j].getIdPostoVaga())
            {
                cout << vetorVagas[j].getIdPessoaVaga() << " ";
            } else
            {
                aux = j;
                break;
            }
        }
    }

    return 0;
}