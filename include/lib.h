#ifndef _LIB_H
#define _LIB_H

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdatomic.h>

#define sys_check(cond)                                                     \
do {                                                                        \
    if ((cond) != 0) {                                                      \
        perror(#cond);                                                      \
        exit(1);                                                            \
    }                                                                       \
} while (0)

typedef struct {
    double *x;
    double *y;
    double *z;
    double acc;
    size_t n;
} thread_doubles_t;

#define MS(ts)                                                              \
    ((ts).tv_sec * 1000.0 + (ts).tv_nsec / 1000000.0)

#define RAND_INT(A,B)                                                       \
    rand() % ( A - B ) + A                                                  \

#define RAND_DOUBLE(A)                                                      \
    random() / RAND_MAX

#define GET_RAND(_1, _2, NAME, ...) NAME

#define RAND(...)                                                           \
    GET_RAND(__VA_ARGS__, RAND_INT, RAND_DOUBLE) (__VA_ARGS__)

#define MAX(a,b) ((a > b) ? a : b)

#define MIN(a,b) ((a < b) ? a : b)


#endif
