#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int num,num2;
	string texto;
	
	cout << "ingresa un dos numeros" << endl;
	
	cin << num;
	cin << num2;
	
	cout << "que quieres hacer con ellos(ingresa +,-,*,/)" << endl;
	
	cin << texto;
	
	switch(texto)
	case '+':
		cout << num + num2 << endl;
			break;
		
	case '-':
		cout << num - num2 << endl;
			break;
	
	case '*':
		cout << num * num2 << endl;
			break;
			
	case '/':
		cout << num / num2 << endl;
			break;
		
	default:
		cout << "algo anda mal" << endl;
	
	cin.get();
	return 0;
}
