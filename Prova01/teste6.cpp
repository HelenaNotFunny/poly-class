#include <iostream>
#include <string>
#include "Poly.h"

using namespace std;

int main(void)
{
  Poly Pvaz;
  Poly Pnulo(0);
  Poly Punit(0);
  Poly P2(2);
  Poly P3(3);
  Poly Result;

  // Polinomios para teste
  Punit.setCoef(0,1);

  P2.setCoef(2,-3.0);
  P2.setCoef(1,5.0);
  P2.setCoef(0,6.0);

  P3.setCoef(3,1.0);
  P3.setCoef(2,-3.0);
  P3.setCoef(1,5.0);
  P3.setCoef(0,6.0);

  // Testando produto de vazio e vazio
  Result = Pvaz*Pvaz;
  if (Result.empty()) cout << "OK vazio*vazio\n";
  else cerr << "ERRO vazio*vazio\n";

  // Testando produto de vazio e nulo
  Result = Pvaz*Pnulo;
  if (Result.empty()) cout << "OK vazio*nulo\n";
  else cerr << "ERRO vazio*nulo\n";

  // Testando produto de nulo e vazio
  Result = Pnulo*Pvaz;
  if (Result.empty()) cout << "OK nulo*vazio\n";
  else cerr << "ERRO nulo*vazio\n";

  // Testando produto de vazio e polinomio
  Result = Pvaz*P3;
  if (Result.empty()) cout << "OK vazio*polinomio\n";
  else cerr << "ERRO vazio*nulo\n";

  // Testando produto de polinomio e vazio
  Result = P3*Pvaz;
  if (Result.empty()) cout << "OK polinomio*vazio\n";
  else cerr << "ERRO nulo*vazio\n";

  // Testando produto de nulo e nulo
  Result = Pnulo*Pnulo;
  if (Result.isZero()) cout << "OK nulo*nulo\n";
  else cerr << "ERRO nulo*vazio\n";

  // Testando produto de nulo e polinomio
  Result = Pnulo*P2;
  if (Result.isZero()) cout << "OK nulo*polinomio\n";
  else cerr << "ERRO nulo*polinomio\n";

  // Testando produto de polinomio e nulo
  Result = P2*Pnulo;
  if (Result.isZero()) cout << "OK polinomio*nulo\n";
  else cerr << "ERRO polinomio*nulo\n";

  // Testando produto de unitario e polinomio
  Result = Punit*P2;
  if (Result == P2) cout << "OK unitario*polinomio\n";
  else cerr << "ERRO unitario*polinomio\n";

  // Testando produto de polinomio e unitario
  Result = P2*Punit;
  if (Result == P2) cout << "OK polinomio*unitario\n";
  else cerr << "ERRO polinomio*unitario\n";

  // Testando produto de polinomio2 e polinomio3
  Result = P2*P3;
  if (Result.getGrau() != 5) cerr << "ERRO no grau de polinomio2*polinomio3\n";
  cout << P2 << " * " << P3 << " = " << Result << " (verifique se estah correto)\n";

  // Testando produto de polinomio3 e polinomio2
  Result = P3*P2;
  if (Result.getGrau() != 5) cerr << "ERRO no grau de polinomio3*polinomio2\n";
  cout << P3 << " * " << P2 << " = " << Result << " (verifique se estah correto)\n";

  return 0;
}

