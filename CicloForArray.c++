#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
  char c[4]; //Array
  c[0] = 'H';
  c[1] = 'O';
  c[2] = 'L';
  c[3] = 'A';
  c[4] = '!';
  for (int i = 0; i<5; i++) //Bucle For
  {
    cout << c[i];
  }
  cout << endl;
  cin.get();
  return 0;
}
