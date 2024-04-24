#include <stdio.h>

int main(){
    int N, i;
    printf("Enter the number of messages: ");
    scanf("%d", &N);
    getchar(); // Consume the newline character

    char color[N][20];

    printf("Enter the messages:\n");
    for(i = 0; i < N; i++){
        fgets(color[i], 20, stdin);
    }

    printf("Entered messages:\n");
    for(i = 0; i < N; i++){
        printf("%s", color[i]);
    }

    return 0;
}
