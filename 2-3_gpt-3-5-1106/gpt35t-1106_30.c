#include <stdio.h>
#define MAX_LINE_LENGTH 100

int main() {
    char line[MAX_LINE_LENGTH];

    printf("Enter a line of text: ");
    fgets(line, sizeof(line), stdin);

    printf("You entered: %s\n", line);

    return 0;
}
