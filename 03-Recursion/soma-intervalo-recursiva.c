#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int sum(int m, int n) {
    if (m == n) {
        return m;
    }

    return sum(m, n - 1) + n;
}

int main() {

    printf("%d", sum(2,5));

}