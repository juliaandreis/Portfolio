#ifndef FILA_H
#define FILA_H

#include "Nodo.h"

template<class T>
class Fila {
private:
    Nodo<T> *inicio;
    Nodo<T> *fim;
    int tamanho;

public:
    Fila();
    ~Fila();

    Nodo<T>* getInicio();
    Nodo<T>* getFim();
    int getTamanho();
    void setInicio(Nodo<T>* novoInicio);
    void setFim(Nodo<T>* novoFim);
    void setTamanho(int novoTamanho);

    void push_back(T elemento);
    void push_front(T elemento);
    T pop_back();
    T pop_front();

    T front();
    bool find(string palavra);
   // void chegou(T elemento);
    T saiu();

    void inverte();
    void imprime();
    bool ehVazia();
    bool pop_midle(string placa);
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
Nodo<T>* Fila<T>::getInicio(){return inicio;}

template<class T>
Nodo<T>* Fila<T>::getFim(){return fim;}

template<class T>
int Fila<T>::getTamanho(){return tamanho;}

template<class T>
void Fila<T>::setInicio(Nodo<T>* novoInicio){inicio = novoInicio;}

template<class T>
void Fila<T>::setFim(Nodo<T>* novoFim){fim = novoFim;}

template<class T>
void Fila<T>::setTamanho(int novoTamanho){tamanho = novoTamanho;}

template<class T>
void Fila<T>::push_back(T elemento){
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
void Fila<T>::push_front(T elemento){
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
T Fila<T>::pop_back(){
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
T Fila<T>::pop_front(){
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
T Fila<T>::front(){return inicio->getElemento();}

template<class T>
bool Fila<T>::find(string palavra){
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
T Fila<T>::saiu(){
    T elemento = inicio->getElemento();
    inicio = inicio->getProximo();
    if (inicio != nullptr) {
        inicio->setAnterior(nullptr);
        tamanho--;
    } else {
        tamanho = 0;
    }
    return elemento;
}

template<class T>
void Fila<T>::inverte() {
    Nodo<T>* atual = inicio;
    Nodo<T>* temp = nullptr;

    while (atual != nullptr) {
        temp = atual->getAnterior();
        atual->setAnterior(atual->getProximo());
        atual->setProximo(temp);
        atual = atual->getAnterior();
    }

    temp = inicio;
    inicio = fim;
    fim = temp;
}

template<class T>
void Fila<T>::imprime(){
    Nodo<T> *atual = inicio;
    while (atual != nullptr) {
        atual->imprime();
        cout << endl;
        atual = atual->getProximo();
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

template<class T>
bool Fila<T>::pop_midle(string placa){
    if (!find(placa)) {
        return false;
    }

    Nodo<T> *atual = inicio;

    while (atual->getPlaca() != placa) {
        push_back(atual->getPlaca());
        atual = atual->getProximo();
        pop_front();
    }

    T saiu = pop_front();

    cout << "Saiu: " << saiu.getPlaca() << endl;

    return true;
}

#endif // FILA_H
