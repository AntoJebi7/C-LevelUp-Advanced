/*
Finding the size of an array.
Searching for an element (linear search).
Sorting an array (using qsort).
Finding the maximum and minimum elements.
Calculating the sum and average of array elements.
Reversing an array.
Copying an array.
Merging two arrays.
Removing duplicates from an array.
 */

#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to find maximum and minimum in an array
void findMaxMin(int arr[], int size, int *max, int *min) {
    *max = arr[0];
    *min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > *max) *max = arr[i];
        if (arr[i] < *min) *min = arr[i];
    }
}

// Function to remove duplicates from a sorted array
int removeDuplicates(int arr[], int size) {
    if (size == 0 || size == 1) return size;

    int j = 0; // Index for the next unique element
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            arr[j++] = arr[i];
        }
    }
    arr[j++] = arr[size - 1];
    return j;
}

int main() {
    int arr1[] = {5, 3, 8, 6, 2, 8, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {7, 2, 9};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    // 1. Size of an array
    printf("Size of arr1: %d\n", size1);

    // 2. Searching for an element (linear search)
    int key = 6, found = 0;
    for (int i = 0; i < size1; i++) {
        if (arr1[i] == key) {
            printf("Element %d found at index %d in arr1\n", key, i);
            found = 1;
            break;
        }
    }
    if (!found) printf("Element %d not found in arr1\n", key);

    // 3. Sorting an array
    qsort(arr1, size1, sizeof(int), compare);
    printf("Sorted arr1: ");
    for (int i = 0; i < size1; i++) printf("%d ", arr1[i]);
    printf("\n");

    // 4. Finding maximum and minimum
    int max, min;
    findMaxMin(arr1, size1, &max, &min);
    printf("Max: %d, Min: %d\n", max, min);

    // 5. Sum and average of array elements
    int sum = 0;
    for (int i = 0; i < size1; i++) sum += arr1[i];
    double avg = (double)sum / size1;
    printf("Sum: %d, Average: %.2f\n", sum, avg);

    // 6. Reversing an array
    printf("Reversed arr1: ");
    for (int i = 0; i < size1 / 2; i++) {
        int temp = arr1[i];
        arr1[i] = arr1[size1 - i - 1];
        arr1[size1 - i - 1] = temp;
    }
    for (int i = 0; i < size1; i++) printf("%d ", arr1[i]);
    printf("\n");

    // 7. Copying an array
    int arrCopy[size1];
    for (int i = 0; i < size1; i++) arrCopy[i] = arr1[i];
    printf("Copied array: ");
    for (int i = 0; i < size1; i++) printf("%d ", arrCopy[i]);
    printf("\n");

    // 8. Merging two arrays
    int mergedSize = size1 + size2;
    int merged[mergedSize];
    for (int i = 0; i < size1; i++) merged[i] = arr1[i];
    for (int i = 0; i < size2; i++) merged[size1 + i] = arr2[i];
    printf("Merged array: ");
    for (int i = 0; i < mergedSize; i++) printf("%d ", merged[i]);
    printf("\n");

    // 9. Removing duplicates (sort first)
    qsort(merged, mergedSize, sizeof(int), compare);
    mergedSize = removeDuplicates(merged, mergedSize);
    printf("Merged array after removing duplicates: ");
    for (int i = 0; i < mergedSize; i++) printf("%d ", merged[i]);
    printf("\n");

    return 0;
}
