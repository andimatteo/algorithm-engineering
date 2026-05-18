#include "lib.h"

/*
 * simple function for computing the lcp of two strings
 * */
int compute_lcp(int n, char *a, char *b) {
    int lcp = 0;

    while (lcp < n && a[lcp] == b[lcp]) {
        lcp++;
    }

    return lcp;
}

/*
 * kasai algorithm for constructing the lcp array
 * */
int build_lcp(int N, char *text, int *lcp, int *SA, int *AS) {
    int h = 0;

    for (int i = 0; i < N; i++) {
        int q = AS[i];

        if (q == 0)
            continue;

        int j = SA[q - 1];

        // lower bound on h
        h = MAX(h-1,0);

        h += compute_lcp(MIN(N - i,N - j) - h, text + i + h, text + j + h);

        // debug
        // printf("i: %d j: %d lcp[%d]=%d\n",i,j,q-1,h);

        // set new lcp in array
        lcp[q - 1] = h;

    }

    return 0;
}


/*
 * static precomputed example
 * */
int main() {

    int n = 10;
    /*
     * here we do not store explicitly the strings of 
     * SA(T) and the SA^-1(T). We just store the indexes
     * */
    char text[] = "aabacabbaa";
    int lcp[] = {0,0,0,0,0,0,0,0,0,0};
    int SA[] = {9,8,0,1,5,3,7,2,6,4};
    int AS[] = {2,3,7,5,9,4,8,6,1,0};

    sys_check(build_lcp(n,text,lcp,SA,AS));

    printf("lcp[] = [");
    for (int i = 0; i < n; i++) {
        printf("%d",lcp[i]);
        if (i != n - 1)
            printf(", ");
    }
    printf("]\n");

    return 0;
}
