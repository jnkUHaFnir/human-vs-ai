char** stringArray = malloc(x * sizeof(char*));
for (int i = 0; i < x; i++) {
    stringArray[i] = malloc(51 * sizeof(char));
}
