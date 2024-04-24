#include <stdio.h>

int main() {
    int N, i;
    char color[20][20];

    printf("Enter the number of messages: ");
    scanf("%d", &N);
    getchar(); // consume the newline character

    printf("Enter the messages:\n");

    for (i = 0; i < N; i++) {
        fgets(color[i], 20, stdin);
    }

    for (i = 0; i < N; i++) {
        printf("%s", color[i]);
    }

    return 0;
}
