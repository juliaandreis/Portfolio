#include "Teste.h"
#include <iostream>

using namespace std;

int main() {
  Teste<int> t1;

  int x, y;
  cin >> x >> y;
  cout << t1.imprime(x, y);
  
  Teste<bool> t2;

  bool a, b;
  cin >> a >> b;
  cout << t2.imprime(a, b);

  return 0;
}