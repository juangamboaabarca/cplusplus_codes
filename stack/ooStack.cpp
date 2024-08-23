// Pila en C++
// (C) Julio 2001, Salvador Pozo
// C con Clase: http://c.conclase.net

#include <iostream>
using namespace std;
 
class nodo {
   public:
    nodo(int v, nodo *sig = NULL)
    {
       valor = v;
       siguiente = sig;
    }

   private:
    int valor;
    nodo *siguiente;
        
   friend class pila;
};
 
typedef nodo *pnodo;
 
class pila {
   public:
    pila() : ultimo(NULL) {}
    ~pila();
    
    void Push(int v);
    int Pop();

   private:
    pnodo ultimo;
};
 
pila::~pila()
{
   pnodo aux;
   
   while(ultimo) {
      aux = ultimo;
      ultimo = ultimo->siguiente;
      delete aux;
   }
}

void pila::Push(int v)
{
   pnodo nuevo;
 
   /* Crear un nodo nuevo */
   nuevo = new nodo(v, ultimo);
   /* Ahora, el comienzo de nuestra pila es en nuevo nodo */
   ultimo = nuevo;
}

int pila::Pop()
{

   pnodo nodo; /* variable auxiliar para manipular nodo */
   int v;      /* variable auxiliar para retorno */
   
   if(!ultimo) return 0; /* Si no hay nodos en la pila retornamos 0 */
   /* Nodo apunta al primer elemento de la pila */
   nodo = ultimo;
   /* Asignamos a pila toda la pila menos el primer elemento */
   ultimo = nodo->siguiente;
   /* Guardamos el valor de retorno */
   v = nodo->valor; 
   /* Borrar el nodo */
   delete nodo;
   return v;
}

int main()
{
   pila Pila;

   Pila.Push(20);
   cout << "Push(20)" << endl;
   Pila.Push(10);
   cout << "Push(10)" << endl;
   cout << "Pop() = " << Pila.Pop() << endl;
   Pila.Push(40);
   cout << "Push(40)" << endl;
   Pila.Push(30);
   cout << "Push(30)" << endl;
   cout << "Pop() = " << Pila.Pop() << endl;
   cout << "Pop() = " << Pila.Pop() << endl;
   Pila.Push(90);
   cout << "Push(90)" << endl;
   cout << "Pop() = " << Pila.Pop() << endl;
   cout << "Pop() = " << Pila.Pop() << endl;

   cin.get();
   return 0;
}

