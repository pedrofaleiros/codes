#include <stdio.h>
#include <stdlib.h>

int sequencia(int n)
{
    if(n == 1){
        return 1;
    }else{
        return sequencia(n-1) + 2;
    }
}

int main()
{
    int n;

    printf("Numero N: ");
    scanf("%d", &n);

    if(n <= 0){
        printf("Erro\n");
        exit(-1);
    }

    for(int i = 1; i <= n; i++){
        int aux = sequencia(i);
        printf("%d ", aux);
    }

    printf("\n");

    return 0;
}