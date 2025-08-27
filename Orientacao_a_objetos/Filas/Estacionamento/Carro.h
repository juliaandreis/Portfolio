#ifndef CARRO_H
#define CARRO_H

#include <iostream>
#include <string>

using namespace std;

class Carro {
    private:
        string placa;

    public:
        Carro();
        Carro(string placa);
        ~Carro();

        void setPlaca(string placa);
        string getPlaca();

        void imprime();
};

Carro::Carro(){}
Carro::Carro(string placa){this->placa = placa;}
Carro::~Carro(){}

void Carro::setPlaca(string placa){this->placa = placa;}
string Carro::getPlaca(){return placa;}

void Carro::imprime(){cout << placa << endl;}

#endif // CARRO_H