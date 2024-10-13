#include <iostream>
#include <string>
#include <cmath>

#include "Poly.h"

using namespace std;

// Funcao para imprimir as informacoes sobre um Poly
void imprimir(const string& Nome, const Poly& P)
{
  cout << Nome << '\t'
       << "coefs=[";
  for (int i=0; i<=P.getGrau(); ++i)
  {
    cout << P.getCoef(i);
    if (i<P.getGrau()) cout << ' ';
  }
  cout << "]\n";
}

int main(void)
{
  const Poly Pvazio;
  const Poly P0(0);
  Poly P2(2);
  P2.setCoef(0,3.5);
  P2.setCoef(2,-1);

  int i;

  // Testando op[]

  cout << "==========\n";
  cout << "i" << '\t' << "Pvaz" << '\t' << "P0" << '\t' << "P2" << endl;
  for (i=-1; i<=3; ++i)
  {
    cout << i << '\t' << Pvazio[i] << '\t' << P0[i] << '\t' << P2[i] << endl;
  }

  // Testando comparacoes
  cout << "==========\n";
  Poly Pvazio_2(Pvazio);
  cout << 1;
  Poly P0_2(P0);
  cout << 2;
  Poly P2_2(P2);
  cout << 3;
  if (Pvazio_2 == Pvazio) cout << "OK == com Pvazio\n";
  else cout << "ERRO == com Pvazio\n";
  if (P0_2 == P0) cout << "OK == com P0\n";
  else cout << "ERRO == com P0\n";
  if (P2_2 == P2) cout << "OK == com P2\n";
  else cout << "ERRO == com P2\n";

  if (P0 != Pvazio) cout << "OK != com P0,Pvazio\n";
  else cout << "ERRO != com P0,Pvazio\n";
  if (P2 != P0) cout << "OK != com P2,P0\n";
  else cout << "ERRO == com P2,P0\n";
  if (Pvazio != P2) cout << "OK != com Pvazio,P2\n";
  else cout << "ERRO == com Pvazio,P2\n";

  // Testando predicados
  cout << "==========\n";
  if (Pvazio.empty()) cout << "OK empty com Pvazio\n";
  else cout << "ERRO empty com Pvazio\n";
  if (P0.empty()) cout << "ERRO empty com P0\n";
  else cout << "OK empty com P0\n";
  if (P2.empty()) cout << "ERRO empty com P2\n";
  else cout << "OK empty com P2\n";

  if (Pvazio.isZero()) cout << "ERRO isZero com Pvazio\n";
  else cout << "OK isZero com Pvazio\n";
  if (P0.isZero()) cout << "OK isZero com P0\n";
  else cout << "ERRO isZero com P0\n";
  if (P2.isZero()) cout << "ERRO isZero com P2\n";
  else cout << "OK isZero com P2\n";

  // Testando getValor

  cout << "==========\n";
  cout << "x" << '\t' << "Pvaz" << '\t' << "P0" << '\t' << "P2" << endl;
  for (double x=-1.0; x<=3.0; ++x)
  {
    cout << x << '\t' << Pvazio.getValor(x) << '\t' << P0.getValor(x) << '\t' << P2.getValor(x) << endl;
    cout << x << '\t' << Pvazio(x) << '\t' << P0(x) << '\t' << P2(x) << endl;
  }
  cout << "P2(1.87) deveria dar 0.0 e deu " << P2(sqrt(3.5)) << endl;

  // Testando recriar

  cout << "==========\n";
  P2.recriar(-1000);
  imprimir("Vaz", P2);
  P2.recriar(0);
  imprimir("0", P2);
  P2.recriar(2);
  imprimir("2", P2);

  // Testando << com os casos listados na especificacao

  cout << "==========\n";
  P2.recriar(3);
  P2.setCoef(0,5.7);
  P2.setCoef(1,1.4);
  P2.setCoef(2,3.2);
  P2.setCoef(3,0.2);
  cout << "0.2*x^3+3.2*x^2+1.4*x+5.7" << "\tESPERADO\n";
  cout << P2 << "\tOBTIDO\n";

  P2.setCoef(0,5.7);
  P2.setCoef(1,1.0);
  P2.setCoef(2,3.2);
  P2.setCoef(3,1.0);
  cout << "x^3+3.2*x^2+x+5.7" << "\tESPERADO\n";
  cout << P2 << "\tOBTIDO\n";

  P2.setCoef(0,5.7);
  P2.setCoef(1,-1.4);
  P2.setCoef(2,3.2);
  P2.setCoef(3,-0.2);
  cout << "-0.2*x^3+3.2*x^2-1.4*x+5.7" << "\tESPERADO\n";
  cout << P2 << "\tOBTIDO\n";

  P2.setCoef(0,5.7);
  P2.setCoef(1,-1.0);
  P2.setCoef(2,3.2);
  P2.setCoef(3,-1.0);
  cout << "-x^3+3.2*x^2-x+5.7" << "\tESPERADO\n";
  cout << P2 << "\tOBTIDO\n";

  P2.setCoef(0,0.0);
  P2.setCoef(1,1.4);
  P2.setCoef(2,0.0);
  P2.setCoef(3,0.2);
  cout << "0.2*x^3+1.4*x" << "\tESPERADO\n";
  cout << P2 << "\tOBTIDO\n";

  P2.recriar(1);
  P2.setCoef(0,0.0);
  P2.setCoef(1,1.0);
  cout << "x" << "\tESPERADO\n";
  cout << P2 << "\tOBTIDO\n";

  P2.recriar(0);
  P2.setCoef(0,1.0);
  cout << "1" << "\tESPERADO\n";
  cout << P2 << "\tOBTIDO\n";

  P2.setCoef(0,0.0);
  cout << "0" << "\tESPERADO\n";
  cout << P2 << "\tOBTIDO\n";

  cout << "><" << "\tESPERADO\n";
  cout << '>' << Pvazio << '<' << "\tOBTIDO\n";

  return 0;
}

