/* 
Dado um inteiro n,
definir i  como o enésimo elemento a partir do topo da pilha,
deixando a pilha sem seus n elementos superiores
*/
#include <stdio.h>
#include <stdlib.h>
#include "basico_pilha.h"

int main()
{
    int n, i, j;
    pilha * p;
    p = aloca_pilha();

    push(p, 1);
    push(p, 2);
    push(p, 3);
    push(p, 4);
    push(p, 5);
    push(p, 6);
    push(p, 7);

    printf("\n n: ");
    scanf("%d", &n);

    for(j = 0; j < n; j++){
        i = pop(p);
    }

    (i == -1) ? printf("\n lista pequena") : printf("\n i = %d", i);

    printf("\n");
    return 0;
}