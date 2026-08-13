#include <stdlib.h>
#include <stdio.h>

float fibonacciModificado(float n){
    if(n == 0){return 0;}
    if(n == 1){return 2;}
    return ((n*n + 1)/n + fibonacciModificado(n - 1));
}

int main(){
    float num = fibonacciModificado(4);
    printf("%.2f", num);
    return -1;
}