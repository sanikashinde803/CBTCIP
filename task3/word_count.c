#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

// Function to count words, lines, and characters
void count_words_lines_chars(FILE *fp, int *words, int *lines, int *chars) {
    char line[MAX_LINE_LENGTH];
    *words = 0;
    *lines = 0;
    *chars = 0;

    while (fgets(line, sizeof(line), fp)) {
        (*lines)++;

        int in_word = 0; // 0 means currently not in a word
        for (int i = 0; line[i] != '\0'; i++) {
            (*chars)++;

            // Check for words
            if (isalnum(line[i])) {
                if (!in_word) {
                    (*words)++;
                    in_word = 1;
                }
            } else {
                in_word = 0;
            }
        }
    }
}

int main() {
    char filename[100];
    FILE *fp;
    int words, lines, chars;

    // Get filename from user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Count words, lines, and characters
    count_words_lines_chars(fp, &words, &lines, &chars);

    // Close the file
    fclose(fp);

    // Print the results
    printf("\nStatistics for file: %s\n", filename);
    printf("Number of words: %d\n", words);
    printf("Number of lines: %d\n", lines);
    printf("Number of characters: %d\n", chars);

    return EXIT_SUCCESS;
}
