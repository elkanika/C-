#include <iostream>
using namespace std;

void funcion(int num = 2);

int main()
{
  funcion();
  funcion(12);
  cin.get();
  return 0;
}

void funcion (int num)
{
  cout << (num + 3) << endl;
}
