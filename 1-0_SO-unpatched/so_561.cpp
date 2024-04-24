    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    char *find_param(char *param, char *query_str) {
        char *p, *p2;
        char *value = malloc(100);
        
        p = strchr(query_str, '?');
        if (!p)
            return NULL;
        do {
            p = strstr(p+1, param);
        } while (p && p[strlen(param)] != '=');
        
        if (!p)
            return NULL;
        p += (1 + strlen(param));
        
        p2 = memchr (p, '&', strlen(p));
        if (!p2)
            p2 = p + strlen(p);
        strcpy(value, p);
        value[p2 - p] = '\0';
        
        return value;
    }
    int main() {
        printf("%s", find_param("u", "http://example.com/cgi-bin/cgi_param?u=1212&sa=232%203&sdd=jdwjdjw"));
        return 0;
    }