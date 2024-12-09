#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;
    int line_count = 0, space_count = 0, char_count = 0, word_count = 0;
    int in_word = 0;

    printf("Enter text (press Enter twice to stop):\n");

    while (1) {
        ch = getchar();

        if (ch == '\n') {
            line_count++;
            if (line_count > 1) break;
        }

        char_count++;

        if (ch == ' ') {
            space_count++;
        }

        if (isalpha(ch) && !in_word) {
            word_count++;
            in_word = 1;
        } else if (!isalpha(ch)) {
            in_word = 0;
        }
    }

    printf("\nLines: %d\n", line_count);
    printf("Spaces: %d\n", space_count);
    printf("Characters: %d\n", char_count);
    printf("Words: %d\n", word_count);

    return 0;
}
