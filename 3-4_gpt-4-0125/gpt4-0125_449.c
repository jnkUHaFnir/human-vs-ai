char message[256]; // Make sure this is large enough to hold the combined string.
strcpy(message, "TEXT "); // Copy the initial string into message.
strcat(message, var); // Concatenate var onto message.
char message2[256]; // Adjust size as necessary.

strcpy(message2, "TEXT "); // Start with "TEXT "
strcat(message2, foo); // Add foo.
strcat(message2, " TEXT "); // Then add " TEXT "
strcat(message2, bar); // Finally, add bar.
size_t totalSize = strlen("TEXT ") + strlen(foo) + strlen(" TEXT ") + strlen(bar) + 1; // +1 for the null terminator.
char* message2 = malloc(totalSize);

if (message2) {
    snprintf(message2, totalSize, "%s%s%s%s", "TEXT ", foo, " TEXT ", bar); // This constructs the whole string at once.

    // Use message2 as needed...

    free(message2); // Don't forget to free dynamically allocated memory.
} else {
    // Handle malloc failure
}
