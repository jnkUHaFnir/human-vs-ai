char *param(char *attribute_name) {
    char *query_str = getenv("QUERY_STRING");
    urlDecode(query_str);
    printf("qstr = %s<br/>", query_str);
    int i;
    char *param_value = NULL;
    char *temp = malloc(strlen(attribute_name) + 3);
    char *x;
    strcpy(temp, "?");
    strcat(temp, attribute_name);
    strcat(temp, "=");

    x = strstr(query_str, temp);
    attribute_name = strdup(attribute_name);

    if (x == NULL) {
        free(temp);
        temp = malloc(strlen(attribute_name) + 3);
        strcpy(temp, "&");
        strcat(temp, attribute_name);
        strcat(temp, "=");
        x = strstr(query_str, temp);
    }

    if (x != NULL) {
        param_value = malloc(strlen(x) - strlen(temp) + 1);
        int s = strlen(x) - strlen(temp);
        int t = strlen(x) - s;
        strncpy(param_value, &x[t], s);
        param_value[s] = '\0';
        for (i = strlen(temp) + 1; i <= strlen(x); i++) {
            if (x[i] != '&') {
                strncat(param_value, &x[i], 1);
            } else {
                break;
            }
        }
    }
    free(temp);

    return param_value;
}

int urlDecode(char *str) {
    unsigned int i;
    char tmp[BUFSIZ];
    char *ptr = tmp;
    memset(tmp, 0, sizeof(tmp));
    for (i = 0; i < strlen(str) && str[i] != '\0'; i++) {
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
    puts(value);
    free(value);

    printf("</body></html>");
    return 0;
}
