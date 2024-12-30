#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char prod[20], alpha[20], beta[20];
    int i, j;
    
    // Get user input safely
    printf("Enter the production: ");
    fgets(prod, sizeof(prod), stdin);
    prod[strcspn(prod, "\n")] = 0;  // Remove the trailing newline character from fgets input
    
    // Check if the production has left recursion
    if (prod[0] == prod[3]) {
        printf("\nEntered production is left recursive\n");

        // Extract alpha and beta parts from the production
        i = 4; 
        j = 0;
        while (prod[i] != '/' && prod[i] != '\0') { // Handle '->' part
            alpha[j++] = prod[i++];
        }
        alpha[j] = '\0';

        i++; // Skip over '/'
        j = 0;
        while (prod[i] != '\0') { // Handle right-hand side of the production
            beta[j++] = prod[i++];
        }
        beta[j] = '\0';

        // Output the modified production
        printf("The production after removing left recursion is:\n");
        printf("%c->%s%c'\n", prod[0], beta, prod[0]);
        printf("%c'->%s%c'/$", prod[0], alpha, prod[0]);
    } else {
        printf("\nEntered production is not left recursive\n");
    }
    
    return 0;
}
