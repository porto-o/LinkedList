#include <stdlib.h>
#include <stdio.h>

typedef struct Nodo
{
    Elem dato;
    struct Nodo *sig; // Apuntador hacia un Nodo
}*Lista;

// Comenzando especificación

// vacia:->Lista
Lista vacia()
{
    return NULL;
}

// const:Elem, Lista->Lista
Lista cons(Elem e, Lista l)
{
    // Cada elemento vive en un nodo
    // 1.- Crear nodo
        // Generame espacio en memoria para contener al struct Nodo
        // Convertimos a tipo lista porque malloc devuelve un pointer
    Lista temp = (Lista)malloc(sizeof(struct Nodo));

    temp->dato = e;
    temp->sig = l;

    return temp;
};

// Observadoras

// esvacia:Lista -> Bool
int esvacia(Lista l)
{
  return l==NULL;
};

// cabeza:Lista->Elem;
Elem cabeza(Lista l)
{
    return l->dato; // Campo dato de l
};

// Desdobladoras

//resto:Lista->Lista;
Lista resto(Lista l)
{
    return l->sig;
};