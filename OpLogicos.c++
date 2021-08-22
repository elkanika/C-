#include <iostream>
using namespace std;
bool comprobador;
int num1, num2, num3, num4;
int main()
{
  num1 = 12;
  num2 = 20;
  num3 = 4;
  num4 = 13;
  comprobador = (num4 > num1 && num3 < num2);
  cout << comprobador << endl;
  cin.get();
  return 0;
}

//no se le puede ingresar valor a una variable si no está en main
//&& y si los dos son verdaderos es verdadero
//|| or si uno es verdadero todo es verdadero
//!(num4 > num1) si la declaracion es verdadero entonces da falso
