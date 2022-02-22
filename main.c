#include <stdlib.h>
#include <stdio.h>
#include "D:\Users\ismae\CLionProjects\Listas\Elem.h"
#include "D:\Users\ismae\CLionProjects\Listas\Lista.h"

Lista LlenaLista(Lista);
Lista LlenaListaOrd();
int NumElemsL(Lista);
void ImpLista(Lista);
Lista PegaListas(Lista,Lista);
Lista InvierteLista(Lista);
Lista InsertOrd(Elem, Lista);
Lista OrdenaLista(Lista);

int main()
{
    Lista a = vacia(), b = vacia(), c = vacia();
    puts("Captura los elementos de la lista a:");
    a = LlenaLista(a);

    puts("\nLos elementos de la lista 'a' ordenados son: ");
    ImpLista(OrdenaLista(a));

    //puts("\nCaptura los elementos de la lista b:");
    //b = LlenaLista(b);

    //puts("\nCaptura los elementos de la lista c:");
    //c = LlenaListaOrd();
    //puts("\nLos elementos de la lista c ordenada son: ");
    //ImpLista(c);

    //puts("\nLos elementos de la lista 'a' son:");
    //ImpLista(a);

    //puts("\nLos elementos de la lista 'b' son:");
    //ImpLista(b);

    //puts("\nLos elementos de la lista a,b son: ");
    //ImpLista(PegaListas(a,b));

    //puts("\nLos elementos de la lista b,a son: ");
    //ImpLista(PegaListas(b,a));

    //puts("\nLos elementos de la lista a,b invertidos: ");
    //ImpLista(InvierteLista(PegaListas(a,b)));

    //puts("\nLos elementos de la lista b,a invertidos: ");
    //ImpLista(InvierteLista(PegaListas(b,a)));

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

Lista LlenaListaOrd()
{
    Elem e;
    Lista a=vacia();
    while((e=LeeElem()))
        a=InsertOrd(e,a);
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
     if((esvacia(a)))
         return a;
     else
         return PegaListas(InvierteLista(resto(a)), cons(cabeza(a), vacia()));
}

Lista InsertOrd(Elem e, Lista a)
{
    if(esvacia(a))
        return cons(e,a);
    else if(EsMenor(e,cabeza(a)))
        return cons(e,a);
    else
        return cons(cabeza(a),InsertOrd(e,resto(a)));


}

Lista OrdenaLista(Lista a)
{
  if((esvacia(a)))
      return a;
  else
      return InsertOrd(cabeza(a), OrdenaLista(resto(a)));
};