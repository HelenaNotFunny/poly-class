// Part+101 - Definição da classe Poly
#include "Poly.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Construtor default para polinômios vazios
Poly::Poly(): grau(-1), a(nullptr) {}

// Construtor default com 1 parametro
Poly::Poly(int G): grau(G), a(nullptr)
{
  if (G < 0){ // Parametro negativo criar polinomio identico ao default
    grau = -1;
    a = nullptr;
  }
  else if (G == 0){ // Parametro nulo
    grau = 0;
    a = new double[1];
    a[0] = 0.0;
  }
  else{ // Parametro maior que 0
    grau = G;
    a = new double[G+1];
    for(int i=0; i < G; i++) {
        a[i] = 0.0;
    }
    a[G] = 1.0;
  }
}

// Construtor por cópia
Poly::Poly(const Poly& P): grau(P.grau), a(nullptr){
  if (grau>=0){ // Alocação da memória
      a = new double[grau+1];
    }
  for (int i=0; i<=grau; i++){ // Copia dos coeficientes
      a[i] = P.a[i];
    }
}

//Construtor por movimento
Poly::Poly(Poly&& P) noexcept: grau(P.grau), a(P.a)
{
  P.grau = -1;
  P.a = nullptr;
}

// Destrutor
Poly::~Poly()
{
  delete[] a;
}

// Sobrecarga do operador de atribuição por cópia
Poly &Poly::operator=(const Poly& P)
{
  if (this == &P) return *this;
  if(grau != P.grau){
    delete[] a;
    grau = P.grau;
    if (grau > 0) a = new double [grau+1];
    else a = nullptr;
  }
  for (int i = 0; i <=grau; i++){
    a[i] = P.a[i];
  }
  return *this;
}

// Sobrecarga do operador de atribuição por movimento
Poly &Poly::operator=(Poly&& P) noexcept{
  delete[] a; // Libera memória anterior
  // Transferencia do conteúdo
  grau = P.grau;
  a = P.a;
  // Zera o array provisorio
  P.grau = -1;
  P.a = nullptr;
  return *this;
}

//Sobrecarga do operador []
double Poly::operator[](int i) const{
  return this->getCoef(i);
}

// Sobrecarga do operador de comparação
bool Poly::operator==(const Poly& P)const{
  if (this->grau == P.grau){
    for(int i = 0; i < P.grau; i++){
      if(this->a[i] != P.a[i]) return false;
    }
    return true;
  }
  return false;
}

// Sobrecarga do operador de diferença
bool Poly::operator!=(const Poly& P)const{
  if(*this == P) return false;
  return true;
}

// Sobrecarga do operador ()
double Poly::operator()(double x)const{
  return this->getValor(x);
}

ostream &operator<<(ostream& X, const Poly& P)
{
  if(P.empty()) return X;
  for(int i = P.getGrau(); i >=0; i--){
    if(P[i]== 0.0){
      if(i==0 && P.getGrau()==0) X << P[i];
    }
    else{
        if(P[i] < 0.0) X << '-';
        else{
          if(i!= P.getGrau()) X << '+';
        }
        if(abs(P[i]) != 1.0 || i == 0) X << abs(P[i]);
        if(i != 0){
          if(abs(P[i]) != 1.0) X << '*';
            X << 'x';
          if(i > 1){
            X << '^';
            X << i;
          }
        }
    }
  }
  return X;
}

// Método getGrau
int Poly::getGrau() const {
  return grau;
}

// Método getCoef
double Poly::getCoef(int i) const {
  if(i < 0 || i > grau){ // Checagem se o indice é possível no polinômio
    return 0.0;
  }
  else{
    return a[i];
  }
}

//Método setCoef
void Poly::setCoef(int i, double valor){
  if (i < 0 || i > grau){ // Testando se o indice é possível
    cerr << "Indice invalido" << endl;
    return;
  }
  else if(valor == 0.0 && i == grau && grau > 0){ // Testando se o valor é possível
    cerr << "Valor invalido" << endl;
    return;
  }
  else{
    a[i] = valor;
  }
}

//Método recriar - NOT SURE
void Poly::recriar(int novoGrau){
  Poly prov(novoGrau);
  *this = move(prov);
}

// Método empty
bool Poly::empty()const{
  if(this->getGrau() < 0) return true;
  return false;
}

// Método isZero
bool Poly::isZero()const{
  if(this->getGrau() == 0 && this->getCoef(0)==0.0) return true;
  return false;
}

// Método getValor
double Poly::getValor(double x)const{
  if(this->empty()) return 0.0;
  double soma(0.0);
  for (int i = 0; i <= this->getGrau(); ++i){
    soma = soma + this->getCoef(i) * pow(x, i);
  }
  return soma;
}

