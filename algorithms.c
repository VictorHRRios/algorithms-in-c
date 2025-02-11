#include <stdio.h>
#include "utils.h"
#include "sorts.h"
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
int binary_search(int*, size_t, size_t, int);

float time_diff(struct timeval *start, struct timeval *end){
  return (end->tv_sec - start->tv_sec) + 1e-6*(end->tv_usec - start->tv_usec);
}

int main() 
{
    srand ( time(NULL) );
    double t1, t2;
    int size;
    int* array;
    struct timeval start;
    struct timeval end;
    float average_time;
    FILE *times;
    //printf("Array size (if size is more than 10 it will randomly fill the array): ");
    //scanf("%d", &size);
    int avg_time_counter = 5;
    times = fopen("tiempos.txt", "w");
    fprintf(times, "insertion\n");
    for (int size = 10000; size <= 100000; size+= 10000){
        int array2[size];
        array = create_array(size, 0);
        average_time = 0;

        for (int i = 0; i < avg_time_counter; i++) {
            memcpy(array2, array, sizeof(size) * size);
            gettimeofday(&start, NULL);
            insertion_sort(array2, size);
            gettimeofday(&end, NULL);
            average_time += time_diff(&start, &end);
        }
        average_time = average_time / avg_time_counter;
        fprintf(times, "%d, %f\n", size, average_time);
    } //hacer esto adentro
    fprintf(times, "selection\n");
    for (int size = 10000; size <= 100000; size+= 10000){
        int array2[size];
        array = create_array(size, 0);
        average_time = 0;
        for (int i = 0; i < avg_time_counter; i++) {
            memcpy(array2, array, sizeof(size) * size);
            gettimeofday(&start, NULL);
            selection_sort(array2, size);
            gettimeofday(&end, NULL); 
            average_time += time_diff(&start, &end);
        }
        average_time = average_time / avg_time_counter;
        fprintf(times, "%d, %f\n", size, average_time);
    }
    fprintf(times, "merge\n");
    for (int size = 10000; size <= 100000; size+= 10000){
        int array2[size];
        array = create_array(size, 0);
        average_time = 0;
        for (int i = 0; i < avg_time_counter; i++) {
            memcpy(array2, array, sizeof(size) * size);
            gettimeofday(&start, NULL);
            merge_sort(array2, 0, size-1);
            gettimeofday(&end, NULL); 
            average_time += time_diff(&start, &end);
        }
        average_time = average_time / avg_time_counter;
        fprintf(times, "%d, %f\n", size, average_time);
    }

   fclose(times);
    return 0;
}

int binary_search(int* array, size_t p, size_t r, int target)
{
    if (p < r) {
        int q = (p+(r-1))/2;
        if (array[q] == target) {
            return q;
        } else if (target < array[q]) {
            return binary_search(array, p, q, target);
        } else {
            return binary_search(array, q+1, r, target);
        }
    } else {
        return -1;
    }
}
/*
void calculate_time(int initial_size, int max_size, int iteration_size, FILE* times) {
    int avg_time_counter = 5;
    struct timeval start;
    struct timeval end;
    for (int size = initial_size; size <= max_size; size+= iteration_size){
        int copy_array[size];
        int array = create_array(size, 0);
        float average_time = 0;

        for (int i = 0; i < avg_time_counter; i++) {
            memcpy(copy_array, array, sizeof(size) * size);
            gettimeofday(&start, NULL);
            insertion_sort(copy_array, size);
            gettimeofday(&end, NULL);
            average_time += time_diff(&start, &end);
        }
        average_time = average_time / avg_time_counter;
        fprintf(times, "%d, %f\n", size, average_time);
    } //hacer esto adentro
}

*/