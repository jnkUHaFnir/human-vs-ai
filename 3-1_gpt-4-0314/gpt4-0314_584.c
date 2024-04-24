#include <assert.h>
#include <string.h>
#include <stdio.h>

int main() {
  char buf1[16] = {0};
  char buf2[16] = {0};
  int n = snprintf(buf1, sizeof buf1, "Lorem ipsum %d dolor sit", 123456);
  assert(strcmp(buf1, "Lorem ipsum 123") == 0);  // ok

  // Solution:
  int char_written = snprintf(NULL, 0, "Lorem ipsum %d dolor sit", 123456);
  int buf1_used = sizeof buf1 - 1;  // First buffer used characters (excluding null terminator)
  if (n >= buf1_used) {
    snprintf(buf2, sizeof buf2, "%s", &buf1[strlen(buf1)]);
  }

  assert(strcmp(buf2, "456 dolor sit") == 0);  // expected result
}
