#include "pais.h"

using namespace std;

//construtor e destrutor
Pais::Pais(){}

Pais::~Pais(){}

Pais::Pais(string codigoISO, string nome, int populacao, float dimensao){
    this->codigoISO = codigoISO;
    this->nome = nome;
    this->populacao = populacao;
    this->dimensao = dimensao;
    fronteiras = new Pais*[40];
    for (int i = 0; i < 40; i++) {
        fronteiras[i] = nullptr; // Inicializa todos os ponteiros como nulos
    }
    nf = 0;
}

string Pais::getCodigoISO(){
    return codigoISO;
}

string Pais::getNome(){
    return nome;
}

int Pais::getPopulacao(){
    return populacao;
}

float Pais::getDimensao(){
    return dimensao;
}

bool Pais::verificaIgualdade(Pais p){
    return this->codigoISO == p.getCodigoISO();
}

void Pais::setFronteira(Pais *p){
    if (nf<40){
        fronteiras[nf] = p;
        nf++
}
    
bool Pais::verificaLimitrofe(Pais *p){
    if (!verificaIgualdade(*p)){
        for (int i = 0; i < nf; i++) {
            if (fronteiras[i] == p) {
                return true;
            }
        }
    }
    return false;
}

float Pais::getDensidadePopulacional(){
    return((float)populacao/dimensao);
} 

Pais** Pais::getVizinhosComuns(Pais *p){
    Pais *resultado[40];
    int k = 0;
    if (!verificaIgualdade(*p)){
        for (int i = 0; i < nf; i++) {
            for (int j = 0; j < p->nf; j++){
                if (fronteiras[i] != nullptr && p->fronteiras[j] != nullptr && fronteiras[i] == p->fronteiras[j]) {
                    resultado[k] = p->fronteiras[j];
                    k++;
                }
            }
        }
    } 
    return resultado;
}

