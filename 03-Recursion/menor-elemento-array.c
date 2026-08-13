#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


int calcMin(int array[], int size){
    int min = array[size - 1];
    if(size == 1){
        return min;
    }
    if(calcMin(array, size - 1)< min ){
       min = calcMin(array, size - 1);
    }
    else{
        calcMin(array, size - 1);
    }
    return min;
}

int main(){

    int array [7] = {3,7,13,9,5,9,1};
    int num = INT_MAX;

    for(int i = 0; i < 7; i++){
        if(array[i] < num){
            num = array[i];
        }
    }

    printf("%d", num);
    printf("\n%d",calcMin(array,7));
    return -1;
}