# Linked List
***
### Behaviour
It's a data structure where the last input.
is the first output **(LiFo)**
***
### Form
1. Empty list, `[]`.
2. At least 1 element **`[X|Xs]`** where X is the last input and is called **head**.
2. Xs is the **rest** of the list and is also a list.
***
### Specification
**Builders**.
`empty:->List`
`new:Elem,List->List`
**Watchers**.
`isEmpty:List->Bool`
`head:List->Elem`
**Splitters**.
`rest:List->List`
***
###Axioms
1. `isEmpty(empty()) = True`
2. `isEmpty(new(e,l)) = False`
3. `head(empty()) = ERROR`
4. `head(new(e,l)) = e`
5. `rest(empty()) = ERROR`
6. `rest(new(e,l)) = l`

