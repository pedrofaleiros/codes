#include <stdio.h>

int serie(int n){
    
    if(n > 1){
        int aux = serie(n-1) + 2;
        printf("%d ", aux);
        return aux;
    }else{
        printf("1 ");
        return 1;
    }
}

int main(){

    printf("Numero: ");
    int n;
    scanf("%d", &n);

    if(n > 0){
        serie(n);
    }

    printf("\n");

    return 0;
}
