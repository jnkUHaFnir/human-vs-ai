#include <stdio.h>
#define MAX_LENGTH 100

int main() {
    char buf[MAX_LENGTH];
    
    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        // Process the input string
        printf("Input: %s", buf);
    }

    return 0;
}
