#include <stdlib.h>
#include <stdio.h>
#include "D:\Users\ismae\CLionProjects\Listas\Elem.h"
#include "D:\Users\ismae\CLionProjects\Listas\Lista.h"

int NumElemsL(Lista);
Lista LlenaLista(Lista);
void ImpLista(Lista);
Lista PegaListas(Lista,Lista);
Lista InvierteLista(Lista);

int main()
{
    Lista a = vacia(), b = vacia();
    puts("Captura los elementos de la lista a:");
    a = LlenaLista(a);

    puts("\nCaptura los elementos de la lista b:");
    b = LlenaLista(b);

    puts("\nLos elementos de la lista 'a' son:");
    ImpLista(a);

    puts("\nLos elementos de la lista 'b' son:");
    ImpLista(b);

    puts("\nLos elementos de la lista a,b son: ");
    ImpLista(PegaListas(a,b));

    puts("\nLos elementos de la lista b,a son: ");
    ImpLista(PegaListas(b,a));
    //a = cons(4, cons(10, cons(30,vacia())));
    //esvacia(a)? printf("Es vacia :(\n"):printf("No es vacia :(\n");
    //cabeza(a);
    //printf("La lista tiene %d elementos\n", NumElemsL(a));
    //ImpElem(cabeza(a));
    //ImpElem(cabeza(resto(a)));
    return 0;
};

int NumElemsL(Lista l)
{
    if(esvacia(l))
        return 0;
    else
        // At least 1 element
        return 1 + NumElemsL(resto(l));
};

Lista LlenaLista(Lista a)
{
    Elem e;
    while ((e=LeeElem()))
        a = cons(e,a);
    return a;
};

void ImpLista(Lista a)
{
    if(!(esvacia(a))) {
        ImpElem(cabeza(a));
        ImpLista(resto(a));
    }
};

Lista PegaListas(Lista a1,Lista a2)
{
  if(esvacia(a1))
      return a2;
  else
      return cons(cabeza(a1), PegaListas(resto(a1),a2));
};

Lista InvierteLista(Lista a)
{
    /**
     * Invertir resto
     * Convertir cabeza a lista
     * Pegar listas
     * */
}