int main(void)
{
    setvbuf (stdout, NULL, _IONBF, 0);
    char input[50];
    int check = 0;
    while ((check = scanf("%49s", input)) == 1) {
        printf("%s\n", input);
    }

    fflush(stdout);

    char* myAnswer = createList();
    printf("%s\n", myAnswer);

    return 0;
}
