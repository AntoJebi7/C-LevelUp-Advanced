/*
strlen - To find the length of a string.
strcpy - To copy one string to another.
strncpy - To copy n characters of a string.
strcat - To concatenate two strings.
strncat - To concatenate n characters of a string.
strcmp - To compare two strings.
strncmp - To compare n characters of two strings.
strchr - To find the first occurrence of a character in a string.
strrchr - To find the last occurrence of a character in a string.
strstr - To find the first occurrence of a substring.
strtok - To split a string into tokens.
sprintf - To format and store a string.
strrev (not in the standard library but implemented for demonstration) - To reverse a string.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Custom function to reverse a string (since `strrev` is not standard)
void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    char str1[50] = "Hello";
    char str2[50] = "World";
    char str3[50];
    char str4[50] = "Hello, World!";

    // strlen
    printf("Length of str1: %zu\n", strlen(str1));

    // strcpy
    strcpy(str3, str1);
    printf("After strcpy, str3: %s\n", str3);

    // strncpy
    strncpy(str3, str2, 3);
    str3[3] = '\0'; // Ensure null termination
    printf("After strncpy, str3: %s\n", str3);

    // strcat
    strcat(str1, " ");
    strcat(str1, str2);
    printf("After strcat, str1: %s\n", str1);

    // strncat
    strncat(str1, "!!!", 2);
    printf("After strncat, str1: %s\n", str1);

    // strcmp
    int cmp = strcmp("abc", "abd");
    printf("Comparison of 'abc' and 'abd': %d\n", cmp);

    // strncmp
    cmp = strncmp("abcde", "abcdx", 4);
    printf("Comparison of first 4 characters of 'abcde' and 'abcdx': %d\n", cmp);

    // strchr
    char *pos = strchr(str4, 'o');
    printf("First occurrence of 'o' in str4: %s\n", pos);

    // strrchr
    pos = strrchr(str4, 'o');
    printf("Last occurrence of 'o' in str4: %s\n", pos);

    // strstr
    pos = strstr(str4, "World");
    printf("First occurrence of 'World' in str4: %s\n", pos);

    // strtok
    char str5[50] = "C,Python,Java,JavaScript";
    printf("Tokens in str5:\n");
    char *token = strtok(str5, ",");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ",");
    }

    // sprintf
    char formattedStr[100];
    int year = 2025;
    sprintf(formattedStr, "Welcome to %d!", year);
    printf("Formatted string: %s\n", formattedStr);

    // Custom strrev (reverse string)
    char str6[50] = "ReverseMe";
    reverseString(str6);
    printf("Reversed str6: %s\n", str6);

    return 0;
}
