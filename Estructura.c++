#include <iostream>
using namespace std;

int main()
{
  struct Hogar
  {
    int direccion;
    int tel;
    Hogar(){direccion = 0; tel = 2;} // es como un valor predefinido
    int verDir(){return direccion;}
    int guardaDir(int a){direccion = a;}
    //~ es para funcion constructora
  }Sharif, Benavidez, Perez;
  Sharif.direccion = 4954;
  Sharif.tel = 14255655;
  Benavidez.direccion = 5494;
  Benavidez.tel = 55468701;

  cout << Benavidez.tel << endl;
  cout << Perez.tel << endl;

  Perez.guardaDir(156);

  cout << Perez.verDir() << endl;
  cin.get();
  return 0;
}



/*#include <iostream>
using namespace std;

int main()
{
  struct personaje
  {
     int edad;
     int tel;
  }Ezequiel;
  Ezequiel.edad = 16;
  Ezequiel.tel = 17829315;
  cout << Ezequiel.tel<< endl;
  cin.get();
  return 0;
}
*/
