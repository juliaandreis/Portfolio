#include "Fila.h"
#include "Pilha.h"
#include <ctime>
#include <cstdlib>


int main() {
    Fila<Pilha<char>> fila;
    Pilha<char> pilha1;
    Pilha<char> pilha2;

    string palavra = "julia";
    for (char c : palavra) {
        pilha1.push(c);
    }

    palavra = "renner";
    for (char c : palavra) {
        pilha2.push(c);
    }


    fila.push_back(pilha1);
    fila.push_back(pilha2);

    fila.imprime();


    return 0;
}