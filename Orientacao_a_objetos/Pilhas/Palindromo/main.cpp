#include "Validador.h"

int main(){
    Validador<char> teste;

    cout << teste.inverterPalavra("julia") << endl;

    if (teste.ehPalindromo("julia")){
      cout << "A palavra é um palíndromo." << endl;
    }
    else {
      cout << "A palavra não é um palíndromo." << endl;
    }
  
  return 0;
}
