#include<windows.h>
#include<iostream>
#include<conio.h>



using namespace std;

void ocultar_cursor(){
HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO info;
info.dwSize = 100;
info.bVisible = false;
SetConsoleCursorInfo(consoleHandle, &info);
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

int main()
{
	
	ocultar_cursor();	
	system("cls");
	int y_op;
	bool b=false;
	system("color 0f");
	
	

	
	
	int x=3,y=5;

	do
	{	

		system("cls");
		system("color 0f");	
		gotoxy(5,1);printf("Men%c de Opciones", 163);
		gotoxy(5,5); cout<<"Nuevo Juego"<<endl;
		gotoxy(5,6); cout<<"Instrucciones"<<endl;
		gotoxy(5,7); cout<<"Marcador"<<endl;
		gotoxy(5,8); cout<<"Niveles"<<endl;	
		gotoxy(5,9); printf("Cr%cditos",130);
		gotoxy(5,10); cout<<"Salir"<<endl;
		
		
		while(!b)
		{
		
		if(kbhit());
		{
			char tecla = getch();
			gotoxy(x,y); printf(" ");	
			
			if(tecla==72 && y>5){ y--; y_op=y; } //ARRIBA 72
			if(tecla==80 && y<10) { y++; y_op=y;} //ABAJO 80
			gotoxy(x,y); printf("%c", 62);
			
			if(tecla==13)
			{
				b=true;
						}
			
		}
	}
		
	
		switch(y_op)
		{
			case 5:
				
				system("cls");
				cout<<"Opcion jugar";
				getch();
				b=false;		
				break;
			
			case 6:
				system("cls");
				cout<<"Opcion instrucciones";
				getch();
				b=false;
				break;
				
			case 7:
				system("cls");
				cout<<"Opcion marcador";
				getch();
				b=false;
				break;
				
			case 8:
				system("cls");
				cout<<"Opcion nivel";
				getch();
				b=false;
				break;
				
			case 9:
				system("cls");
				cout<<"Opcion creditos";
				getch();
				b=false;
				break;
			
			case 10:
				system("cls");
				cout<<"Opcion salir";
				getch();
				b=false;
				break;
				
			default:
				cout<<"Esa opcion no existe";
				b=false;
				break;						
		}
	}while(y_op!=11);
}


