char *message = malloc(strlen("TEXT ") + strlen(var) + 1); // +1 for null terminator
strcpy(message, "TEXT ");
strcat(message, var);

char *message2 = malloc(strlen("TEXT ") + strlen(foo) + strlen(" TEXT ") + strlen(bar) + 1); // +1 for null terminator
strcpy(message2, "TEXT ");
strcat(message2, foo);
strcat(message2, " TEXT ");
strcat(message2, bar);
