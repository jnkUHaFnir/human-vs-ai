p = strchr(sentence, '\n');
if (p) *p = '\0';
sentence[strcspn(sentence, "\n")] = '\0';
