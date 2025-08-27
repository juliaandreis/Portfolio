#include "Lista.h"
#include "Cartas.h"
#include "Baralho.h"
#include <ctime>
#include <cstdlib>

int main(){
    srand(time(0));

    Lista<Cartas> lista;
    Baralho baralho;

    string naipes[] = {"Ouros", "Copas", "Espadas", "Paus"};
    string cartas[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            string carta = cartas[j];
            string naipe = naipes[i];
            Cartas novaCarta(carta, naipe);
            lista.push_back(novaCarta);
        }
    }cout << lista.getTamanho() << endl;


    baralho.embaralhar(&lista);

    cout << lista.getTamanho() << endl;

 
    cout << endl << "Lista apos insercao:" << endl;
    lista.imprime();
    cout << lista.getTamanho() << endl;

    return 0;
}