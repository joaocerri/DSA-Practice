#include <stdlib.h>
#include <stdio.h>

int main() {

    int fibonnaci = 7;
    int sum, num1 = 0;
    int num2 = 1;

    for(int i = 0; i < fibonnaci - 1; i++){
        sum = num1+num2;
        num1 = num2;
        num2 = sum;
    }

    printf("%d", sum);

}