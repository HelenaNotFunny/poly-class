// Parte 01 do projeto - Declaração da classe Poly
#ifndef POLY_H
#define POLY_H

#include <iostream>

class Poly{
private: /// Os dados das classes
  int grau; // Grau do polinômio
  double *a; // Array de coeficientes do polinômio (dimensão: grau+1)
public:
  /// Construtores e o destrutor:
  Poly(); // Construtor default para polinômios vazios
  explicit Poly(int G); // Construtor default para polinômios com 1 parametro
  Poly(const Poly& P); // Construtor por cópia
  Poly(Poly&& P) noexcept;// Construtor por movimento
  ~Poly(); // Destrutor
  // Criar função void clear?

  /// Sobrecarga de operadores
  Poly& operator=(const Poly& P); // Sobrecarga do operador de atribuição por cópia
  Poly& operator=(Poly&& P) noexcept; // Sobrecarga do operador de atribuição por movimento
  double operator[](int i) const; // Sobrecarga do operador [] (getCoef)
  bool operator==(const Poly& P) const; // Sobrecarga do operador de comparação
  bool operator!=(const Poly& P) const; // Sobrecarga do operador de diferença
  double operator()(double x) const; // Sobrecarga de operador para retornar valor do polinômio
  friend std::ostream& operator<<(std::ostream& X, const Poly& P); // Sobrecarga do operador de saída de dados
  friend std::istream& operator>>(std::istream& X, Poly& P); // Sobrecarga do operador de entrada de dados
  Poly operator-() const; // Sobrecarga do operador - unário (retorna o negativo de um polinômio)
  Poly operator+(const Poly& P) const; // Sobrecarga do operador + binário (soma)
  Poly operator-(const Poly& P) const; // Sobrecarga do operador - binário (subtração)

  /// Métodos
  int getGrau() const; // Método que retorna o grau de um polinômio
  double getCoef(int i) const; // Método que retorna o coeficiente do termo i
  void setCoef(int i, double valor); // Método que altera o coeficiente do termo i
  void recriar(int novoGrau); // Método para redefinir o grau
  bool empty() const; // Método que retorna true se polinomio vazio
  bool isZero() const; // Método que retorna se é um polinômio nulo
  double getValor(double x) const; // Método que retorna o valor do polinômio para um parâmetro x
  bool salvar(const std::string& nomeArquivo) const; // Método para salvar polinômio em arquivo
  bool ler(const std::string& nomeArquivo); // Método para ler um polinômio de um arquivo
};
#endif //#ifndef POLY_H_
