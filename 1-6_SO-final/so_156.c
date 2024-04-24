    int scanner(const char *data, char *buffer, size_t buflen)
    {
        char format[32];
        snprintf(format, sizeof(format), "%%%ds", (int)buflen);
        return sscanf(data, format, buffer);
    }