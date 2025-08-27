#ifndef VALIDADOR_H
#define VALIDADOR_H 

#include "pilha.h"

template<class T>
class Validador {
    public:
        Pilha<T> criarPilha(string palavra);
        string inverterPalavra(string palavra);
        bool ehPalindromo(string palavra);
        bool ehPalindromo(Pilha<T> pilha);
};

template<class T>
Pilha<T> Validador<T>::criarPilha(string palavra)
{
    Pilha<T> pilha;
    for (char c : palavra) {
        pilha.push(c);
    }
    return pilha;
}

template<class T>
string Validador<T>::inverterPalavra(string palavra){
    string palavraInvertida = "";

    for (int i = palavra.length() - 1; i >= 0; i--) {
        palavraInvertida += palavra[i];
    }
/*    for (T c : palavra){
        palavraInvertida = c + palavraInvertida;
        cout << palavraInvertida << endl;
    }

*/
    return palavraInvertida;
}

template<class T>
bool Validador<T>::ehPalindromo(Pilha<T> pilha) {
    Pilha<T> invertida = pilha.inverte();
    pilha.inverte();

    if (pilha.ehVazia() || invertida.ehVazia()) {
        return false;
    }

    bool iguais = true;

    while (iguais && !pilha.ehVazia() && !invertida.ehVazia()) {
        T elemPalindromo = pilha.pop();
        T elemInvertida = invertida.pop();
        
        if (elemPalindromo != elemInvertida) {
            iguais = false;
            break;
        }
    }
    return iguais;
}

template<class T>
bool Validador<T>::ehPalindromo(string palavra) {
    Pilha<T> pilha = criarPilha(palavra);
    Pilha<T> invertida = pilha.inverte();
    pilha.inverte();

    if (pilha.ehVazia() || invertida.ehVazia()) {
        return false;
    }

    bool iguais = true;

    while (iguais && !pilha.ehVazia() && !invertida.ehVazia()) {
        T elemPalindromo = pilha.pop();
        T elemInvertida = invertida.pop();
        
        if (elemPalindromo != elemInvertida) {
            iguais = false;
            break;
        }
    }
    return iguais;
}


#endif // VALIDADOR_H