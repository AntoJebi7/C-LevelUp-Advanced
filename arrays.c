#include <stdio.h>

int main() {
    // 1D Array Implementation
    int arr1D[5] = {1, 2, 3, 4, 5};
    printf("1D Array:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr1D[i]);
    }
    printf("\n\n");

    // 2D Array Implementation
    int arr2D[3][3] = {
        // c1 c2 c3  columns
        {1, 2, 3}, //row 1
        {4, 5, 6}, //row 2
        {7, 8, 9}  //row 3
    };
    printf("2D Array (3x3):\n");
    for (int i = 0; i < 3; i++) { //row
        for (int j = 0; j < 3; j++) {  // column
            printf("%d ", arr2D[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // 3D Array Implementation
    int arr3D[2][2][2] = {
        {
            {1, 2},
            {3, 4}
        },
        {
                {5, 6},
                {7, 8}
        }
    };
    printf("3D Array (2x2x2):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                printf("%d ", arr3D[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
