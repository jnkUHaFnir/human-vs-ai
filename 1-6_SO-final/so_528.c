    if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) {        } 
    else if (entry->d_type == DT_DIR) {
        strcpy(path_copy, path);
        strcat(path_copy, "/");
        strcat(path_copy, entry->d_name);
        rmrf(path_copy);
        remove(path);
    } else { //file delete
        strcpy(path_copy, path);
        strcat(path_copy, "/");
        strcat(path_copy, entry->d_name);
        remove(path_copy);
    }