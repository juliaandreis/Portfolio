#ifndef BARALHO_H
#define BARALHO_H

#include "Lista.h"
#include "Cartas.h"
#include <ctime>
#include <cstdlib>

class Baralho{
    public:
        Baralho();
        ~Baralho();
        bool embaralhar(Lista<Cartas>* lista);
};


Baralho::Baralho(){}

Baralho::~Baralho(){}

bool Baralho::embaralhar(Lista<Cartas>* lista) {
    if (lista == nullptr || lista->getTamanho() == 0)
        return false;

    Lista<Cartas> embaralhada;
    srand(time(0));

    int tamanho = lista->getTamanho();
    for (int i = tamanho; i > 0; i--) {
        int pos = rand() % i;
        Cartas carta = lista->pop_midle(pos);
        embaralhada.push_back(carta);
    }
    
    while (!embaralhada.ehVazia()) {
        lista->push_back(embaralhada.pop_front());
    }

    return true;
}


#endif // BARALHO_H