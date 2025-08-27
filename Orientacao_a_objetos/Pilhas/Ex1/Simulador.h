#ifndef SIMULADOR_H
#define SIMULADOR_H
#include "Pilha.h"
#include <stdlib.h>
#include <ctime>

class Simulador{
private:
    Pilha<int> pratosMolhados;
    Pilha<int> pratosSecos;
    int turnos;

public:
    Simulador();
    ~Simulador();
    Simulador(int turnos);

    int lavarPratos();
    int secarPratos();

    int executarSimulacao();
};

Simulador::Simulador(){}

Simulador::~Simulador(){}

Simulador::Simulador(int turnos){
    this->turnos = turnos;
}

int Simulador::lavarPratos(){
    int pratosLavados = rand() % 5 + 1;

    return pratosLavados;
}

int Simulador::secarPratos(){
    int pratosSecos = rand() % 3 + 1;

    return pratosSecos;
}

int Simulador::executarSimulacao(){
    int lavados;
    int secos;

    while (turnos > 0){
        lavados = lavarPratos();
        secos = secarPratos();

        cout << "Turno: " << turnos << endl;
        cout << "Pratos lavados: " << lavados << endl;
        cout << "Pratos secos: " << secos << endl;

        if (lavados < secos){
            secos = lavados;
        }

        for (int i = 0; i < lavados; i++){
            pratosMolhados.push(pratosMolhados.getTamanho() + 1);
        }

        for (int i = 0; i < secos; i++){
            if (!pratosMolhados.ehVazia()){
                pratosSecos.push(pratosMolhados.pop());
            }
        }

        cout << "Pilha molhados: " << pratosMolhados.getTamanho() << endl;
        //pratosMolhados.imprime();
        cout << "Pilha secos: " << pratosSecos.getTamanho() << endl << endl;
        //pratosSecos.imprime();
        turnos--;
    }
    return pratosMolhados.getTamanho();
}

#endif // SIMULADOR_H