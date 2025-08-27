#ifndef PILHA_H
#define PILHA_H 

#include "Nodo.h"

template<class T>
class Pilha {
private:
    Nodo<T>* base;
    Nodo<T>* topo;
    int tamanho;

public:
    Pilha();
    ~Pilha();

    Nodo<T>* getTopo();
    Nodo<T>* getBase();
    int getTamanho();

    void push(T elemento);
    bool find(T elemento);
    T pop();

    Pilha<T> inverte();
    bool ehVazia();
    void imprime();
};

template<class T>
Pilha<T>::~Pilha(){}

template<class T>
Pilha<T>::Pilha(){
    base = nullptr;
    topo = nullptr;
    tamanho = 0;
}

template<class T>
Nodo<T>* Pilha<T>::getTopo(){
    return topo;
}

template<class T>
Nodo<T>* Pilha<T>::getBase(){
    return base;
}

template<class T>
int Pilha<T>::getTamanho() { return tamanho; }

template<class T>
void Pilha<T>::push(T elemento){
    Nodo<T>* novo = new Nodo<T>(elemento);
    if (ehVazia()){
        base = novo;
        topo = novo;
    }
    else{
        if (topo != nullptr){
            topo->setProx(novo);
            novo->setAnt(topo);
            topo = novo;
        }
    }
    tamanho++;
}

template<class T>
T Pilha<T>::pop(){
    Nodo<T>* nodoParaRemover = topo;
    T elemento = nodoParaRemover->getElemento();
    if (topo == base) {
        base = nullptr;
        topo = nullptr;
    }
    else {
        topo = topo->getAnt();
        topo->setProx(nullptr);
    }

    delete nodoParaRemover;
    tamanho--;

    return elemento;
}

template<class T>
bool Pilha<T>::find(T elemento){
    Nodo<T>* aux = topo;
    while (aux != nullptr) {
        if (aux->getElemento() == elemento) {
            return true;
        }
        aux = aux->getAnt();
    }
return false;
}

template<class T>
Pilha<T> Pilha<T>::inverte(){
    Pilha<T> pilhaInvertida;
    Nodo<T>* antigoTopo = topo;
    Nodo<T>* antigoAnterior = nullptr;

    while (antigoTopo != nullptr) {
        pilhaInvertida.push(antigoTopo->getElemento());
        antigoAnterior = antigoTopo->getAnt();
        antigoTopo->setAnt(antigoTopo->getProx());
        antigoTopo->setProx(antigoAnterior);
        antigoTopo = antigoTopo->getProx();
    }

    antigoAnterior = topo;
    topo = base;
    base = antigoAnterior;

    return pilhaInvertida;
}

template<class T>
bool Pilha<T>::ehVazia(){
    if (topo == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

template<class T>
void Pilha<T>::imprime(){
  Nodo<T> *esteNodo = topo;
  while (esteNodo != nullptr){
    cout << esteNodo->getElemento() << endl;
    esteNodo = esteNodo->getAnt();
  };
}

#endif // PILHA_H
