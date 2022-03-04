# Linked List
***
### Behaviour
It's a data structure where the last input.
is the first output **(LiFo)**
***
### Form
1. Empty list, `[]`.
2. At least 1 element **`[X|Xs]`** where X is the last input and is called **head**.
3. Xs is the **rest** of the list and is also a list.

![Illustration!](https://miro.medium.com/max/970/1*f2oDQ0cdY54olxCFOIMIdQ.png)

***
### Specification
- **Builders**.
    - `empty:->List`
    - `newList:Elem,List->List`
- **Watchers**.
    - `isEmpty:List->Bool`
    - `head:List->Elem`
- **Splitters**.
    - `rest:List->List`
***
###Axioms
1. `isEmpty(empty()) = True`
2. `isEmpty(newList(e,l)) = False`
3. `head(empty()) = ERROR`
4. `head(newList(e,l)) = e`
5. `rest(empty()) = ERROR`
6. `rest(newList(e,l)) = l`

