#include <stdio.h>
#include <ctype.h>
#include <string.h>

void main() {
    char str[20];
    int state, i = 1;
    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    if (isalpha(str[0])) {
        state = 1;
    } else if (isdigit(str[0])) {
        state = 2;
    } else {
        state = 10;
    }

    while (str[i] != '\0') {
        switch (state) {
            case 1:
                if (isalpha(str[i]) || isdigit(str[i])) {
                    state = 1;
                } else if (str[i] == '(') {
                    state = 3;
                } else if (str[i] == '[') {
                    state = 5;
                } else {
                    state = 10;
                }
                break;
            case 2:
                if (isdigit(str[i])) {
                    state = 2;
                } else if (str[i] == '.' && isdigit(str[i + 1])) {
                    state = 4;
                } else {
                    state = 10;
                }
                break;
            case 3:
                if (str[i] == ')' && str[i + 1] == '\0') {
                    state = 6;
                } else {
                    state = 10;
                }
                break;
            case 4:
                if (isdigit(str[i])) {
                    state = 4;
                } else {
                    state = 10;
                }
                break;
            case 5:
                if (isdigit(str[i])) {
                    state = 5;
                } else if (str[i] == ']' && str[i + 1] == '\0') {
                    state = 7;
                } else {
                    state = 10;
                }
                break;
            default:
                state = 10;
                break;
        }
        i++;
        if (state == 10) {
            break;
        }
    }

    printf("%s", str);
    if (state == 1) {
        printf(" Input is a variable.\n");
    } else if (state == 2) {
        printf(" Input is an integer constant.\n");
    } else if (state == 4) {
        printf(" Input is a real constant.\n");
    } else if (state == 6) {
        printf(" Input is a function.\n");
    } else if (state == 7) {
        printf(" Input is an array.\n");
    } else {
        printf(" There is an error in the given expression.\n");
    }
}
