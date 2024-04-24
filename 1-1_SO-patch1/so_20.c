    #include <stdint.h> /* fixed-width integer types */
    #include <stdlib.h> /* strtol */
    #include <stdbool.h>
    #include <errno.h>
    static bool
    str_to_uint16(const char *str, uint16_t *res)
    {
      long int val = strtol(str, NULL, 10);
      if (errno == ERANGE || val > UINT16_MAX || val < 0)
        return false;
      *res = (uint16_t) val;
      return true;
    }