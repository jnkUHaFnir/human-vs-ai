#include <stdio.h>

struct book {
    char name[20];
};

int main() {
    struct book buk[10];
    int i;
    char c;

    for (i = 0; i < 3; i++) {
        printf("Enter name of book %d: ", i + 1);
        scanf(" %[^\n]s", buk[i].name); // Note the space before %[^\n]s to consume the newline
        while ((c = getchar()) != '\n' && c != EOF); // Consume any extra characters including newline
    }

    return 0;
}
