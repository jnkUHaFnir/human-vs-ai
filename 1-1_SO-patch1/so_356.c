    void format_filename(const char *fmt, int jobid, const char *jobname
                         char *buffer, size_t buflen);
    {
        char *end = buffer + buflen - 1;
        const char *src = fmt;
        char *dst = buffer;
        char c;
        assert(buffer != 0 && fmt != 0 && buflen != 0 && jobname != 0);
        while ((c = *src++) != '\0')
        {
            if (dst >= end)
                err_exit("buffer overflow in %s(): format = %s\n",
                         __func__, fmt);
            else if (c != '%')
                *dst++ = c;
            else if ((c = *src++) == '\0' || c == '%')
                *dst++ = '%';
            else if (c == 's')
            {
                size_t len = strlen(jobname);
                if (len > end - dst)
                    err_exit("buffer overflow on jobname in %s(): format = %s\n",
                             __func__, fmt);
                else
                {
                    strcpy(dst, jobname);
                    dst += len;
                }
            }
            else if (c == 'd')
            {
                 int nchars = snprintf(dst, end - dst, "%d", jobid);
                 if (nchars < 0 || nchars >= end - dst)
                     err_exit("format error on jobid in %s(); format = %s\n",
                              __func__, fmt);
                 dst += nchars;
            }
            else
                err_exit("invalid format character %d in %s(): format = %s\n",
                         c, __func__, fmt);
        }
        *dst = '\0';
    }