#include<stdio.h>
#include<stdlib.h>

struct HashNode //hashing node key-value pair
{
    char key[15];
    int  value;

    void display() {printf("(%s,%d)",key,value);}
};

struct HashTable //hash table
{
    int  size;
    HashNode* array;
};

int  compare(const char s1[],const char s2[]) // checks if two strings are equal
{
    int  i;
    for(i=0;((s1[i]!='\0')&&(s2[i]!='\0'));++i) if(s1[i]!=s2[i]) return 0;;
    if(s1[i]!='\0') return 0;
    if(s2[i]!='\0') return 0;
    return 1;
}

HashTable* Initialize(int  S) // create hash table // S : SIZE
{
    HashTable* entries = (HashTable*) malloc(sizeof(HashTable));
    entries->size = S;
    entries->array = (HashNode*) calloc(S,sizeof(HashNode));
    return entries;
}

int  hash_function(char str[],int  size) // hashing function
{
    int  i;
    int  hash = 0;
    int  p = 1;
    for(i=0;str[i]!='\0';++i)
    {
        hash = (hash + (str[i]-'a'+1)*p)%size;
        p = (p*31)%size;
    }
    return hash;
}

int  Search(char str[],HashTable* table) // searches and returns value associated with given key
{
    int  hash = hash_function(str,table->size);
    int  i = hash;
    if(compare(str,(table->array)[i].key)) return (table->array)[i].value;
    i = (i+1)%(table->size);
    while(i!=hash) // linear probing
    {
        if(compare(str,(table->array)[i].key)) {return (table->array)[i].value;}
        else {i = (i+1)%(table->size);}
    }
    return -1;
}

int  Delete(char str[],HashTable* table)
{
    int  hash = hash_function(str,table->size);
    int  i = hash;
    //int  j,empty;
    if(compare(str,(table->array)[i].key)) // checking current hash
    {
        ((table->array)[i].key)[0] = '\0';
        ((table->array)[i].value) = 0;
        // the below commented lines are an additional optional overhead to improve searching efficiency in future after delettions
        /*j=1;
        empty = i;
        while(j<table->size)
        {
            if((table->array)[(i+j)%(table->size)].key[0]=='\0') break;
            if(empty==hash_function((table->array)[(i+j)%(table->size)].key,table->size))
            {
                (table->array)[empty] = (table->array)[(i+j)%(table->size)];
                empty = (i+j)%(table->size);
                ((table->array)[empty].key)[0] = '\0';
                ((table->array)[empty].value) = 0;
            }
            ++j;
        }*/
        return i;
    }
    i = (i+1)%(table->size);
    while(i!=hash) // linear probing
    {
        if(compare(str,(table->array)[i].key))
        {
            ((table->array)[i].key)[0] = '\0';
            ((table->array)[i].value) = 0;
            /*j=1;
            empty = i;
            while(j<table->size)
            {
                if((table->array)[(i+j)%(table->size)].key[0]=='\0') break;
                if(empty==hash_function((table->array)[(i+j)%(table->size)].key,table->size))
                {
                    (table->array)[empty] = (table->array)[(i+j)%(table->size)];
                    empty = (i+j)%(table->size);
                    ((table->array)[empty].key)[0] = '\0';
                    ((table->array)[empty].value) = 0;
                }
                ++j;
            }*/
            return i;
        }
        else i = (i+1)%(table->size);
    }
    return -1;
}

int  IncreaseValue(char str[],HashTable* table)
{
    int  hash = hash_function(str,table->size);
    int  i = hash;
    if(compare(str,(table->array)[i].key)) // checking current hash
    {
        ((table->array)[i].value) += 1;
        return i;
    }
    i = (i+1)%(table->size);
    while(i!=hash) // linear probing
    {
        if(compare(str,(table->array)[i].key))
        {
            ((table->array)[i].value) += 1;
            return i;
        }
        else i = (i+1)%(table->size);
    }
    return -1;
}

void Print(HashTable* table) // print table
{
    (table->array)[0].display();
    for(int  i=1;i<(table->size);++i)
    {
        printf(" ");
        (table->array)[i].display();
    }
}

int  Insert(HashNode node,HashTable* table)
{
    int  hash = hash_function(node.key,table->size);
    int  i = hash;
    if(((table->array)[i].key)[0]=='\0') // check if current position is empty
    {
        (table->array)[i] = node;
        return i;
    }
    i = (i+1)%(table->size);
    while(i!=hash) // linear probing
    {
        if(((table->array)[i].key)[0]=='\0')
        {
            (table->array)[i] = node;
            return i;
        }
        else i = (i+1)%(table->size);
    }
    return -1;
}

void DeleteTable(HashTable* table) // deallocate hash table
{
    free(table->array);
    free(table);
}
