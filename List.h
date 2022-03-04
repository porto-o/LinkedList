#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    Elem data;
    struct Node *next; // Apuntador hacia un Node
}*List;

// Comenzando especificación

// empty:->List
List empty()
{
    return NULL;
}

// const:Elem, List->List
List newList(Elem e, List l)
{
    // Cada elemento vive en un nodo
    // 1.- Crear nodo
        // Generame espacio en memoria para contener al struct Node
        // Convertimos a tipo lista porque malloc devuelve un pointer
    List temp = (List)malloc(sizeof(struct Node));

    temp->data = e;
    temp->next = l;

    return temp;
};

// Observadoras

// isEmpty:List -> Bool
int isEmpty(List l)
{
  return l==NULL;
};

// head:List->Elem;
Elem head(List l)
{
    return l->data; // Campo data de l
};

// Desdobladoras

//rest:List->List;
List rest(List l)
{
    return l->next;
};