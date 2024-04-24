    char word[20];
    size_t i, len;
    
    printf("Enter word: ");
    scanf("%19s", word);
    
    len = strlen(word);
    
    printf("String reversed: "); 
    for (i = len-1; i >= 0; i--){
        printf("%c", word[i]);
    }
    putchar('\n');