#pragma once
#include <iostream>
#include <string>
#include "FuncionarioCaixa.h"

using namespace std;

class Empresa {
public:
    Empresa();
  Empresa(string nomeEmpresa, FuncionarioCaixa f1, FuncionarioCaixa f2);
  ~Empresa();

  void setNomeEmpresa(string nomeEmpresa);
  string getNomeEmpresa();
  void setFuncionario1(FuncionarioCaixa f1);
  void setFuncionario2(FuncionarioCaixa f2);
  FuncionarioCaixa getFuncionario1();
  FuncionarioCaixa getFuncionario2();
  void imprime_info();

private:
  string nome;
  FuncionarioCaixa funcionario1;
  FuncionarioCaixa funcionario2;
};

Empresa::Empresa(){}

Empresa::~Empresa(){}

Empresa::Empresa(string nomeEmpresa, FuncionarioCaixa f1, FuncionarioCaixa f2){
    nome = nomeEmpresa;
    funcionario1 = f1;
    funcionario2 = f2;
}

void Empresa::setNomeEmpresa(string nomeEmpresa){
    nome = nomeEmpresa;
}

string Empresa::getNomeEmpresa(){
    return nome;
}

void Empresa::setFuncionario1(FuncionarioCaixa f1){
    funcionario1 = f1;
}

FuncionarioCaixa Empresa::getFuncionario1(){
    return funcionario1;
}

void Empresa::setFuncionario2(FuncionarioCaixa f2){
    funcionario2 = f2;
}

FuncionarioCaixa Empresa::getFuncionario2(){
    return funcionario2;
}

void Empresa::imprime_info(){
    cout << "Empresa: " << nome << endl;
    funcionario1.imprime_info();
    cout << endl;
    funcionario2.imprime_info();
}