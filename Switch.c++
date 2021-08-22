#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
  char c;
  cout << "escribe una letra" << endl;
  cin >> c;
  switch (c)
  {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    cout << "Es una vocal \n" << endl;
    break;
    default:
    cout << "Es una consonante \n" << endl;
  }
  system("pause");
  return 0;
}
