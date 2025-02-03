#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindromeString(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;  // If characters don't match, it's not a palindrome
        }
        left++;
        right--;
    }
    return true;  // If loop completes, the string is a palindrome
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);  // Read the string without spaces

    if (isPalindromeString(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
