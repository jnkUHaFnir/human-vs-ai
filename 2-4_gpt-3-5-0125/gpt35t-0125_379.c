while (*words[c] != '\0' && c < 20) {
    int index = 0;
    while (words[c][index] != '\0') {
        if ((words[c][index] >= 'a' && words[c][index] <= 'z') || (words[c][index] >= 'A' && words[c][index] <= 'Z')) {                    
            freq[words[c][index] - 'a']++;
        }
        index++;
    }
    c++;
}
