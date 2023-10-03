#ifndef ORDENAR_H
#define ORDENAR_H
#include<QString>
#include<Fila.h>
namespace adf{
class Ordenar
{
public:
    Ordenar(const int& size);
    ~Ordenar();
    QString accessVector();
    void OrdenarCrescente();
    void OrdenarDecrescente();
private:
    int size;
    int *vector;

};
}
#endif // ORDENAR_H
