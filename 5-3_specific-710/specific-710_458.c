#include <stdio.h>
#include <assert.h>

void replaceindex(char *s, char *replace, unsigned int start, unsigned int end)
{
  assert(start < end);
  
  char *p = s, *q = s, *r = replace;
  register unsigned int i = 0;
  int found = 0;

  while (*q) {
    if (!found && i == start) {
      found = 1;
      
      int replace_len = 0;
      char *temp_r = r;
      while (*temp_r) {
        replace_len++;
        temp_r++;
      }
      
      int substr_len = end - start;
      
      if (replace_len < substr_len) {
        for (; *r; ++r, ++start, ++q)
          *p++ = *r;
          
        for (int j = 0; j < substr_len - replace_len; j++)
          q++;
      } else {
        for (; *r; ++r, ++q)
          *p++ = *r;
        
        while (++start < end)
          q++;
      }
    }

    *p++ = *q++;
    i++;
  }
}

int main() {
  char str[] = "([10 20]...[10 20]..[30 80])";
  printf("Before: %s\n", str);
  replaceindex(str, "50", 1, 7);
  printf("After: %s\n", str);

  return 0;
}
Before: ([10 20]...[10 20]..[30 80])
After: (50...[10 20]..[30 80])
