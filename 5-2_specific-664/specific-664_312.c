#include <stdio.h>

struct book {
    char name[20];
};

int main() {
    struct book buk[10];
    int i;
    char c; // To capture the newline character

    for (i = 0; i < 3; i++) {
        printf("Enter name of book %d: ", i + 1);
        scanf(" %[^\n]%c", buk[i].name, &c); // Added %c to capture the newline character
    }

    return 0;
}
