#include <stdio.h>
#include <stdlib.h>

int main() {
    // 1. Dynamic Memory Allocation for 1D Array
    int *arr1;
    int size1 = 5;
    arr1 = (int *)malloc(size1 * sizeof(int));  // Allocating memory for 1D array

    if (arr1 == NULL) {
        printf("Memory allocation failed for 1D array\n");
        return 1;
    }

    // Initializing 1D array and displaying values
    for (int i = 0; i < size1; i++) {
        arr1[i] = i + 1;
    }
    printf("1D Array (Dynamically Allocated):\n");
    for (int i = 0; i < size1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    // 2. Dynamic Memory Allocation for 2D Array
    int **arr2;
    int rows2 = 3, cols2 = 4;
    arr2 = (int **)malloc(rows2 * sizeof(int *));  // Allocating memory for rows

    if (arr2 == NULL) {
        printf("Memory allocation failed for 2D array (rows)\n");
        free(arr1);
        return 1;
    }

    for (int i = 0; i < rows2; i++) {
        arr2[i] = (int *)malloc(cols2 * sizeof(int));  // Allocating memory for columns (for each row)
        if (arr2[i] == NULL) {
            printf("Memory allocation failed for 2D array (columns)\n");
            free(arr1);
            for (int j = 0; j < i; j++) {
                free(arr2[j]);
            }
            free(arr2);
            return 1;
        }
    }

    // Initializing and displaying 2D array
    printf("\n2D Array (Dynamically Allocated):\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            arr2[i][j] = (i + 1) * (j + 1);
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }

    // 3. Dynamic Memory Allocation for 3D Array
    int ***arr3;
    int slices3 = 2, rows3 = 3, cols3 = 2;
    arr3 = (int ***)malloc(slices3 * sizeof(int **));  // Allocating memory for slices

    if (arr3 == NULL) {
        printf("Memory allocation failed for 3D array (slices)\n");
        free(arr1);
        for (int i = 0; i < rows2; i++) {
            free(arr2[i]);
        }
        free(arr2);
        return 1;
    }

    for (int i = 0; i < slices3; i++) {
        arr3[i] = (int **)malloc(rows3 * sizeof(int *));  // Allocating memory for rows in each slice
        if (arr3[i] == NULL) {
            printf("Memory allocation failed for 3D array (rows)\n");
            free(arr1);
            for (int i = 0; i < rows2; i++) {
                free(arr2[i]);
            }
            free(arr2);
            for (int j = 0; j < i; j++) {
                free(arr3[j]);
            }
            free(arr3);
            return 1;
        }

        for (int j = 0; j < rows3; j++) {
            arr3[i][j] = (int *)malloc(cols3 * sizeof(int));  // Allocating memory for columns in each row
            if (arr3[i][j] == NULL) {
                printf("Memory allocation failed for 3D array (columns)\n");
                free(arr1);
                for (int i = 0; i < rows2; i++) {
                    free(arr2[i]);
                }
                free(arr2);
                for (int k = 0; k < i; k++) {
                    free(arr3[k]);
                }
                free(arr3);
                return 1;
            }
        }
    }

    // Initializing and displaying 3D array
    printf("\n3D Array (Dynamically Allocated):\n");
    for (int i = 0; i < slices3; i++) {
        for (int j = 0; j < rows3; j++) {
            for (int k = 0; k < cols3; k++) {
                arr3[i][j][k] = (i + 1) * (j + 1) * (k + 1);
                printf("arr3[%d][%d][%d] = %d\n", i, j, k, arr3[i][j][k]);
            }
        }
    }

    // 4. Using realloc() to resize the 1D array
    printf("\nResizing 1D Array using realloc():\n");
    size1 = 7;
    arr1 = (int *)realloc(arr1, size1 * sizeof(int));  // Resizing the 1D array

    if (arr1 == NULL) {
        printf("Memory reallocation failed for 1D array\n");
        free(arr2);
        for (int i = 0; i < rows2; i++) {
            free(arr2[i]);
        }
        free(arr2);
        for (int i = 0; i < slices3; i++) {
            for (int j = 0; j < rows3; j++) {
                free(arr3[i][j]);
            }
            free(arr3[i]);
        }
        free(arr3);
        return 1;
    }

    // Initializing and displaying resized 1D array
    for (int i = 5; i < size1; i++) {
        arr1[i] = i + 1;
    }
    printf("Resized 1D Array:\n");
    for (int i = 0; i < size1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    // 5. Freeing dynamically allocated memory
    free(arr1);
    for (int i = 0; i < rows2; i++) {
        free(arr2[i]);
    }
    free(arr2);
    for (int i = 0; i < slices3; i++) {
        for (int j = 0; j < rows3; j++) {
            free(arr3[i][j]);
        }
        free(arr3[i]);
    }
    free(arr3);

    return 0;
}
