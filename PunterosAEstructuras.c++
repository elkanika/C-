#include <iostream>
#include <stdio.h>
using namespace std;

struct miestructura
{
  int a;

}miestructura, *puntero;

int main()
{
  miestructura.a = 12;
  puntero = &miestructura;
  cout << puntero << endl;
  cout << &miestructura.a << endl;
  cout << puntero->a << endl;


  cin.get();
  return 0;
}
