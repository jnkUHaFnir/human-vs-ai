#include <stdio.h>

#define MAX_BUF_SIZE 1024 // Maximum buffer size

int main() {
    char buf[MAX_BUF_SIZE];
    
    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        // Process the input stored in 'buf'
        
        // You might want to remove the newline character if it's present
        size_t len = strlen(buf);
        if (len > 0 && buf[len - 1] == '\n') {
            buf[len - 1] = '\0';
        }

        // Proceed with processing the input
        printf("Input: %s\n", buf);
    }

    return 0;
}
