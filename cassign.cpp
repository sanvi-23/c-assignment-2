#define STRINGTOOLKIT_H
#define STRINGTOOLKIT_H
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "stringtoolkit.h"

void to_uppercase(char str[]);
void to_lowercase(char str[]);
int count_vowels(const char str[]);
void reverse_string(char str[]);
void sort_strings(char arr[][100], int n);
void reverse_words(char str[]);




void to_uppercase(char str[]) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

void to_lowercase(char str[]) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

int count_vowels(const char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (strchr("aeiou", c)) {
            count++;
        }
    }
    return count;
}

void reverse_string(char str[]) {
    int start = 0;
    int end = strlen(str) - 1;
    while (start < end) {
        char temp = str[start];
        str[start++] = str[end];
        str[end--] = temp;
    }
}

void sort_strings(char arr[][100], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char temp[100];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

void reverse_words(char str[]) {
    char *words[100];
    int count = 0;

    // Tokenize string and store words
    char *token = strtok(str, " ");
    while (token != NULL) {
        words[count++] = token;
        token = strtok(NULL, " ");
    }

    // Rebuild string in reverse order
    str[0] = '\0';
    for (int i = count - 1; i >= 0; i--) {
        strcat(str, words[i]);
        if (i > 0) strcat(str, " ");
    }
}

#include <stdio.h>
#include "stringtoolkit.h"

int main() {
    char text[] = "This is a Sample String";
    char reverseTest[] = "Reverse";
    char wordReverse[] = "One two three four";

    printf("Original: %s\n", text);

    to_uppercase(text);
    printf("Uppercase: %s\n", text);

    to_lowercase(text);
    printf("Lowercase: %s\n", text);

    printf("Vowel Count: %d\n", count_vowels(text));

    reverse_string(reverseTest);
    printf("Reversed String: %s\n", reverseTest);

    char words[4][100] = {"delta", "alpha", "charlie", "bravo"};
    sort_strings(words, 4);
    printf("Sorted Strings:\n");
    for (int i = 0; i < 4; i++) {
        printf("%s\n", words[i]);
    }

    reverse_words(wordReverse);
    printf("Words Reversed: %s\n", wordReverse);

    return 0;
}

