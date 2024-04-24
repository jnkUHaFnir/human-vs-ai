    // You must free the result if result is non-NULL.
    char *str_replace(char *orig, char *rep, char *with) {
        char *result;
        char *ins;
        char *tmp;
        int len_rep;
        int len_with;
        int len_front;
        if (!(ins = strstr(orig, rep))) 
            return NULL;
        len_rep = strlen(rep);
        len_with = strlen(with);
        len_front = ins - orig;
        result = malloc(strlen(orig) + len_with - len_rep + 1);
        tmp = strncpy(result, orig, len_front) + len_front;
        tmp = strcpy(tmp, with) + len_with;
        strcpy(tmp, ins + len_rep);
        return result;
    }