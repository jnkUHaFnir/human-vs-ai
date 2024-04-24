#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* param(char *attribute_name) {
    char *query_str = getenv("QUERY_STRING");
    if(query_str == NULL) {
        return NULL; // Handle case where QUERY_STRING is not available
    }

    int query_len = strlen(query_str);
    char* decoded_query_str = malloc(query_len + 1);
    if(decoded_query_str == NULL) {
        return NULL; // Handle memory allocation failure
    }
    memset(decoded_query_str, 0, query_len + 1);

    urlDecode(query_str, decoded_query_str);

    char *param_value = NULL;
    char *temp = malloc(strlen(attribute_name) + 3);
    if(temp == NULL) {
        free(decoded_query_str);
        return NULL; // Handle memory allocation failure
    }

    char *x;
    strcpy(temp, "?");
    strcat(temp, attribute_name);
    strcat(temp, "=");

    x = strstr(decoded_query_str, temp);

    if (x == NULL) {
        free(temp);
        temp = malloc(strlen(attribute_name) + 3);
        if(temp == NULL) {
            free(decoded_query_str);
            return NULL; // Handle memory allocation failure
        }
        strcpy(temp, "&");
        strcat(temp, attribute_name);
        strcat(temp, "=");
        x = strstr(decoded_query_str, temp);
    }

    if (x != NULL) {
        char* end = strchr(x, '&');
        if(end == NULL) {
            end = x + strlen(x);
        }
        
        param_value = malloc(end - (x + strlen(temp)) + 1);
        if(param_value == NULL) {
            free(temp);
            free(decoded_query_str);
            return NULL; // Handle memory allocation failure
        }

        strncpy(param_value, x + strlen(temp), end - (x + strlen(temp)));
        param_value[end - (x + strlen(temp))] = '\0';
    }

    free(temp);
    free(decoded_query_str);

    return param_value;
}

void urlDecode(char* src, char* dest) {
    char a, b;
    while (*src) {
        if ((*src == '%') &&
            ((a = src[1]) && (b = src[2])) &&
            (isxdigit(a) && isxdigit(b))) {

            if (a >= 'a')
                a -= 'a' - 'A';
            if (a >= 'A')
                a -= ('A' - 10);
            else
                a -= '0';
            if (b >= 'a')
                b -= 'a' - 'A';
            if (b >= 'A')
                b -= ('A' - 10);
            else
                b -= '0';
            *dest++ = 16 * a + b;
            src += 3;
        } else if (*src == '+') {
            *dest++ = ' ';
            src++;
        } else {
            *dest++ = *src++;
        }
    }
    *dest = '\0';
}

int main() {
    printf("Content-type: text/html\n\r\n\r");
    printf("<!Doctype html>");
    printf("<html>");
    printf("<meta charset=\"UTF-8\"><meta http-equiv=\"Content-type\" content=\"text/html; charset=UTF-8\">");
    printf("<body>");

    char attr[] = "u";
    char *value = param(attr);
    
    if(value != NULL) {
        puts(value);
        free(value);
    } else {
        printf("Parameter not found.");
    }

    printf("</body></html>");
    return 0;
}
