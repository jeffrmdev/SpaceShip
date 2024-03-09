#include<iostream>
#include<windows.h>
#include<conio.h>

//constantes
#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77



using namespace std;

void ocultar_cursor();

void gotoxy(int x,int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}



int main(){
	
	
	ocultar_cursor();
	int x=10, y=6;
	gotoxy(x,y); cout<<"*";
	bool b=false;
	while(!b)
	{
		
		if(kbhit());
		{
			
			char tecla = getch();
			gotoxy(x,y); cout<<" ";
			
			if(tecla==ARRIBA){ 	y--;	} //ARRIBA 72
			if(tecla==ABAJO){ 	y++;	} //ABAJO 80
			if(tecla==IZQUIERDA){ 	x--;	} //IZQUIERDA 75
			if(tecla==DERECHA){ 	x++;	} //DERECHA 77
			
			gotoxy(x,y); cout<<"*";
		}
	}	
}

void ocultar_cursor(){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = false;
	SetConsoleCursorInfo(consoleHandle, &info);
}

