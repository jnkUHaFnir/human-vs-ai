char temp[100]; // Make sure to allocate enough space for the concatenated string
strcpy(temp, "TEXT ");
strcat(temp, var);
message = strdup(temp);

strcpy(temp, "TEXT ");
strcat(temp, foo);
strcat(temp, " TEXT ");
strcat(temp, bar);
message2 = strdup(temp);
