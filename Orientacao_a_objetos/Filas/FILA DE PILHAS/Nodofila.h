#ifndef NODOFILA_H
#define NODOFILA_H

#include <iostream>
#include <string>
#include "Pessoa.h"

using namespace std;

template<class T>
class Nodofila {
private:
  T elemento;
  Nodofila *ant;
  Nodofila *prox;

public:
  Nodofila();
  ~Nodofila();
  Nodofila(T elemento);

  void setElemento(T elemento);
  void setPrioridade(Prioridade prioridade);
  void setProx(Nodofila *prox);
  void setAnt(Nodofila *ant);

  T getElemento();
  Prioridade getPrioridade();
  Nodofila *getProx();
  Nodofila *getAnt();

  void imprime();
};

template<class T>
Nodofila<T>::Nodofila(){}

template<class T>
Nodofila<T>::~Nodofila(){}

template<class T>
Nodofila<T>::Nodofila(T elemento) {
  this->elemento = elemento;
  this->prox = nullptr;
  this->ant = nullptr;
}

template<class T>
void Nodofila<T>::setElemento(T elemento){this->elemento = elemento;}

template<class T>
void Nodofila<T>::setPrioridade(Prioridade prioridade){elemento.setPrioridade(prioridade);}

template<class T>
void Nodofila<T>::setProx(Nodofila *prox){this->prox = prox;}

template<class T>
void Nodofila<T>::setAnt(Nodofila *ant){this->ant = ant;}

template<class T>
T Nodofila<T>::getElemento(){return elemento;}

template<class T>
Prioridade Nodofila<T>::getPrioridade(){return elemento.getPrioridade();}

template<class T>
Nodofila<T>* Nodofila<T>::getProx(){return prox;}

template<class T>
Nodofila<T>* Nodofila<T>::getAnt(){return ant;}

template<class T>
void Nodofila<T>::imprime(){
  elemento.imprime();
}

#endif // NODOFILA_H