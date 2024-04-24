int main() {
    int N, i;
    printf("Get the num : ");
    scanf("%d", &N);
    getchar(); // consume newline character

    char color[N][20];
    printf("Enter the message\n");
    for (i = 0; i < N; i++) {
        fgets(color[i], 20, stdin);
    }
    for (i = 0; i < N; i++) {
        printf("%s", color[i]);
    }
    return 0;
}
