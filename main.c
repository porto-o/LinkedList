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

int main() {
    Lista l = cons(1, cons(2, cons(3, cons(4,vacia()))));
    //ImpLista(l);

    Lista m = cons(5, cons(6, cons(7, cons(8, cons(5, cons(5, cons(5,vacia())))))));
    //ImpLista(PegarListas(l,m));
    //ImpLista(InvertirLista(m));
    //ImpElem(EstaEn(8,m));
    //ImpElem(Ocurrencias(5,m));
    //ImpLista(SubLista(5,m));
    //ImpLista(SubLista2(5,5,m));
    //ImpLista(CambiaElem(900,5,m));
    ImpLista(InsertFrenteN(5,45,m));
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

    return cons(e, PegarListas(InsertFrenteN(n,e, resto(l)),l));

}