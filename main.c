#include <stdio.h>
#include "Elem.h"
#include "List.h"

List Fill(List a);
List FillSorted();
int NumElemsL(List);
void PrintList(List a);
List PasteList(List a1, List a2);
List InvertList(List a);
List InsertSort(Elem e, List a);
List SortList(List a);
int isIn(Elem e, List a);

int main()
{
    List a = empty(), b = empty(), c = empty();
    Elem e;

    puts("Capture the elements of list 'a' (press 0 to stop):");
    a = Fill(a);

    puts("\nThe elements of list 'a' are:");
    PrintList(a);

    puts("\nThe ordered elements of the list 'a' are: ");
    PrintList(SortList(a));

    puts("\nCapture the element to search in the list 'a'");
    e = ReadElem();
    if(isIn(e, a))
        printf("The element is in the list\n");
    else
        printf("The element is not in the list\n");

    /*puts("\nCapture the elements of list 'b' (press 0 to stop exec):");
    b = Fill(b);

    puts("\nCapture the elements of list 'c' (press 0 to stop exec):");
    c = FillSorted();

    puts("\nThe ordered elements of the list 'c' are: ");
    PrintList(c);

    puts("\nThe elements of list 'b' are:");
    PrintList(b);

    puts("\nThe elements of list a,b are: ");
    PrintList(PasteList(a,b));

    puts("\nThe elements of list b,a are: ");
    PrintList(PasteList(b,a));

    puts("\nThe inverted elements of list a,b are: ");
    PrintList(InvertList(PasteList(a,b)));

    puts("\nThe inverted elements of list b,a are: ");
    PrintList(InvertList(PasteList(b,a)));

    a = newList(4, newList(10, newList(30,empty())));
    isEmpty(a)? printf("\nIs empty :(\n"):printf("\nIs not empty :(\n");
    head(a);
    printf("The list has %d elements\n", NumElemsL(a));
    PrintElem(head(a));
    PrintElem(head(rest(a)));*/
    return 0;
};

int NumElemsL(List l)
{
    if(isEmpty(l))
        return 0;
    else
        // At least 1 element
        return 1 + NumElemsL(rest(l));
};

List Fill(List a)
{
    Elem e;
    while ((e= ReadElem()))
        a = newList(e, a);
    return a;
};

List FillSorted()
{
    Elem e;
    List a= empty();
    while((e= ReadElem()))
        a= InsertSort(e, a);
    return a;
};

void PrintList(List a)
{
    if(!(isEmpty(a))) {
        PrintElem(head(a));
        PrintList(rest(a));
    }
};

List PasteList(List a1, List a2)
{
  if(isEmpty(a1))
      return a2;
  else
      return newList(head(a1), PasteList(rest(a1), a2));
};

List InvertList(List a)
{
    /**
     * Invert rest
     * Turn head into list
     * Paste lists
     * */
     if((isEmpty(a)))
         return a;
     else
         return PasteList(InvertList(rest(a)), newList(head(a), empty()));
}

List InsertSort(Elem e, List a)
{
    if(isEmpty(a))
        return newList(e, a);
    else if(isLess(e, head(a)))
        return newList(e, a);
    else
        return newList(head(a), InsertSort(e, rest(a)));


}

List SortList(List a)
{
  if((isEmpty(a)))
      return a;
  else
      return InsertSort(head(a), SortList(rest(a)));
};

int isIn(Elem e, List a) {
    int bool = 0;
    if ((isEmpty(a)))
        return 0;
    else
    {
        for (int i = 0; i < NumElemsL(a); ++i) {
            bool = (e == head(a)) ? 1 : isIn(e, rest(a));
        }
        return bool;
    }
}