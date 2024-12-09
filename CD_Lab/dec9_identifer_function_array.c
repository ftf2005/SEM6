#include <stdio.h>
#include <ctype.h>

int main() {
    char word[50];
    int i;
    printf("Enter a word: ");
    scanf("%s", word);  

    if (isalpha(word[0]) || word[0] == '_') {
        int array = 0, function = 0;

        for (i = 0; word[i] != '\0'; i++) {
            if (word[i] == '[' || word[i] == ']') {
                array = 1;
                break;
            }
        }

        for (i = 0; word[i] != '\0'; i++) {
            if (word[i] == '(' || word[i] == ')') {
                function = 1;
                break;
            }
        }

        if (array) 
		{
            printf("%s is an array\n", word);
        } 
		else if (function) 
		{
            printf("%s is a function\n", word);
        } 
		else
		{
            printf("%s is an identifier\n", word);
        }
    } 
	else 
	{
        printf("%s is not a valid identifier\n", word);
    }

    return 0;
}
