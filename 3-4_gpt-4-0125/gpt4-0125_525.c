printf("Comparing '%s' and '%s'\n", scanWord[countX], currentWord[countX]);
bool strings_equal = true;
for (int i = 0; scanWord[countX][i] && currentWord[countX][i]; i++) {
    if (scanWord[countX][i] != currentWord[countX][i]) {
        strings_equal = false;
        break;
    }
}
if (strings_equal && scanWord[countX][strlen(scanWord[countX])] == '\0' &&
    currentWord[countX][strlen(currentWord[countX])] == '\0') {
    // Increase scoreCurrent as strings match
    scoreCurrent += 2;
} else {
    // Strings don't match
}
