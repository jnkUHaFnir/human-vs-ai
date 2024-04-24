char *name = malloc(sizeof(char) * 256); 

printf("What is your name? ");

// Using fgets to allow spaces in input
fgets(name, 256, stdin);

// Removing trailing newline character
name[strcspn(name, "\n")] = '\0';

printf("Hello %s. Nice to meet you.\n", name);
free(name);
