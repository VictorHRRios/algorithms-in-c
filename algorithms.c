#include <stdio.h>
void insertion_sort(int*, size_t);
void swap(int*, int*);
void print_array(int*, size_t);

int main() 
{
    int array[] = {7,3,2,1,0};
    int size = sizeof(array) / sizeof(array[0]);
    insertion_sort(array, size);
    print_array(array, size);
    return 0;
}