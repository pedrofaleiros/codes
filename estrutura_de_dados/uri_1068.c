#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pilha, n, i, j;
    i = 0;

    scanf("%d", &n);

    for(; i < n; i++)
    {
        pilha = j = 0;

        char expressao[1000];

        scanf("%s", expressao);

        int aux = 0;
        while(expressao[j] != '\0')
        {
            if(expressao[j] == '('){
                pilha++;
            }else if(expressao[j] == ')'){
                pilha--;
            }

            if(pilha < 0){
                aux = -1;
                printf("incorrect\n");
                break;
            }

            j++;
        }

        if(pilha == 0 && aux == 0){
            printf("correct\n");
        }

    }

    return 0;
}