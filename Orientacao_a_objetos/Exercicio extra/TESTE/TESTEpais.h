#pragma once
#include <iostream>
#include <string>

using namespace std;

class Pais {
    private:
        string codigoISO;
        string nome;
        int populacao;
        float dimensao;
        Pais** fronteiras[40];
        int nf;

    public:
        Pais();
        ~Pais();

        //get set
        Pais(string codigoISO, string nome, int populacao, float dimensao);
        void setFronteira(Pais *p);
        string getCodigoISO();
        string getNome();
        int getPopulacao();
        float getDimensao();
    
        //metodos
        bool verificaIgualdade(Pais p);
        bool verificaLimitrofe(Pais *p);
        float getDensidadePopulacional();  
        Pais** getVizinhosComuns(Pais *p);
};