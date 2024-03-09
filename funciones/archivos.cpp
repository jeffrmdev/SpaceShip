#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

void leer();
void marcadores();
void colocar();

int main(){
	
	colocar();
	//marcadores();	
	//leer();
}

void marcadores()
{
		
	ofstream documento;
	documento.open("archivo.txt",ios::out);
	
	if(documento.fail())
	{
		cout<<"Error al abrir";
	}
	documento<<"Este es nuestro segundo documento de texto en C++";
	documento.close();
	
	system("pause");
	
}

void colocar()
{
	ofstream documento;
	string texto;
	documento.open("archivo.txt", ios::app);
	if(documento.fail())
	{
		cout<<"Error al abrir";
	}
	cout<<"Ingrese el texto: ";
	getline(cin,texto);
	documento<<texto<<endl;
	documento.close();
	system("pause");
		
}
void leer()
{
	ifstream documento;
	string texto;
	documento.open("archivo.txt", ios::in);
	if(documento.fail())
	{
		cout<<"Error al abrir el documento";	
	} 
	while(!documento.eof())
	{
		getline(documento,texto);
		cout<<texto<<endl;
	}
	documento.close();
}
