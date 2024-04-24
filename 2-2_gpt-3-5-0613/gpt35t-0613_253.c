bool bits[strlen(text_copy)][8];
int text_length = strlen(text_copy);
bool** bits = (bool**)malloc(text_length * sizeof(bool*));
for (int i = 0; i < text_length; i++) {
    bits[i] = (bool*)malloc(8 * sizeof(bool));
}
for (int i = 0; i < text_length; i++) {
    free(bits[i]);
}
free(bits);
