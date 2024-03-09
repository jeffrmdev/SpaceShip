#include<iostream>

using namespace std;

int main()
{
	int f,c;
	cout<<"Ingrese el numero de filas: ";
	cin>>f;
	
	cout<<"Ingrese numero de columnas: ";
	cin>>c;
	
	
	char foto[f][c];
	
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<"Posicion ["<<i<<"]["<<j<<"]";
			cin>>foto[i][j];
		}
	}
	
	for(int i=0;i<f;i++)
	{
		
		for(int j=0;j<c;j++)
		{
			cout<<foto[i][j];
		}
		cout<<endl;
	}
	
}
