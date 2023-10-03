#include "Ordenar.h"


namespace adf{
Ordenar::Ordenar(const int& size) :
    size(0),
    vector(0)
{
    if (size <= 0)
        throw QString("size invalido");
    try
    {
        vector = new int[size];
        this->size = size;

        std::srand(time(0));
        for (int i = 0; i < size; i++)
        {
            vector[i] = std::rand() % 101;
        }
    }
    catch (std::bad_alloc &erro)
    {
        throw QString("memoria nao alocada");
    }
}

QString Ordenar::accessVector()
{
    QString exit= "";
    for (int i = 0; i < size; i++)
    {
        exit+= QString::number(vector[i]) + '/';
    }
    exit += '\n';
    return exit;
}
void Ordenar::OrdenarCrescente()
{
    adf::Fila f(size);

    for (int i = 0; i < size; i++)
    {
        f.inserir(vector[i]);
    }

    for (int i = 0; i < size; i++)
    {
        int Max = f.retirar();
        for (int j = 1; j < size - i; j++)
        {
            int aux = f.retirar();
            if (aux < Max)
            {
                f.inserir(Max);
                Max = aux;
            }
            else
            {
                f.inserir(aux);
            }
        }
        vector[i] = Max;
    }
}

void Ordenar::OrdenarDecrescente()
{
    adf::Fila f(size);

    for (int i = 0; i < size; i++)
    {
        f.inserir(vector[i]);
    }

    for (int i = 0; i < size; i++)
    {
        int min = f.retirar();
        for (int j = 1; j < size-i; j++)
        {
            int aux = f.retirar();
            if (aux > min)
            {
                f.inserir(min);
                min = aux;
            }
            else
            {
                f.inserir(aux);
            }
        }
        vector[i] = min;
    }
}
Ordenar::~Ordenar()
{
    delete[] vector;
    vector = nullptr;
}
}
