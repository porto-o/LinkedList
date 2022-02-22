#include <stdlib.h>
#include <stdio.h>

typedef int Elem;

void ImpElem(Elem e)
{
    printf("%d,",e);
}

Elem LeeElem()
{
    Elem e;
    scanf("%d", &e);
    return e;
}

int EsMenor(Elem e1, Elem e2)
{
    return e1<e2;
};