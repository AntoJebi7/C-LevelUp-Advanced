#include <stdio.h>

// Structure to demonstrate pointer to structure
struct Point {
    int x;
    int y;
};

int add(int a, int b) {
    return a + b;
}

int main() {
    // 1. Normal Pointer
    int num = 10;
    int *ptr = &num;  // Pointer to an integer
    printf("Normal Pointer: Value of num = %d, Value pointed by ptr = %d\n", num, *ptr);

    // 2. Pointer to Pointer
    int **ptr2 = &ptr;  // Pointer to pointer to an integer
    printf("Pointer to Pointer: Value of num = %d, Value pointed by ptr = %d, Value pointed by ptr2 = %d\n", num, *ptr, **ptr2);

    // 3. Array of Pointers
    int *arr[3];  // Array of 3 integer pointers
    arr[0] = &num;
    arr[1] = &num;
    arr[2] = &num;
    printf("Array of Pointers: Value at arr[0] = %d, Value at arr[1] = %d, Value at arr[2] = %d\n", *arr[0], *arr[1], *arr[2]);

    // 4. Pointer to Array
    int arr2[3] = {1, 2, 3};
    int (*ptr3)[3] = &arr2;  // Pointer to an array of 3 integers
    printf("Pointer to Array: arr2[0] = %d, arr2[1] = %d, arr2[2] = %d\n", (*ptr3)[0], (*ptr3)[1], (*ptr3)[2]);

    // 5. Function Pointer
    int (*func_ptr)(int, int) = &add;  // Pointer to function
    printf("Function Pointer: Result of add(5, 3) = %d\n", func_ptr(5, 3));

    // 6. Void Pointer
    void *ptr4 = &num;  // Void pointer can point to any data type
    printf("Void Pointer: Value of num = %d\n", *((int *)ptr4));  // Casting void pointer to int pointer

    // 7. Pointer to Structure
    struct Point p1 = {10, 20};
    struct Point *ptr5 = &p1;  // Pointer to structure
    printf("Pointer to Structure: p1.x = %d, p1.y = %d\n", ptr5->x, ptr5->y);

    // 8. Pointer to Constant
    const int *ptr6 = &num;  // Pointer to a constant integer
    // *ptr6 = 20;  // Uncommenting this line will cause a compilation error because *ptr6 is constant
    printf("Pointer to Constant: Value pointed by ptr6 = %d\n", *ptr6);

    return 0;
}
