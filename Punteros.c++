#include <iostream>
#include <stdio.h>
using namespace std;

int numero = 12;
int *puntero = &numero;
int main()
{
  cout << puntero << endl;
  cin.get();
  return 0;
}
/*
Los punteros de declaran con * en un int
Los punteros sirven para guardar el valor de la dirección de alguna variable.
Para saber el la dirección de una variable se utiliza el & antes del nombre.
Si colocas el * en el cout del puntero entonces cambiar el valor de memoria
por el valor de la variable.
*/
