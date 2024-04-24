#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* param(char *query_str, char *attribute_name) {
    char *param_value = NULL;
    char *temp = malloc(strlen(attribute_name) + 3);
    char *x;

    if (query_str == NULL) {
        return NULL;
    }

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
        char* end_pos = strchr(x, '&');
        if (end_pos != NULL) {
            param_value = malloc(end_pos - x);
            strncpy(param_value, x + strlen(temp), end_pos - x - strlen(temp));
            param_value[end_pos - x - strlen(temp)] = '\0';
        } else {
            param_value = strdup(x + strlen(temp));
        }
    }

    free(temp);

    return param_value;
}

int urlDecode(char* str) {
    unsigned int i, j = 0;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == '%' && isxdigit(str[i+1]) && isxdigit(str[i+2])) {
            int digit1 = (isdigit(str[i+1])) ? (str[i+1] - '0') : (toupper(str[i+1]) - 'A' + 10);
            int digit2 = (isdigit(str[i+2])) ? (str[i+2] - '0') : (toupper(str[i+2]) - 'A' + 10);
            str[j] = (char)((digit1 << 4) + digit2);
            i += 2;
        } else {
            str[j] = str[i];
        }
        j++;
    }
    str[j] = '\0';

    return 0;
}

int main() {
    char *query_str = getenv("QUERY_STRING");
    if (query_str == NULL) {
        printf("Content-type: text/html\n\n");
        printf("No query parameter provided.");
        return 1;
    }

    urlDecode(query_str);

    char attr[] = "u";
    char *value = param(query_str, attr);

    printf("Content-type: text/html\n\n");
    printf("<!DOCTYPE html>\n");
    printf("<html>\n");
    printf("<head>\n");
    printf("<meta charset=\"UTF-8\">\n");
    printf("</head>\n");
    printf("<body>\n");

    if (value != NULL) {
        printf("Value of 'u' parameter is: %s\n", value);
        free(value);
    } else {
        printf("Parameter 'u' not found.");
    }

    printf("</body>\n");
    printf("</html>\n");

    return 0;
}
