#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>

using namespace std;

enum Prioridade {
    BAIXA = 0,
    MEDIA = 1,
    ALTA = 2
};

class Pessoa {
private:
    Prioridade prioridade;

public:
    Pessoa();
    ~Pessoa();
    Pessoa(Prioridade prioridade);

    void setPrioridade(Prioridade prioridade);
    Prioridade getPrioridade();

    void imprime();
};

Pessoa::Pessoa(){}

Pessoa::~Pessoa(){}

Pessoa::Pessoa(Prioridade prioridade) {
    this->prioridade = prioridade;
}

void Pessoa::setPrioridade(Prioridade prioridade) {
    this->prioridade = prioridade;
}

Prioridade Pessoa::getPrioridade() {
    return prioridade;
}

void Pessoa::imprime() {
    switch (prioridade) {
        case BAIXA:
            cout << "Prioridade: BAIXA" << endl;
            break;
        case MEDIA:
            cout << "Prioridade: MEDIA" << endl;
            break;
        case ALTA:
            cout << "Prioridade: ALTA" << endl;
            break;
        default:
            cout << "Prioridade: DESCONHECIDA" << endl;
    }
}

#endif // PESSOA_H