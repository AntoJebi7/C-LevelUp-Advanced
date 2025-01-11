#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char data[100];

    // 1. Writing to a file
    file = fopen("example.txt", "w");  // Open file for writing
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return 1;  // Exit the program if the file can't be opened
    }

    fprintf(file, "This is a file handling demo in C.\n");  //Writes formatted text to the file
    fputs("We are writing more data to the file.\n", file);  //Writes a string directly to the file.
    fclose(file);  // Close the file after writing

    // 2. Reading from a file
    file = fopen("example.txt", "r");  // Open file for reading
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return 1;  // Exit if the file can't be opened
    }

    // Read a single character using fgetc
    char ch = fgetc(file);
    printf("First character: %c\n", ch);

    // Read a line using fgets
    fgets(data, sizeof(data), file);
    printf("First line: %s\n", data);

    // 3. File error handling
    if (ferror(file)) {
        printf("Error reading file.\n");
    }

    // 4. File positioning with ftell and fseek
    long position = ftell(file);
    printf("Current position in file: %ld\n", position);

    fseek(file, 0, SEEK_SET);  // Move file pointer back to the beginning
    fgets(data, sizeof(data), file);
    printf("After fseek, first line again: %s\n", data);

    fclose(file);  // Close the file after reading

    // 5. Checking end of file (EOF)
    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    while (fgets(data, sizeof(data), file)) {
        printf("Reading line: %s", data);  // Read line by line
    }

    if (feof(file)) {
        printf("End of file reached.\n");
    }

    fclose(file);  // Always close the file after operations

    return 0;
}
