#include <stdio.h>
#include <stdlib.h>
#include<math.h>
void insertion_sort(int*, size_t);
void swap(int*, int*);
void print_array(int*, size_t);
int* create_array(int size);
void merge_sort(int*, size_t, size_t);
void merge(int*, size_t, size_t, size_t);
int binary_search(int*, size_t, size_t, int);

int main() 
{
    int size;
    int* array;

    printf("Array size (if size is more than 10 it will randomly fill the array): ");
    scanf("%d", &size);
    array = create_array(size);
    printf("Crated array: ");
    print_array(array, size);
    merge_sort(array, 0, size-1);
    //insertion_sort(array, size);

    printf("Ordered array: ");
    print_array(array, size);
    int search_query;
    printf("Search for an element: ");
    scanf("%d", &search_query);
    int search_index = binary_search(array, 0, size, search_query);

    if (search_index != -1) {
        printf("FOUND [%d] IN %d\n", search_query, search_index);
    } else {
        printf("NOT FOUND\n");
    }
    return 0;
}

/*
function insertionSort(array):
    for i from 1 to length(array):
        key = array[i]  // Store current element
        j = i - 1  // Index of the element to compare with
        while j >= 0 and array[j] > key:
            array[j + 1] = array[j]  // Shift elements to the right
            j = j - 1
        array[j + 1] = key  // Insert key at the correct position
*/

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

int* create_array(int size) 
{
    int *m = malloc(sizeof(size) * size);

    if (m == NULL) {
        printf("Bad Allocation]\n");
        return NULL;
    }

    if (size > 10) {
        int max = 1000;
        int min = -1000;
        for (int i = 0; i < size; i++) {
            m[i] = rand() % (max - min + 1) + min;
        }
        return m;
    }

    for (int i = 0; i < size; i++) {
        printf("[%d]:", i);
        scanf("%d", &m[i]);
    }

    return m;
}