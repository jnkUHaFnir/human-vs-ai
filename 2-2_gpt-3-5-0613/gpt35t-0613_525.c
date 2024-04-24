while (countX < 10) {
    int i = 0;
    while (scanWord[countX][i] != '\0' && currentWord[countX][i] != '\0') {
        if (scanWord[countX][i] == currentWord[countX][i]) {
            scoreCurrent++;
            scoreCurrent++;
        }
        i++;
    }
    countX++;
}
