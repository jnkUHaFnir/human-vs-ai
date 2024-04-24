char message[100]; // Assuming maximum length of message
strcpy(message, "TEXT "); // Copy the first part
strcat(message, var); // Concatenate the second part

char message2[100]; // Assuming maximum length for message2
strcpy(message2, "TEXT "); // Copy the first part
strcat(message2, foo); // Concatenate the second part
strcat(message2, " TEXT "); // Concatenate the third part
strcat(message2, bar); // Concatenate the fourth part
char message[100]; // Assuming maximum length of message
sprintf(message, "TEXT %s", var);

char message2[100]; // Assuming maximum length for message2
sprintf(message2, "TEXT %s TEXT %s", foo, bar);
