#include <iostream>
using namespace std;
int num1 = 14;
int num2 = 14;
int main()
{
  if (num1<num2)
  {
    cout << "Es menor" << endl;
  }else if(num1==num2)
  {
    cout << "valen lo mismo" << endl;
  }
  else
  {
    cout << "no es menor" << endl;
  }
  cin.get();
  return 0;
}
