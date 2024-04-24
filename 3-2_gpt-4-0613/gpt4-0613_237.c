#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void insert(char **str, char input, int pos) {
    int length = strlen(*str);
    
    char* tmp = malloc(length + 2); // Extra space for new character and null terminator
    strncpy(tmp, *str, pos);
    tmp[pos] = input;
    strcpy(tmp + pos + 1, *str + pos);
  
    free(*str);
    *str = tmp;
}

int main(void) {
    int n;
    char input;
    char *str;

    printf("How many characters do you want to input: ");
    scanf("%d", &n);
    str = malloc(n + 1);
    printf("Input the string: ");
    scanf("%s", str);
    str[n] = '\0'; // Always remember to null-terminate your string

    printf("What is the character you want to insert: ");
    scanf(" %c", &input);

    insert(&str, input, 0); // Insert the character at the first position

    printf("%s\n", str);

    free(str);
    return 0;
}
