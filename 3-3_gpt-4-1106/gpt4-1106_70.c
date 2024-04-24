#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int compat_asprintf(char **strp, const char *fmt, ...) {
    int size = 0;
    va_list args;

    // Initialize the va_list variable with the ... after fmt
    va_start(args, fmt);

    // Use vsnprintf with a NULL buffer to get the size needed for the resulting string
    size = vsnprintf(NULL, 0, fmt, args);
    if (size < 0) {
        va_end(args);
        return -1;
    }

    // Allocate memory for the output string
    *strp = (char *)malloc(size + 1); // +1 for the null-terminator
    if (!*strp) {
        va_end(args);
        return -1;
    }

    // Now use vsnprintf again but with the allocated buffer
    size = vsnprintf(*strp, size + 1, fmt, args);

    // Cleanup the va_list variable
    va_end(args);

    return size;
}
#ifndef COMPAT_ASPRINTF_H
#define COMPAT_ASPRINTF_H

int compat_asprintf(char **strp, const char *fmt, ...);

#endif // COMPAT_ASPRINTF_H
#include "compat_asprintf.h"

// Use a preprocessor directive to replace asprintf with compat_asprintf
#ifndef HAVE_ASPRINTF // You might need to check this based on your platform capabilities
#define asprintf compat_asprintf
#endif

// ...

After making these changes, run `autoheader` and `autoconf` to regenerate the `configure` script and `config.h` header (if using autotools), making sure your build system knows whether it needs to use the compatibility function or not.
