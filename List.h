#include <stdlib.h>
#include <stdio.h>

typedef struct Nodo
{
    Elem dato;
    struct Nodo *sig; // Pointer to other Nodo
}*Lista;

// Begins Spec

// vacia:->Lista
Lista vacia()
{
    return NULL;
}

// const:Elem, Lista->Lista
Lista cons(Elem e, Lista l)
{
    // Each element lives in a node
    // 1.- Create node
        // Generate space in memory for struct node
        // Convert to type Lista because 'malloc' returns a pointer
    Lista temp = (Lista)malloc(sizeof(struct Nodo));

    temp->dato = e;
    temp->sig = l;

    return temp;
};

// Observers

// esVacia:Lista -> Bool
int esVacia(Lista l)
{
  return l==NULL;
};

// cabeza:Lista->Elem;
Elem cabeza(Lista l)
{
    return l->dato; // Data field of the node
};

// Splitter

//resto:Lista->Lista;
Lista resto(Lista l)
{
    return l->sig;
};