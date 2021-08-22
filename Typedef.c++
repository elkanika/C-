#include <iostream>
#include <stdio.h>
using namespace std;

// unsigned int entero sin signo, ni positivo ni negativo
// no colocar valores negativos

typedef unsigned int uint;

// no explotar este tipo de variable

int main()
{
  uint numero = 10;
  cout << numero << endl;

  cin.get();
  return 0;
}
