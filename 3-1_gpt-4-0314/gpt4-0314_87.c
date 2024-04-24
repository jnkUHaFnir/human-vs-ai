int main() {
    int N, i, radius, diameter, count = 0;
    printf("Get the num : ");
    scanf("%d", &N);

    char str[20];
    char color[N][20];

    getchar(); // Consume the newline character

    printf("Enter the message\n");
    for (i = 0; i < N; i++) {
        fgets(color[i], 20, stdin);
    }
    for (i = 0; i < N; i++) {
        printf("%s", color[i]);
    }
    return 0;
}
Get the num : 3
Enter the message
red 50
50 green
blue 50
red 50
50 green
blue 50
