//---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>



struct node
{
	int n;
	node *next;
	node *prev;
};
node *start=NULL;
node *endp=NULL;
node *datap=NULL;
int op;
int val;
using namespace std;
void show(node *l)
{
	if (l==NULL) {
		cout<<"La lista esta nula"<<endl;
	}
	else
	{
		cout<<l->n<<"->";
		while(l->next!=start)
		{
			cout<<l->next->n<<"->";
			l=l->next;
		}
		cout<<endl;
	}
}
void insert(node *&p,int n)
{
	if (p==NULL) {
		datap=new struct node;
		datap->n=n;
		datap->next=datap;
		datap->prev=datap;
		start=datap;
		endp=datap;
	}
	else
	{
		if (p->n>n&&p->prev==endp) {
			datap= new struct node;
			datap->n=n;
			datap->next=p;
			datap->prev=p->prev;
			p->prev->next=datap;
			p->prev=datap;
			start=datap;
		}
		else
		{
			if (p->n<n&&p->next==start) {
				datap= new struct node;
				datap->n=n;
				datap->next=p->next;
				datap->prev=p;
				p->next->prev=datap;
				p->next=datap;
				endp=datap;
			}
			else
			{
				if (p->n<n && p->next->n>n) {
					datap = new struct node;
					datap->n=n;
					datap->next=p->next;
					p->next->prev=datap;
					datap->prev=p;
					p->next=datap;
				}
				else
				{
					insert(p->next,n);
				}
			}
		}
	}
}
int main()
{
	do
	{
		cout<<"1-Ingresar"<<endl;
		cout<<"2-Mostrar"<<endl;
		cin>>op;
		switch(op)
		{
			case 1:
				cout<<"Ingrese el dato"<<endl;
				cin>>val;
				insert(start,val);
				break;
			case 2:
				show(start);
				break;
		}
		cout<<"Inicio:"<<start->n<<endl;
		cout<<"Fin:"<<endp->n<<endl;
		getch();
	}while (true);
	return 0;
}
//---------------------------------------------------------------------------
