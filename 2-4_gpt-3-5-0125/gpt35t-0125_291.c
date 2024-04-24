#include <stdio.h>

int main() {
    char name[128];
    
    int match = scanf(" %[^0-9a-zA-Z\n]", name); 
    printf("%d", match);    
    
    if (match == 1) {
        printf("Matched");
    } else {
        printf("Invalid");
    }
    
    return 0;
}
