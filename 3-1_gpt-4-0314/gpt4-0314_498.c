#include <stdio.h>
#include <stdlib.h>

void deldigit(char* str) {
    int count = 0;

    while(*str != '\0') {
        if(*str >= '0' && *str <= '9') // include the case for '0'
            count++;
        else
            *(str - count) = *str; 
        str++;
    }

    *(str - count) = '\0';
    
}

int main() {
    char str[100];

    printf("insert word: ");
    scanf("%s", str);
    deldigit(str);
    printf("%s", str); // print the output in main()

    return 0;
}
