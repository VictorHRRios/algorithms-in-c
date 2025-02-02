#include "sorts.h"
#include "utils.h"
void insertion_sort(int* array, size_t size) 
{
    int key, j;
    for(int i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            swap(&array[j+1], &array[j]);
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void merge_sort(int* array, size_t p, size_t r)
{
    if (p < r) {
        int q = p+(r-p)/2;
        merge_sort(array, p, q);
        merge_sort(array, q+1, r);
        merge(array, p, q, r);
    }
}

void merge(int* array, size_t p, size_t q, size_t r)
{
    int c_size = q-p+1;
    int v_size = r-q;
    int c[c_size];
    int v[v_size];

    for (int i = 0; i < c_size; i++) {
        c[i] = array[i+p];
    }
    for (int i = 0; i < v_size; i++) {
        v[i] = array[i+q+1];
    }

    int c_index = 0;
    int v_index = 0;
    int k = p;

    while (c_index < c_size && v_index < v_size) {
            if (c[c_index] < v[v_index]) {
                array[k] = c[c_index];
                c_index++;
            } else {
                array[k] = v[v_index];
                v_index++;
            }
            k++; 
    }
    while (c_index < c_size) {
        array[k] = c[c_index];
        c_index++;
        k++;
    }
    while (v_index < v_size) {
        array[k] = v[v_index];
        v_index++;
        k++;
    }
}