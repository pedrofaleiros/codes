#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, y = 1, i;
    printf("Numero N: ");
    scanf("%d", &n);

    if(n <= 0){
        printf("Erro\n");
        exit(-1);
    }

    for(i = 0; i < n; i++){
        printf("%d ", y);
        y += 2;
    }

    printf("\n");

    return 0;
}