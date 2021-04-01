/* 
 Dado um inteiro n, 
 definir i  como o enésimo elemento a partir dotopo da pilha,  
 deixando a pilha inalterada.
*/
#include "basico_pilha.h"

int define_i(pilha * p, int n);

int main()
{
    int n, i;
    pilha * p;
    p = aloca_pilha();

    push(p, 1);
    push(p, 2);
    push(p, 3);
    push(p, 4);
    push(p, 5);
    push(p, 6);
    push(p, 7);

    scanf("%d", &n);

    i = define_i(p, n);

    (i == -1) ? printf("\n lista possui menos que %d elementos", n) : printf("\n i = %d", i);

    printf("\n");
    return 0;
}

int define_i(pilha * p, int n)
{
    pilha * aux;
    int ret;
    aux = aloca_pilha();
    for(int i = 0; i < n; i++)
    {
        if(stackpop(p) != -1){
            ret = pop(p);
            push(aux, ret);
        }else{
            ret = -1;
            i = n;
        }
    }

    while(aux->topo)
        push(p, pop(aux));
    
    return ret;
}