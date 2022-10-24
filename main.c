#include "Elem.h"
#include "List.h"


int NumElems(Lista);
void ImpLista(Lista);
Lista PegarListas(Lista, Lista);
Lista InvertirLista(Lista);
int EstaEn(Elem, Lista);
int Ocurrencias(Elem, Lista);
Lista SubLista(Elem, Lista); // Retorna la lista formada despues de la primera ocurrencia de E en L
Lista SubLista2(Elem, Elem, Lista); // Retorna la lista entre las primeras ocurrencias de 2 elementos en una lista
Lista SubLista3(Elem, Lista);
Lista CambiaElem(Elem, Elem, Lista); // Cambia todos los elementos de una lista e1, con e2
Lista InsertFrenteN(int, Elem, Lista); // Inserta n veces el elemento al frente de la lista
Lista InsertFinalN(int, Elem, Lista); // Inserta n veces el elemento al final de la lista
int EsPalindromo(Lista);
int ListasIguales(Lista, Lista);
Lista OrdenarLista(Lista);
Lista InsOrd(Elem, Lista);

int main() {
    Lista l = cons(1, cons(2, cons(3, cons(3, cons(2, cons(1, vacia()))))));
    //ImpLista(l);

    Lista m = cons(1, cons(-1, cons(3, cons(4,vacia()))));
    //ImpLista(PegarListas(l,m));
    //ImpLista(InvertirLista(m));
    //ImpElem(EstaEn(8,m));
    //ImpElem(Ocurrencias(5,m));
    //ImpLista(SubLista(5,m));
    //ImpLista(SubLista2(5,5,m));
    //ImpLista(CambiaElem(900,5,m));
    ImpLista(InsertFrenteN(10,45,m));
    //ImpLista(PegarListas(l,m));
    //printf("\n");
    //ImpLista(PegarListas(m,l));
    printf("\n");
    ImpLista(InsertFinalN(10,45,m));
    //ImpElem(EsPalindromo(l));
    //ImpLista(OrdenarLista(m));
    //ImpLista(InsOrd(2,m));
}

int NumElems(Lista l){
    if(esVacia(l)){
        return 0;
    }else{
        return 1 + NumElems(resto(l));
    }
}

void ImpLista(Lista l){
    if(!esVacia(l)){
        ImpElem(cabeza(l));
        ImpLista(resto(l));
    }
}

Lista PegarListas(Lista l, Lista m){
    if(esVacia(l))
        return m;
    else
        return cons(cabeza(l), PegarListas(resto(l), m));
}

Lista InvertirLista(Lista l){
    if(esVacia(l))
        return vacia();
    else
        return PegarListas(InvertirLista(resto(l)), cons(cabeza(l),vacia()));
}

int EstaEn(Elem e, Lista l){
    if(esVacia(l))
        return 0;
    else if(!(EsIgual(cabeza(l),e))){
        return EstaEn(e, resto(l));
    }else{
        return 1;
    }
}

int Ocurrencias(Elem e, Lista l){
    if(esVacia(l) && !EstaEn(e,l))
        return 0;
    else if(EsIgual(e, cabeza(l)))
        return 1 + Ocurrencias(e, resto(l));
    else
        return Ocurrencias(e, resto(l));

}

Lista SubLista(Elem e, Lista l)
{
    if(esVacia(l))
        return vacia();
    else if(EsIgual(cabeza(l), e))
        return resto(l);
    else
        return SubLista(e, resto(l));
}


/**
 * 1. Vemos si la cabeza coincide con mi limite 1
 *
 * 2. Si coincide, llamamos a la funcion que "arma" la lista después de la coincidencia, le mandamos el resto
 *      2.1. Si coincide e2 con la cabeza del resto, retornamos vacia porque no existe ningun numero intermedio
 *      2.2. Si no coincide, construimos esa cabeza y llamamos otra vez a esa función pero ahora le mandamos
 *              el otro resto
 *
 * 3. Si no coincide, llamamos recursivamente ahora con el resto
 * */

Lista SubLista2(Elem e1, Elem e2, Lista l)
{
    if(esVacia(l))
        return l;
    else if(EsIgual(e1, cabeza(l)))
        return SubLista3(e2,resto(l));
    else
        return SubLista2(e1,e2, resto(l));
}

Lista SubLista3(Elem e2, Lista l)
{
    if(esVacia(l))
        return l;
    else if(!(SonDiferentes(e2,cabeza(l))))
        return cons(cabeza(l), SubLista3(e2, resto(l)));

    // Aqui quitamos el último else donde se retorna vacio, porque siempre retornaria un vacio
}

Lista CambiaElem(Elem e1, Elem e2, Lista l)
{
    if(esVacia(l))
        return l;
    else if(EsIgual(e2, cabeza(l))){
        return cons(e1, CambiaElem(e1,e2, resto(l)));
    }
    else
        return cons(cabeza(l),CambiaElem(e1,e2, resto(l)));
}

Lista InsertFrenteN(int n, Elem e, Lista l)
{
    if(n > 0) {
        l = cons(e, InsertFrenteN(n - 1, e, l));
        return l;
    }else
        return l;
}

Lista InsertFinalN(int n, Elem e, Lista l)
{
    if(n > 0)
        return PegarListas(l, (cons(e, InsertFinalN(n-1,e,vacia()))));
    else
        return l;
}

int ListasIguales(Lista l1, Lista l2)
{
    if(esVacia(l1) && esVacia(l2))
        return 1;
    else if(esVacia(l1))
        return 0;
    else if(esVacia(l2))
        return 0;
    else if(EsIgual(cabeza(l1), cabeza(l2)))
        return ListasIguales(resto(l1), resto(l2));
    else
        return 0;

}

int EsPalindromo(Lista l)
{
    return ListasIguales(InvertirLista(l),l);
}

// Repasar InsOrd y OrdenarLista

Lista InsOrd(Elem e, Lista l)
{
    if(esVacia(l) || esMenor(e, cabeza(l)))
        return cons(e,l);
    else
        return cons(cabeza(l), InsOrd(e, resto(l)));
}

Lista OrdenarLista(Lista l)
{
    if(esVacia(l))
        return l;
    else
        return InsOrd(cabeza(l), OrdenarLista(resto(l)));
}