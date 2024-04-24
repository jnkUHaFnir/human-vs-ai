char arr[MAX_STRINGS][MAX_STRING_LENGTH]; // Define sizes appropriately
int count = 0; // To keep track of valid strings added to arr

s1 = strtok(str1, ";");
while (s1 != NULL) {
    st7 = strstr(s1, "s__");
    if (st7 != NULL) {
        strncpy(arr[count], st7, MAX_STRING_LENGTH-1); // Copy string to arr
        arr[count][MAX_STRING_LENGTH-1] = '\0'; // Null-terminate
        count++;
    }
    s1 = strtok(NULL, ";");
}

// Now arr contains all substrings starting with "s__". You can sort these.
for (int i = 0; i < count - 1; ++i) {
    for (int j = i + 1; j < count; ++j) {
        if (strcmp(arr[i], arr[j]) > 0) {
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[j]);
            strcpy(arr[j], temp);
        }
    }
}

// Print sorted substrings
for(int i = 0; i < count; i++) {
    printf("%s\n", arr[i]);
}
