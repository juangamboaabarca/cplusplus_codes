#include<iostream>
#include<stdlib.h>
using namespace std;
struct Nodo
{
	int n;
	Nodo *sig;
};
Nodo *dato = NULL, *ini = NULL, *aux = NULL;
void insertarAux(Nodo *&p, int n)
{
	bool bandera = false;
	aux = p;
	dato = new struct Nodo;
	dato->n = n;
	if (aux==NULL)
	{
		dato->sig = NULL;
		p = dato;
	}
	else
	{ 
		if (aux->n > n && aux == ini)
		{
			dato->sig = aux;
			p = dato;
		}
		else
		{ 
			while (aux->sig != NULL && (!bandera))
			{
				if (aux->n<n && aux->sig->n>n)
				{
					bandera = true;
				}
				else
				{ 
					aux = aux->sig;
				}
			}
			if (!bandera)
			{
				dato->sig = NULL;
				aux->sig = dato;
			}
			else
			{
				dato->sig = aux->sig;
				aux->sig = dato;
			}
		}
		
	}
}
void mostrar(struct Nodo *l) {
	//clrscr();
	while (l != NULL) {
		cout<< l->n<<"->";
		l = l->sig;
	}
	system("PAUSE");
	cout<<endl;
}
int main()
{
	insertarAux(ini, 50);
	insertarAux(ini, 20);
	insertarAux(ini, 30);
	insertarAux(ini, 10);
	insertarAux(ini, 35);
	insertarAux(ini, 60);
	insertarAux(ini, 40);
	aux = ini;
	mostrar(aux);
	return 0;
}

