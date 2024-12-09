#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int len;

    printf("Enter a string: ");
    scanf("%s", input);

    len = strlen(input);

    if (len >= 2 && input[0] == 'a' && input[len - 1] == 'b') {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}
