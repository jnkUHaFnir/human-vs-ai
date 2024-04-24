#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int urlDecode(char *str) {
    char *src = str, *dst = str;
    char decodedChar;
    while (*src) {
        if (*src == '%' && src[1] && src[2]) {
            sscanf(src + 1, "%2hhx", &decodedChar);
            *dst++ = decodedChar;
            src += 3;
        } else {
            *dst++ = *src++;
        }
    }
    *dst = '\0';
    return 0;
}

char *param(char *attribute_name) {
    char *query_str = getenv("QUERY_STRING");
    if (!query_str) return NULL;

    urlDecode(query_str);
    printf("qstr = %s<br/>", query_str);

    char *start, *end;
    char *result = NULL;
    char *param_value;

    start = strstr(query_str, attribute_name);
    if (start) {
        start += strlen(attribute_name);
        if (*start == '=') {
            start++;
            end = strchr(start, '&');
            if (end) {
                param_value = strndup(start, end - start);
            } else {
                param_value = strdup(start);
            }
            result = param_value;
        }
    }
    return result;
}

int main() {
    printf("Content-type: text/html\n\n");
    printf("<!Doctype html>");
    printf("<html>");
    printf("<meta charset=\"UTF-8\"><meta http-equiv=\"Content-type\" content=\"text/html; charset=UTF-8\">");
    printf("<body>");

    char attr[] = "u";
    char *value = param(attr);
    if (value) {
        puts(value);
        free(value);
    } else {
        puts("Attribute not found.");
    }

    printf("</body></html>");
    return 0;
}
