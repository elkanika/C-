#include <iostream>
#include <stdio.h>
using namespace std;

class cuentas
{
public:  //se puede utilizar fuera de la clase
   int sumados(int arg);
   int sumatres(int arg);
private:    //único de la clase
   int resultado;
protected:
};

int cuentas::sumados(int arg)
{
  resultado = arg + 2;
  return resultado;
}
int cuentas::sumatres(int arg)
{
  resultado = arg + 3;
  return resultado;
}

int main()
{
  cuentas cuenta;
  cout << "+ 2 = " << cuenta.sumados(2) << endl;
  cout << "+ 3 = "  << cuenta.sumatres(2) << endl;
  cin.get();
  return 0;
}
