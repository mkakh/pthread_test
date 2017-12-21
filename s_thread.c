#include <stdio.h>
#define N  1000000

int main(void) {
    long a[N];
    for (int i = 0; i < N; i++) {
       a[i] = i;
    }

    for (int i = 0; i < N; i++) {
        a[i] = a[i] * a[i] * a[i];
    }

    //for (int i = 0; i < N; i++) {
    //    printf("%ld ", a[i]);
    //}
    puts("");
}

