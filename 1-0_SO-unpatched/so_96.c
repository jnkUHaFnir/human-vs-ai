    char word[20];
    
    printf("Enter word: ");
    if (scanf("%19s", word) == 1) {   
      printf("String reversed: "); 
      for (size_t i = strlen(word); i != 0; i--){
        printf("%c", word[i-1]);
      }
      putchar('\n');
    }