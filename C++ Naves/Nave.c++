#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <list>

using namespace std;

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80



void gotoxy(int x, int y){
  HANDLE Conh;
  Conh = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD dwPos;
  dwPos.X = x;
  dwPos.Y = y;

  SetConsoleCursorPosition(Conh, dwPos);

}

void ocultarcursor(){
  HANDLE Conh;
  Conh = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO cci;
  cci.dwSize = 100;
  cci.bVisible = FALSE;

  SetConsoleCursorInfo(Conh,&cci);

}

void pintar_limites()
{
  for(int i = 2; i < 118; i++)
  {
    gotoxy(i,1); printf("%c", 205);
    gotoxy(i,28); printf("%c", 205);

  }

  for(int i = 2; i < 28; i++)
  {
    gotoxy(1,i); printf("%c", 186);
    gotoxy(118,i); printf("%c", 186);

  }

    gotoxy(1,1); printf("%c", 201);
    gotoxy(1,28); printf("%c", 200);
    gotoxy(118,1); printf("%c", 187);
    gotoxy(118,28); printf("%c", 188);

}



class Navesita
{
  int x,y;
  int corazones;
  int vidas;
public:
  Navesita(int _x, int _y, int _corazones, int _vidas): x(_x), y(_y),corazones(_corazones), vidas(_vidas){}
  int X() {return x;}
  int Y() {return y;}
  void COR() {corazones--;}
  void pintar();
  void borrar();
  void mover();
  void pintar_corazones();
  void morir();
  int VID() {return vidas;}

};



void Navesita::pintar()
{
   gotoxy(x,y); printf("  %c", 179);
   gotoxy(x,y+1); printf(" %c%c%c",0 , 219, 0);
   gotoxy(x,y+2); printf("%c%c%c%c%c", 47,205,202,205,92);

}

void Navesita::borrar()
{
   gotoxy(x,y); printf("        ");
   gotoxy(x,y+1); printf("        ");
   gotoxy(x,y+2); printf("        ");

}

void Navesita::mover()
{
  if (kbhit()) {
      char tecla = getch();
      borrar();
      if(tecla == IZQUIERDA && x>3) x--;
      if(tecla == DERECHA && x+6 <118) x++;
      if(tecla == ARRIBA && y>2) y--;
      if(tecla == ABAJO && y+3 <28) y++;
      if(tecla == 'e')corazones--;
      pintar();
      pintar_corazones();
  }



}

void Navesita::pintar_corazones()
{
    gotoxy(50,0); printf("VIDAS %d", vidas);
    gotoxy(64,0); printf("salud");
    gotoxy(70,0); printf("      ");
    for(int i = 0; i < corazones; i++)
    {
      gotoxy(70+i,0); printf("%c", 3);

    }



}

void Navesita::morir()
{
    if(corazones == 0)
    {
      borrar();
      gotoxy(x,y); printf("   **   ");
      gotoxy(x,y+1); printf(" **** ");
      gotoxy(x,y+2); printf("   **   ");
      Sleep(200);
      borrar();
      gotoxy(x,y); printf(" * ** * ");
      gotoxy(x,y+1); printf("  ****  ");
      gotoxy(x,y+2); printf(" * ** * ");
      Sleep(200);
      borrar();
      vidas--;
      corazones = 3;
      pintar_corazones();
      pintar();
    }





}

class ast
{
   int x,y;
 public:
   ast(int _x, int _y):x(_x), y(_y){}
   void pintar();
   void mover();
   void choque(class Navesita &N);
   int X() {return x;}
   int Y() {return y;}
};

void ast::pintar()
{
   gotoxy(x,y); printf("%c", 184);


}

void ast::mover()
{
   gotoxy(x, y); printf(" ");
   y++;
   if(y > 27)
   {
     x = rand()%116 + 1;
     y = 2;
   }
   pintar();





}

void ast::choque(Navesita &N)
{
  if( x >= N.X() && x < N.X()+5 && y >= N.Y() && y <= N.Y()+2)
  {
      N.COR();
      N.borrar();
      N.pintar();
      N.pintar_corazones();
      x = rand()%116 + 1;
      y = 2;

  }



}

class BALA
{
   int x,y;
 public:
   BALA(int _x, int _y): x(_x), y(_y){}
   int X() {return x;}
   int Y() {return y;}
   void mover();
   bool fuera();

};

void BALA::mover()
{
   gotoxy(x,y); printf(" ");
   y--;
   gotoxy(x,y); printf("*");

}


bool BALA::fuera()
{
   if(y == 2)  return true;
   return false;

}



int main()
{
  ocultarcursor();
  Navesita n(7, 7, 3, 3);
  n.pintar();
  n.borrar();
  n.pintar_corazones();
  pintar_limites();


  list<ast*> A;
  list<ast*>::iterator itA;
  for(int i=0; i<3; i++)
  {
    A.push_back(new ast(rand()% 116 + 1, rand()% 5 + 4));
  }

  list<BALA*> B;
  list<BALA*>::iterator it;

  bool gameover = false;
  int puntos = 0;
  while (!gameover)
  {
    gotoxy(4,2); printf("Puntos %d ", puntos);
    if(kbhit())
    {
      char tecla = getch();
      if(tecla == 'a')
      B.push_back(new BALA(n.X() + 2, n.Y() -1));
    }

    for(it = B.begin(); it != B.end(); it++)
    {
      (*it)->mover();
      if((*it)->fuera())
      {
         gotoxy((*it)->X(), (*it)->Y()); printf(" ");
         delete(*it);
         it = B.erase(it);

      };
    }
    for(itA = A.begin(); itA != A.end(); itA++)
    {
      (*itA)->mover();
      (*itA)->choque(n);
    }

    for(itA = A.begin(); itA != A.end(); itA++)
    {
      for (it = B.begin(); it != B.end(); it++)
      {
        if((*itA)->X() == (*it)->X() && ( (*itA)->Y() +1 == (*it)->Y()  ))
        {
          gotoxy((*it)->X(),(*it)->Y()); printf(" ");
          delete(*it);
          it = B.erase(it);

          A.push_back(new ast(rand()%116 + 1, 4));
          gotoxy((*itA)->X(),(*itA)->Y()); printf(" ");
          delete(*itA);
          itA = A.erase(itA);

          puntos+=5;

        }

      }


    }
    if(n.VID()==0) gameover = true;

     for(itA = A.begin(); itA!=A.end();itA++)
     {
       (*itA)->mover();
       (*itA)->choque(n);
     }


     n.morir();
     n.mover();
     Sleep(30);

  }
  return 0;
}
