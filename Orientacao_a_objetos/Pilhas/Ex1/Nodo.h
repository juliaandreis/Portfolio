#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <string>

using namespace std;

template<class T>
class Nodo{
private:
  T elemento;
  Nodo<T> *prox;
  Nodo<T> *ant;

public:
  Nodo<T>();
  ~Nodo<T>();
  Nodo<T>(T elemento);

  void setElemento(T elemento);
  void setProx(Nodo<T> *prox);
  void setAnt(Nodo<T> *ant);

  Nodo<T> *getProx();
  Nodo<T> *getAnt();
  T getElemento();

  void imprime();
};

template<class T>
Nodo<T>::Nodo(){}

template<class T>
Nodo<T>::~Nodo(){}

template<class T>
Nodo<T>::Nodo(T elemento){
  this->elemento = elemento;
  this->prox = nullptr;
  this->ant = nullptr;
}

template<class T>
void Nodo<T>::setElemento(T elemento){
  this->elemento = elemento;
}

template<class T>
void Nodo<T>::setProx(Nodo<T> *prox){
  this->prox = prox;
}

template<class T>
void Nodo<T>::setAnt(Nodo<T> *ant){
  this->ant = ant;
}

template<class T>
Nodo<T>* Nodo<T>::getAnt(){return ant;}

template<class T>
T Nodo<T>::getElemento(){return elemento;}

template<class T>
Nodo<T>* Nodo<T>::getProx(){return prox;}

template<class T>
void Nodo<T>::imprime(){
  cout << elemento << endl;
}

#endif // NODO_H