#include <iostream>
using namespace std;

int num1 = 2;
int num2 = 4;
int suma;
int sumar(int a, int b)
{
  return (a) + (b);
}
void funcion()
{
  cout << "Funcion sin valor de retorno" << endl;
}
int main()
{
  suma = sumar(num1, num2);
  cout << suma << endl;
  funcion();
  cin.get();
  return 0;
}
