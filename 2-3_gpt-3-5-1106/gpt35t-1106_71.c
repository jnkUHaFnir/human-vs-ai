char message[100]; // Make sure the message array is large enough to hold the concatenated strings
strcpy(message, "TEXT "); // Copy the first string into the message array

// Concatenate the second string
strcat(message, var);

char message2[100]; // Make sure the message2 array is large enough to hold the concatenated strings
strcpy(message2, "TEXT "); // Copy the first string into the message2 array

// Concatenate the second and third strings
strcat(message2, foo);
strcat(message2, " TEXT ");
strcat(message2, bar);
