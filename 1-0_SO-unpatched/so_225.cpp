    #include <cctype>
    size_t buflen = something;
    for (size_t i = 0; i < buflen; ++i)
        if (!isalnum(buf[i]) || buf[i] != ' ')
            memcpy(buf[i], buf[i + 1], --buflen - i);