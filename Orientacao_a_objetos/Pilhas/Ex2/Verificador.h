#ifndef VERIFCADOR_H
#define VERIFCADOR_H
#include "Pilha.h"

class Verificador {
private:
    Pilha<char> pilha;

public:
    Verificador();
    ~Verificador();

    bool isBalanceada(string expressao);
};

Verificador::Verificador(){}
    
Verificador::~Verificador(){}

bool Verificador::isBalanceada(string expressao){
    for (char c : expressao){
        if (c == '(' || c == '[' || c == '{' ){
            pilha.push(c);
            //pilha.imprime();
        }
        else if (c == ')' || c == ']' || c == '}'){
            if (pilha.ehVazia()) {
                return false;
            }
            switch (c){
                case ')':
                    if (pilha.pop() != '(') {
                        return false;
                    }
                    break;
                case ']':
                    if (pilha.pop() != '[') {
                        return false;
                    }
                    break;
                case '}':
                    if (pilha.pop() != '{') {
                        return false;
                    }
                    break;
            }
        }
        else {
            continue;
        }
    }
    return pilha.ehVazia();
}

#endif // VERIFICADOR_H