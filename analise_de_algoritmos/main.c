#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 100

int main(int argc, char *argv[])
{

	hash_table *table = aloc_hash_table();

	FILE *fp;
	char row[MAX_CHAR];
	char *token;
	int i;

	fp = fopen("data.csv", "r");

	while (!feof(fp))
	{
		fgets(row, MAX_CHAR, fp);

		i = 0;
		while (row[i] != '\0' && row[i] != '\n')
			i++;

		char *str = malloc(sizeof(char) * i + 1);

		strncpy(str, &row[0], i);
		str[i] = '\0';

		insert_hash_table(table, str);
	}

	print_hash_table(table);

	return 0;
}