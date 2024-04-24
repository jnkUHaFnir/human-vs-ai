#include <stdio.h>

struct book {
    char name[20];
};

int main() {
    struct book buk[10];
    int i;
    for(i = 0; i < 3; i++) {
        printf("Enter name of book %d: ", i + 1);
        // Consume any leftover newline character in the input buffer.
        scanf(" %[^\n]", buk[i].name);
        // The space before %[^\n] tells scanf to skip any whitespace characters, including newline, before attempting to read the input.
    }
    // Optionally add code to display the entered book names.
    for(i = 0; i < 3; i++) {
        printf("%s\n", buk[i].name);
    }
    return 0;
}
