#include "linked_list.h"

#define HASH_TABLE_SIZE 100

unsigned long hash_djb2(char *str)
{
    unsigned long hash = 5381;
    int c;

    for (int i = 0; str[i]; i++)
        hash = ((hash << 5) + hash) + str[i];

    return hash % HASH_TABLE_SIZE;
}

typedef struct hash_table
{
    linked_list **vet;
    int size;
    int count;
} hash_table;

hash_table *aloc_hash_table()
{
    hash_table *ht = (hash_table *)malloc(sizeof(hash_table));

    ht->vet = (linked_list **)malloc(sizeof(linked_list*) * HASH_TABLE_SIZE);

    for (int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        ht->vet[i] = NULL;
    }

    ht->count = 0;
    ht->size = HASH_TABLE_SIZE;

    return ht;
}

void insert_hash_table(hash_table *ht, char *str)
{
    int index = hash_djb2(str);

    if (ht->vet[index] == NULL)
    {
        ht->vet[index] = aloc_linked_list();
    }
    insert_linked_list(ht->vet[index], str);
    ht->count++;
}

void print_hash_table(hash_table *ht)
{
    for (int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        if (ht->vet[i] != NULL)
        {
            printf("\n%d: ", i);
            print_linked_list(ht->vet[i]);
        }
    }
}