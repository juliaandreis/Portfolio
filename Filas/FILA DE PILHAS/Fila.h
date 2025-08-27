#ifndef FILA_H
#define FILA_H

#include "Nodofila.h"

template<class T>
class Fila {
private:
    Nodofila<T> *inicio;
    Nodofila<T> *fim;
    int tamanho;

public:
    Fila();
    ~Fila();

    Nodofila<T>* getInicio();
    Nodofila<T>* getFim();
    int getTamanho();
    void setInicio(Nodofila<T>* novoInicio);
    void setFim(Nodofila<T>* novoFim);
    void setTamanho(int novoTamanho);

    void push_back(T elemento);
    void push_front(T elemento);
    T pop_back();
    T pop_front();

    T front();
    bool find(T elemento);
    void chegou(T elemento);
    T saiu();

    void inverte();
    void imprime();
    bool ehVazia();
};

template<class T>
Fila<T>::Fila(){
    inicio = nullptr;
    fim = nullptr;
    tamanho = 0;
}

template<class T>
Fila<T>::~Fila(){}

template<class T>
Nodofila<T>* Fila<T>::getInicio(){return inicio;}

template<class T>
Nodofila<T>* Fila<T>::getFim(){return fim;}

template<class T>
int Fila<T>::getTamanho(){return tamanho;}

template<class T>
void Fila<T>::setInicio(Nodofila<T>* novoInicio){this->inicio = inicio;}

template<class T>
void Fila<T>::setFim(Nodofila<T>* novoFim){this->fim = fim;}

template<class T>
void Fila<T>::setTamanho(int novoTamanho){this->tamanho = tamanho;}

template<class T>
void Fila<T>::push_back(T elemento){
    Nodofila<T> *novo = new Nodofila<T>(elemento);
    if (inicio == nullptr){
        inicio = novo;
        fim = novo;
    }
    else{
        novo->setAnt(fim);
        fim->setProx(novo);
        fim = novo;
    }
    tamanho++;
}

template<class T>
void Fila<T>::push_front(T elemento){
    Nodofila<T> *novo = new Nodofila<T>(elemento);
    if (inicio == nullptr){
        inicio = novo;
        fim = novo;
    }
    else{
        novo->setProx(inicio);
        inicio->setAnt(novo);
        inicio = novo;
    }
    tamanho++;
}

template<class T>
T Fila<T>::pop_back(){
    if (fim == nullptr) {
        return -1;
    }
    T elemento = fim->getElemento();
    Nodofila<T>* temp = fim;
    if (inicio == fim) {
        inicio = nullptr;
        fim = nullptr;
    } else {
        fim = fim->getAnt();
        fim->setProx(nullptr);
    }
    delete temp;
    tamanho--;
    return elemento;
}

template<class T>
T Fila<T>::pop_front(){
    if (inicio == nullptr) {
        return -1;
    }
    T elemento = inicio->getElemento();
    Nodofila<T>* temp = inicio;
    if (inicio == fim) {
        inicio = nullptr;
        fim = nullptr;
    } else {
        inicio = inicio->getAnt();
        inicio->setProx(nullptr);
    }
    delete temp;
    tamanho--;
    return elemento;
}

template<class T>
T Fila<T>::front(){
    return inicio->getElemento();
}

template<class T>
bool Fila<T>::find(T letra){
    while (fim!=nullptr){
        if (fim->getElemento() == letra){
            return true;
        }
    }
return false;
}

template<class T>
void Fila<T>::chegou(T elemento){
    Nodofila<T> *novo = new Nodofila<T>(elemento);

    if (inicio == nullptr) {
        inicio = novo;
        fim = novo;
    } else {
        Nodofila<T> *atual = inicio;

        while (atual != nullptr && atual->getPrioridade() >= novo->getPrioridade()) {
            atual = atual->getProx();
        }

        if (atual == inicio) {
            novo->setProx(inicio);
            inicio->setAnt(novo);
            inicio = novo;
        } else if (atual == nullptr) {
            fim->setProx(novo);
            novo->setAnt(fim);
            fim = novo;
        } else {
            Nodofila<T> *anterior = atual->getAnt();
            novo->setProx(atual);
            novo->setAnt(anterior);
            anterior->setProx(novo);
            atual->setAnt(novo);
        }
    }

    tamanho++;
}

/*
template<class T>
void Fila<T>::chegou(T elemento){
    Nodo<T> *novo = new Nodo<T>(elemento);
    if (inicio == nullptr) {
        inicio = novo;
        fim = novo;
    } else {
        Nodo<T> *atual = fim;
        while (atual != nullptr && atual->getPrioridade() < novo->getPrioridade()) {
            atual = atual->getAnt();
        }
        if (atual == nullptr) {
            novo->setProx(inicio);
            inicio->setAnt(novo);
            inicio = novo;
        } else if (atual == fim) {
            novo->setProx(fim);
            fim->setAnt(novo);
            fim = novo;
        } else {
            Nodo<T> *anterior = atual->getAnt();
            novo->setProx(atual);
            novo->setAnt(anterior);
            atual->setAnt(novo);

            if (anterior != nullptr) {
                anterior->setProx(novo);
            } else {
                inicio = novo;
            }
            
            if (atual) atual->imprime();
            if (anterior) anterior->imprime();
            if (novo) novo->imprime();
        }
    }
    tamanho++;
}*/

template<class T>
T Fila<T>::saiu(){
    T elemento = inicio->getElemento();
    inicio = inicio->getProx();
    if (inicio != nullptr) {
        inicio->setAnt(nullptr);
        tamanho--;
    } else {
        tamanho = 0;
    }
    return elemento;
}

template<class T>
void Fila<T>::imprime(){
    Nodofila<T> *atual = inicio;
    while (atual != nullptr) {
        atual->imprime();
        cout << endl;
        atual = atual->getProx();
    }
}

template<class T>
bool Fila<T>::ehVazia(){
    if (inicio == nullptr){
        return true;
    }
    else {
        return false;
    }
}

#endif // FILA_H