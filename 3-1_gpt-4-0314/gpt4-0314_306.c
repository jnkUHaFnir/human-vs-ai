#include <stdio.h>
#include <string.h>

struct number {
    char digits[11];
};

void remove_zero(struct number *a) {
    char* b = (*a).digits;
    int firstNonZeroIndex = -1;
    
    // Find the index of the first non-zero digit 
    for (int i = 0; i < strlen(b); i++) {
        if (b[i] != '0') {
            firstNonZeroIndex = i;
            break;
        }
    }
    
    // If no non-zero digits found, return
    if (firstNonZeroIndex == -1) {
        return;
    }
    
    // Shift the remaining numbers to the left
    for (int i = 0; i < strlen(b) - firstNonZeroIndex; i++) {
        (*a).digits[i] = b[firstNonZeroIndex + i];
    }
    
    // Null-terminate the string
    (*a).digits[strlen(b) - firstNonZeroIndex] = '\0';
}

int main() {
    struct number a;
    strcpy(a.digits, "000013204");
    
    printf("Before removing zero: %s\n", a.digits);
    remove_zero(&a);
    printf("After removing zero: %s\n", a.digits);
    
    return 0;
}
Before removing zero: 000013204
After removing zero: 13204
