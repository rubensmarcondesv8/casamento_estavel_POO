#include <iostream>
#include <cstdio>
#include <list>
#include <string.h>
#include <math.h>

using namespace std;

struct Posto
{
    unsigned int idPosto;
    unsigned int limitePessoas;
    Localizacao localPosto;
    unsigned int ultimoIdPessoa = 0;
};

struct Pessoa
{
    unsigned int idPessoa;
    unsigned int idade;
    Localizacao localPessoa;
    Posto *listaPreferenciaPosto;
    double *distanciaPostos;
};

struct Localizacao
{
    double x;
    double y;
};

double calculaDistancia(Localizacao l1, Localizacao l2){
    return sqrt(pow((l1.x - l2.x), 2) + pow((l1.y - l2.y), 2));
}

void trocaPessoa(Pessoa *a, Pessoa *b) {
    Pessoa aux = *a;
    *a = *b;
    *b = aux;
}

void montaListaPreferenciaPostos(Pessoa *lista, unsigned int tamanho){
    for (int i = 0; i < tamanho - 1; i++)
    {
        for (int j = 0; j < tamanho - i - 1; j++)
        {
            if(lista[j].idade < lista[j + 1].idade) 
            {
                trocaPessoa(&lista[j], &lista[j + 1]);
            }
        }
    }
}

void montaListaPreferenciaPessoa(Pessoa *pessoa, Posto *posto, unsigned int qtdePostos){
    pessoa->listaPreferenciaPosto = posto;
    for (int i = 0; i < qtdePostos; i++)
    {
        pessoa->distanciaPostos[i] = calculaDistancia(pessoa->localPessoa, posto[i].localPosto);
    }
     for (int j = 0; j < qtdePostos - 1; j++)
    {
        for (int k = 0; k < qtdePostos - j - 1; k++)
        {
            if(pessoa->distanciaPostos[j] > pessoa->distanciaPostos[j + 1]) 
            {
                //criar um funçao template pra troca de objetosS
                trocaPessoa(&lista[j], &lista[j + 1]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    Pessoa* listaPessoas;
    Posto* listaPostos;
    unsigned int numeroPessoas;
    unsigned int numeroPostos;

    string entrada;
    
    while(cin)
    {
        cin >> entrada;            
        numeroPostos = stoul(entrada);
        for (int j = 0; j < numeroPostos; j++)
        {
            listaPostos[j].idPosto = j;
            cin >> entrada;
            listaPostos[j].limitePessoas = stoul(entrada);
            cin >> entrada;
            listaPostos[j].localPosto.x = stoul(entrada);
            cin >> entrada;
            listaPostos[j].localPosto.y = stoul(entrada);

        }

        cin >> entrada;
        numeroPessoas = stoul(entrada);
        for(int k = 0; k < numeroPessoas; k++)
        {
            listaPessoas[k].idPessoa = k;
            cin >> entrada;
            listaPessoas[k].idade = stoul(entrada);
            cin >> entrada;
            listaPessoas[k].localPessoa.x = stoul(entrada);
            cin >> entrada;
            listaPessoas[k].localPessoa.y = stoul(entrada);
        }
    }
    
    return 0;
}
