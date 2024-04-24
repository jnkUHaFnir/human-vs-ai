#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PARAM_LENGTH 1000

int urlDecode(char *str) {
    char *ptr = str;
    while (*str) {
        if (*str == '%' && isxdigit((unsigned char)str[1]) && isxdigit((unsigned char)str[2])) {
            *ptr++ = (char)strtol(str + 1, NULL, 16);
            str += 3;
        } else {
            *ptr++ = *str++;
        }
    }
    *ptr = '\0';
    
    return 0;
}

char *param(const char *attribute_name) {
    char *param_value = NULL;
    char *query_str = getenv("QUERY_STRING");
    if (query_str) {
        urlDecode(query_str);
        printf("qstr = %s<br/>", query_str);

        size_t attr_len = strlen(attribute_name);
        char *temp = malloc(attr_len + 3);
        strcpy(temp, "?");
        strcat(temp, attribute_name);
        strcat(temp, "=");

        char *x = strstr(query_str, temp);
        if (!x) {
            free(temp);
            temp = malloc(attr_len + 3);
            strcpy(temp, "&");
            strcat(temp, attribute_name);
            strcat(temp, "=");
            x = strstr(query_str, temp);
        }

        if (x) {
            x += strlen(temp);
            char *end = strchr(x, '&');
            if (end) {
                param_value = malloc(end - x + 1);
                strncpy(param_value, x, end - x);
                param_value[end - x] = '\0';
            } else {
                param_value = strdup(x);
            }
        }

        free(temp);
    }

    return param_value;
}

int main() {
    printf("Content-type: text/html\n\r\n\r");
    printf("<!Doctype html>");
    printf("<html>");
    printf("<meta charset=\"UTF-8\"><meta http-equiv=\"Content-type\" content=\"text/html; charset=UTF-8\">");
    printf("<body>");

    const char attr[] = "u";
    char *value = param(attr);
    
    if (value) {
        printf("Value of 'u' parameter: %s<br/>", value);
        free(value);
    } else {
        printf("'u' parameter not found<br/>");
    }

    printf("</body></html>");
    return 0;
}
