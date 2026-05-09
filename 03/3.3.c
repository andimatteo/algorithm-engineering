#include "lib.h"

int algorithm(int *S, int *S1, int n, int m) {
    
    int s = 0;
    for (int i = 0; (i < n) && (s < m); i++) {
        double p = (double)rand() / RAND_MAX;

        printf("p = %.2f, q = %.2f\n",p,((double)(m - s) / (n - i)));

        if (p <= ((double)(m - s) / (n - i))) {
            printf("s = %d, i = %d: %d campionato\n",
                    s,i,S[i]);
            S1[s++] = S[i];
        }

    }
    return 0;
}

int main() {

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
