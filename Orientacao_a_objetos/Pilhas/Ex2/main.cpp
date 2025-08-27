//#include <ctype.h>
#include "Verificador.h"

int main(){
    Verificador verificador;
    string expressao;
    char continuar;

    do{
        cout << "Digite uma expressao: ";
        getline(cin,expressao);

        if(verificador.isBalanceada(expressao)){
            cout << "A expressao esta balanceada!" << endl;
        }
        else{
            cout << "A expressao nao esta balanceada!" << endl;
        }

        cout << "Deseja verificar outra expressao? (s/n): ";
        cin >> continuar;
        cin.ignore();
    } while (tolower(continuar) == 's');

    return 0;
}