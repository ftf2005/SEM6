#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    char prod[20], alpha[20], beta[20];
    int i, j;
    
    printf("Enter the production: ");
    fgets(prod, sizeof(prod), stdin);
    prod[strcspn(prod, "\n")] = 0;  
    if (prod[0] == prod[3]) {
        printf("\nEntered production is left recursive\n");

        i = 4; 
        j = 0;
        while (prod[i] != '/' && prod[i] != '\0') { 
            alpha[j++] = prod[i++];
        }
        alpha[j] = '\0';

        i++; 
        j = 0;
        while (prod[i] != '\0') { 
            beta[j++] = prod[i++];
        }
        beta[j] = '\0';

        printf("The production after removing left recursion is:\n");
        printf("%c->%s%c'\n", prod[0], beta, prod[0]);
        printf("%c'->%s%c'/$", prod[0], alpha, prod[0]);
    } else {
        printf("\nEntered production is not left recursive\n");
    }
    return 0;
}
