char *param(char *attribute_name) {
    char *query_str = getenv("QUERY_STRING");
    char *decoded_query = strdup(query_str);
    urlDecode(decoded_query);

    int i;
    char *param_value = NULL;
    char *temp = malloc(strlen(attribute_name) + 3);
    char *x;
    strcpy(temp, "?");
    strcat(temp, attribute_name);
    strcat(temp, "=");

    x = strstr(decoded_query, temp);
    attribute_name = strdup(attribute_name);

    if (x == NULL) {
        free(temp);
        temp = malloc(strlen(attribute_name) + 3);
        strcpy(temp, "&");
        strcat(temp, attribute_name);
        strcat(temp, "=");
        x = strstr(decoded_query, temp);
    }

    if (x != NULL) {
        param_value = malloc(strlen(x) - strlen(temp) + 1);
        int s = strlen(temp);
        int t = strlen(temp);
        strncpy(param_value, &x[t], strlen(x) - strlen(temp));
        param_value[strlen(x) - strlen(temp)] = '\0';
    }
    free(temp);
    free(attribute_name);
    free(decoded_query);

    return param_value;
}
