#include <stdio.h>
#include <string.h>

struct number { char digits[11]; };

void remove_zero(struct number *a) {
    char *b = (*a).digits;
    while (*b) {
        if (*b != '0') {
            // Replace (*a).digits with the rest of b
            memmove((*a).digits, b, strlen(b) + 1); // move the rest of the string to the beginning
            break;
        }
        b++;
    }
}

int main() {
    struct number num = {"000013204"};
    remove_zero(&num);
    printf("%s\n", num.digits); // Output should be "13204"
    return 0;
}
