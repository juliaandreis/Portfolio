#include "Calculadora.h"
#include "Empresa.h"
#include "FuncionarioCaixa.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  Calculadora<int> calc1("Azul");
  Calculadora<float> calc2("Vermelha");

  int a1 = 2;
  FuncionarioCaixa funcionario1("Ana", "Rua das Flores, 123", calc1);
  FuncionarioCaixa funcionario2("Maria Santos", "Avenida Central, 456", calc2);

  cout << "F1 Soma: " << funcionario1.soma(a1, a1) << endl;
  cout << "F1 Subtracao: " << funcionario1.subtrai(5, 4) << endl;
  cout << "F1 Multiplicacao: " << funcionario1.multiplica(2, 3) << endl;
  cout << endl;
  cout << "F2 Divisao: " << funcionario2.divide(6, 3) << endl;
  cout << "F2 Soma: " << funcionario2.soma(7, 2) << endl;
  cout << "F2 Multiplicacao: " << funcionario2.multiplica(8, 3) << endl;
  cout << endl;

  Empresa empresa1("Amazon", funcionario1, funcionario2);
  empresa1.imprime_info();

  return 0;
}
