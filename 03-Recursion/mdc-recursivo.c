#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int MDC(int x, int y){
    if(y == 0){
        return x;
    }
    return MDC(y, x%y);
}

int main() {

    printf("%d", MDC(11,3));

}