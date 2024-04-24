int *pSet = (int*) malloc(sizeof(int));
int i = 0;
int c;

printf("Please enter a stream of numbers to make a set out of them: \n");
while (1) {
    if (scanf("%d", &c) != 1) {
        break; // If scanf fails to read an integer, break out of the loop
    }
    
    pSet[i] = c;
    printf("%d ", c);
    
    i++;
    pSet = (int*) realloc(pSet, sizeof(int)*(i+1));
    if(pSet == NULL) {
        return FAIL;        
    }
}

// Print the values stored in the array
printf("\nValues stored in the array: ");
for (int j = 0; j < i; j++) {
    printf("%d ", pSet[j]);
}

free(pSet);
