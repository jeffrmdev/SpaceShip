#include<windows.h>
#include<iostream>
#include<conio.h>

using namespace std;

void gotoxy(int x,int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}

int y=1;

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  // you can loop k higher to see more color choices
  for(float k = 1; k < 255; k+=0.35)
  {
    
    Sleep(50);
	gotoxy(k,y); cout<<"*";
	gotoxy(k-1,y+k); cout<<" ";
	
	if(y==120)
	{
		y+1;
		k=1;
	}
	
	
    
  }
 
}
