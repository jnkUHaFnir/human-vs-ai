for (size_t i = 0; i < strlen(cAFirst); i++) {
    k = (int)cAFirst[i];
    if (isupper(cAFirst[i])) {
        uc++;
    }
    if (islower(cAFirst[i])) {
        lc++;
    }
}
