// Parte 01 do projeto - Declara��o da classe Poly
#ifndef POLY_H
#define POLY_H

#include <iostream>

class Poly{
private: /// Os dados das classes
  int grau; // Grau do polin�mio
  double *a; // Array de coeficientes do polin�mio (dimens�o: grau+1)
public:
  /// Construtores e o destrutor:
  Poly(); // Construtor default para polin�mios vazios
  explicit Poly(int G); // Construtor default para polin�mios com 1 parametro
  Poly(const Poly& P); // Construtor por c�pia
  Poly(Poly&& P) noexcept;// Construtor por movimento
  ~Poly(); // Destrutor

  /// Sobrecarga de operadores
  Poly &operator=(const Poly& P); // Sobrecarga do operador de atribui��o por c�pia
  Poly &operator=(Poly&& P) noexcept; // Sobrecarga do operador de atribui��o por movimento
  double operator[](int i) const; // Sobrecarga do operador []
  bool operator==(const Poly& P) const; // Sobrecarga do operador de compara��o
  bool operator!=(const Poly& P) const; // Sobrecarga do operador de diferen�a
  double operator()(double x) const; // Sobrecarga de operador para retornar valor do polin�mio
  friend std::ostream &operator<<(std::ostream& X, const Poly& P); // Sobrecarga do operador de escrita

  /// M�todos
  int getGrau() const; // M�todo que retorna o grau de um polin�mio
  double getCoef(int i) const; // M�todo que retorna o coeficiente do termo i
  void setCoef(int i, double valor); // M�todo que altera o coeficiente do termo i
  void recriar(int novoGrau); // M�todo para redefinir o grau
  bool empty() const; // M�todo que retorna true se polinomio vazio
  bool isZero() const; // M�todo que retorna se � um polin�mio nulo
  double getValor(double x) const; // M�todo que retorna o valor do polin�mio para um par�metro x
};
#endif //#ifndef POLY_H_