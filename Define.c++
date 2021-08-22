#define sumar(a,b) a+b
#define multiplicar(a,b) a*b   //los () siempre juntos
#define dividir(a,b) a/b

#include <iostream>
#include <stdio.h>
int num1 = 2;
int num2 = 4;

int suma;
int mul;
int divid;

using namespace std;

int main()
{
  suma = sumar(num1, num2);
  mul = multiplicar(num1, num2);
  divid = dividir(num2, num1);
  cout << "la suma es: "<< suma << endl;
  cout << "la multiplicacion es: "<< mul << endl;
  cout << "el cociente es: "<< divid << endl;
  cin.get();
  return 0;
}
