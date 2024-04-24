static string printInt(Object self) {
    char buffer[32]; // Or however large you need it to be
    snprintf(buffer, sizeof(buffer), "%lu", getValueInt(self));
    string str = (string)GC_MALLOC(strlen(buffer) + 1);
    strcpy(str, buffer);
    return str;
}
int gc_asprintf(char **strp, const char *fmt, ...) {
    int size;
    va_list args;

    // Use vsnprintf with a null buffer to calculate the required size
    va_start(args, fmt);
    size = vsnprintf(NULL, 0, fmt, args);
    va_end(args);

    if (size < 0) return -1;

    // Allocate memory with the garbage collector
    *strp = (char *)GC_MALLOC(size + 1);
    if (!*strp) return -1;

    // Now use vsnprintf for real
    va_start(args, fmt);
    size = vsnprintf(*strp, size + 1, fmt, args);
    va_end(args);

    return size;
}
