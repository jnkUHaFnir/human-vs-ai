char *message;
char *var = "some text";

message = malloc(strlen("TEXT ") + strlen(var) + 1);  // allocate memory for the concatenated string
strcpy(message, "TEXT ");
strcat(message, var);   // concatenate the two strings

printf("%s", message);

free(message);   // free the memory when you're done with it
