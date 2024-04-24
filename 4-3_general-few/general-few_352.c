#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <gc.h>

typedef char * string;

static string printInt(Object self) {
  string tmp;
  string str;

  // Use GC_asprintf from Boehm GC for allocation
  if (GC_asprintf(&tmp, "%lu", getValueInt(self)) == -1) {
    return NULL; // Check for allocation failure
  }

  // Allocate memory for str using GC_MALLOC
  str = GC_MALLOC(strlen(tmp) + 1);

  strcpy(str, tmp);
  GC_FREE(tmp); // Free the temporary string allocated by GC_asprintf

  return str;
}
