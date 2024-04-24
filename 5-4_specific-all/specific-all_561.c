#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *param(const char *attribute_name) {
    char *query_str = getenv("QUERY_STRING");
    if (query_str == NULL) {
        return NULL;
    }

    char *decoded_query_str = strdup(query_str);
    urlDecode(decoded_query_str);

    char *param_value = NULL;
    char *temp = malloc(strlen(attribute_name) + 3);
    if (temp == NULL) {
        free(decoded_query_str);
        return NULL;
    }

    strcpy(temp, "?");
    strcat(temp, attribute_name);
    strcat(temp, "=");

    char *param_start = strstr(decoded_query_str, temp);

    if (param_start == NULL) {
        free(temp);
        strcpy(temp, "&");
        strcat(temp, attribute_name);
        strcat(temp, "=");
        param_start = strstr(decoded_query_str, temp);
    }

    free(temp);

    if (param_start != NULL) {
        param_start += strlen(attribute_name) + 1; // Move to the start of the value
        char *param_end = strchr(param_start, '&');
        if (param_end == NULL) {
            param_end = decoded_query_str + strlen(decoded_query_str);
        }

        param_value = malloc(param_end - param_start + 1);
        if (param_value == NULL) {
            free(decoded_query_str);
            return NULL;
        }

        strncpy(param_value, param_start, param_end - param_start);
        param_value[param_end - param_start] = '\0'; // Null-terminate the string
    }

    free(decoded_query_str);

    return param_value;
}
