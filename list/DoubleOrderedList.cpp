#include<iostream>
#include<stdlib.h>
#include <conio.h>
using namespace std;

struct Nodo
{
	int n;
	string nombre;
	Nodo *sig;
	Nodo *ant;
};
Nodo *dato = NULL, *ini = NULL, *aux = NULL;
void insertar(Nodo *&p, int n) // insertar recursivo
{
	if (p == NULL) {
		dato = new struct Nodo;
		dato->n = n;
		dato->sig = NULL;
		dato->ant=NULL;
		p = dato;
	}
	else
	{
		if (p->n>n && p==ini) {
			dato = new struct Nodo;
			dato->n = n;
			dato->sig = p;
			dato->ant=NULL;
			p->ant=dato;
			p = dato;
		}
		else
		{
			if (p->n<n&&p->sig == NULL) {
				dato = new struct Nodo;
				dato->n = n;
				dato->sig = NULL;
				dato->ant=p;
				p->sig = dato;
			}
			else
			{ 
				if (p->n<n && p->sig->n>n) {
					dato = new struct Nodo;
					dato->n = n;
					dato->sig = p->sig;
					p->sig->ant=dato;
					dato->ant=p;
					p->sig = dato;
				}
				else
				{
					insertar(p->sig, n);
				}
			}
		}
	}
}
void mostrarR(Nodo *l)
{
	if(l==NULL)
	{
		cout<<"NULL"<<endl;
	}
	else
	{
			//mostrarR(l->sig);
			cout<<l->n<<" ->";
			mostrarR(l->sig);
	}
}
void mostrarI(Nodo *l)
{
	while(l!=NULL)
	{
		cout<<l->n<<" -> ";
		l=l->sig;
	}
	cout<<"NULL"<<endl;
}
int Buscar(Nodo *l,int p, int b)
{
	if (l==NULL)
	{
		return -1;
	}
	else
	{
		
			if (l->n==b)
			{
				return p;
			}
			else
			{
				return Buscar(l->sig,p+1,b);
			}
		
	}
}
int Eliminar(Nodo *&l, int b)
{
		if (l==NULL)
		{
			return -1;
		}
		else
		{
			if (l->sig!=NULL)
			{
				if (l->sig->n==b)
				{
					l->sig->sig->ant=l;
					l->sig=l->sig->sig;
					return 1;
				}
				else
				{
					return Eliminar(l->sig,b);
				}
			}
			else
			{
				if (l->n==b)
				{
					l=NULL;
					return 1;
				}
				else
				{
					return -1; 
				}
			}
		}
}
void mostrar(struct Nodo *l) {
	//clrscr();
	while (l != NULL) {
		if (l->ant==NULL)
		{
			if (l->sig==NULL)
			{
				cout<< l->n<<"(NULL,NULL)"<<endl;
			}
			else
			{
				cout<< l->n<<"(NULL,"<<l->sig->n<<")"<<endl;
			}
		}
		else
		{
			if (l->sig==NULL)
			{
				cout<< l->n<<"("<<l->ant->n<<",NULL)"<<endl;
			}
			else
			{
				cout<< l->n<<"("<<l->ant->n<<","<<l->sig->n<<")"<<endl;
			}
		}
		l = l->sig;
	}
	system("PAUSE");
	cout<<endl;
}
int main()
{
	//cout<<"UNO"<<endl;
	insertar(ini, 50);
	//mostrar(ini);
	//cout<<"DOS"<<endl;
	insertar(ini, 20);
	//mostrar(ini);
	//cout<<"tres"<<endl;
	insertar(ini, 30);
	//mostrar(ini);
	//cout<<"cuatro"<<endl;
	insertar(ini, 10);
	//mostrar(ini);
	//cout<<"cinco"<<endl;
	insertar(ini, 35);
	//mostrar(ini);
	//cout<<"seis"<<endl;
	insertar(ini, 60);
	//mostrar(ini);
	//cout<<"siete"<<endl;
	insertar(ini, 40);
	mostrarR(ini);
	cout<<"Buscar 35"<<endl;
	int resp=Buscar(ini,1,35);
	if (resp>0)
	{
		cout<<"Dato encontrado y esta en la pos "<<resp<<endl;
	}
	else
	{
		cout<<"Dato no encontrado"<<endl;
	}
	int e=Eliminar(ini,35);
	if (e<0)
	{
		cout<<"El dato no se encuentra en la lista"<<endl;
	}
	else
	{
		cout<<"Dato Eliminado con exito"<<endl;
	}
	mostrarI(ini);
	getch();
	return 0;
}
