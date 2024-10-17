// Part+101 - Defini��o da classe Poly
#include "Poly.h"
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

// Construtor default para polin�mios vazios
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
        a[i] = 0.0; // Atribue zero a todos os coeficientes que n�o sejam o a maior
    }
    a[G] = 1.0; // Atribui 1.0 ao coeficiente de maior grau
  }
}

// Construtor por c�pia
Poly::Poly(const Poly& P): grau(P.grau), a(nullptr){
  if (grau>=0){ // Aloca��o da mem�ria
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

// Sobrecarga do operador de atribui��o por c�pia
Poly& Poly::operator=(const Poly& P)
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

// Sobrecarga do operador de atribui��o por movimento
Poly& Poly::operator=(Poly&& P) noexcept{
  delete[] a; // Libera mem�ria anterior
  // Transferencia do conte�do
  grau = P.grau;
  a = P.a;
  // Zera o array provisorio
  P.grau = -1;
  P.a = nullptr;
  return *this;
}

//Sobrecarga do operador []
double Poly::operator[](int i) const{
  return this->getCoef(i); // Operador que retorna a mesma coisa de getCoef
}

// Sobrecarga do operador de compara��o
bool Poly::operator==(const Poly& P)const{
  if (this->grau == P.grau){ // Checar se os graus s�o iguais
    for(int i = 0; i < P.grau; i++){
      if(this->a[i] != P.a[i]) return false; // Compara se os coeficientes s�o diferentes e retorna false caso sejam
    }
    return true; // Retorna true se todos os coeficientes forem iguais
  }
  return false; // Retorna falso se os graus n�o forem iguais
}

// Sobrecarga do operador de diferen�a
bool Poly::operator!=(const Poly& P)const{
  if(*this == P) return false; // Retorna falso se os polinomios forem iguais
  return true; // Retorna true em todos os outros casos
}

// Sobrecarga do operador ()
double Poly::operator()(double x)const{
  return this->getValor(x);
}

// Sobrecarga do operador para sa�da de dados
ostream& operator<<(ostream& X, const Poly& P)
{
  if(P.empty()) return X; // Se o polin�mio for vazio, retorna nada

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

// Sobrecarga do operador para entrada de dados
istream& operator>>(std::istream& X, Poly& P){
  if(P.empty()) return X; // Se o polin�mio for vazio, retorna nada

  for(int i = P.getGrau(); i >= 0; i--){ // For que corre pelos coeficientes
    cout << "x^" << i << ": ";
    X >> P.a[i]; // Entrada de dados
    while(i== P.getGrau() && P.getGrau() != 0 && P.a[i] == 0.0){ // Checagem se o maior coeficiente � zero
      cout << "x^" << i << ": ";
      X >> P.a[i];
    }
  }
  return X;
}

// Sobrecarga do operador - un�rio
Poly Poly::operator-() const{
  if(this->empty()) return *this; // O negativo de um vazio � vazio

  Poly prov(grau);
  for(int i = 0; i <=grau; ++i){
    prov.a[i] = - this->a[i]; // Adiciona o negativo dos coefiecientes na prov - posso usar o set coef?
  }
  return prov;
}

// Sobrecarga do operador + bin�rio
Poly Poly::operator+(const Poly& P) const{
  if(this->empty()) return P; // Soma com empty retorna o outro polin�mio
  if(P.empty()) return *this;
  // else
  if(this->isZero()) return P;  // Soma com nulo (exceto empty) retorna o outro polin�mio
  if(P.isZero()) return *this;

  int maiorGrau;
  maiorGrau = max(this->getGrau(), P.getGrau());
  Poly subtracao(maiorGrau);
  for(int i = 0; i <= maiorGrau; ++i){
    subtracao.a[i] = this->getCoef(i) + P[i]; // ver se tem como usar os colchetes no this
  }
  // precisa testar o polinomio provisorio
  Poly prov = subtracao;
  while(subtracao.getCoef(maiorGrau) == 0.0 && maiorGrau!= 0){
    maiorGrau -= 1;
    subtracao.recriar(maiorGrau);
    for(int i = 0; i <= maiorGrau; ++i){
      subtracao.a[i] = prov[i];
    }
  }
  return subtracao;
}

Poly Poly::operator-(const Poly &P) const{
  return operator+(-P);
}

Poly Poly::operator*(const Poly& P) const{
  if(this->empty()) return *this; // Multiplica��o com empty retorna o outro polin�mio
  if(P.empty()) return P;

  if(this->isZero()) return *this;  // Multiplica��o com nulo retorna o outro polin�mio
  if(P.isZero()) return P;

  Poly prov(P.getGrau() + this->getGrau());
  prov.a[prov.getGrau()] = 0.0; // Inicializar prov com zeros
  for(int i = 0; i <= this->getGrau(); ++i){
      for(int j = 0; j <= P.getGrau(); ++j){
        prov.a[i+j] = prov[i+j] + this->getCoef(i) * P[j];
      }
  }
  return prov;
}

// M�todo getGrau
int Poly::getGrau() const {
  return grau;
}

// M�todo getCoef
double Poly::getCoef(int i) const {
  if(i < 0 || i > grau){ // Checagem se o indice � poss�vel no polin�mio
    return 0.0;
  }
  else{
    return a[i];
  }
}

//M�todo setCoef
void Poly::setCoef(int i, double valor){
  if (i < 0 || i > grau){ // Testando se o indice � poss�vel
    cerr << "Indice invalido" << endl;
    return;
  }
  else if(valor == 0.0 && i == grau && grau > 0){ // Testando se o valor � poss�vel
    cerr << "Valor invalido" << endl;
    return;
  }
  else{
    a[i] = valor;
  }
}

//M�todo recriar - NOT SURE
void Poly::recriar(int novoGrau){
  //Poly prov(novoGrau); // Poly provisorio criado com o construtor espec�fico
  //*this = move(prov);
  *this = move(Poly(novoGrau)); // move n�o � necess�rio nesse caso
}

// M�todo empty
bool Poly::empty()const{
  if(this->getGrau() < 0) return true; // Retorna true se grau negativos
  return false; // Retorna false em todos os outros casos
}

// M�todo isZero
bool Poly::isZero()const{
  if(this->getGrau() == 0 && this->getCoef(0)==0.0) return true; // Retorna true se grau zero e coeficinte zero
  return false; // Retorna false em todos os outros casos
}

// M�todo getValor
double Poly::getValor(double x)const{
  if(this->empty()) return 0.0;

  double soma(0.0);
  for (int i = 0; i <= this->getGrau(); ++i){
    soma = soma + this->getCoef(i) * pow(x, i);
  }
  return soma;
}

// M�todo salvar
bool Poly::salvar(const string& nomeArquivo) const
{
  ofstream arquivo(nomeArquivo);
  if (!arquivo.is_open()) return false; // Teste para ver se o arquivo foi aberto

  arquivo << "POLY " << grau << endl;
  for(int i = 0; i<=grau; i++){
    arquivo << a[i] << " ";
  }
  arquivo << endl;
  return true;
}

bool Poly::ler(const std::string& nomeArquivo){
ifstream arquivo(nomeArquivo);
  if (!arquivo.is_open()) return false; // Retorna falso caso o arquvo n�o seja aberto

  string cabecalho;
  arquivo >> cabecalho; // Entrada do cabe�alho
  if (!arquivo || cabecalho!="POLY") return false; // Teste da leitura do arquivo e do cabe�alho correto

  int grauPolinomio;
  arquivo >> grauPolinomio; // Entrada do grau do polin�mio
  if(!arquivo) return false; // erro na leitura
  Poly prov(grauPolinomio); // Polinomio provisorio

  if(grauPolinomio < 0) return true; // Se o grau for negativo, n�o h� mais nada a ser lido
  for(int i = 0; i <= grauPolinomio; ++i){
    arquivo >> prov.a[i]; // entrada dos coeficientes
    if(!arquivo) return false;
  }
  if(prov.a[grauPolinomio] == 0.0 && grauPolinomio != 0) return false; // Teste se o polin�mio � valido
  *this = move(prov);
  return true;
}
