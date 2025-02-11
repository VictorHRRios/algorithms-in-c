#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void swap(int* m, int* n) 
{
    int temp = *m;
    *m = *n;
    *n = temp;
}

void print_array(int* m, size_t size)
{
    printf("[");
    for(int i = 0; i < size-1; i++) {
        printf("%d, ", m[i]);
    }
    printf("%d]\n",m[size-1]);
}

int* create_array(int size, int order) 
{
    int *m = malloc(sizeof(int) * size);
    if (m == NULL) {
        printf("Bad Allocation\n");
        return NULL;
    }
    if (size <= 10) {
        for (int i = 0; i < size; i++) {
            printf("[%d]:", i);
            scanf("%d", &m[i]);
        }
        return m;
    }
    switch (order) {
    case 0:
        for (int i = 0; i < size; i++) {
            m[i] = i;
        }
        break;
    case 1:
        for (int i = 0; i < size; i++) {
            m[i] = size-i - 1;
        }
        break;
    case 2:
        int max = 1000;
        int min = -1000;
        for (int i = 0; i < size; i++) {
            m[i] = rand() % (max - min + 1) + min;
        }
        return m;
    default:
        printf("error\n");
        free(m);
        break;
    }

    return m;
}


int* create_ordered_array(int size) 
{
    int *m = malloc(sizeof(size) * size);

    if (m == NULL) {
        printf("Bad Allocation]\n");
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        printf("[%d]:", i);
        scanf("%d", &m[i]);
    }

    return m;
}