#include <stdio.h>
#include <string.h>

int main() {
    char names[50][32];
    char states[50][2];
    int b, i;

    // Get the number of times to loop
    printf("Enter the number of times to loop: ");
    scanf("%d", &b);

    // Prompt the user to input names and states
    for (i = 0; i < b; i++) {
        printf("Enter name %d: ", i + 1);
        scanf("%s", names[i]);
        printf("Enter state %d: ", i + 1);
        scanf("%s", states[i]);
    }

    // Print names for people who live in TX
    for (i = 0; i < b; i++) {
        if (strcmp(states[i], "tx") == 0) {
            printf("%s\n", names[i]);
        }
    }

    return 0;
}
