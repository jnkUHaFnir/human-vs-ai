#include "stand_in_asprintf.h" // Replace with the actual filename and path
stand_in_asprintf(&message, "%.*s: %.*s",
                  (int) result_code_string.length,
                  (char *) result_code_string.data,
                  (int) result_string.length,
                  (char *) result_string.data);
