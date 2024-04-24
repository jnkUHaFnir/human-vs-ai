#include <stdio.h>

struct book {
    char name[20];
};

int main() {
    struct book buk[10];
    int i;
    for (i = 0; i < 3; i++) {
        printf("Enter name of book %d: ", i + 1);
        // Use fgets to read the entire line, including whitespaces
        fgets(buk[i].name, sizeof(buk[i].name), stdin);
    }

    for (i = 0; i < 3; i++) {
        printf("Book %d: %s", i + 1, buk[i].name);
    }

    return 0;
}
