char path[1024]; // make sure buffer is large enough to hold the concatenated string
snprintf(path, sizeof(path), "%s%s", path_cmp1, path_cmp2);
