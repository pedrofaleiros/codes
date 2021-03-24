#include <stdio.h>
#include "calculadora.c"

int main()
{
    int n1, n2;
    printf("\nsomar numeros: ");
    scanf("%d %d", &n1, &n2);

    int soma = somar(n1, n2);
    int primo = verifica_primo(soma);

    printf("\nSoma: %d\n", soma);
    printf("Primo? ");
    if(primo == True)
        printf("sim\n");
    else
        printf("nao\n");

    coordenada coord;

    coord.x = n1;
    coord.y = n2;

    printf("\nCoordenadas: (%d, %d)\n", coord.x, coord.y);

    return 0;
}