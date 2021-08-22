#include <iostream>
#include <stdio.h>
using namespace std;

namespace ciudad
{
  int calle;
}

namespace pueblito
{
  int calle = 10;
}

using namespace ciudad;
int main()
{
  calle = 12;
  std::cout << calle << endl; // para acceder a calle de pueblito es
  std::cin.get();             // << pueblito::calle <<
  return 0;                   // std:: es para utilizar std si no está
}
