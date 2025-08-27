#ifndef COMBATENTE_H
#define COMBATENTE_H

#include <iostream>

using namespace std;

class Combatente {
    private:
        char nome;
        int iniciativa;

    public:
        Combatente();
        Combatente(char nome, int iniciativa);
        ~Combatente();

        void setNome(char nome);
        void setIniciativa(int iniciativa);
        char getNome();
        int getIniciativa();

        void imprime();
};

Combatente::Combatente(){}

Combatente::Combatente(char nome, int iniciativa){
    this->nome = nome;
    this->iniciativa = iniciativa;
}

Combatente::~Combatente(){}

void Combatente::setNome(char nome){this->nome = nome;}

void Combatente::setIniciativa(int iniciativa){this->iniciativa = iniciativa;}

char Combatente::getNome(){return nome;}

int Combatente::getIniciativa(){return iniciativa;}

void Combatente::imprime(){cout << nome << " " <<  iniciativa << endl;}

#endif // COMBATENTE_H