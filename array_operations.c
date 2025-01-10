#include <stdio.h>

int main() {
    // 1D Array Operations
    int arr1D[5] = {1, 2, 3, 4, 5};
    int sum1D = 0, diff1D = 0;

    // Sum and difference of 1D array elements
    for (int i = 0; i < 5; i++) {
        sum1D += arr1D[i];
        diff1D -= arr1D[i];  // start with 0, so subtracting elements
    }

    printf("1D Array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr1D[i]);
    }
    printf("\nSum of 1D array elements: %d\n", sum1D);
    printf("Difference (start with 0, subtract each element): %d\n\n", diff1D);

    // 2D Array Operations
    int arr2D[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int arr2D_add[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    int arr2D_sub[3][3];
    int arr2D_mul[3][3];

    // Matrix addition and subtraction
    printf("2D Array (3x3) + 2D Array (3x3):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr2D[i][j] + arr2D_add[i][j]);
        }
        printf("\n");
    }

    // Matrix subtraction
    printf("\n2D Array (3x3) - 2D Array (3x3):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr2D_sub[i][j] = arr2D[i][j] - arr2D_add[i][j];
            printf("%d ", arr2D_sub[i][j]);
        }
        printf("\n");
    }

    // Matrix multiplication
    printf("\nMatrix Multiplication (2D Array * 2D Array):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr2D_mul[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                arr2D_mul[i][j] += arr2D[i][k] * arr2D_add[k][j];
            }
            printf("%d ", arr2D_mul[i][j]);
        }
        printf("\n");
    }

    // 3D Array Operations
    int arr3D[2][2][2] = {
        {{1, 2}, {3, 4}},
        {{5, 6}, {7, 8}}
    };
    int arr3D_add[2][2][2] = {
        {{8, 7}, {6, 5}},
        {{4, 3}, {2, 1}}
    };
    int arr3D_sum[2][2][2];

    // 3D Array addition
    printf("\n3D Array Addition (2x2x2):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                arr3D_sum[i][j][k] = arr3D[i][j][k] + arr3D_add[i][j][k];
                printf("%d ", arr3D_sum[i][j][k]);
            }
            printf("\n");
        }
    }

    return 0;
}
