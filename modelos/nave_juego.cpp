#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<windows.h>

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

void color(int c)
{
SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),c);
}


int main(){
	
	int x=10, y=3;
	int numeros[]={2,4,6,8,10};
	
	//alas
	color(1);	gotoxy(x+3,y+1); printf("%c", 219);
	color(9);	gotoxy(x+4,y+1); printf("%c%c", 219, 219);
	color(9);	gotoxy(x+5,y+2); printf("%c%c%c", 219, 219,219);
	
	color(1);	gotoxy(x+3,y+7); printf("%c", 219);
	color(9);	gotoxy(x+4,y+7); printf("%c%c", 219, 219);
	color(9);	gotoxy(x+5,y+6); printf("%c%c%c", 219, 219,219);
	
	
	//Llamas
	color(12);	gotoxy(x+1,y+3); printf("%c", 219);
	color(4);	gotoxy(x+3,y+3); printf("%c", 219);
	color(4);	gotoxy(x+2,y+4); printf("%c", 219);
	color(4);	gotoxy(x+3,y+5); printf("%c", 219);
	color(12);	gotoxy(x+1,y+5); printf("%c", 219);
	
	//cuerpo
	color(7);	gotoxy(x+4,y+4); printf("%c%c%c%c%c%c%c", 219,32,32,32,32,219,254,254);
	color(7);	gotoxy(x+4,y+3); printf("%c", 219);
	color(15);	gotoxy(x+5,y+3); printf("%c%c%c%c", 219,32,32,219);
	color(15);	gotoxy(x+5,y+4); printf("%c%c", 219,219);
	color(7);	gotoxy(x+4,y+5); printf("%c", 219);
	color(15);	gotoxy(x+5,y+5); printf("%c%c%c%c", 219,32,32,219);

	//capsula
	color(6);	gotoxy(x+6,y+3); printf("%c%c", 219,219);
	color(6);	gotoxy(x+7,y+4); printf("%c%c", 219,219);
	color(6);	gotoxy(x+6,y+5); printf("%c%c", 219,219);
	
	
	x=10,y=20;
	gotoxy(x,y);
	
	if(kbhit());
		{
			char tecla = getch();
			
			if(tecla==27) {
				system("exit");
			}	
			
			
		}
		Sleep(30);
	
	for(int i=0;i<5;i++)
	{
		cout<<numeros[i]<<endl;
		}	
		
}

