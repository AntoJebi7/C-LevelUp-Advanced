#include <stdio.h>     // Standard I/O functions
#include <stdarg.h>     // For variable arguments
#include <errno.h>      // For error handling
#include <string.h>     // For strerror()

// Define a macro for error handling
#define MAX_BUFFER_SIZE 1024

// Function to calculate the sum of any number of integers using variable arguments
int sum(int num, ...) {
    va_list args; //... list argument variable
    va_start(args, num); // ... and 14 args to be started
    int result = 0;

    // Loop through the variable arguments
    for (int i = 0; i < num; i++) {
        result += va_arg(args, int);  // to get one arg from args (...) and its type int
    }

    va_end(args);  // to end the operation
    return result;
}

// Function to demonstrate error handling using errno
void demonstrateErrorHandling() {
    FILE *file = fopen("nonexistentfile.txt", "r");  // Try to open a non-existent file
    if (!file) {
        perror("Error opening file");  // Print error message
        printf("Error code: %d\n", errno);  // Print error code (errno)
        printf("Error description: %s\n", strerror(errno));  // Print error description using strerror()
    }
}

// Main function demonstrating conditionals and other features
int main() {
    // Conditional Compilation (using #ifdef and #ifndef)
#ifdef MAX_BUFFER_SIZE
    printf("MAX_BUFFER_SIZE is defined as %d\n", MAX_BUFFER_SIZE);
#endif

#ifndef MIN_BUFFER_SIZE
    printf("MIN_BUFFER_SIZE is not defined.\n");
#endif

    // Demonstrating variable arguments
    int result = sum(14, 10, 20, 30,454,565,6,76,7,68,78,7,8,7,78);
    printf("The sum of 10, 20, and 30 is: %d\n", result);

    // Demonstrate error handling
    demonstrateErrorHandling();

    // Macros: Showing the MAX_BUFFER_SIZE in action
    char buffer[MAX_BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "This buffer can hold up to %d characters.\n", MAX_BUFFER_SIZE);
    printf("%s", buffer);

    return 0;
}
