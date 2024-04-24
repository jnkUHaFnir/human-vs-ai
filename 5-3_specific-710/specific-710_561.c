#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *param(char *attribute_name) {
    char *query_str = getenv("QUERY_STRING");
    urlDecode(query_str);
    printf("qstr = %s<br/>", query_str);

    char *param_value = NULL;
    char *temp = malloc(strlen(attribute_name) + 3);
    char *x;
    strcpy(temp, "?");
    strcat(temp, attribute_name);
    strcat(temp, "=");

    x = strstr(query_str, temp);
    if (x == NULL) {
        free(temp);
        temp = malloc(strlen(attribute_name) + 3);
        strcpy(temp, "&");
        strcat(temp, attribute_name);
        strcat(temp, "=");
        x = strstr(query_str, temp);
    }

    if (x != NULL) {
        size_t param_len = strcspn(x + strlen(temp), "&");
        param_value = malloc(param_len + 1);
        strncpy(param_value, x + strlen(temp), param_len);
        param_value[param_len] = '\0';
    }

    free(temp);

    return param_value;
}

int urlDecode(char *str) {
    unsigned int i;
    char tmp[BUFSIZ];
    char *ptr = tmp;
    memset(tmp, 0, sizeof(tmp));
    for (i=0; i < strlen(str); i++) {
        if (str[i] != '%') {
            *ptr++ = str[i];
            continue;
        }
        if (!isdigit(str[i+1]) || !isdigit(str[i+2])) {
            *ptr++ = str[i];
            continue;
        }
        *ptr++ = ((str[i+1] - '0') << 4) | (str[i+2] - '0');
        i += 2;
    }
    *ptr = '\0';
    strcpy(str, tmp);

    return 0;
}

int main() {
    printf("Content-type: text/html\n\r\n\r");
    printf("<!Doctype html>");
    printf("<html>");
    printf("<meta charset=\"UTF-8\"><meta http-equiv=\"Content-type\" content=\"text/html; charset=UTF-8\">");
    printf("<body>");

    char attr[] = "u";
    char *value = param(attr);

    // Encode HTML special characters for safe output
    if (value != NULL) {
        char *encoded_value = strdup(value); // Copy to not modify original value
        for (size_t i = 0; i < strlen(encoded_value); i++) {
            if (encoded_value[i] == '<') {
                value = realloc(encoded_value, strlen(encoded_value) + 4); // Reallocate memory
                memmove(&encoded_value[i + 4], &encoded_value[i + 1], strlen(encoded_value) - i); // Shift characters
                memcpy(&encoded_value[i], "&lt;", 4); // Replace '<' with '&lt;'
                i += 3; // Skip the added characters
            } else if (encoded_value[i] == '>') {
                value = realloc(encoded_value, strlen(encoded_value) + 4);
                memmove(&encoded_value[i + 4], &encoded_value[i + 1], strlen(encoded_value) - i);
                memcpy(&encoded_value[i], "&gt;", 4);
                i += 3;
            }
        }
    
        printf("Value = %s<br/>", encoded_value);
        free(encoded_value);
    } else {
        printf("Value not found<br/>");
    }

    free(value);

    printf("</body></html>");
    return 0;
}
``` 

These corrections should help address the issues you were facing and improve the security of your code.
