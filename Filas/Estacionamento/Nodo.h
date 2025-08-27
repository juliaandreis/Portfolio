#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <string>

using namespace std;

template<class T>
class Nodo {
private:
  T elemento;
  Nodo *anterior;
  Nodo *proximo;

public:
  Nodo();
  ~Nodo();
  Nodo(T elemento);

  void setElemento(T elemento);
  void setAnterior(Nodo *anterior);
  void setProximo(Nodo *proximo);

  T getElemento();
  Nodo *getAnterior();
  Nodo *getProximo();

  void imprime();

  string getPlaca();
};

template<class T>
Nodo<T>::Nodo(){}

template<class T>
Nodo<T>::~Nodo(){}

template<class T>
Nodo<T>::Nodo(T elemento) {
  this->elemento = elemento;
  this->proximo = nullptr;
  this->anterior = nullptr;
}

template<class T>
void Nodo<T>::setElemento(T elemento){this->elemento = elemento;}


template<class T>
void Nodo<T>::setAnterior(Nodo *anterior){this->anterior = anterior;}

template<class T>
void Nodo<T>::setProximo(Nodo *proximo){this->proximo = proximo;}

template<class T>
T Nodo<T>::getElemento(){return elemento;}

template<class T>
Nodo<T>* Nodo<T>::getAnterior(){return anterior;}

template<class T>
Nodo<T>* Nodo<T>::getProximo(){return proximo;}

template<class T>
void Nodo<T>::imprime(){
  elemento.imprime();
}

template<class T>
string Nodo<T>::getPlaca() {
  return elemento.getPlaca();
}

#endif // NODO_H
