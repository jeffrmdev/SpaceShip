#include<iostream>

using namespace std;

int main()
{
	string nombre="Jeff";
	string apellido="Rios";
	cout<<nombre<<endl;
	cout<<apellido<<endl;
	
	
	cout<<endl;
	string *p1=&nombre;
	string *p2=&apellido;
	
	cout<<p1<<endl;
	cout<<p2<<endl;
}
