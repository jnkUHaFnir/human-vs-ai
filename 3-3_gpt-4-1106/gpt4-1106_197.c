char x[50]; // Assuming 'x' is an array of char
int result;

// The loop will break when ':' is encountered, and ':' will be included
while ((result = scanf("%49[^:]", x)) != EOF) { // Read until ':'
    if (result == 1) { // If something was read...
        char c;
        scanf("%c", &c); // Read the ':' character
        if (c == ':') {
            int len = strlen(x);
            x[len] = ':';      // Append ':' to the string
            x[len + 1] = '\0'; // Null-terminate the string
        } else {
            // Handle unexpected character if necessary
        }
    } else {
        // No more input or an error occurred.
        break;
    }

    // Your logic here with 'x' as needed.
    
    // Note: If there's a possibility of a newline '\n' being read immediately
    // after ':', you'll want to handle that case separately here.
}

// Do note that the '%*c' has been removed, and directly read by `scanf("%c", &c);`
// This is to ensure that the ':' is read and then appended to the string.
