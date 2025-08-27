#pragma once
#include <iostream>
#include <string>

using namespace std;

class Calculadora{
    public:
        Calculadora();
        Calculadora(string);
        ~Calculadora();
        float getMemoria();
        void setMemoria(float);
        string getCor();
        void setCor(string);
        float soma (float, float);
        float subtrai (float, float);
        float multiplica (float, float);
        float divide (float, float);
        int eleva_ao_quadrado(int);
        int eleva_ao_cubo(int);
        void imprime_info();

    private:
        string cor;
        float memoria;
};

Calculadora::Calculadora(){}

Calculadora::~Calculadora(){}

Calculadora::Calculadora(string novaCor){
    memoria = 0;
    cor = novaCor;
}

float Calculadora::getMemoria(){
    return memoria;
}
void Calculadora::setMemoria(float valor){
    memoria = valor;
}
string Calculadora::getCor(){
    return cor;
}
void Calculadora::setCor(string novaCor){
    cor = novaCor;
}

float Calculadora::soma (float x, float y){
    memoria = (x + y);
    return (x + y);
}
float Calculadora::subtrai (float x, float y){
    memoria = (x - y);
    return (x - y);
}
float Calculadora::multiplica (float x, float y){
    memoria = (x * y);
    return (x * y);
}
float Calculadora::divide (float x, float y){
    memoria = (x / y);
    return (x / y);
}

int Calculadora::eleva_ao_quadrado(int x){
    memoria = (x*x);
    return (x*x);
}
int Calculadora::eleva_ao_cubo(int x){
    memoria = (x*x*x);
    return (x*x*x);
}

void Calculadora::imprime_info(){
    cout << "Cor da calculadora: " << cor << endl;
    cout << "Memória: " << memoria << endl;
}