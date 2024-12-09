#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;
    int vowels = 0, consonants = 0;
    int prev_ch = 0;

    printf("Enter a paragraph (press Enter twice to end input):\n");

    while (1) {
        ch = getchar();

        if (ch == '\n' && prev_ch == '\n') {
            break;
        }

        prev_ch = ch;

        ch = tolower(ch);

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowels++;
        } else if (ch >= 'a' && ch <= 'z') {
            consonants++;
        }
    }

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);

    return 0;
}
