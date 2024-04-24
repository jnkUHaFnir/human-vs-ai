for (i = 0; i < N; i++) {
        c = 0;
        while (*(words[i] + c) != '\0') {
            if ((*(words[i] + c) >= 'a' && *(words[i] + c) <= 'z') || (*(words[i] + c) >= 'A' &&  *(words[i] + c) <= 'Z')) {                    
                freq[*(words[i] + c) - 'a']++;
            }
            c++;
        }
    }
for (i = 0; i < 26; i++) {
        printf("%c occurs %d times in the entered string.\n", i + 'a', freq[i]);
    }
