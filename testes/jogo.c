#include "velha.h"

int main()
{
    int opcao = 1;

    while(opcao == 1)
    {
        printf("\n 1 - Jogar\n 2 - Sair\n > ");
        scanf("%d", &opcao);

        if(opcao == 1){
            Tab * tab;
            tab = constructor();
            tab->play;
        }
    }


    printf("\n");
    return 0;
}