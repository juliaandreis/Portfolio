#ifndef CARTAS_H
#define CARTAS_H

#include <iostream>
#include <string>

using namespace std;

class Cartas {
    private:
        string carta;
        string naipe;
    public:
        Cartas();
        Cartas(string carta, string naipe);
        ~Cartas();

        string getCarta();
        string getNaipe();
        void setCarta(string carta);
        void setNaipe(string naipe);

        void imprime();
};

Cartas::Cartas(){}

Cartas::Cartas(string carta, string naipe){
    this->carta = carta; 
    this->naipe = naipe;
}

Cartas::~Cartas(){}

string Cartas::getCarta() {
    return carta;
}

string Cartas::getNaipe() {
    return naipe;
}

void Cartas::setCarta(string carta) {
    this->carta = carta;
}

void Cartas::setNaipe(string naipe) {
    this->naipe = naipe;
}

void Cartas::imprime() {
    cout << carta << " de " << naipe << endl;
}

#endif // CARTAS_H