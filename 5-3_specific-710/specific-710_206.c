#include <stddef.h>

int are_overlapping(const char *a, const char *b) {
  return (a < b && a + strlen(a) > b) || (b < a && b + strlen(b) > a);
}
