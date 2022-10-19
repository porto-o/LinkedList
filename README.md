# Linked Lista
***
### Behaviour
It's a dato structure where the last input.
is the first output **(LiFo)**
***
### Form
1. Empty list, `[]`.
2. At least 1 element **`[X|Xs]`** where X is the last input and is called **cabeza**.
3. Xs is the **resto** of the list and is also a list.

![Illustration!](https://miro.medium.com/max/970/1*f2oDQ0cdY54olxCFOIMIdQ.png)

***
### Specification
- **Builders**.
    - `vacia:->Lista`
    - `cons:Elem,Lista->Lista`
- **Observers**.
    - `esVacia:Lista->Bool`
    - `cabeza:Lista->Elem`
- **Splitters**.
    - `resto:Lista->Lista`
***
### Axioms
1. `esVacia(vacia()) = True`
2. `esVacia(cons(e,l)) = False`
3. `cabeza(vacia()) = ERROR`
4. `cabeza(cons(e,l)) = e`
5. `resto(vacia()) = ERROR`
6. `resto(cons(e,l)) = l`

