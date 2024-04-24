rub[idx].name = (char *) malloc(strlen(tmp));
rub[idx].name = tmp;
rub[idx].name = (char *) malloc(strlen(tmp) + 1); // +1 to include the null terminator
strcpy(rub[idx].name, tmp); // Copy the contents of tmp into the allocated memory

// Repeat the above two lines for surname, address, and number fields
