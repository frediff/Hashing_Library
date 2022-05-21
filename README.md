# Hashing_Library
This is a simple definition of a library that can be used to create hash-tables with a simple and fast hashing algorithm.
### Usage :
 > ``` HashNode ``` : It is simply a pair of $\LARGE{ (key, ~ value) }$
 
 > ```Hashtable``` : It is a data structure that stores the HashNodes based on the hashing function : $$ {\LARGE{ \left(  \sum_{i=0}^{len} str[i] \cdot 31^i  \right)  \mod size }} $$

### User Methods :
- ```Delete()``` : for deleting a key
- ```Insert()``` : for inserting a key
- ```Search()``` : for searching a key
- ```Print()``` : for printing the Hash-Table
- ```display()``` : for displaying a Hash-Node
- ```DeleteTable()``` : for deleting a Hash-Table and releasing the container memory

<strong> * Note : The code contains definitions and not implementation! </strong>
