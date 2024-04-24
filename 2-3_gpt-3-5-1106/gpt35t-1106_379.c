int main() {
    // existing code

    while (c < N) {
        int j = 0;
        while (*(words[c] + j) != '\0') {
            if ((*(words[c] + j) >= 'a' && *(words[c] + j) <= 'z') || (*(words[c] + j) >= 'A' &&  *(words[c] + j) <= 'Z')) {
                freq[*(words[c] + j) - 'a']++;
            }
            j++;
        }
        c++;
    }

    for (i = 0; i < 26; i++) {
        printf("%c occurs %d times in the entered string.\n", i + 'a', freq[i]);
    }
    return 0;
}
