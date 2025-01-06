#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char prod[20][20], alpha[20][20], beta[20][20];
    int i, j, k, n;

    printf("Enter the number of productions: ");
    scanf("%d", &n);
    getchar();  
    printf("Enter %d productions:\n", n);
    for(k = 0; k < n; k++) {
        fgets(prod[k], sizeof(prod[k]), stdin);
        prod[k][strcspn(prod[k], "\n")] = 0; 
    }
    for(k = 0; k < n; k++) {
  
        if (prod[k][0] == prod[k][3]) {
            printf("\nProduction %d is left recursive:\n", k + 1);

            i = 4;
            j = 0;
            while (prod[k][i] != '/' && prod[k][i] != '\0') { 
                alpha[k][j++] = prod[k][i++];
            }
            alpha[k][j] = '\0';

            i++;  
            j = 0;
            while (prod[k][i] != '\0') { 
                beta[k][j++] = prod[k][i++];
            }
            beta[k][j] = '\0';

            printf("The production after removing left recursion is:\n");
            printf("%c->%s%c'\n", prod[k][0], beta[k], prod[k][0]);
            printf("%c'->%s%c'/$\n", prod[k][0], alpha[k], prod[k][0]);
        } else {
            printf("\nProduction %d is not left recursive.\n", k + 1);
        }
    }

    return 0;
}
