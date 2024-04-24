#include <stdio.h>

void deldigit(char* str) {
    char* result = str;
    int count = 0;
    
    while (*str != '\0') {
        if (*str >= '0' && *str <= '9') {
            count++;
        } else {
            *(result) = *str;
            result++;
        }
        str++;
    }
    
    *result = '\0';
    printf("%s", str);
}

int main() {
    char str[100];
    
    printf("insert word: ");
    scanf("%s", str);
    deldigit(str);
    
    return 0;
}
