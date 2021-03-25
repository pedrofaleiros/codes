#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento{
    char c;
    struct elemento * prox;
}elemento;

typedef struct lista{
    int qtd;
    struct elemento * inicio;
}lista;

int main()
{
    int n, i = 0;

    scanf("%d", &n);

    for(; i < n; i++)
    {
        char expressao[1000];

        scanf("%s", expressao);

        
    }

    return 0;
}