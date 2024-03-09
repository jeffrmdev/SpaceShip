#include<iostream>
#include<windows.h>
#include<stdio.h>
#include<conio.h>

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80


using namespace std;

void EliminarCursor()
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	
	cci.dwSize = 50;
	cci.bVisible = FALSE;
	
	SetConsoleCursorInfo(hcon, &cci);
}


void color(int c)
{
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),c);
}

void gotoxy(int x,int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}

class personaje
{
	int x, y;
	
	public:	
	personaje(int _x, int _y):x(_x),y(_y){}
	void modelo();
	void mover();
	void borrar();
};



void personaje::borrar()
{
	//cabello
	gotoxy(x+1,y+0); printf("%c%c%c%c%c%c%c%c%c%c", 32,32,32,32,32,32,32,32,32,32);
	gotoxy(x+1,y+1); printf("%c%c%c%c%c%c%c%c%c",32,32,32,32,32,32,32,32,32);
	gotoxy(x+2,y+2); printf("%c%c",32,32);
	gotoxy(x+2,y+3); printf("%c%c",32,32);
	
	//rostro
	gotoxy(x+4,y+2); printf("%c%c%c%c%c",32,32,32,32,32);
	gotoxy(x+5,y+2); printf("%c",32);
	gotoxy(x+7,y+2); printf("%c",32);
	gotoxy(x+4,y+3); printf("%c%c%c%c%c",32,32,32,32,32);
	//cuerpo
	
		//brazo izquierdo
		gotoxy(x+3,y+4); printf("%c",32);
		gotoxy(x+3,y+5); printf("%c",32);
		
		//brazo derecho
		gotoxy(x+8,y+4); printf("%c",32);
		gotoxy(x+8,y+5); printf("%c",32);
		
		//torso
		gotoxy(x+4,y+4); printf("%c%c",32,32);
		gotoxy(x+6,y+4); printf("%c",32);
		gotoxy(x+7,y+4); printf("%c",32);
		gotoxy(x+4,y+5); printf("%c%c%c%c",32,32,32,32);
		
		//Piernitas owo
		
		gotoxy(x+4,y+6); printf("%c",32);
		gotoxy(x+5,y+6); printf("%c",32);	
		gotoxy(x+7,y+6); printf("%c",32);
		gotoxy(x+8,y+6); printf("%c",32);
}

void personaje::modelo()
{
	//cabello
	color(240); gotoxy(x+1,y+0); printf("%c%c%c%c%c%c%c%c%c%c", 32,220,32,32,220,220,220,220,220,220);
	gotoxy(x+1,y+1); printf("%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219);
	gotoxy(x+2,y+2); printf("%c%c",219,219);
	gotoxy(x+2,y+3); printf("%c%c",219,219);
	
	//rostro
	color(126); gotoxy(x+4,y+2); printf("%c%c%c%c%c",219,219,219,219,219);
	color(241); gotoxy(x+5,y+2); printf("%c",219);
	color(241); gotoxy(x+7,y+2); printf("%c",219);
	color(126); gotoxy(x+4,y+3); printf("%c%c%c%c%c",219,219,219,219,219);
	color(228); gotoxy(x+6,y+3); printf("%c",254);
	
	//cuerpo
	
		//brazo izquierdo
		color(245); gotoxy(x+3,y+4); printf("%c",219);
		color(245); gotoxy(x+3,y+5); printf("%c",219);
		
		//brazo derecho
		color(245); gotoxy(x+8,y+4); printf("%c",219);
		color(245); gotoxy(x+8,y+5); printf("%c",219);
		
		//torso
		color(252); gotoxy(x+4,y+4); printf("%c%c",219,219);
		color(251); gotoxy(x+6,y+4); printf("%c",219);
		color(252); gotoxy(x+7,y+4); printf("%c",219);
		color(244); gotoxy(x+4,y+5); printf("%c%c%c%c",219,219,219,219);
		
		//Piernitas owo
		
		color(240); gotoxy(x+4,y+6); printf("%c",219);
		color(248); gotoxy(x+5,y+6); printf("%c",220);	
		color(240); gotoxy(x+7,y+6); printf("%c",219);
		color(248); gotoxy(x+8,y+6); printf("%c",220);
		
}


void personaje::mover()
{
	bool game_over = false;
	
	while(!game_over)
	{
		
		if(kbhit())	
		{
			char tecla=getch();
			borrar();
			if(tecla == ARRIBA) y--;
			if(tecla == ABAJO) y++;
			if(tecla == DERECHA) x++;
			if(tecla == IZQUIERDA) x--;
			modelo();
							
		}
	}
}


int main()
{
	
	color(240); gotoxy(1,1); printf("%c%c%c%c%c%c%c%c%c%c", 32,220,32,32,220,220,220,220,220,220);
	color(240); gotoxy(1,2); printf("%c%c%c%c%c%c%c%c%c%c", 32,220,32,32,220,220,220,220,220,220);
	color(240); gotoxy(1,3); printf("%c%c%c%c%c%c%c%c%c%c", 32,220,32,32,220,220,220,220,220,220);
	EliminarCursor();
	system("color f1");
	personaje m(15,7);
	m.modelo();
	m.mover();
	Sleep(90);
	gotoxy(0,30);
	
}
