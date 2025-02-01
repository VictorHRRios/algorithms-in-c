#include <stdio.h>
#include <stdlib.h>
void insertion_sort(int*, size_t);
void swap(int*, int*);
void print_array(int*, size_t);
int* create_array(int size);

int main() 
{
    int size;
    int* array;

    printf("Array size (if size is more than 10 it will randomly fill the array): ");
    scanf("%d", &size);
    array = create_array(size);
    printf("Crated array: ");
    print_array(array, size);
    //merge_sort(array, 0, size);
    insertion_sort(array, size);

    printf("Ordered array: ");
    print_array(array, size);
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
        int q = ceil((p+r)/2);
        merge_sort(array, p, q);
        merge_sort(array, q+1, r);
        //merge(array, p, q, r);
        printf("%d, %d", p, q)
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