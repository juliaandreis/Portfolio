#pragma once
#include <iostream>
#include <string>
#include "Calculadora.h"

using namespace std;

class FuncionarioCaixa{
    public:
        //Construtor e destrutor:
        FuncionarioCaixa();
        FuncionarioCaixa(string nomes, string enderecos,  Calculadora calc);
        ~FuncionarioCaixa();

        //Metodos de entrada:
        string getNome();
        void setNome(string novoNome);
        string getEndereco();
        void setEndereco(string novoEndereco);

        //Metodos calculadora:
        float soma (float x, float y);
        float subtrai (float x, float y);
        float multiplica (float x, float y);
        float divide (float x, float y);
        int eleva_ao_quadrado(int x);
        int eleva_ao_cubo(int x);

        void imprime_info();

    private:
        string nome;
        string endereco;
        Calculadora calculadora;
};

//Construtor e destrutor:
FuncionarioCaixa::FuncionarioCaixa(){}

FuncionarioCaixa::~FuncionarioCaixa(){}

FuncionarioCaixa::FuncionarioCaixa(string nomes, string enderecos, Calculadora calc){
    nome = nomes;
    endereco = enderecos;
    calculadora = calc;
}

//Metodos de entrada:
string FuncionarioCaixa::getNome(){return nome;}

void FuncionarioCaixa::setNome(string novoNome){nome = novoNome;}

string FuncionarioCaixa::getEndereco(){return endereco;}

void FuncionarioCaixa::setEndereco(string novoEndereco){endereco = novoEndereco;}

//Metodos calculadora:
float FuncionarioCaixa::soma (float x, float y){
    return (calculadora.soma(x,y));
}

float FuncionarioCaixa::subtrai (float x, float y){
    return (calculadora.subtrai(x,y));
}
float FuncionarioCaixa::multiplica (float x, float y){
    return (calculadora.multiplica(x,y));
}
float FuncionarioCaixa::divide (float x, float y){
    return (calculadora.divide(x,y));
}
int FuncionarioCaixa::eleva_ao_quadrado(int x){
    return (calculadora.eleva_ao_quadrado(x));
}
int FuncionarioCaixa::eleva_ao_cubo(int x){
    return (calculadora.eleva_ao_cubo(x));
}

void FuncionarioCaixa::imprime_info(){
    cout << "Nome: " << nome << endl;
    cout << "Endereco: " << endereco << endl;
    calculadora.imprime_info();
}