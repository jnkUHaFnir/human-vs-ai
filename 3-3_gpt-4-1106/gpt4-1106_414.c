rub[idx].name = (char *) malloc(strlen(tmp));
rub[idx].name = tmp;
tmp = getString();
rub[idx].name = (char *) malloc(strlen(tmp) + 1); // +1 for the null terminator
strcpy(rub[idx].name, tmp);
free(tmp); // Free the temporary buffer after use
