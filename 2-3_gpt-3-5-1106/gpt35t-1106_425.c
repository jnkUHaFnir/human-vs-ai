char *name = malloc(256); 

printf("What is your name? ");
scanf(" %[^\n]", name);

printf("Hello %s. Nice to meet you.\n", name);
