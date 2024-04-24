char charLookup[][3] = { "ab", "àa", "ss", "åa", "ÅA", "ÿy", "XX", "" };
if (strcmp(pCharWorker, charLookup[j]) == 0) {
    printf("Detected char: %s \n", pCharWorker);
    strcpy(pCharWorker, charLookup[j + 1]);
    printf("Replaced with char: %s \n", pCharWorker);
    finishedFlag = 1;
}
