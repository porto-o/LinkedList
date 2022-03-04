#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    Elem data;
    struct Node *next; // Pointer to other Node
}*List;

// Begins Spec

// empty:->List
List empty()
{
    return NULL;
}

// const:Elem, List->List
List newList(Elem e, List l)
{
    // Each element lives in a node
    // 1.- Create node
        // Generate space in memory for struct node
        // Convert to type List because 'malloc' returns a pointer
    List temp = (List)malloc(sizeof(struct Node));

    temp->data = e;
    temp->next = l;

    return temp;
};

// Observers

// isEmpty:List -> Bool
int isEmpty(List l)
{
  return l==NULL;
};

// head:List->Elem;
Elem head(List l)
{
    return l->data; // Data field of the node
};

// Splitter

//rest:List->List;
List rest(List l)
{
    return l->next;
};