#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];
    printf("Enter numbers separated by spaces: ");
    fgets(input, sizeof(input), stdin);

    int sum = 0;
    int count = 0;
    char *token = strtok(input, " ");
    while (token != NULL) {
        sum += atoi(token);
        count++;
        token = strtok(NULL, " ");
    }

    if (count == 0) {
        printf("No numbers entered!\n");
    } else {
        printf("Average is: %.2f\n", (double)sum / count);
    }

    return 0;
}
