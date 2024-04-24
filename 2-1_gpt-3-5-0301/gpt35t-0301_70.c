#include "asprintf/asprintf.h"

...

char *message;

asprintf(&message, "%.*s: %.*s",
          (int) result_code_string.length,
          (char *) result_code_string.data,
          (int) result_string.length,
          (char *) result_string.data);
