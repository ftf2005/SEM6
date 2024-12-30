#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char str[20];
    int state, i = 0;
    
    // Get the input string
    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove trailing newline

    // Initial state based on the first character
    if (isalpha(str[0])) state = 1;   // Variable
    else if (isdigit(str[0])) state = 2;  // Integer constant
    else state = 10;  // Error

    // Process the string character by character
    while (str[i] != '\0' && state != 10) {
        switch (state) {
            case 1: // Variable
                if (isalnum(str[i]) || str[i] == '(' || str[i] == '[') state = 1;
                else if (str[i] == ')') state = 6;  // Function
                else if (str[i] == ']') state = 7;  // Array
                else state = 10;  // Error
                break;
            case 2: // Integer constant
                if (isdigit(str[i])) state = 2;
                else if (str[i] == '.' && isdigit(str[i+1])) state = 4; // Real constant
                else state = 10;
                break;
            case 4: // Real constant
                if (isdigit(str[i])) state = 4;
                else state = 10;
                break;
            case 6: // Function
                if (str[i] != ')') state = 10;
                break;
            case 7: // Array
                if (str[i] != ']') state = 10;
                break;
        }
        i++;
    }

    // Output based on the final state
    if (state == 1) printf("Input is a variable.\n");
    else if (state == 2) printf("Input is an integer constant.\n");
    else if (state == 4) printf("Input is a real constant.\n");
    else if (state == 6) printf("Input is a function.\n");
    else if (state == 7) printf("Input is an array.\n");
    else printf("There is an error in the given expression.\n");

    return 0;
}
