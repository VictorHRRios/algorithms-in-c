#include <stdio.h>
#include "utils.h"
#include "sorts.h"
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

