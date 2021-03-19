#include <stdio.h>

int main()
{
    char nome[30];

    scanf("%[a-zA-Z1-9 ]", nome);

    int aux = printf("%s\n", nome) - 1;

    printf("> %d\n", aux);

    return 0;
}