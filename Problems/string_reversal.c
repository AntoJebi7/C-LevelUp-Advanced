#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        // Swap using arithmetic (addition and subtraction)
        str[left] = str[left] + str[right];
        str[right] = str[left] - str[right];
        str[left] = str[left] - str[right];

        // Move pointers towards the center
        left++;
        right--;
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);  // Read a string without spaces

    reverseString(str);
    printf("Reversed string: %s\n", str);

    return 0;
}
