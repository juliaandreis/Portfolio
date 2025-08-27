#include "pais.h"

int main () {
    Pais brasil("BRA","Brasil", 212583750, 8510417.771);
    Pais argentina("ARG","Argentina", 47327407, 2780400);
    Pais paraguai("PRY","Paraguai", 6109644, 406752);
    
    brasil.setFronteira(&argentina);
    brasil.setFronteira(&paraguai);
    argentina.setFronteira(&brasil);
    argentina.setFronteira(&paraguai);

    cout << brasil.verificaIgualdade(brasil) << endl;
    cout << brasil.verificaIgualdade(argentina) << endl;
    cout << brasil.verificaLimitrofe(&argentina) << endl;
    cout << brasil.getDensidadePopulacional() << endl;
    brasil.getVizinhosComuns(&argentina);

    return 0;

}
