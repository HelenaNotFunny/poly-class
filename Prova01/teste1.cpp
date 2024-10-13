#include <iostream>
#include <string>

#include "Poly.h"

using namespace std;

// Funcao para imprimir as informacoes sobre um Poly
void imprimir(const string& Nome, const Poly& P)
{
  cout << Nome << '\t'
       << "Grau=" << P.getGrau() << '\t'
       << "coef(0)=" << P.getCoef(0) << '\t'
       << "coefs=[";
  for (int i=0; i<=P.getGrau(); ++i)
  {
    cout << P.getCoef(i);
    if (i<P.getGrau()) cout << ' ';
  }
  cout << "]\n";
}

// Funcao que inicializa e retorna um Poly
// Ao retornar, pode usar o construtor por movimento
Poly inicializa()
{
  Poly prov(2);
  for (int i=0; i<=prov.getGrau(); ++i) prov.setCoef(i, 666.6);
  return prov;
}

int main(void)
{
  int i;
  // Testando o construtor default;

  cout << "==========\n";
  Poly P0;
  imprimir("P0",P0);   // OK - deve imprimir [] - OK
  P0.setCoef(0, -3.5); // Deve dar erro (indice) - OK

  // Testando o construtor especifico;

  cout << "==========\n";
  Poly P1(-10);
  imprimir("P1",P1);   // OK - deve imprimir [] - OK
  P1.setCoef(0, -3.5); // Deve dar erro (indice) - OK

  Poly P2(0);
  imprimir("P2",P2);   // OK - deve imprimir [0] - OK
  P2.setCoef(0, 0.0);  // OK
  imprimir("P2",P2);   // OK - deve imprimir [0] - OK
  P2.setCoef(0, -3.5); // OK
  imprimir("P2",P2);   // OK - deve imprimir [-3.5] - OK
  P2.setCoef(1, 4.5);  // Deve dar erro (indice) - OK

  Poly P3(2);
  imprimir("P3",P3);   // OK - deve imprimir [0 0 1] - OK
  // Alterando P3
  for (i=0; i<=P3.getGrau(); ++i) P3.setCoef(i, i+0.7); // OK
  imprimir("P3",P3);   // OK - deve imprimir [0.7 1.7 2.7] - OK
  P3.setCoef(-1, 4.5); // Deve dar erro (indice) - OK
  P3.setCoef(3, 4.5);  // Deve dar erro (indice) - OK
  P3.setCoef(2, 0.0);  // Deve dar erro (valor) - OK

  // Testando o construtor por cópia

  cout << "==========\n";
  Poly P4(P0);
  imprimir("P4",P4);   // OK - deve imprimir [] - OK
  P4.setCoef(0, -3.5); // Deve dar erro (indice) - OK

  Poly P5(P3);
  imprimir("P5",P5);   // OK - deve imprimir [0.7 1.7 2.7] - OK
  // Alterando P3
  for (i=0; i<=P3.getGrau(); ++i) P3.setCoef(i, 1.0);
  // Verificando que P5 nao alterou
  imprimir("P5",P5);   // OK - deve imprimir [0.7 1.7 2.7] - OK

  // Testando o construtor por movimento
  // Pode chamar esse construtor 2 vezes:
  // - Para retornar o valor de inicializa() para uma variavel sem nome
  // - Para criar P6 a partir da variavel sem nome

  cout << "==========\n";
  Poly P6(inicializa());
  imprimir("P6",P6);   // OK - deve imprimir [666.6 666.6 666.6] - OK
  // Alterando P6
  for (i=0; i<=P6.getGrau(); ++i) P6.setCoef(i, i+0.7); // OK
  imprimir("P6",P6);   // OK - deve imprimir [0.7 1.7 2.7] - OK

  // Testando o operador de atribuicao por copia

  cout << "==========\n";
  P6.operator=(P1);
  imprimir("P6",P6);   // OK - deve imprimir [] - OK
  imprimir("P1",P1);   // OK - deve imprimir [] - OK
  P2 = P5;
  imprimir("P2",P2);   // OK - deve imprimir [0.7 1.7 2.7] - OK
  imprimir("P5",P5);   // OK - deve imprimir [0.7 1.7 2.7] - OK
  P0 = P3 = P4;
  imprimir("P0",P0);   // OK - deve imprimir [] - OK
  imprimir("P3",P3);   // OK - deve imprimir [] - OK
  imprimir("P4",P4);   // OK - deve imprimir [] - OK

  // Testando o operador de atribuicao por movimento

  cout << "==========\n";

  P1 = Poly(3);
  imprimir("P1",P1);   // OK - deve imprimir [0 0 0 1] - OK
  P5 = inicializa();
  imprimir("P5",P5);   // OK - deve imprimir [666.6 666.6 666.6] - OK

  return 0;
}

