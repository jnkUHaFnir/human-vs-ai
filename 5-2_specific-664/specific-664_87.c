#include <stdio.h>

int main() {
    int N, i;
    char color[N][20];

    printf("Enter the number of colors: ");
    scanf("%d", &N);

    // Consume the newline character left in the input buffer
    getchar();

    printf("Enter the colors:\n");
    for (i = 0; i < N; i++) {
        fgets(color[i], 20, stdin);
    }

    printf("Entered colors:\n");
    for (i = 0; i < N; i++) {
        printf("%s", color[i]);
    }

    return 0;
}
