int are_overlapping(const char *a, const char *b) {
    return (a < b + strlen(b)) && (b < a + strlen(a));
}
