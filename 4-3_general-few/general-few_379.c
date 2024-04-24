// Calculate letter frequency
for (i = 0; i < N; i++) {
    c = 0;
    while (*words[i] != '\0') {
        if ((*words[i] >= 'a' && *words[i] <= 'z') || (*words[i] >= 'A' &&  *words[i] <= 'Z')) {
            freq[tolower(*words[i]) - 'a']++;  // Convert the letter to lowercase for a consistent count
        }
        words[i]++;
        c++;
    }
}

// Print letter frequency
for (i = 0; i < 26; i++) {
    if (freq[i] > 0) {
        printf("%c occurs %d times in the entered string.\n", i + 'a', freq[i]);
    }
}
