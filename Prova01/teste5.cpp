#include <iostream>
#include <string>
#include "Poly.h"

using namespace std;

int main(void)
{
  Poly Pvaz;
  Poly Pnulo(0);
  Poly P2A(2), P2B(2);
  Poly P3(3);
  Poly Result;

  // Polinomios para teste
  P2A.setCoef(2,-3.0);
  P2A.setCoef(1,5.0);
  P2A.setCoef(0,6.0);

  P2B.setCoef(2,3.0);
  P2B.setCoef(1,-5.0);
  P2B.setCoef(0,-1.0);

  P3.setCoef(3,1.0);
  P3.setCoef(2,-3.0);
  P3.setCoef(1,5.0);
  P3.setCoef(0,6.0);

  // Testando negativo de vazio
  Result = -Pvaz;
  if (Result.empty()) cout << "OK -vazio\n";
  else cerr << "ERRO -vazio\n";

  // Testando negativo de nulo
  Result = -Pnulo;
  if (Result.isZero()) cout << "OK -nulo\n";
  else cerr << "ERRO -nulo\n";

  // Testando negativo de polinomio
  Result = -P2A;
  try
  {
    if (Result.getGrau() != P2A.getGrau()) throw 1;
    for (int i=0; i<=Result.getGrau(); ++i) if (Result.getCoef(i) != -P2A.getCoef(i)) throw 2;
    cout << "OK -polinomio\n";
  }
  catch(int i)
  {
    cerr << "ERRO -polinomio: -[" << P2A << "]=" << Result << endl;
  }

  // Testando soma de vazio e vazio
  Result = Pvaz+Pvaz;
  if (Result.empty()) cout << "OK vazio+vazio\n";
  else cerr << "ERRO vazio+vazio\n";
  // Testando subtracao de vazio e vazio
  Result = Pvaz-Pvaz;
  if (Result.empty()) cout << "OK vazio-vazio\n";
  else cerr << "ERRO vazio-vazio\n";

  // Testando soma de vazio e nulo
  Result = Pvaz+Pnulo;
  if (Result.isZero()) cout << "OK vazio+nulo\n";
  else cerr << "ERRO vazio+nulo\n";
  // Testando subtracao de vazio e nulo
  Result = Pvaz-Pnulo;
  if (Result.isZero()) cout << "OK vazio-nulo\n";
  else cerr << "ERRO vazio-nulo\n";

  // Testando soma de nulo e vazio
  Result = Pnulo+Pvaz;
  if (Result.isZero()) cout << "OK nulo+vazio\n";
  else cerr << "ERRO nulo+vazio\n";
  // Testando subtracao de nulo e vazio
  Result = Pnulo-Pvaz;
  if (Result.isZero()) cout << "OK nulo-vazio\n";
  else cerr << "ERRO nulo-vazio\n";

  // Testando soma de polinomio e vazio
  Result = P2A+Pvaz;
  if (Result == P2A) cout << "OK polinomio+vazio\n";
  else cerr << "ERRO polinomio+vazio\n";
  // Testando subtracao de polinomio e vazio
  Result = P2A-Pvaz;
  if (Result == P2A) cout << "OK polinomio-vazio\n";
  else cerr << "ERRO polinomio-vazio\n";

  // Testando soma de vazio e polinomio
  Result = Pvaz+P2A;
  if (Result == P2A) cout << "OK vazio+polinomio\n";
  else cerr << "ERRO polinomio+vazio\n";
  // Testando subtracao de vazio e polinomio
  Result = Pvaz-P2A;
  if (Result == -P2A) cout << "OK vazio-polinomio\n";
  else cerr << "ERRO polinomio-vazio\n";

  // Testando soma de polinomio2 e polinomio3
  Result = P2A+P3;
  if (Result.getGrau() != 3) cerr << "ERRO no grau de polinomio2+polinomio3\n";
  cout << P2A << " + " << P3 << " = " << Result << " (verifique se estah correto)\n";
  // Testando subtracao de polinomio2 e polinomio3
  Result = P2A-P3;
  if (Result.getGrau() != 3) cerr << "ERRO no grau de polinomio2-polinomio3\n";
  cout << P2A << " - " << P3 << " = " << Result << " (verifique se estah correto)\n";

  // Testando soma de polinomio3 e polinomio2
  Result = P3+P2A;
  if (Result.getGrau() != 3) cerr << "ERRO no grau de polinomio3+polinomio2\n";
  cout << P3 << " + " << P2A << " = " << Result << " (verifique se estah correto)\n";
  // Testando subtracao de polinomio3 e polinomio2
  Result = P3-P2A;
  if (Result.getGrau() != 3) cerr << "ERRO no grau de polinomio3-polinomio2\n";
  cout << P3 << " - " << P2A << " = " << Result << " (verifique se estah correto)\n";

  // Testando soma de polinomio2 e polinomio2 com reducao de grau
  Result = P2A+P2B;
  cout << P2A << " + " << P2B << " = " << Result << '\t';
  if (Result.getGrau() != 0) cerr << "ERRO no grau de polinomio2+polinomio2 com reducao\n";
  else if (Result.getCoef(0) != 5.0) cerr << "ERRO no coeficiente de polinomio2+polinomio2 com reducao\n";
  else cout << "OK polinomio2+polinomio2 com reducao\n";

  // Testando subtracao de polinomio2 e polinomio2 com reducao de grau
  Result = P2B - (-P2A);
  cout << P2B << " - " << -P2A << " = " << Result << '\t';
  if (Result.getGrau() != 0) cerr << "ERRO no grau de polinomio2-polinomio2 com reducao\n";
  else if (Result.getCoef(0) != 5.0) cerr << "ERRO no coeficiente de polinomio2-polinomio2 com reducao\n";
  else cout << "OK polinomio2-polinomio2 com reducao\n";

  // Testando soma de polinomio2 e polinomio2 com resultado nulo
  Result = P2A + (-P2A);
  cout << P2A << " + " << -P2A << " = " << Result << '\t';
  if (!Result.isZero()) cerr << "ERRO polinomio2+polinomio2 com resultado nulo\n";
  else cout << "OK polinomio2+polinomio2 com resultado nulo\n";

  // Testando subtracao de polinomio2 e polinomio2 com resultado nulo
  Result = P2B - P2B;
  cout << P2B << " - " << P2B << " = " << Result << '\t';
  if (!Result.isZero()) cerr << "ERRO polinomio2-polinomio2 com resultado nulo\n";
  else cout << "OK polinomio2-polinomio2 com resultado nulo\n";

  return 0;
}

