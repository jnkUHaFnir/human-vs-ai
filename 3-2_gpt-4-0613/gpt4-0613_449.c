char message[100]; // 100 is just an example, make sure this is large enough

strcpy(message, "TEXT ");
strcat(message, var);
char message2[100]; // Again, make sure this is large enough

strcpy(message2, "TEXT ");
strcat(message2, foo);
strcat(message2, " TEXT ");
strcat(message2, bar);
char message3[100];
snprintf(message3, sizeof(message3), "TEXT %s TEXT %s", foo, bar);
