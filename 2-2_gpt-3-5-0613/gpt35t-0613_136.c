splitString = malloc(strlen(buffer) + 1);
splitString = strtok(buffer, delim);
free(splitString);
