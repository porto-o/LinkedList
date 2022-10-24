#include <stdlib.h>
#include <stdio.h>

typedef int Elem;

void ImpElem(Elem e){printf("%d, ", e);}

Elem LeerElem(){
    Elem e;
    scanf("%d",&e);
    return e;
}

int EsIgual(Elem e1, Elem e2){
    return 1 ? e1 == e2 : 0;
}

int SonDiferentes(Elem e1, Elem e2)
{
    return e1 != e2;
}

int esMenor(Elem e1, Elem e2){return e1 < e2;}