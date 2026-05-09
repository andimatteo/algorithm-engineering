/*
 * reservoir sampling example
 * */
#include "lib.h"

int algorithm(int *S, int *S1, int n, int m) {

    // init reservoir
    for (int i = 0; i < m; i++) {
        S1[i] = S[i];
    }

    // after that we go one item by one
    for (int i = m; i < n; i++) {
        int h = RAND(0,i - 1);

        printf("%d\n",h);

        if (h < m) {
            S1[h] = S[i];
        }

    }

    return 0;
}

int main() {

    srand(time(NULL));
    int n = 10;
    int m = 5;

    int S[] = {1,2,3,4,1,2,3,4,1,2};
    int S1[m];


    sys_check(algorithm(S,S1,n,m));

    // print result
    printf("S = [");
    for (int i = 0; i < m; i++) {
        printf("%d",S1[i]);
        if (i != m - 1)
            printf(",");
    }
    printf("]\n");

    return 0;
}
