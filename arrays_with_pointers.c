#include <stdio.h>

int main() {
    // 1D Array with Pointers
    int arr1[] = {1, 2, 3, 4, 5};
    int *ptr1 = arr1;  // Pointer to the first element of the array

    printf("1D Array using Pointers:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr1 + i));  // Access elements using pointer arithmetic
    }
    printf("\n\n");

    // 2D Array with Pointers
    int arr2[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int (*ptr2)[3] = arr2;  // Pointer to an array of 3 integers (rows)

    printf("2D Array using Pointers:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", *(*(ptr2 + i) + j));  // Access elements using pointer arithmetic
        }
        printf("\n");
    }
    printf("\n");

    // 3D Array with Pointers
    int arr3[2][2][2] = {
        {{1, 2}, {3, 4}},
        {{5, 6}, {7, 8}}
    };
    int (*ptr3)[2][2] = arr3;  // Pointer to a 2D array of 2x2 elements

    printf("3D Array using Pointers:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                printf("%d ", *(*(*(ptr3 + i) + j) + k));  // Access elements using pointer arithmetic
            }
            printf("\n");
        }
    }

    return 0;
}
