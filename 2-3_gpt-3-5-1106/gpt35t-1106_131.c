int main(void)
{
    setvbuf (stdout, NULL, _IONBF, 0);
    char input[50];
    char check = 'a';
    for(int i=0; check != EOF; ++i){
        check = scanf("%s", input);
        getchar(); // consume the newline character
        printf("%s\n",input);
    }

    fflush(stdout);

    char* myAnswer = createList();
    printf("%s\n", myAnswer);

    return 0;
}
