#include <stdio.h>
#include <string.h>

int main() {
    char temp;
    char variable1[50];
    char variable2[50];

    if (1) {
        scanf(" %c", &temp); // Notice the space before %c to consume any leading whitespace
        fgets(variable1, 50, stdin);
        strtok(variable1, "\n");

        printf("%s ", variable1);

        while ((temp = getchar()) != '\n' && temp != EOF); // Consume remaining characters including newline

        // Perform similar cleanup before reading the second input
        scanf(" %c", &temp);
        fgets(variable2, 50, stdin);
        strtok(variable2, "\n");

        printf("%s ", variable2);
    }

    return 0;
}
