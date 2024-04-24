        int alpha(const char *word1, const char *word2) {
            for (size_t i = 0;; i++) {
                if (word1[i] == '\0' && word2[i] == '\0')
                    return 2;
                if (word1[i] == word2[i])
                    continue;
                if (word1[i] < word2[i])
                    return 1;
                else
                    return 0;
            }
        }