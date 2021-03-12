#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Numero N: ");
    scanf("%d", &n);

    if(n <= 0){
        printf("Erro\n");
        exit(-1);
    }


    int y = 1;
    while(y < n*2){
        printf("%d ", y);
        y += 2;
    }

    printf("\n");

    return 0;
}