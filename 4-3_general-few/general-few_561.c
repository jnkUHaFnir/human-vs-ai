char *param(const char *attribute_name) {
    char *query_str = getenv("QUERY_STRING");
    urlDecode(query_str);
    printf("qstr = %s<br/>", query_str);
    
    char *param_value = NULL;
    
    char *temp = malloc(strlen(attribute_name) + 3);
    sprintf(temp, "?%s=", attribute_name);

    char *x = strstr(query_str, temp);
    if (x == NULL) {
        sprintf(temp, "&%s=", attribute_name);
        x = strstr(query_str, temp);
    }

    if (x != NULL) {
        x += strlen(temp);
        char *end = strchr(x, '&');
        if (end != NULL) {
            param_value = strndup(x, end - x);
        } else {
            param_value = strdup(x);
        }
    }

    free(temp);

    return param_value;
}
