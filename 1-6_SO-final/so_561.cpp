    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    char *find_param(char *param, char *query_str) {
      char *p, *p2;
      char *value = malloc(100);
      
      p = strchr(query_str, '?');
      do {
          p = strstr(query_str, "u");
      } while (p && p[1] != '=');
      
      if (!p) {
          printf("Not found");
          exit(EXIT_FAILURE);
      }
      p+=2;
      
      p2 = memchr (p, '&', strlen(p));
      strcpy(value, p);
      value[p2 - p] = '\0';
      
      return value;
    }
    int main() {
      printf("%s", find_param("u", "http://example.com/cgi-bin/cgi_param?u=1212&sa=232%203&sdd=jdwjdjw"));
      return 0;
    }