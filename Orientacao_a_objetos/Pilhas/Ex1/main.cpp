#include "Simulador.h"

int main(){
    srand(time(0));
    
    Simulador simulador(5);

    cout << simulador.executarSimulacao() << endl;

    return 0;
}