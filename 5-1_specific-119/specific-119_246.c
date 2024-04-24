#include <stdio.h>
#include <string.h>

int main() {
    int intArray[1000];
    long long longLongArray[500];
    char charArray[4000];
    
    // Assign zeros using int
    memset(intArray, 0, sizeof(intArray));
    
    // Assign zeros using long long
    memset(longLongArray, 0, sizeof(longLongArray));
    
    // Assign zeros using char
    memset(charArray, 0, sizeof(charArray));

    return 0;
}
