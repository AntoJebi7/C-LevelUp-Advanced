#include<stdio.h>

int factorial(int n) {
    // Base case to stop recursion
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);  // Recursive case
}

int main() {
    printf("%d\n", factorial(5));  // Correctly print the result
    return 0;
}
