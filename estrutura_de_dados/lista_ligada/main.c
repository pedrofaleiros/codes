#include <stdio.h>
#include <stdlib.h>
#include "basico.c"

int main()
{
    lista * numeros;
    int opcao = 1, num;

    numeros = aloca_lista();

    while(opcao){
        printf("\n1 - inserir numero\n2 - mostrar lista\n3 - remove numero\n0 - sair\nopcao: ");
        scanf("%d", &opcao);

        if(opcao == 1){
            printf("\nnumero: ");
            scanf("%d", &num);
            inclui_ordenado(numeros, num);
        }else if(opcao == 2){
            mostra_lista(numeros);
        }else if(opcao == 3){
            printf("\nremover numero: ");
            scanf("%d", &num);
            remove_elemento(numeros, num);
        }
    }
}