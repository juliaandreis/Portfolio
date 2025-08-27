#include "Fila.h"
#include <ctime>
#include <cstdlib>


int main() {
    Fila<Pessoa> fila;
    int total_chegadas = 0;
    int total_saidas = 0;

    srand(time(0));

    int iteracoes;
    cout << "Digite o numero de iteracoes: ";
    cin >> iteracoes;

    for (int i = 0; i < iteracoes; i++) {
        int chegada_pessoas = rand() % 4 + 2;
        cout << "chegaram: " << chegada_pessoas << endl;
        int saida_pessoas = rand() % 3;
        cout << "sairam: " << saida_pessoas << endl;

        total_chegadas += chegada_pessoas;
        total_saidas += saida_pessoas;

        for (int j = 0; j < chegada_pessoas; j++){
          Prioridade prioridade;
          int priorid = rand() % 3;
          cout << priorid << endl;

          switch (priorid) {
              case 0:
                  prioridade = BAIXA;
                  break;
              case 1:
                  prioridade = MEDIA;
                  break;
              case 2:
                  prioridade = ALTA;
                  break;
          }
          Pessoa pessoa(prioridade);
          fila.chegou(pessoa);
        }
        //cout << "Fila antes de sairem as pessoas: " << endl;
        //fila.imprime();
        for (int a = 0; a < saida_pessoas; a++){
          if (fila.ehVazia()){
            cout << "Fila vazia" << endl;
          }
          else{
            fila.saiu();
          }
        }
        cout << "Fila atual: " << endl;
        fila.imprime();
        cout << "------------------------" << endl;
    }

    cout << "Total de chegadas: " << total_chegadas << endl;
    cout << "Media de chegadas: " << (total_chegadas / static_cast<double>(iteracoes)) << endl;
    cout << "Total de saidas: " << total_saidas << endl;
    cout << "Media de saidas: " << (total_saidas / static_cast<double>(iteracoes)) << endl;

    return 0;
}