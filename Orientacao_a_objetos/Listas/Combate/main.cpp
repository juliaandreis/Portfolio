#include "Lista.h"
#include "Combatente.h"
#include <ctime>
#include <cstdlib>

int main(){
    srand(time(0));

    Lista<Combatente> lista;

    for (int i = 0; i < 10; i++) {
        char nome = 'A' + (rand() % 26);
        int iniciativa = rand() % 10 + 1;
        Combatente combatente(nome, iniciativa);
        lista.push(combatente);
        lista.imprime();
        cout << endl;
    }

    cout << endl << "Lista apos insercao:" << endl;
    lista.imprime();

    return 0;
}