int main(void) {
    printf("found: %s\n", strnstr(in, searchingFor, 10) ? "yes" : "no");
    return 0;
}
