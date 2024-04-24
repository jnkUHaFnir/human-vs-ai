char message[100]; // assuming a fixed length for the concatenated message
strcpy(message, "TEXT "); // copy the initial string

char var[] = "var";
strcat(message, var); // concatenate var to message

// repeat the process for the additional strings
char message2[100]; // assuming a fixed length for the concatenated message
strcpy(message2, "TEXT ");

char foo[] = "foo";
char bar[] = "bar";

strcat(strcat(strcat(message2, "TEXT "), foo), " TEXT ");
strcat(message2, bar);

printf("Concatenated message: %s\n", message);
printf("Concatenated message2: %s\n", message2);
