char re[size_data];
strncpy(re, data, size_data);

char* token = strtok(re, " "); // Tokenize based on space
if (token != NULL && strcmp(token, "POST") == 0) {
    // The first token is "POST", meaning it's a POST request
    // *something happens*
}
