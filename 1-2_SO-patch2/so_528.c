    if ((strcmp(entry->d_name, ".") != 0) && (strcmp(entry->d_name, "..") != 0)) {
        if (entry->d_type == DT_DIR) {
            strcpy(path_copy, path);
            strcat(path_copy, "/");
            strcat(path_copy, entry->d_name);
            rmrf(path_copy);
            remove(path);
        } else {
            sprintf(path_copy, "%s/%s", path, entry->d_name);
            remove(path_copy);
        }
    }