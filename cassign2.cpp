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

