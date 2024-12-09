#include <stdio.h>
int main() {
    char input[100];
    int vowels = 0, consonants = 0;
    int i = 0;
    printf("Enter a string: ");
    scanf("%s", input);  
    while (input[i] != '\0') {
        char ch = input[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
        i++; 
    }
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    return 0;
}
