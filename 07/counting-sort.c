#include "lib.h"

void counting_sort(int * src, int * dst, int n, int k) {
    int * counting = (int*)(malloc(sizeof(int) * k));

    for (int i = 0; i < k; i++) {
        counting[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        counting[src[i]]++;
    }

    int idx = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < counting[i]; j++) {
            dst[idx++] = i;
        }
    }
}

int main() {

    int n = 16;
    int k = 5;
    int src[] = {1,2,3,4,1,2,3,4,1,2,3,4,1,2,3,4};
    int dst[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    counting_sort(src,dst,n,k);

    printf("[");
    for (int i = 0; i < n; i++) {
        if (i == n - 1)
            printf("%d",dst[i]);
        else
            printf("%d,",dst[i]);
    }
    printf("]\n");

    return 0;
}
