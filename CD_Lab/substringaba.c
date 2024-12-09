#include <stdio.h>

int main() {
    char input[100];
    int i = 0;

    printf("Enter a string: ");
    
    while (scanf("%c", &input[i]) && input[i] != '\n' && i < 99) {
        i++;
    }

    for (int j = 0; j < i-2; j++) {
        if (input[j] == 'a' && input[j+1] == 'b' && input[j+2] == 'a') {
            printf("The substring 'aba' is present in the input.\n");
            return 0;
        }
    }

    printf("The substring 'aba' is not present in the input.\n");
    return 0;
}
