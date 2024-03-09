#include<iostream>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<fstream>

//constantes
#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77


using namespace std;


void creditos();
void jugador();
void instrucciones();
void marcadores();


//DISEÑO
void jeff();
void margen();
void meteoros();
void control();


void ocultar_cursor(){
HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO info;
info.dwSize = 100;
info.bVisible = false;
SetConsoleCursorInfo(consoleHandle, &info);
}

//color y gotoxy
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

class CARATULA{
	
	int x, y;
	int x1, y1;
	
	public:
		CARATULA(int _x, int _y, int _x1, int _y1);
		void nave();
		void titulo();
};

CARATULA::CARATULA(int _x, int _y, int _x1, int _y1){
	
	x=_x; 
	y=_y;
	x1=_x1;
	y1=_y1;
}


class NAVE{
	
	//atributos
	int x, y;
	int energia;
	int vidas;
	
	//metodos
	public:	
	
		NAVE(int _x, int _y, int _energia, int _vidas);
		void dibujar_nave();
		void mover_nave();
		void borrar_nave();
		void energia_nave();
		void perder_vida();
		void explosion();
		void borrar_explosion();
		int perder(){ return vidas; };
};


NAVE::NAVE(int _x, int _y, int _energia, int _vidas){
	
	x=_x;
	y=_y;
	energia=_energia;
	vidas= _vidas;
}

void NAVE::energia_nave(){
	
	int g=0;
	int col[]={244,253,251,250,242};
	
	gotoxy(102,1); color(244); printf(" Vidas: ");
	gotoxy(109,1); color(244); printf("       ");
	for(int i=0; i < vidas; i++)
	{
		g+=2;
		gotoxy(108+g,1); color(244); printf("%c",254);
		if(vidas==0)
		{
			gotoxy(109,1); color(244); printf("       ");
		}
	}
	
	
	gotoxy(4,1); color(242); printf(" Energ%ca: ", 161);
	gotoxy(13,1); color(242); printf("       ");
	for(int i=0; i < energia; i++)
	{
		gotoxy(14+i,1); color(col[i]); printf("%c",254);
	}
	
	perder_vida();	
	
}

void NAVE::perder_vida(){
	
	if(energia==0)
	{
		borrar_nave();
		explosion();
		Sleep(400);
		energia=5;
		borrar_explosion();
		vidas--;
		dibujar_nave();
		energia_nave();
			
	}
}

void NAVE::explosion(){
	
	gotoxy(x+3,y+3); color(6); printf("%c%c%c%c%c%c%c", 32,32,32,178,32,32,32);
	gotoxy(x+3,y+4); color(6); printf("%c%c%c%c%c%c%c", 32,32,178,178,178,32,32);
	gotoxy(x+3,y+5); color(6); printf("%c%c%c%c%c%c%c", 32,32,32,178,32,32,32);
	
	Sleep(200);
	gotoxy(x+3,y+4); color(4); printf("%c%c", 176,176); gotoxy(x+8,y+4); color(4); printf("%c%c", 176,176);
	gotoxy(x+3,y+1); color(4); printf("%c%c%c%c%c%c%c", 176,32,32,176,32,32,176);
	gotoxy(x+3,y+2); color(4); printf("%c%c%c%c%c%c%c", 32,176,32,176,32,176,32);
	gotoxy(x+3,y+6); color(4); printf("%c%c%c%c%c%c%c", 32,176,32,176,32,176,32);
	gotoxy(x+3,y+7); color(4); printf("%c%c%c%c%c%c%c", 176,32,32,176,32,32,176);
}

void NAVE::borrar_explosion(){
	
	gotoxy(x+3,y+4); color(6); printf("       ");
	gotoxy(x+3,y+3); color(4); printf("       ");
	gotoxy(x+3,y+5); color(6); printf("       ");
	gotoxy(x+3,y+1); color(4); printf("       ");
	gotoxy(x+3,y+2); color(4); printf("       ");
	gotoxy(x+3,y+3); color(6); printf("       ");
	gotoxy(x+3,y+6); color(4); printf("       ");
	gotoxy(x+3,y+7); color(4); printf("       ");
	
}

void NAVE::dibujar_nave(){
		
	//ALLA ARRIBA
	color(1);	gotoxy(x+3,y+1); printf("%c", 219);
	color(9);	gotoxy(x+4,y+1); printf("%c%c", 219, 219);
	color(9);	gotoxy(x+5,y+2); printf("%c%c%c", 219, 219,219);
	//ALA ABAJO
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
	color(7);	gotoxy(x+4,y+4); printf("%c%c%c%c%c%c%c", 219,32,32,32,32,32,254,254);
	color(7);	gotoxy(x+4,y+3); printf("%c", 219);
	color(15);	gotoxy(x+5,y+3); printf("%c%c%c%c", 219,32,32,219);
	color(15);	gotoxy(x+5,y+4); printf("%c%c%c%c%c", 219,219,32,219,219);
	color(7);	gotoxy(x+4,y+5); printf("%c", 219);
	color(15);	gotoxy(x+5,y+5); printf("%c%c%c%c", 219,32,32,219);
	//capsula
	color(6);	gotoxy(x+6,y+3); printf("%c%c", 219,219);
	color(6);	gotoxy(x+7,y+4); printf("%c%c", 219,219);
	color(6);	gotoxy(x+6,y+5); printf("%c%c", 219,219);
}

void NAVE::borrar_nave(){
	
	color(1);	gotoxy(x+3,y+1); printf(" ");
	color(9);	gotoxy(x+4,y+1); printf("  ");
	color(9);	gotoxy(x+5,y+2); printf("   ");
	color(1);	gotoxy(x+3,y+7); printf(" ");
	color(9);	gotoxy(x+4,y+7); printf("  ");
	color(9);	gotoxy(x+5,y+6); printf("   ");
	color(12);	gotoxy(x+1,y+3); printf(" ");
	color(4);	gotoxy(x+3,y+3); printf(" ");
	color(4);	gotoxy(x+2,y+4); printf(" ");
	color(4);	gotoxy(x+3,y+5); printf(" ");
	color(12);	gotoxy(x+1,y+5); printf(" ");
	color(7);	gotoxy(x+4,y+4); printf("       ");
	color(7);	gotoxy(x+4,y+3); printf(" ");
	color(15);	gotoxy(x+5,y+3); printf("    ");
	color(15);	gotoxy(x+5,y+4); printf("     ");
	color(7);	gotoxy(x+4,y+5); printf(" ");
	color(15);	gotoxy(x+5,y+5); printf("    ");
	color(6);	gotoxy(x+6,y+3); printf("  ");
	color(6);	gotoxy(x+7,y+4); printf("  ");
	color(6);	gotoxy(x+6,y+5); printf("  ");
}

void NAVE::mover_nave(){
	
	if(kbhit());
		{
			
				
			char tecla = getch();
			borrar_nave();
			
			if(tecla==ARRIBA && y>2) 	{ y-=1; } //ARRIBA 72
			if(tecla==ABAJO && y<19) 	{ y+=1; } //ABAJO 80
			if(tecla==IZQUIERDA && x>4) { x-=2; } //IZQUIERDA 75
			if(tecla==DERECHA && x<104)	{ x+=2;	} //DERECHA 77
			//salir del juego
			
			
			
			dibujar_nave();
			if(tecla==27)
			{
				energia--;		
				
			}
		}
		Sleep(30);
}


int main()
{
	ocultar_cursor();
	
	int x=15, y=18, op=1;
	float puntos=0.25;
	int v=3, i;
	bool fin_juego=false, menu=false, nivel=false;
	string opciones[]={"Nuevo Juego", "Instrucciones","Marcador","Dificultad","Creditos","Salir"};
	
	NAVE navecita(10,5,5,v);
	NAVE nave_portada(87,18,5,v);
	
	system("color f0");
	margen();
	meteoros();
	
	CARATULA nave(58,9,40,10);
	CARATULA titulo(43,4,40,10);
	
	nave.nave();
	color(240);
	titulo.titulo();
	
	gotoxy(51,24); printf("POR: JEFFERSON RIOS");
	Sleep(1000);
	gotoxy(39,26); cout<<"Presione cualquier tecla para continuar...";
	gotoxy(1,29);
	getch();
	
	system("cls");
	system("color 0f");
	
	CARATULA creditos_titulo(58,4,55,10);
	CARATULA creditos_nave(70,12,60,10);
	
	
	do{
		
		
		nivel=false;
		NAVE navecita(10,10,5,v);
		system("cls");
		CARATULA titulo2(11,5,35,5);
		titulo2.titulo();
		
		
		NAVE nave_menu(55,15,3,3);
		nave_menu.dibujar_nave();
		gotoxy(80,19); color(4); printf("%c%c", 254,254);
		
		
		color(15);
		margen();	
		gotoxy(12,15); printf("Men%c de Opciones", 163);
		gotoxy(15,18); cout<<"Nuevo Juego"<<endl;
		gotoxy(15,19); cout<<"Instrucciones"<<endl;
		gotoxy(15,20); cout<<"Marcador"<<endl;
		gotoxy(15,21); cout<<"Dificultad"<<endl;	
		gotoxy(15,22); printf("Cr%cditos",130);
		gotoxy(15,23); cout<<"Salir"<<endl;

		gotoxy(x,y); color(240);  cout<<opciones[i]; //POSICION INICIAL


		while(!menu)
		{
		
			if(kbhit());
			{
				char tecla = getch();
				gotoxy(x,y); color(15); cout<<opciones[i]; //printf("           ");	
			
				if(tecla==72 && y>18){ y--; op--; i--;} //ARRIBA 72
				if(tecla==80 && y<23) { y++; op++; i++;} //ABAJO 80
				gotoxy(x,y); color(240);  cout<<opciones[i]; //printf("%c%c", 62,62);
				
				if(tecla==13) //ENTER
				{
					menu=true;
				}
			
			}
		}
		
		system("color 0f");
		switch(op)
		{
			case 1:
				
				system("cls");
				margen();
				jugador();	
				system("cls");
				margen();
				
				gotoxy(56,0); cout<<" P L A Y E R ";
				gotoxy(54,1); color(240); cout<<" Puntaje: 00000 ";
				gotoxy(54,28); color(240); cout<<"  SPACE SHIP  ";	
				navecita.dibujar_nave(); 
				while(!fin_juego)
				{
					
					navecita.energia_nave();
					navecita.mover_nave();	
							
					
					if(navecita.perder()==0)
					{
						navecita.borrar_nave();
						fin_juego=true;
						gotoxy(53,15); cout<<"G A M E  O V E R";
						Sleep(3000);
					}
							
				}
					
				getch();
				fin_juego = false;												
				x=15, y=18, op=1, i=0;
				color(15);
				menu=false;
				break;
			
			case 2:
				system("cls");
				instrucciones();
				margen();
				nave_portada.dibujar_nave();
				gotoxy(105,22); color(4); printf("%c", 254);
				
				Sleep(2000);
				gotoxy(50,28); 
				color(240); cout<<"Presiona cualquier boton";
				getch();
				color(15);
				
				x=15, y=18, op=1, i=0;
				menu=false;
				break;
				
			case 3:
				system("cls");
				margen();
				gotoxy(11,7); printf("Puntuaciones m%cs altas", 160);
				marcadores();
				
				Sleep(2000);
				gotoxy(50,28); 
				color(240); cout<<"Presiona cualquier boton";
				getch();
				color(15);
				
				x=15, y=18, op=1, i=0;
				menu=false;
				break;
				
			case 4:
				
				system("cls");
				margen();
				gotoxy(11,7); cout<<"Selecciona la dificultad";
				gotoxy(14,14); printf("F%ccil", 160);
				gotoxy(14,15); printf("Normal", 160);
				gotoxy(14,16); printf("Dif%ccil", 161);
				
				x=11, y=14;
				while(!nivel)
				{
					if(kbhit());
					{
						char tecla = getch();
						gotoxy(x,y); printf("  ");	
			
						if(tecla==72 && y>14){ y--; v++; } //ARRIBA 72
						if(tecla==80 && y<16) { y++; v--;} //ABAJO 80
						gotoxy(x,y); printf("%c%c", 62,62);
				
						if(tecla==13) //ENTER
						{
							nivel=true;
						}
			
					}
				}				
												
				x=15, y=18, op=1, i=0;
				menu=false;
				break;
				
			case 5:
				system("cls");
				system("color f0");
				
				creditos();
				margen();
				jeff();
				creditos_titulo.titulo();
				creditos_nave.nave();
				
				Sleep(2000);
				gotoxy(48,28); 
				color(15); cout<<"Presiona cualquier boton";
				getch();
				color(15);
				
				x=15, y=18, op=1, i=0;
				menu=false;
				break;
			
			case 6:
				exit(0);
				break;
				
			default:
				Sleep(100);
				cout<<"Esa opcion no existe";
				x=12, y=18, op=1;
				menu=false;
				break;						
		}
	}
	while(op!=6);
	gotoxy(1,31);
	
}



void CARATULA::titulo()
{

		
 	gotoxy(x+1,y+1); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",32,219,219,32,219,219,32,32,32,219,32,32,32,219,32,32,219,219,32);
 	gotoxy(x+1,y+2); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,32,32,32,219,32,219,32,219,32,219,32,219,32,219,32,219,32,32);
 	gotoxy(x+1,y+3); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",32,219,32,32,219,219,32,32,219,219,219,32,219,32,32,32,219,219,32);
 	gotoxy(x+1,y+4); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",32,32,219,32,219,32,32,32,219,32,219,32,219,32,219,32,219,32,32);
 	gotoxy(x+1,y+5); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,32,32,219,32,32,32,219,32,219,32,32,219,32,32,219,219,32);
	

	
 	gotoxy(x1+1,y1+1); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",32,219,219,32,219,32,219,32,219,32,219,219,32);
 	gotoxy(x1+1,y1+2); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",219,32,32,32,219,32,219,32,219,32,219,32,219);
 	gotoxy(x1+1,y1+3); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",32,219,32,32,219,219,219,32,219,32,219,219,32);
 	gotoxy(x1+1,y1+4); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",32,32,219,32,219,32,219,32,219,32,219,32,32);
 	gotoxy(x1+1,y1+5); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,32,32,219,32,219,32,219,32,219,32,32);
}

void CARATULA::nave()
{	
	//fuego
	color(244); gotoxy(x+1,y+4); printf("%c%c%c%c", 219,32,219,219); 
	color(244); gotoxy(x+2,y+5); printf("%c%c%c%c", 219,32,32,219);
	color(252); gotoxy(x+3,y+5); printf("%c%c",219,219);
	color(244); gotoxy(x+1,y+6); printf("%c", 219);
	color(252); gotoxy(x+2,y+6); printf("%c%c",219,219);
	color(240); gotoxy(x+4,y+6); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219,219,219,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32);
	color(244); gotoxy(x+2,y+7); printf("%c%c%c%c", 219,32,32,219);
	color(252); gotoxy(x+3,y+7); printf("%c%c",219,219);
	color(244); gotoxy(x+1,y+8); printf("%c%c%c%c", 219,32,219,219);
	
	//ala superior
	color(249); gotoxy(x+5,y+2); printf("%c%c%c%c%c", 219,219,219,219,219);
	color(249); gotoxy(x+6,y+3); printf("%c%c%c%c%c", 219,219,219,219,219);
	color(249); gotoxy(x+6,y+1); printf("%c%c%c", 219,219,219);
	color(249); gotoxy(x+9,y+2); printf("%c%c", 219,219);
	color(249); gotoxy(x+11,y+3); printf("%c", 219);

	//cuerpo nave
	color(240); gotoxy(x+6,y+5); printf("%c%c%c%c%c%c", 219,32,32,32,32,219);
	color(240); gotoxy(x+7,y+4); printf("%c%c%c%c%c", 219,219,219,219,219);
	color(240); gotoxy(x+6,y+7); printf("%c", 219);
	color(247); gotoxy(x+7,y+7); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	color(240); gotoxy(x+7,y+8); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	color(240); gotoxy(x+19,y+5); printf("%c%c", 219,219);
	color(240); gotoxy(x+21,y+6); printf("%c", 219);
	color(240); gotoxy(x+21,y+7); printf("%c", 219);
	color(240); gotoxy(x+17,y+9); printf("%c%c%c%c", 219,219,219,219);
	
	
	
	//arma
	color(248); gotoxy(x+22,y+7); printf("%c%c", 219,219);
	color(244); gotoxy(x+30,y+7); printf("%c%c", 254,254);
	color(252); gotoxy(x+27,y+7); printf("%c%c%c", 254,254,254);
	//capsula
	color(246); gotoxy(x+13,y+2); printf("%c%c%c", 219,219,219);
	color(246); gotoxy(x+12,y+3); printf("%c%c%c%c%c", 219,32,32,219,219);
	color(7); gotoxy(x+13,y+3); printf("%c%c",219,219);
	color(246); gotoxy(x+12,y+4); printf("%c%c%c%c%c%c%c", 219,219,219,219,219,219,219);
	color(246); gotoxy(x+12,y+5); printf("%c%c%c%c%c%c%c", 219,219,219,219,219,219,219);
	color(246); gotoxy(x+13,y+6); printf("%c%c%c%c%c", 219,219,219,219,219);
	
	//ala inferior 7
	color(241); gotoxy(x+7,y+9); printf("%c%c%c%c%c%c%c%c", 219,219,219,219,219,219,219,219);
	color(241); gotoxy(x+6,y+10); printf("%c%c%c%c%c%c%c%c", 219,219,219,219,219,219,219,219);
	color(241); gotoxy(x+7,y+11); printf("%c%c%c%c%c", 219,219,219,219,219);
	color(241); gotoxy(x+8,y+12); printf("%c%c%c", 219,219,219);

	
	
}

void jeff()
{	
	int x=15, y=10;				
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

void jugador()
{
	int i=0;
	ofstream documento;
	string texto;
	documento.open("jugadores.txt", ios::app);
	if(documento.fail())
	{
		cout<<"Error al abrir";
	}
	gotoxy(11,8);	cout<<"Ingresa tu nickname: ";
	gotoxy(11,10);	cin>>texto;
	
	documento<<"    "<<texto<<"|"<<endl;	
	gotoxy(11,25); cout<<"Jugador: "<<texto;
	documento.close();
	Sleep(2000);
}

void instrucciones()
{
	ifstream inst;
	string texto;
	inst.open("instrucciones.txt", ios::in);
	if(inst.fail())
	{
		cout<<"Error al abrir el documento";	
	} 
	while(!inst.eof())
	{
		getline(inst,texto);
		cout<<texto<<endl;
	}
	inst.close();
	
}


void creditos()
{
	ifstream creditos;
	string texto;
	creditos.open("creditos.txt", ios::in);
	
	if(creditos.fail())
	{
		cout<<"Error al abrir el documento";	
	} 
	while(!creditos.eof())
	{
		getline(creditos,texto);
		cout<<texto<<endl;
	}
	creditos.close();	
}

void marcadores()
{
	int y=12;
	ifstream marcador;
	string texto;
	marcador.open("jugadores.txt", ios::in);
	
	if(marcador.fail())
	{
		cout<<"Error al abrir el documento";	
	} 
	for(int i=1;i<=10;i++)
	{
		getline(marcador,texto);
		gotoxy(15,y++); cout<<i<<". "<<texto;
	}
	marcador.close();	
}

void meteoros()
{
	int x=0, y=3;
	
	//Fuego
	color(248);
	gotoxy(x+15,y+2);  printf("*");
	gotoxy(x+75,y+5);  printf("*");
	gotoxy(x+30,y+15);  printf("*");
	gotoxy(x+25,y+20);  printf("*");
	gotoxy(x+19,y+8);  printf("o");
	gotoxy(x+56,y+6);  printf("o");
	gotoxy(x+64,y+16);  printf("o");
	gotoxy(x+93,y+14);  printf("o");
	
	gotoxy(x+109,y+20);  printf("*");
	gotoxy(x+90,y+8);  printf("*");
	gotoxy(x+26,y+22);  printf("*");
	gotoxy(x+7,y+18);  printf("*");
	gotoxy(x+36,y+12);  printf("*");
	gotoxy(x+12,y+13);  printf("o");
	gotoxy(x+69,y+5);  printf("o");
	gotoxy(x+11,y+16);  printf("o");
	color(15);
}


void margen()
{	
	for(int i=4; i<=115; i++)
	{
		//eje x superior:	
		gotoxy(i,2); printf("%c", 223);
		//eje x inferior:
		gotoxy(i,27); printf("%c",220);
	}
	
	for(int i=2; i<=27; i++)
	{
		//eje y izquierdo:
		gotoxy(4,i); printf("%c",219);
		//eje y derecho:
		gotoxy(115,i); printf("%c",219);
	}	
}


