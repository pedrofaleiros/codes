#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element
{
	char *value;
	struct element *next;
} element;

typedef struct linked_list
{
	struct element *root;
	int count;
} linked_list;

element *aloc_element(char *str)
{
	element *el;
	el = (element *)malloc(sizeof(element));

	el->next = NULL;
	el->value = str;

	return el;
}

linked_list *aloc_linked_list()
{
	linked_list *list;

	list = (linked_list *)malloc(sizeof(linked_list));

	list->count = 0;
	list->root = NULL;

	return list;
}

void insert_linked_list(linked_list *list, char *str)
{
	if (list == NULL)
		list = aloc_linked_list();

	element *el = aloc_element(str);

	if (list->root == NULL)
	{
		list->root = el;
		list->count++;
	}
	else
	{

		element *aux;

		aux = list->root;

		while (aux->next != NULL)
			aux = aux->next;

		aux->next = el;
		list->count++;
	}
}

void remove_linked_list(linked_list *list, char *str)
{
	element *aux, *ant;

	aux = list->root;
	ant = NULL;

	while (aux != NULL && strcmp(aux->value, str) != 0)
	{
		ant = aux;
		aux = aux->next;
	}

	if (aux == NULL)
		return;

	if (ant == NULL)
	{
		list->root = aux->next;
	}
	else
	{
		ant->next = aux->next;
	}
	list->count--;
	free(aux);
}

void print_linked_list(linked_list *list)
{
	element *aux;
	aux = list->root;

	while (aux != NULL)
	{
		printf("%s, ", aux->value);
		aux = aux->next;
	}
}