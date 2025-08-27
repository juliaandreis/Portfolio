template<class T>
class Teste {
  public:
    Teste();
    ~Teste();
    T imprime(T valor1, T valor2);
};

template<class T>
Teste<T>::Teste(){}

template<class T>
Teste<T>::~Teste(){}

template<class T>
T Teste<T>::imprime(T valor1, T valor2){
  return valor1 + valor2;
}

template<>
bool Teste<bool>::imprime(bool valor1, bool valor2){
   return valor1 || valor2;
}