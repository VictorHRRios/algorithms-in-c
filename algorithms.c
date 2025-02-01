#include <stdio.h>
void insertion_sort(int*, size_t);
void swap(int*, int*);
void print_array(int*, size_t);

int main() 
{
    int array[] = {10,3,2,1,0};
    int size = sizeof(array) / sizeof(array[0]);
    insertion_sort(array, size);
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
    printf("%d]",m[size-1]);
}