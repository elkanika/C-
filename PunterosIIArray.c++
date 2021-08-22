#include <iostream>
#include <stdio.h>
using namespace std;

int array[5];
int *puntero;

int main()
{
  puntero = array; // puntero = &array[0];
  cout << "direccion a array[0]; " << &array[0] << endl; //puntero++; para ir a
  cout << "puntero " << puntero << endl;                 // array[1]

  cin.get();
  return 0;
}
