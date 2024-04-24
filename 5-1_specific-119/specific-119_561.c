#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *urlDecode(char *str) {
    unsigned int i;
    char tmp[BUFSIZ];
    char *ptr = tmp;
    memset(tmp, 0, sizeof(tmp));
    for (i=0; i < strlen(str); i++) {
        if (str[i] != '%') {
            *ptr++ = str[i];
            continue;
        }
        if (!isxdigit(str[i+1]) || !isxdigit(str[i+2])) {
            *ptr++ = str[i];
            continue;
        }
        *ptr++ = ((str[i+1] - '0') << 4) | (str[i+2] - '0');
        i += 2;
    }
    *ptr = '\0';
    strcpy(str, tmp);

    return str;
}

char *param(char *attribute_name) {
    char *query_str = getenv("QUERY_STRING");
    urlDecode(query_str);
    printf("qstr = %s<br/>", query_str);

    char *param_value = NULL;
    char *temp = malloc(strlen(attribute_name) + 3);
    strcpy(temp, "&");
    strcat(temp, attribute_name);
    strcat(temp, "=");

    char *x = strstr(query_str, temp);

    if (x != NULL) {
        x += strlen(temp);
        param_value = malloc(strlen(x) + 1);
        sscanf(x, "%[^&]", param_value);
    }

    free(temp);

    return param_value;
}

int main() {
    printf("Content-type: text/html\n\r\n\r");
    printf("<!Doctype html>");
    printf("<html>");
    printf("<meta charset=\"UTF-8\"><meta http-equiv=\"Content-type\" content=\"text/html; charset=UTF-8\">");
    printf("<body>");

    char attr[] = "u";
    char *value = param(attr);
    if (value != NULL) {
        printf("Value: %s<br/>", value);
        free(value);
    }

    printf("</body></html>");
    return 0;
}
