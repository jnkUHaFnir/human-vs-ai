#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *param(const char *query_str, const char *attribute_name) {
    char *param_value = NULL;
    char *temp = malloc(strlen(attribute_name) + 3);

    if (temp == NULL) {
        // Error handling for malloc failure
        return NULL;
    }

    strcpy(temp, "&");
    strcat(temp, attribute_name);
    strcat(temp, "=");

    char *start_pos = strstr(query_str, temp);

    if (start_pos == NULL) {
        strcpy(temp, "?");
        strcat(temp, attribute_name);
        strcat(temp, "=");
        start_pos = strstr(query_str, temp);
    }

    if (start_pos != NULL) {
        start_pos += strlen(temp);
        char *end_pos = strchr(start_pos, '&');

        if (end_pos == NULL) {
            end_pos = start_pos + strlen(start_pos);
        }

        param_value = malloc(end_pos - start_pos + 1);

        if (param_value == NULL) {
            free(temp);
            return NULL;
        }

        strncpy(param_value, start_pos, end_pos - start_pos);
        param_value[end_pos - start_pos] = '\0';
    }

    free(temp);

    return param_value;
}

