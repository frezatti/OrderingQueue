#ifndef FILA_H
#define FILA_H

#include<QString>

namespace adf{
class Fila
{

    public:
        Fila(const int& tamanho);
        ~Fila();

        bool estaVazia() const;
        bool estaCheio() const;

        int getQuantidadeElementos() const;
        int acessar() const;
        void inserir(const int& entrada);
        int retirar();
    private:
        int tamanho;
        int *array;
        int inicio;
        int fim;
        int quantidadeElementos;
};
}
#endif // FILA_H
