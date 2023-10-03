#include "Fila.h"

namespace adf{
Fila::Fila(const int &tamanho):
    tamanho(0),
    array(0),
    inicio(-1),
    fim(-1),
    quantidadeElementos(0)
{
    if (tamanho <= 0)
        throw QString("Tamanho de vetor invalido");
    try
    {
        array = new int[tamanho];
        this->tamanho = tamanho;
    }
    catch (std::bad_alloc &erro)
    {
        throw QString("Nao foi possivel criar vetor");
    }
}

Fila::~Fila()
{
    if (array)
    {
        delete[] array;
        array = nullptr;
    }
}

bool Fila::estaVazia() const
{
    return (!quantidadeElementos);
}

bool Fila::estaCheio() const
{
    return (quantidadeElementos == tamanho);
}

int Fila::acessar() const
{
    if (estaVazia())
        throw QString("fila esta vazia");
    return array[inicio];
}

void Fila::inserir(const int &entrada)
{
    if (estaCheio())
        throw QString("fila ja cheia");
    if (estaVazia())
    {
        inicio = fim = 0;
        array[fim] = entrada;
        quantidadeElementos++;
        return;
    }
    fim++;
    if (fim == tamanho)
        this->fim = 0;
    array[fim] = entrada;
    quantidadeElementos++;
}

int Fila::retirar()
{
    if (estaVazia())
        throw QString("fila ja vazia");
    int aux = array[inicio];
    inicio++;
    if (inicio == tamanho)
        this->inicio = 0;
    quantidadeElementos--;
    if (estaVazia())
        inicio = fim = -1;
    return aux;
}

int Fila::getQuantidadeElementos() const
{
    return this->quantidadeElementos;
}
}
