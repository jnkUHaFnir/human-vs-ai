for (c = 0; c < N; c++) {
    char *word = words[c];
    while (*word) {
        if ((*word >= 'a' && *word <= 'z') || (*word >= 'A' && *word <= 'Z')) {                    
            freq[tolower(*word) - 'a']++;
        }
        word++;
    }
}
