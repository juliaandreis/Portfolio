#include "pais.h"
#include <iostream>
#include <string>

int main() {
  Pais brasil("BRA", "Brasil", 212583750, 8510417.771);
  Pais argentina("ARG", "Argentina", 47327407, 2780400);
  Pais paraguai("PRY", "Paraguai", 6109644, 406752);

  brasil.setFronteira(&argentina);
  brasil.setFronteira(&paraguai);
  argentina.setFronteira(&brasil);
  argentina.setFronteira(&paraguai);

  cout << brasil.verificaIgualdade(brasil) << endl;
  cout << brasil.verificaIgualdade(argentina) << endl;
  cout << brasil.verificaLimitrofe(&argentina) << endl;
  cout << brasil.getDensidadePopulacional() << endl;
  Pais** vizinhos = brasil.getVizinhosComuns(&argentina);
  for (int i = 0; i < 40; i++){
    if (vizinhos[i] != nullptr){
      cout << vizinhos[i]->getNome() << endl;
    }
  }

  return 0;
}
