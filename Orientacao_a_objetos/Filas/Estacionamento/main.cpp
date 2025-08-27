#include "Fila.h"
#include "Carro.h"

int main(){

    Fila<Carro> fila;
    fila.push_back(Carro("AAAAA"));
    fila.push_back(Carro("BBBBB"));
    fila.push_back(Carro("CCCCC"));
    fila.push_back(Carro("DDDDD"));
    fila.imprime();

    fila.pop_midle("CCCCC");

    fila.imprime();

    return 0;
}