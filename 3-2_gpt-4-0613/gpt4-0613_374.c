int *pSet = (int*) malloc(sizeof(int));
if(pSet == NULL) {
    perror("Failed to allocate memory");
    exit(EXIT_FAILURE);
}

int c, res, i = 0;

printf("Please enter a stream of numbers to make a set out of them: ");
printf("\n");

while((res = scanf("%d", &c)) != EOF) {
    if(res == 0) {
        printf("Not a number\n");
        exit(EXIT_FAILURE);
    }
    pSet = realloc(pSet, sizeof(int)*(i+1));
    if(pSet == NULL) {
        perror("Failed to reallocate memory");
        exit(EXIT_FAILURE);
    }
    pSet[i] = c;
    printf("%d ", c);
    i++;
}
free(pSet);
