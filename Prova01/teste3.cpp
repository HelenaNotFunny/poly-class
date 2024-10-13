#include <iostream>
#include "Poly.h"

using namespace std;

int main(void)
{
  Poly PVaz;
  Poly P0(0);
  Poly P2(2);

  cout << "\nTestando digitacao de polinomio vazio. Nao deve fazer nada\n";
  cin >> PVaz;
  cout << "Salvando polinomio vazio no arquivo pvaz.txt. Arquivo deve conter:\n";
  cout << "============\n";
  cout << "POLY -1" << endl;
  cout << "============\n";
  cout << PVaz;
  //if (!PVaz.salvar("pvaz.txt")) cerr << "ERRO NO SALVAMENTO!!\n";

  cout << "\nTestando digitacao de polinomio grau 0 nulo. Deve imprimir x^0:\n";
  cout << "Voce deve digitar um valor 0.0 para esse coeficiente.\n";
  cout << "Deve imprimir P0=0\n";
  cin >> P0;
  cout << "P0=" << P0 << endl;
  cout << "Salvando polinomio nulo no arquivo pnulo.txt. Arquivo deve conter:\n";
  cout << "============\n";
  cout << "POLY 0\n0" << endl;
  cout << "============\n";
  cout << P0;
  //if (!P0.salvar("pnulo.txt")) cerr << "ERRO NO SALVAMENTO!!\n";

  cout << "\nTestando digitacao de polinomio grau 0 nao nulo. Deve imprimir x^0:\n";
  cout << "Voce deve digitar um valor -1 para esse coeficiente.\n";
  cout << "Deve imprimir P0=-1\n";
  cin >> P0;
  cout << "P0=" << P0 << endl;
  cout << "Salvando polinomio de grau 0 no arquivo p0.txt. Arquivo deve conter:\n";
  cout << "============\n";
  cout << "POLY 0\n-1" << endl;
  cout << "============\n";
  cout << P0;
  //if (!P0.salvar("p0.txt")) cerr << "ERRO NO SALVAMENTO!!\n";

  cout << "\nTestando digitacao de polinomio grau 2. Deve imprimir x^2, depois x^1: depois x^0:\n";
  cout << "Voce deve tentar digitar um valor 0.0 para o coeficiente de maior grau (x^2).\n";
  cout << "O programa deve solicitar que voce digite novamente esse valor. Digite 1,\n";
  cout << "em seguida digite 0 para os demais coeficientes.\n";
  cout << "Deve imprimir P2=x^2\n";
  cin >> P2;
  cout << "P2=" << P2 << endl;
  cout << "Salvando polinomio de grau 2 no arquivo p2.txt. Arquivo deve conter:\n";
  cout << "============\n";
  cout << "POLY 2\n0 0 1" << endl;
  cout << "============\n";
  //if (!P2.salvar("p2.txt")) cerr << "ERRO NO SALVAMENTO!!\n";

  cout << "\nTestando digitacao de polinomio grau 2. Deve imprimir x^2, depois x^1: depois x^0:\n";
  cout << "Voce deve digitar os valor 2.5, 1.5 e 0.5, nessa ordem, para os coeficientes.\n";
  cout << "Deve imprimir P2=2.5*x^2+1.5*x+0.5\n";
  cin >> P2;
  cout << "P2=" << P2 << endl;
  cout << "Salvando polinomio de grau 2 no arquivo p2.txt. Arquivo deve conter:\n";
  cout << "============\n";
  cout << "POLY 2\n0.5 1.5 2.5" << endl;
  cout << "============\n";
  //if (!P2.salvar("p2.txt")) cerr << "ERRO NO SALVAMENTO!!\n";

  return 0;
}

