#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
#include <queue>

template<class T>
class Lista {
private:
    Nodo<T> *inicio;
    Nodo<T> *fim;
    int tamanho;

public:
    Lista();
    ~Lista();

    Nodo<T>* getInicio();
    Nodo<T>* getFim();
    int getTamanho();
    void setInicio(Nodo<T>* novoInicio);
    void setFim(Nodo<T>* novoFim);

    void push(T elemento);
    void push_back(T elemento);
    void push_front(T elemento);
    T pop_back();
    T pop_front();

    T front();
    bool find(string palavra);
    T saiu();

    void inverte();
    void imprime();
    bool ehVazia();
    T pop_midle(int posicao);
};

template<class T>
Lista<T>::Lista(){
    inicio = nullptr;
    fim = nullptr;
    tamanho = 0;
}

template<class T>
Lista<T>::~Lista(){}

template<class T>
Nodo<T>* Lista<T>::getInicio() { return inicio; }

template<class T>
Nodo<T>* Lista<T>::getFim() { return fim; }

template<class T>
int Lista<T>::getTamanho() { return tamanho; }

template<class T>
void Lista<T>::setInicio(Nodo<T>* novoInicio) { inicio = novoInicio; }

template<class T>
void Lista<T>::setFim(Nodo<T>* novoFim) { fim = novoFim; }

template<class T>
void Lista<T>::push_back(T elemento){
    Nodo<T> *novo = new Nodo<T>(elemento);
    if (inicio == nullptr){
        inicio = novo;
        fim = novo;
    }
    else{
        novo->setAnterior(fim);
        fim->setProximo(novo);
        fim = novo;
    }
    tamanho++;
}

template<class T>
void Lista<T>::push(T elemento){
    Nodo<T> *novo = new Nodo<T>(elemento);

    if (inicio == nullptr) {
        inicio = novo;
        fim = novo;
    } else {
        Nodo<T> *atual = inicio;

        while (atual != nullptr && atual->getIniciativa() >= novo->getIniciativa()) {
            atual = atual->getProximo();
        }

        if (atual == inicio) {
            push_front(novo->getElemento());
        } else if (atual == nullptr) {
            push_back(novo->getElemento());
        } else {
            Nodo<T> *anterior = atual->getAnterior();

            novo->setAnterior(anterior);
            novo->setProximo(atual);
            atual->setAnterior(novo);
            anterior->setProximo(novo);
        }
    }

    tamanho++;
}

template<class T>
void Lista<T>::push_front(T elemento){
    Nodo<T> *novo = new Nodo<T>(elemento);
    if (inicio == nullptr){
        inicio = novo;
        fim = novo;
    }
    else{
        novo->setProximo(inicio);
        inicio->setAnterior(novo);
        inicio = novo;
    }
    tamanho++;
}

template<class T>
T Lista<T>::pop_back(){
    if (fim == nullptr) {
        return T();
    }

    T elemento = fim->getElemento();
    Nodo<T>* temp = fim;

    if (inicio == fim) {
        inicio = nullptr;
        fim = nullptr;
    } else {
        fim = fim->getAnterior();
        fim->setProximo(nullptr);
    }

    delete temp;
    tamanho--;
    return elemento;
}

template<class T>
T Lista<T>::pop_front(){
    if (inicio == nullptr) {
        return T();
    }

    T elemento = inicio->getElemento();
    Nodo<T>* temp = inicio;

    if (inicio == fim) {
        inicio = nullptr;
        fim = nullptr;
    } else {
        inicio = inicio->getProximo();
        inicio->setAnterior(nullptr);
    }

    delete temp;
    tamanho--;
    return elemento;
}

template<class T>
T Lista<T>::front(){return inicio->getElemento();}

template<class T>
bool Lista<T>::find(string palavra){
    Nodo<T> *atual = inicio;
    while (atual != nullptr){
        if (atual->getPlaca() == palavra){
            return true;
        }
        atual = atual->getProximo();
    }
    return false;
}

template<class T>
T Lista<T>::saiu(){
    T elemento = inicio->getElemento();
    inicio = inicio->getAtras();
    if (inicio != nullptr) {
        inicio->setFrente(nullptr);
        tamanho--;
    } else {
        tamanho = 0;
    }
    return elemento;
}

template<class T>
void Lista<T>::inverte() {
    Nodo<T>* atual = inicio;
    Nodo<T>* temp = nullptr;

    while (atual != nullptr) {
        temp = atual->getFrente();
        atual->setFrente(atual->getAtras());
        atual->setAtras(temp);
        atual = atual->getFrente();
    }

    temp = inicio;
    inicio = fim;
    fim = temp;
}

template<class T>
void Lista<T>::imprime(){
    Nodo<T> *atual = inicio;
    while (atual != nullptr) {
        atual->imprime();
        atual = atual->getProximo();
    }
}

template<class T>
bool Lista<T>::ehVazia(){
    if (inicio == nullptr){
        return true;
    }
    else {
        return false;
    }
}

template<class T>
T Lista<T>::pop_midle(int posicao){
    if (posicao < 0 || posicao >= tamanho) {
        return T();
    }

    if (posicao == 0) {
        return pop_front();
    }

    if (posicao == tamanho - 1) {
        return pop_back();
    }

    Nodo<T> *atual = inicio;
    
    for (int i = 0; i < posicao; i++){
        atual = atual->getProximo();
    }

    atual->imprime();

    Nodo<T> *anterior = atual->getAnterior();
    Nodo<T> *proximo = atual->getProximo();

    anterior->setProximo(proximo);
    proximo->setAnterior(anterior);

    tamanho--;

    return atual->getElemento();
}

#endif // LISTA_H