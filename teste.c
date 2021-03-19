#include <stdio.h>

int main(){

    int a = 3, b = 2, c = 4;

    if(a = b + c){
        printf("%d\n", a);
    }


    a = 3, b = 2, c = 4;

    if(a == b + c){
        printf("%d\n", a);
    }else{
        printf("%d\n", a);
    }
    return 0;
}