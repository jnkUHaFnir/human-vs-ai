    int scanner(const char *data, char *buffer, size_t buflen)
    {
        char format[32];
        if (buflen == 0)
            return 0;
        snprintf(format, sizeof(format), "%%%ds", (int)(buflen-1));
        return sscanf(data, format, buffer);
    }