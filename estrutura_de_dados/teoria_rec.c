#include <stdio.h>
#include <stdlib.h>

int sequencia(int n)
{
    if(n > 1){
        return sequencia(n-1) + 2;
    }else{
        return 1;
    }
}

int main()
{
    int n;

    printf("Numero N: ");
    scanf("%d", &n);

    if(n > 0){
        int y = 1;
        while(y <= n){
            //int aux = sequencia(y);
            printf("%d ", sequencia(y));
            y += 1;
        }

        printf("\n");
    }else{
        printf("Erro\n");
    }

    return 0;
}