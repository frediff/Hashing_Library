# Hashing_Library
This is a simple implementation of a library that can be used to create hash-tables with a simple and fast hashing algorithm.
### Usage :
 > ``` HashNode ``` : It is simply a pair of $\LARGE{ (key, ~ value) }$
 
 > ```Hashtable``` : It is a data structure that stores the HashNodes based on the hashing function : $$ {\LARGE{ \left(  \sum_{i=0}^{len} str[i] \cdot 31^i  \right)  \mod size }} $$
