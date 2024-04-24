#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    int sum = 0, count = 0;

    printf("Enter numbers separated by spaces: ");
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " ");
    while (token != NULL) {
        int num = atoi(token);
        sum += num;
        count++;
        token = strtok(NULL, " ");
    }

    if (count == 0) {
        printf("No numbers provided.\n");
    } else {
        double average = (double)sum / count;
        printf("Average of the numbers is: %.2f\n", average);
    }

    return 0;
}
