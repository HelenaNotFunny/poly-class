#include <iostream>
#include <string>
#include "Poly.h"

using namespace std;

int main(void)
{
  const string dir_right="poly_arq_right";
  const string nome_right="poly_right";
  const string dir_wrong="poly_arq_wrong";
  const string nome_wrong="poly_wrong";
  string arq;
  int i;

  Poly P;

  cout << "\nTESTE COM ARQUIVOS CORRETOS\n";
  for (i=0; i<=7; ++i)
  {
    arq = dir_right + "\\" + nome_right + to_string(i) + ".txt";
    cout << endl << i << ") Arquivo: " << arq << endl;
    if (P.ler(arq))
    {
      cout << "Leitura correta: P=" << P << endl;
    }
    else
    {
      cerr << "Erro na leitura\n";
    }
  }

  cout << "\nTESTE COM ARQUIVOS INCORRETOS\n";
  for (i=0; i<=6; ++i)
  {
    arq = dir_wrong + "\\" + nome_wrong + to_string(i) + ".txt";
    cout << endl << i << ") Arquivo: " << arq << endl;
    P.recriar(1);
    cout << "Polinomio original P=" << P << endl;
    if (!P.ler(arq))
    {
      cout << "Arquivo com erro corretamente detectado\n";
    }
    else
    {
      cerr << "Erro na leitura: arquivo invalido considerado valido\n";
    }
    cout << "Polinomio apos tentativa de leitura P=" << P << endl;
  }

  return 0;
}

