#include <stdio.h>

int main() {
    char buf[100]; // Define an appropriate buffer size based on your needs

    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        // Process the input stored in buf
    }

    return 0;
}
