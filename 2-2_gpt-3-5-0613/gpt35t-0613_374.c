int *pSet = (int*) malloc(sizeof(int)); 
int i = 0; 
int c;

printf("Please enter a stream of numbers to make a set out of them: ");
printf("\n");

while (scanf("%d", &c) == 1 && c != -1) {
    pSet = (int*) realloc(pSet, sizeof(int)*(i+1));
    if(pSet == NULL) {
        return FAIL;
    }
    pSet[i] = c;
    printf("%d ", c);
    i++;
}

free(pSet);
