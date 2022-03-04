#include <stdlib.h>
#include <stdio.h>

typedef int Elem;

void PrintElem(Elem e){printf("%d, ", e);}
Elem ReadElem(){
    Elem e;
    scanf("%d",&e);
    return e;
}

int isLess(Elem e1, Elem e2){return e1 < e2;}